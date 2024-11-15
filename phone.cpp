#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <iomanip>
using namespace std;

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

    ~Phone() {
        totalBrands--;
        if (isAvailable) {
            totalnumberOfPhones--;
        }
    }

    void uploadPhone(string name, int number, string Brand, bool status) {
        PhoneName = name;
        numberOfProducts = number;
        brand = Brand;
        isAvailable = status;
        cout << "Phone details are updated here:\n";
        displayPhones();
    }

    void displayPhones() const {
        cout << "Phone name: " << PhoneName << "\n"
             << "Number of products: " << numberOfProducts << "\n"
             << "Brand: " << brand << "\n"
             << "availability status: " << (isAvailable ? "Not available" : "Available") << "\n";
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
};

int Phone::totalBrands = 0;
int Phone::totalnumberOfPhones = 0;

class User {
private:
    string userName;
    vector<Phone*> bookedPhones; 
};

int main() {
    const int numPhones = 3;
    Phone* phone[numPhones];
    
    phone[0] = new Phone("Galaxy S24 ultra", 123, "Samsung", false);
    phone[1] = new Phone("Iphone 16", 143, "Apple", false);
    phone[2] = new Phone("Note 13 pro", 230, "Redmi", true);

    for (int i = 0; i < numPhones; ++i) {
        cout << "Displaying phones \n";
        phone[i]->displayPhones();
    }

    for (int i = 0; i < numPhones; ++i) {
        cout << "Attempting to purchase phone from " << (phone[i]->isPresent() ? "available" : "unavailable") << endl; // Corrected 'Phone[i]' to 'phone[i]'
        phone[i]->orderPhone();
    }

    for (int i = 0; i < numPhones; ++i) {
        cout << "Displaying of brands available \n";
        phone[i]->displayPhones(); 
    }

    for (int i = 0; i < numPhones; ++i) {
        cout << "Attempting to purchase from " << (phone[i]->isPresent() ? "available" : "unavailable") << endl; // Corrected 'Phone[i]' to 'phone[i]'
        phone[i]->orderPhone(); 
    }

    Phone::displayStats(); 

    for (int i = 0; i < numPhones; ++i) {
        delete phone[i];
    }
    
    return 0;
}