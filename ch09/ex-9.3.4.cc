#include "../commheader.h"
#include<forward_list>

using std::forward_list;

// Exercise 9.27
void erase_odd(forward_list<int> &fl) {
    auto prev = fl.before_begin();
    auto curr = fl.begin();
    while(curr != fl.end()) {
        if(*curr % 2) {
            curr = fl.erase_after(prev);
        } else {
            prev = curr;
            ++curr;
        }
    }
}

// Exercise 9.28
void insert_into(forward_list<string> &sl, string s1, string s2) {
    auto prev = sl.before_begin();
    auto curr = sl.begin();
    while(curr != sl.end()) {
        if(*curr != s1) {
            prev = curr;
            ++curr;
        } else {
            sl.insert_after(curr, s2);
            return;
        }
    }
    sl.insert_after(prev, s2);
}

int main() {
    forward_list<int> fl = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for(auto a : fl)
        cout << a << " ";
    cout << endl;
    erase_odd(fl);
    for(auto a : fl)
        cout << a << " ";
    cout << endl;
    forward_list<string> sl = { "1", "2", "3", "4" };
    for(auto a : sl)
        cout << a << " ";
    cout << endl;
    insert_into(sl, "1", "0");
    for(auto a : sl)
        cout << a << " ";
    cout << endl;
    insert_into(sl, "5", "5");
    for(auto a : sl)
        cout << a << " ";
    cout << endl;
}