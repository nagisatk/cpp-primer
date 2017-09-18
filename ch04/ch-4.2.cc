#include<iostream>
using std::cout;
using std::endl;

int main() {
    short short_value = 32767;
    short_value += 1;
    // overflow
    cout << "short value: " << short_value << endl;
    return 0;
}