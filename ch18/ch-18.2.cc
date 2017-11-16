#include "../commheader.h"

// Ch 18.2.2
namespace A {
    int i = 1, j = 2;
}
void f() {
    using namespace A;
    cout << i * j << endl;
}

namespace blip {
    int i = 16, j = 15, k = 32;
}
int j = 0;
void manip() {
    using namespace blip;
    ++i;
    // ++j;    // reference to 'j' is ambiguous
    ++::j;
    ++blip::j;
    int k = 97; // hide the blip::k
    ++k;
    cout << i << " " << ::j << " " << blip::j << " " << k << endl;
}

// Ch 18.2.3
namespace C {
    int l;
    namespace D {
        int l;
        int m;
        int f1() {
            int m;
            return l;
        }
    }
    int f2() {
        // return m;   // identifier "m" is undefined
        return D::m;
    }
}

namespace E {
    int n;
    int o;
    class C1 {
    public:
        C1(): n(0), p(0) { }
        int f3() { return o; }
        // int f4() { return q; }  // use of undeclared identifier 'q'
        int f5();
    private:
        int n;
        int p;
    };
    int q = 0;
}

int E::C1::f5() { return q; }

int main() {
    f();
    manip();
    cout << C::f2() << endl;
    auto c = E::C1();
    cout << c.f3() << " " << c.f5() << endl;
}