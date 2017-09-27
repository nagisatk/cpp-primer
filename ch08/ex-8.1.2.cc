#include "../commheader.h"

// Exercise 8.1
istream &test_istream(istream& is) {
    auto old_state = is.rdstate();
    cout << "start: is's current state is: " << old_state << endl;
    string s;
    while(cin >> s)
        cout << s << " ";
    cout << endl;
    cout << "after: is's current state is: " << is.rdstate() << endl;
    cout << "-----: is's old state is: " << old_state << endl;
    is.setstate(old_state);
    cout << "after setstate(old_state): is's state is: " << is.rdstate() << endl;
    is.clear();
    cout << "after clear(): is's state is: " << is.rdstate() << endl;
    return is;
}

int main() {
    test_istream(cin);
    // Exercise 8.2
    /**
     * setstate(oldstate) don't force to overwrite the state of istream.
     */
}