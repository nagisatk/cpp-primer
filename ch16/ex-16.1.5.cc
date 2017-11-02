#include "../commheader.h"

// Exercise 16.26
class NoDefault {
public:
    NoDefault() = delete;
    NoDefault(int) { }
    void show() const {
        cout << "This is no default.\n";
    }
};

// Exercise 16.27
template <typename T> class Stack { };
void f1(Stack<char>) { }    // (a)  No
class Exercise {
    Stack<double> &rsd;     // (b)  No, it's a reference
    Stack<int> is;          // (c)  Yes. Require a Stack<int>
};

int main() {
    /**
     * Exercise 16.26
     * it's ok to initialize a vector<Nodefault>
     * but it's not ok to initialize a vector<Nodefault>(num)
     */
    vector<NoDefault> nvec1;
    // vector<NoDefault> nvec2(0);
    // Exercise 16.27
    Stack<char> *sc;                    // (d)  No, it's a pointer
    f1(*sc);                            // (e)  Yes, require a Stack<char>
    int iObj = sizeof(Stack<string>);   // (f)  Yes, require a Stack<string>
}
