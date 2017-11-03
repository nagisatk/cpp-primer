#include "../commheader.h"

// Exercise 16.42
template <typename T>
void g(T&& val) {
    // prof
    T loc = val;
    cout << "address of loc: " << &loc << endl;
    cout << "address of val: " << &val << endl;
}

// Exercise 16.44
template <typename T>
void h(T val) {
    // prof
    T loc = val;
    cout << "address of loc: " << &loc << endl;
    cout << "address of val: " << &val << endl;
}

template <typename T>
void f(const T &val) {
    // prof
    T loc = val;
    cout << "address of loc: " << &loc << endl;
    cout << "address of val: " << &val << endl;
}

// Exercise 16.45
template <typename T>
void g2(T&& val) {
    vector<T> v;
}


int main() {
    // Exercise 16.42
    int i = 0;
    const int ci = i;
    cout << "address of i  : " << &i << endl;
    cout << "address of ci : " << &ci << endl;
    cout << "g(i):" << endl;
    // (a)  int&    -> int&
    // 当实参为一个左值时，编译器推断T为实参的左值引用类型而不是左值类型。
    // 而int& &&在引用折叠规则的作用下被折叠为int&
    g(i);   // same as i
    cout << "g(ci):" << endl;
    // (b)  const int&  -> int&
    // 同上。
    g(ci);  // same as ci
    cout << "g(i * ci):" << endl;
    // (c)  int -> int&&
    // 实参是一个右值，编译器就推断T为该右值的类型，
    // 因此val的类型就是右值类型的右值引用
    g(i * ci);  // differ from ci and i
    // Exercise 16.43
    // (i = ci)返回一个左值，所以推断类型是int&，引用折叠之后是int&
    // Exercise 16.44
    // 函数声明为T，表明参数传递是传值的，三个调用中，T均为int
    cout << "h(i):" << endl;
    h(i);
    cout << "h(ci):" << endl;
    h(ci);
    cout << "h(i * ci):" << endl;
    h(i * ci);
    // 函数声明为const int& 时，表明可以传递给它任何类型的参数，T的类型推断结果也不会是const的。
    // T为int， val的类型为const int&
    cout << "f(i):" << endl;
    f(i);
    cout << "f(ci):" << endl;
    f(ci);
    cout << "f(i * ci):" << endl;
    f(i * ci);
    // Exercise 16.45
    g2(42);
    /**
     * T被推断为int&。
     * 引用不是对象，没有实际地址，因此不能定义指向引用的指针。
     * 所以不能声明vector<int&>
     */
    // g2(i);   // error
}