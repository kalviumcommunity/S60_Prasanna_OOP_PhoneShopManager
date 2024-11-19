#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <iomanip>
using namespace std;

// Base Class
class Phone {
private:
    string PhoneName;
    int numberOfProducts;
    string brand;
    bool isAvailable;
    static int totalBrands;
    static int totalnumberOfPhones;

public:
    Phone() : PhoneName(""), numberOfProducts(0), brand(""), isAvailable(false) {
        totalBrands++;
    }

    Phone(string name, int num, string Brand, bool status)
        : PhoneName(name), numberOfProducts(num), brand(Brand), isAvailable(status) {
        totalBrands++;
    }

    virtual ~Phone() { 
        totalBrands--;
        if (isAvailable) {
            totalnumberOfPhones--;
        }
    }

    virtual void displayPhones() const { 
        cout << "Phone name: " << PhoneName << "\n"
             << "Number of products: " << numberOfProducts << "\n"
             << "Brand: " << brand << "\n"
             << "Availability status: " << (isAvailable ? "Not available" : "Available") << "\n";
    }

    bool isPresent() const {
        return !isAvailable && numberOfProducts > 0;
    }

    bool orderPhone() {
        if (isPresent()) {
            cout << "Phone successfully purchased from " << PhoneName << "\n";
            numberOfProducts -= 1;
            totalnumberOfPhones++;
            if (numberOfProducts == 0) {
                isAvailable = true;
            }
            return true;
        } else {
            cout << "The model " << PhoneName << " is not available.\n";
            return false;
        }
    }

    static void displayStats() {
        cout << "Total brands: " << totalBrands << "\n";
        cout << "Total phones purchased: " << totalnumberOfPhones << "\n";
    }

    static int getTotalBrands() {
        return totalBrands;
    }

    string getPhoneName() const {
        return PhoneName;
    }

    string getBrand() const {
        return brand;
    }

    int getNumberOfProducts() const {
        return numberOfProducts;
    }

    string getAvailabilityStatus() const {
        return isAvailable ? "Not available" : "Available";
    }
};

int Phone::totalBrands = 0;
int Phone::totalnumberOfPhones = 0;

// Derived Class
class Smartphone : public Phone {
private:
    string operatingSystem;
    int storage;

public:
    Smartphone(string name, int num, string Brand, bool status, string os, int stor)
        : Phone(name, num, Brand, status), operatingSystem(os), storage(stor) {}

    void displayPhones() const override { 
        Phone::displayPhones();
        cout << "Operating System: " << operatingSystem << "\n"
             << "Storage: " << storage << " GB\n";
    }
};

int main() {
    const int numDevices = 3;
    Phone* devices[numDevices]; 

    devices[0] = new Phone("Galaxy S24 ultra", 123, "Samsung", false);
    
    devices[1] = new Phone("Iphone 16", 143, "Apple", false);
    
    devices[2] = new Smartphone("Pixel 9", 50, "Google", false, "Android 14", 256);

    cout << "Displaying device details using polymorphism:\n";
    for (int i = 0; i < numDevices; ++i) {
        devices[i]->displayPhones(); 
        cout << "\n";
    }

    for (int i = 0; i < numDevices; ++i) {
        delete devices[i]; 
    }

    Phone::displayStats();
    cout << "Total number of brands: " << Phone::getTotalBrands() << "\n";

    return 0;
}
