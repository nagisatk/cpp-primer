#include "../commheader.h"

class Foo {
public:
    Foo sorted() &&;
    Foo sorted() const &;
    using Comp = bool(const int&, const int&);
    Foo sorted(Comp*);
    Foo sorted(Comp*) const;
private:
    vector<int> data;
};
#include<algorithm>
using std::sort;
Foo Foo::sorted() && {
    cout << "call Foo Foo::sorted() && " << endl;
    sort(data.begin(), data.end());
    return *this;
}

Foo Foo::sorted() const & {
    cout << "call Foo Foo::sorted() const & " << endl;
    Foo ret(*this);
    sort(ret.data.begin(), ret.data.end());
    return ret;
}


Foo Foo::sorted(Comp *com) {
    cout << "call Foo Foo::sorted(Comp *com) " << endl;
    sort(data.begin(), data.end(), com);
    return *this;
}

Foo Foo::sorted(Comp *com) const {
    cout << "call Foo Foo::sorted(Comp *com) const " << endl;
    Foo ret(*this);
    sort(ret.data.begin(), ret.data.end(), com);
    return ret;
}

bool bar(const int&, const int&) {
    return false;
}

int main() {
    Foo foo1;
    const Foo foo2(foo1);
    Foo &&foo3 = std::move(foo1);
    Foo &foo4(foo1);
    foo2.sorted();
    foo3.sorted();
    foo1.sorted();
    foo4.sorted();
    Foo(foo1).sorted();
    foo1.sorted(bar);
    foo2.sorted(bar);
    foo3.sorted(bar);
    foo4.sorted(bar);
    std::move(foo1).sorted(bar);
    // Exercise 13.56
    // 递归，无法得到合法的返回值
    // Exercise 13.57
    // 可以得到正确的返回值
}