#include "../commheader.h"

#include <list>

using std::list;

vector<int> ivec = { 1, 2, 3, 4, 5 };
list<string> slst = { "q", "w", "e", "r", "t" };

// Exercise 16.19
// cannot print list
template <typename T>
void show_all(const T &t) {
    for (typename T::size_type i = 0; i < t.size(); ++i)
        cout << t[i] << " ";
}

void test_show_all() {
    show_all(ivec);
    cout << endl;
}

// Exercise 16.20
template <typename T>
void show_all2(const T &t) {
    auto beg = std::begin(t);
    auto end2 = std::end(t);
    while(beg != end2)
        cout << *beg++ << " ";
}

void test_show_all2() {
    show_all2(ivec);
    cout << endl;
    show_all2(slst);
    cout << endl;
}

int main() {
    test_show_all();
    test_show_all2();
}