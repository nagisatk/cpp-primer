#include<vector>
#include<iostream>
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

// Exercise 3.14
void collect_int() {
    vector<int> ivec;
    int val;
    while(cin >> val)
        ivec.push_back(val);
    for(int v : ivec)
        cout << v << ' ';
    cout << endl;

    cin.sync();
}

// Exercise 3.15
void collect_string() {
    vector<string> svec;
    string sval;
    while(cin >> sval)
        svec.push_back(sval);
    for(string v : svec)
        cout << v << ' ';
    cout << endl;
}

int main() {
    // collect_int();
    collect_string();
    return 0;
}
