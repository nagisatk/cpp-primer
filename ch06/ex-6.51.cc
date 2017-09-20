#include<iostream>

using std::cin;
using std::cout;
using std::endl;

void f() {
    cout << "Function f() is called." << endl;
}

void f(int) {
    cout << "Function f(int) is called." << endl;
}

void f(int, int) {
    cout << "Function f(int, int) is called." << endl;
}

void f(double, double = 5.4) {
    cout << "Function f(double, double = 5.4) is called." << endl;
}

int main() {
    // f(2.56, 42);    // error
    // f(42, 2.56);    // error
    f(42);          // 2
    f(42, 0);       // 3
    f(2.56, 3.14);  // 4
}