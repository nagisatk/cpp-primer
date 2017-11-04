#include "../commheader.h"
#include<utility>
// Exercise 16.47

template <typename F, typename T1, typename T2>
void flip(F f, T1 &&t1, T2 &&t2) {
    f(std::forward<T2>(t2), std::forward<T1>(t1));
}

void f(int a, int &b) {
    // b is a reference
    cout << a << " " << ++b << endl;
}

void g(int &&a, int &b) {
    // b is a reference
    cout << a << " " << b << endl;
}

template <typename F, typename T1, typename T2>
void flip1(F f, T1 t1, T2 t2) {
    f(t2, t1);
}

template <typename F, typename T1, typename T2>
void flip2(F f, T1 &&t1, T2 &&t2) {
    f(t2, t1);
}

int main() {
    int i = 0, j = 0, k = 0, l = 0;
    cout << i << " " << j  << " " << k << " " << l << endl;
    f(42, i);           // i is changed
    flip1(f, j, 42);    // j will not be changed
    flip2(f, k, 42);    // k is changed by 'reference-collapse'
    // g(l, i);            // error: cannot bind rvalue reference of type 'int&&' to lvalue of type 'int' （l is a lvalue)
    flip(g, i, 42);     // 第三个参数的右值属性被保留了
    // flip1(g, i, 42);    // error
    // flip2(g, i, 42);    // error
    cout << i << " " << j  << " " << k << " " << l << endl;
}