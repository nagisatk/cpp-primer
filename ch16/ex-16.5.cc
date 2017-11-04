#include "../commheader.h"

// Exercise 16.63
template <typename T>
size_t find_all(vector<T> &vec, const T t) {
    size_t count = 0;
    for (auto ele : vec)
        if (ele == t)
            ++count;
    return count;
}

// Exercise 16.64
#include <cstring>
template <>
size_t find_all(vector<const char*> &vec, const char *t) {
    size_t count = 0;
    for (auto ele : vec)
        if (!std::strcmp(ele, t))
            ++count;
    return count;
}


int main() {
    vector<int> ivec{ 1, 2, 3, 4, 3, 2, 1, 0 };
    cout << find_all(ivec, 3) << endl;
    vector<double> dvec{ 1, 2, 3, 4, 3, 2, 1, 0 };
    cout << find_all(dvec, 3.0) << endl;
    vector<string> svec{ "1", "2", "3", "4", "3", "2", "1", "0" };
    cout << find_all(svec, string("3")) << endl;
    vector<const char*> cvec{ "1", "2", "3", "4", "3", "2", "12", "0" };
    cout << find_all(cvec, "1") << endl;
}