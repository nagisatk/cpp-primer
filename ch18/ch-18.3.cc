#include "../commheader.h"

// Ch 18.3.4
struct A {
    int memA;
};

struct B : A {
    int memB;
};

struct C : A {
    int memC;
};

struct D : B,C {
    int memD;
};

void Ch18_3_4() {
    cout << "Size of A:" << sizeof(A) << endl;  // 4
    cout << "Size of B:" << sizeof(B) << endl;  // 8
    cout << "Size of C:" << sizeof(C) << endl;  // 8
    cout << "Size of D:" << sizeof(D) << endl;  // 20 which contain two As.
    D d;
    d.B::memA = 10;
    d.C::memA = 11;
    cout << d.B::memA << endl;
    cout << d.C::memA << endl;
}

int main() {
    Ch18_3_4();
}