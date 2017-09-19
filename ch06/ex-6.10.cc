#include<iostream>
using std::cout;
using std::endl;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main() {
    int a = 10, b = 18;
    cout << "Before," << endl
         << "value of a is " << a << endl
         << "value of b is " << b << endl;
    swap(&a, &b);
    cout << "After," << endl
         << "value of a is " << a << endl
         << "value of b is " << b << endl;
}