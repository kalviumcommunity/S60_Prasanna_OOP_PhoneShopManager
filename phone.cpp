#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <iomanip>
using namespace std;

class Phone{
private:
    string PhoneName;
    int IMEInumber;
    string brand;
    
    
public:
    void check() {
        cout << "Welcome to this Phone Showroom!!" << endl;
    }
};

class User {
private:
    string name;
    int id;
public:
    void buyPhone(int id) {
        cout << "I am interested in buying phone from your shop." << id << "Phone Model" << endl;
    }
};

int main() {
    Phone Samsung;
    User Prasanna;
    
    Samsung.check();
    Prasanna.buyPhone(123);
    return 0;
}