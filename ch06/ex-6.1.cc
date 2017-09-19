#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int fact(int val) {
    int ret = 1;
    while(val > 1)
        ret *= val--;
    return ret;
}

void do_fact() {
    int val;
    cout << "Please input a number and I will show it's fact:" << endl;
    cin >> val;
    cout << "The fact of " << val << " is " << fact(val) << endl;
}

int abs(int val) {
    if(val < 0)
        return -val;
    else
        return val;
}

void do_abs() {
    int val;
    cout << "Please input a number and I will show it's abs:" << endl;
    cin >> val;
    cout << "The abs of " << val << " is " << abs(val) << endl;
}

int main() {
    cout << "Hello," << endl;
    // do_fact();
    do_abs();
}