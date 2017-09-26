#include "../commheader.h"

#include<vector>
using std::vector;
// Exercise 7.43
class NoDefault {
public:
    NoDefault(int n): mem(n) {}
    void display() {
        cout << "Class NoDefault: " << mem << endl;
    }
private:
    int mem;
};

class C {
public:
    C():nod(0) {}
    void display() {
        cout << "Class C: ";
        this->nod.display();
    }
private:
    NoDefault nod;
};

int main() {
    NoDefault nod(9);
    nod.display();
    // Exercise 7.44
    // class NoDefault has no default constructor
    // the statement below is illegal
    // vector<NoDefault> vec(10);
    
    // Exercise 7.45
    // class C has a default constructor
    // the statement below is legal
    // all elements of vec is a object of class C has member NoDefault object
    // with a member whose value is 0.
    vector<C> vec(10);
    for(auto& n : vec) {
        n.display();
    }
}