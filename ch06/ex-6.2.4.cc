#include<iostream>
using std::cout;
using std::endl;

// exercise 6.21
int greaterone(const int a, const int *b) {
    if(a >= *b)
        return a;
    return *b;
}

// exercise 6.22
void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int main() {
    int a = 1;
    int b = 2;
    cout << greaterone(a, &b) << endl;
    swap(&a, &b);
    cout << a << ", " << b << endl;
}