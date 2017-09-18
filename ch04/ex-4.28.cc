#include<iostream>
using std::cout;
using std::endl;
#include<cstdio>

int main() {
    cout << "Built-in type 'char'        takes " << sizeof(char)        << "\tbytes of memory." << endl;
    cout << "Built-in type 'short'       takes " << sizeof(short)       << "\tbytes of memory." << endl;
    cout << "Built-in type 'int'         takes " << sizeof(int)         << "\tbytes of memory." << endl;
    cout << "Built-in type 'long'        takes " << sizeof(long)        << "\tbytes of memory." << endl;
    cout << "Built-in type 'float'       takes " << sizeof(float)       << "\tbytes of memory." << endl;
    cout << "Built-in type 'double'      takes " << sizeof(double)      << "\tbytes of memory." << endl;
    cout << "Built-in type 'long long'   takes " << sizeof(long long)   << "\tbytes of memory." << endl;
    cout << "Built-in type 'long double' takes " << sizeof(long double) << "\tbytes of memory." << endl;
}