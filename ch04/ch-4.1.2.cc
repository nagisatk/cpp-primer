#include<iostream>

int main() {
    int i = 0;
    // UB
    std::cout << i << " " << i++ << '\n';
}