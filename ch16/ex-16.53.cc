#include "../commheader.h"

// Exercise 16.53
template <typename T>
ostream& print(ostream &os, const T &t) {
    return os << t << endl;
}

template <typename T, typename ... Args>
ostream& print(ostream &os, const T &t, const Args& ... args) {
    os << t << " ";
    return print(os, args...);
}

int main() {
    int i = 0;
    char a = 'A';
    string s("how");
    print(cout, 42);
    print(cout, i, a);
    print(cout, "hi", s, i, a, 3.14);
}