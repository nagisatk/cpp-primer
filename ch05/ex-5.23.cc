#include<stdexcept>
#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::runtime_error;

// exercise 5.23
int div_no_execpt() {
    int i, j;
    cin >> i >> j;
    return i/j;
}

// exercise 5.24
void div_has_except() {
    int i, j;
    cin >> i >> j;
    if(j == 0)
        throw runtime_error("Zero division.");
    else
        cout << i/j;
}

// exercise 5.25
void div_has_trycatch() {
    int i, j;
    while(cin >> i >> j) {
        try {
            if(j == 0)
                throw runtime_error("Zero division.");
            else
                cout << i/j;
        } catch (runtime_error err) {
            cout << err.what()
                 << "\nContinue? n for quit:\n";
            char c;
            cin >> c;
            if(!cin || c == 'n')
                break;
        }
    }
}

int main() {
    // cout << div_no_execpt();
    // div_has_except();
    div_has_trycatch();
}