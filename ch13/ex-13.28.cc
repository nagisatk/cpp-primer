#include "../commheader.h"

// Exercise 13.28
class HasPtr {
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0), use(new size_t(1)) { cout << "default: " << *use << endl; }
    HasPtr(const HasPtr &hp):ps(new string(*(hp.ps))), i(hp.i), use(hp.use) { ++*use;cout << "copy: " << *use << endl; }
    HasPtr& operator=(const HasPtr &n);
    ~HasPtr() {
        cout << "destructor: " << *use << endl;
        if(--*use == 0) {
            delete ps;
            delete use;
        }
    }
private:
    string *ps;
    int i;
    size_t *use;
};

HasPtr& HasPtr::operator=(const HasPtr &rhs) {
    cout << "assign: " << *use << endl;
    ++*(rhs.use);
    if(--*use == 0) {
        delete use;
        delete ps;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
}

int main() {
    // output:
    // default: 1
    // copy: 2
    // copy: 3
    // destructor: 3
    // destructor: 2
    // destructor: 1
    HasPtr hp1("Hello");
    HasPtr hp2(hp1);
    HasPtr hp3 = hp2;
}