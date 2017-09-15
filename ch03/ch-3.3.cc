#include<vector>
#include<iostream>
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

#define VARNAME(var) "values in " # var

template <typename T>
void display(vector<T> v) {
    cout << VARNAME(v) << " are : ";
    for(T val : v) {
        cout << val << ' ';
    }
    cout << endl;
}

int main() {
    vector<int> ivec;
    display(ivec);
    vector<int> ivec2(10, 2);    // contain 10 2s
    display(ivec2);
    vector<int> ivec3{
        10, 2                   // contain 10 and 2
    };
    display(ivec3);
    vector<string> svec(10);     // contain 10 null string
    display(svec);
    vector<string> svec2(10, "hi"); // contain 10 "hi"
    display(svec2);
    vector<string> svec3{
        "hi", "k"               // contain "hi" and "k"
    };
    display(svec3);
    vector<string> svec4{
        10, "lk"                // contain 10 "lk"s
    };
    display(svec4);
}
