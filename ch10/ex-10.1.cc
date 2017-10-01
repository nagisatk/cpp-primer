#include "../commheader.h"

#include<algorithm>

// Exercise 10.1
void count_int() {
    vector<int> vec;
    int a;
    // input: 10 89 28 18 10 29 10 23 100
    while(cin >> a)
        vec.push_back(a);
    cout << std::count(vec.begin(), vec.end(), 10) << endl; // 3
}

// Exercise 10.2
void count_str() {
    vector<string> vec;
    string a;
    // input: abc def str ghi jkl str str mno
    while(cin >> a)
        vec.push_back(a);
    cout << std::count(vec.begin(), vec.end(), "str") << endl; // 3
}

int main() {
    count_str();
}