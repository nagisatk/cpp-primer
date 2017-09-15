#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    cout << "Enter two numbers:\n";
    int val1, val2;
    cin >> val1 >> val2;
    cout << "The sum of " << val1 << ", " << val2
         << " is " << val1 + val2 << "." << endl;
    return 0;
}
