#include<iostream>

int main() {
    int i = -42;
    unsigned u = 10;
    std::cout << i + i << std::endl;
    std::cout << i + u << std::endl;
    int ii = 0, &r1 = ii;
    double d = 0, r2 = d;
    r2 = 31.3;
    r2 = r1;
    ii = r2;
    r1 = d;
    return 0;
}
