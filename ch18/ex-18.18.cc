#include "../commheader.h"

// Exercise 18.18
template <typename T>
void swap(T v1, T v2) {
    cout << "---" << endl;
    using std::swap;
    swap(v1.mem1, v2.mem1);
}

struct A {
    // string mem1;
    int mem1;
};

int main() {
    A a, b;
    // a.mem1 = "a";
    // b.mem1 = "b";
    a.mem1 = 1;
    b.mem1 = 2;
    std::swap(a.mem1, b.mem1);
    cout << a.mem1 << " " << b.mem1;
}