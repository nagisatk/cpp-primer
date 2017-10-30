// #include "../commheader.h"
#include<vector>
#include<list>
#include<iostream>
#include<string>

using std::vector;
using std::list;
using std::cout;
using std::endl;
using std::string;

// Exercise 16.4
template <typename IterTy, typename Ty>
IterTy simple_find(IterTy beg, IterTy end, const Ty &val) {
    for (; beg != end; ++beg)
        if (*beg == val)
            return beg;
    return end;
}

void test_simple_find() {
    vector<int> vec{ 1, 2, 3, 4, 5, 6, 7 };
    list<string> lst{ "1", "2", "3", "4", "5", "6", "7" };
    auto res1 = simple_find(vec.begin(), vec.end(), 9);
    if (res1 == vec.end())
        cout << "Not found." << endl;
    else
        cout << "Object found: " << *res1 << endl;
    auto res2 = simple_find(lst.begin(), lst.end(), "6");
    if (res2 == lst.end())
        cout << "Not found." << endl;
    else
        cout << "Object found: " << *res2 << endl;
}
// Exercise 16.5
template <typename Ty, size_t N>
void print(Ty (&arr)[N]) {
    for (auto a : arr)
        cout << a << endl;
}

int arr1[] = { 1, 2, 3, 4 };
string arr2[] = { "Hello", "world", "yoho~" };

void test_print() {
    print(arr1);
    print(arr2);
}

// Exercise 16.6
template <typename Ty, size_t N>
Ty* simple_begin(Ty (&arr)[N]) {
    return arr;
}

template <typename Ty, size_t N>
Ty* simple_end(Ty (&arr)[N]) {
    return arr + N;
}

void test_beg_n_end() {
    auto beg1 = simple_begin(arr1);
    auto end1 = simple_end(arr1);
    for (;beg1 != end1; ++beg1) {
        cout << *beg1 << " ";
    }
    cout << endl;
    auto beg2 = simple_begin(arr2);
    auto end2 = simple_end(arr2);
    for (; beg2 != end2; ++beg2) {
        cout << *beg2 << " ";
    }
    cout << endl;
}

// Exercise 16.7
template <typename Ty, size_t N>
constexpr size_t size_of(Ty (&arr)[N]) {
    return N;
}

void test_size_of() {
    cout << "size of arr1 is: " << size_of(arr1) << endl;
    cout << "size of arr2 is: " << size_of(arr2) << endl;
}

int main() {
    test_simple_find();
    test_print();
    test_beg_n_end();
    test_size_of();
}