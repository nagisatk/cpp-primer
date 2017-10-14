#include "../commheader.h"

// Exercise 13.22
class HasPtr {
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) { }
    HasPtr(const HasPtr &hp):ps(new string(*(hp.ps))), i(hp.i) { }
    HasPtr& operator=(const HasPtr &n) {
        auto nps = new string(*n.ps);
        delete ps;
        ps = nps;
        i = n.i;
        return *this;
    }
    // void modify(const string &s) {
    //     auto nps = new string(s);
    //     delete ps;
    //     ps = nps;
    // }
    // void output() {
    //     cout << *ps << " " << i << endl;
    // }
    ~HasPtr() {
        delete ps;
    }
private:
    string *ps;
    int i;
};

int main() {
    HasPtr hp1("Hello");
    HasPtr hp2(hp1);
    hp1.output();   // Hello
    hp2.output();   // Hello
    hp2.modify("Yoho~");
    hp1.output();   // Hello
    hp2.output();   // Yoho~
    HasPtr hp3 = hp1;
    hp3.output();   // Hello
}