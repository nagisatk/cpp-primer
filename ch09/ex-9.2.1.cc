#include "../commheader.h"

// using vector<int>::Iterator = Iter;
typedef vector<int>::iterator Iter;
bool find(Iter b, Iter e, int val) {
    while(b != e) {
        if(*b == val)
            return true;
        ++b;
    }
    return false;
}

Iter findindex(Iter b, Iter e, int val) {
    while(b != e) {
        if(*b == val)
            return b;
        ++b;
    }
    return e;
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    bool b1 = find(vec.begin(), vec.end(), 9);
    bool b2 = find(vec.begin(), vec.end(), 11);
    cout << b1 << " " << b2 << endl;
    Iter r1 = findindex(vec.begin(), vec.end(), 8);
    Iter r2 = findindex(vec.begin(), vec.end(), 10);
    if(r1 != vec.end()) cout << *r1 << endl;
    if(r2 != vec.end()) cout << *r2 << endl;
    else cout << "No found." << endl;
}