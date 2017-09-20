#include<iostream>
#include<vector>
#include<stdexcept>

using std::runtime_error;
using std::cout;
using std::endl;
using std::vector;

int func(int ,int);

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

int division(int a, int b) {
    if(b == 0)
        throw runtime_error("Zero division.");
    return a / b;
}

int main() {
    // vector<decltype(func)*> fvec;
    vector<int (*)(int, int)> fvec;
    fvec.push_back(add);
    fvec.push_back(sub);
    fvec.push_back(mul);
    fvec.push_back(division);
    for(auto fun : fvec) {
        cout << fun(10, 0) << endl;
    }
}