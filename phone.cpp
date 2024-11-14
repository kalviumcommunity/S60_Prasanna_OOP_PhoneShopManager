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

public:
    void check() {
        cout << "Welcome to this Phone Showroom!!" << endl;
        cout << "I am using this :)" << endl;
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
    Phone *Samsung = new Phone;
    User *Prasanna = new User;
    Samsung->check();
    Prasanna->buyPhone(123);
    delete Samsung;
    delete Prasanna;
    return 0;
}
