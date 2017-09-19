#include<iostream>
using std::cout;

int fact(int val) {
    int ret = 1;
    while(val > 1)
        ret *= val--;
    return ret;
}

int main() {
    int ret = fact(5);
    cout << "5! is " << ret << std::endl;
    return 0;
}