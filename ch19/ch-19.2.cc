#include "../commheader.h"

// Ch 19.2.3
class Base {
    friend bool operator==(const Base&, const Base&);
public:
    Base() = default;
    Base(int b): base(b) { }
    // ~Base();
protected:
    virtual bool equal(const Base &) const;
private:
    int base;
};

class Derived : public Base {
public:
    Derived() = default;
    Derived(int d): derived(d) { }
    Derived(int b, int d): Base(b), derived(d) { }
protected:
    bool equal(const Base&) const;
private:
    int derived;
};

bool Base::equal(const Base &other) const {
    // cout << base << " -- base -- " << other.base << endl;
    return base == other.base;
}

bool Derived::equal(const Base &other) const {
    if(!Base::equal(other)) return false;
    auto r = dynamic_cast<const Derived&>(other);
    // cout << derived << " -- derived -- " << r.derived << endl;
    return derived == r.derived;
}

bool operator==(const Base &lhs, const Base &rhs) {
    return typeid(lhs) == typeid(rhs) && lhs.equal(rhs);
}
void ch19_2_3() {
    cout << typeid(4).name() << endl;
    Derived d1(1, 1);
    Derived d2(1);
    Base &b1 = d1;
    Base &b2 = d2;
    cout << (b1 == b2) << endl;
}

int main() {
    ch19_2_3();
}