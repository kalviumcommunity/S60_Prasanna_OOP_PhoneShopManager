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
    int IMEInumber;
    string brand;
    bool isAvailable;

public:
    Phone() : PhoneName(""), IMEInumber(0), brand(""), isAvailable(false) {}

    Phone(string name, int num, string brand, bool status)
        : PhoneName(name), IMEInumber(num), brand(brand), isAvailable(status) {}

    void uploadPhone(string name, int number, string Brand, bool status) {
        PhoneName = name;
        IMEInumber = number;
        brand = Brand;
        isAvailable = status;
        cout << "Phone details are updated here:\n";
        displayPhones();
    }

    void displayPhones() const {
        cout << "Phone name: " << PhoneName << "\n"
             << "IMEI Number: " << IMEInumber << "\n"
             << "Brand: " << brand << "\n"
             << "availability status: " << (isAvailable ? "Not available" : "Available") << "\n";
    }

    bool isPresent() const {
        return !isAvailable && IMEInumber > 0;
    }

    bool orderPhone() {
        if (isPresent()) {
            isAvailable = true;
            cout << "Phone successfully purchased :- " << PhoneName << "\n";
            return true;
        } else {
            cout << "The model " << PhoneName << " is not available.\n";
            return false;
        }
    }
};

class User {
private:
    string name;
    int id;

public:
    void buyPhone(int id) {
        cout << "I am interested in buying phone from your shop." << endl;
        cout << "User ID: " << this->id << ", Phone Model: " << id << endl;
    }
};

int main() {
    Phone phone[3] = {
        Phone("Galaxy s24 ultra", 101, "Samsung", false),
        Phone("Iphone 16 pro", 209, "Apple", false),
        Phone("Note 13 pro", 130, "Redmi", true)
    };
    for (int i = 0; i < 3; ++i) {
        phone[i].displayPhones();
    }
    for (int i = 0; i < 3; ++i) {
        cout << "Wishing to buy " << phone[i].isPresent() << endl;
        phone[i].orderPhone();
    }
}
