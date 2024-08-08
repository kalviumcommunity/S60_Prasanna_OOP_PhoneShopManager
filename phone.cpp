#include <iostream>
#include <vector>
#include <string>

using namespace std;

class PhoneDetails {
private:
    string ModelName;
    string Brand;

public:
    PhoneDetails(string m, string b) : ModelName(m), Brand(b) {}

    void display() const {
        cout << "Model name: " << ModelName << endl;
        cout << "Brand name: " << Brand << endl;
    }
};

class Shop {
private:
    vector<PhoneDetails> Phones;

public:
    void addPhone(const PhoneDetails& phone) {
        Phones.push_back(phone);
    }

    void showPhones() const {
        cout << "Phones available:\n";
        for (const auto& phone : Phones) {
            phone.display();
        }
    }
};

int main() {
    PhoneDetails phone1("iPhone 15", "Apple");
    PhoneDetails phone2("Samsung S24", "Samsung");

    Shop shop;

    shop.addPhone(phone1);
    shop.addPhone(phone2);

    shop.showPhones();
    return 0;
}

