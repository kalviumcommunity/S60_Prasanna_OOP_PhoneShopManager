#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <iomanip>
using namespace std;

class Device {
public:
    virtual void displayPhones() const = 0; 
    virtual bool isAvailableForPurchase() const = 0; 
    virtual ~Device() {} 
};

class PhoneStatistics {
private:
    static int totalBrands;
    static int totalnumberOfPhones;

public:
    static void incrementBrands() {
        totalBrands++;
    }

    static void decrementBrands() {
        totalBrands--;
    }

    static void incrementPhonesPurchased() {
        totalnumberOfPhones++;
    }

    static void decrementPhonesPurchased() {
        totalnumberOfPhones--;
    }

    static void displayStats() {
        cout << "Total brands: " << totalBrands << "\n";
        cout << "Total phones purchased: " << totalnumberOfPhones << "\n";
    }

    static int getTotalBrands() {
        return totalBrands;
    }
};

int PhoneStatistics::totalBrands = 0;
int PhoneStatistics::totalnumberOfPhones = 0;

class Phone : public Device {
private:
    string PhoneName;
    int numberOfProducts;
    string brand;
    bool isAvailable;

public:
    Phone() : PhoneName(""), numberOfProducts(0), brand(""), isAvailable(false) {
        PhoneStatistics::incrementBrands();
    }

    Phone(string name, int num, string Brand, bool status)
        : PhoneName(name), numberOfProducts(num), brand(Brand), isAvailable(status) {
        PhoneStatistics::incrementBrands();
    }

    virtual ~Phone() { 
        PhoneStatistics::decrementBrands();
        if (isAvailable) {
            PhoneStatistics::decrementPhonesPurchased();
        }
    }

    virtual void displayPhones() const override { 
        cout << "Phone name: " << PhoneName << "\n"
             << "Number of products: " << numberOfProducts << "\n"
             << "Brand: " << brand << "\n"
             << "Availability status: " << (isAvailable ? "Not available" : "Available") << "\n";
    }

    virtual bool isAvailableForPurchase() const override { 
        return !isAvailable && numberOfProducts > 0;
    }

    bool orderPhone() {
        if (isAvailableForPurchase()) {
            cout << "Phone successfully purchased from " << PhoneName << "\n";
            numberOfProducts -= 1;
            PhoneStatistics::incrementPhonesPurchased();
            if (numberOfProducts == 0) {
                isAvailable = true;
            }
            return true;
        } else {
            cout << "The model " << PhoneName << " is not available.\n";
            return false;
        }
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

    bool isAvailableForPurchase() const override { 
        return Phone::isAvailableForPurchase();
    }
};

class FeaturePhone : public Phone {
private:
    bool hasKeypad;

public:
    FeaturePhone(string name, int num, string Brand, bool status, bool keypad)
        : Phone(name, num, Brand, status), hasKeypad(keypad) {}

    void displayPhones() const override {
        Phone::displayPhones();
        cout << "Has Keypad: " << (hasKeypad ? "Yes" : "No") << "\n";
    }

    bool isAvailableForPurchase() const override { 
        return Phone::isAvailableForPurchase();
    }
};

int main() {
    const int numDevices = 4;
    Device* devices[numDevices]; 

    devices[0] = new Phone("Galaxy S24 ultra", 123, "Samsung", false);
    devices[1] = new Phone("Iphone 16", 143, "Apple", false);
    devices[2] = new Smartphone("Pixel 9", 50, "Google", false, "Android 14", 256);
    devices[3] = new FeaturePhone("Nokia 3310", 200, "Nokia", false, true);

    cout << "Displaying device details using polymorphism:\n";
    for (int i = 0; i < numDevices; ++i) {
        devices[i]->displayPhones(); 
        cout << "Available for purchase: " << (devices[i]->isAvailableForPurchase() ? "Yes" : "No") << "\n";
        cout << "\n";
    }

    for (int i = 0; i < numDevices; ++i) {
        delete devices[i]; 
    }

    PhoneStatistics::displayStats();
    cout << "Total number of brands: " << PhoneStatistics::getTotalBrands() << "\n";

    return 0;
}
