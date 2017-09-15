#include<iostream>

int main() {
    int i = 42;
    int &r1 = i;
    const int &r2 = i;
    r1 = 0;
    std::cout << r2 << std::endl;
    const double pi = 3.14;
    // const pointer* 不能通过 *pointer改变对象的值
    // 但可以更改pointer所指向的对象
    const double *cp = &pi;
    std::cout << *cp << std::endl;
    const double e = 2.71828;
    cp = &e;
    std::cout << *cp << std::endl;
    // *const pointer不能更改指向的对象
    // 但是可以通过 *pointer更改对象的值
    double d = 4.72;
    double *const sp = &d;
    *sp = 9.0;
    return 0;
}
