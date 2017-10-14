#include "../commheader.h"

// Exercise 13.30
class HasPtr {
public:
    friend void swap(HasPtr&, HasPtr&);
    friend bool operator<(const HasPtr &lhs, const HasPtr &rhs);
    HasPtr(const string &s = string()): ps(new string(s)), i(0) { }
    HasPtr(const HasPtr &hp): ps(new string(*(hp.ps))), i(hp.i) { }
    HasPtr& operator=(HasPtr n) {
        this->swap(n);
        return *this;
    }
    ~HasPtr() {
        delete ps;
    }
    void swap(HasPtr &rhs) 
    {
        using std::swap;
        swap(ps, rhs.ps);
        swap(i, rhs.i);
        std::cout << "call swap(HasPtr &rhs)" << std::endl;
    }
    void output() const {
        cout << *ps << " " << i << endl;
    }
private:
    string *ps;
    int i;
};

void swap(HasPtr& lhs, HasPtr& rhs) {
    cout << "swap executing." << endl;
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

bool operator<(const HasPtr &lhs, const HasPtr &rhs)
{
    return *lhs.ps < *rhs.ps;
}

#include<algorithm>
int main() {
    HasPtr a("Nihao"), b("Wohao"), c("Tahao");
    vector<HasPtr> vh = { a, b, c };
    std::sort(vh.begin(), vh.end());    // operator=
    for(auto const& h : vh)
        h.output();
}