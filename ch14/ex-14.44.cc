#include "../commheader.h"

#include<functional>
using std::function;

int add(int a, int b) {
    return a + b;
}

struct divide {
    int operator()(int a, int b) {
        return a / b;
    }
};

int main() {
    auto mod = [](int a, int b) { return a % b; };
    map<string, function<int(int, int)>> binops = {
        { "+", add },
        { "-", std::minus<int>() },
        { "*", [](int a, int b) { return a * b; }},
        { "/", divide() },
        { "%", mod }
    };
    int a, b;
    string op;
    // no error checking =_=
    // but if using char rather than string it will be okay
    // in this case
    // however if a op with two or more chars will be added
    // in the future, char is bad.
    while(cin >> a >> op >> b) {
        cout << a << " " << op << " " << b << " = "
             << binops[op](a, b) << endl;
    }

    return 0;
}