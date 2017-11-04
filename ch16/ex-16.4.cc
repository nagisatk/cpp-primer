#include "../commheader.h"

// Exercise 16.51 52
template <typename ... Args>
void g(Args ... args) {
    cout << "sizeof...(Args): " << sizeof...(Args) << endl;
    cout << "sizeof...(args): " << sizeof...(args) << endl;
}

template <typename T, typename ... Args>
void foo(const T &t, const Args ... rest) {
    cout << t << endl;
    g(rest...);
}


int main() {
    int i = 0; double d = 3.14; string s = "how now brown cow";
    foo(i, s, 42, d);
    foo(s, 42, "hi");
    foo(d, s);
    foo("hi");
}