
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    // read and write string object
    string s1;
    cin >> s1;
    cout << s1;
    // read an unknown number of string values
    string word;
    // while(cin >> word)
        // cout << word << endl;
    // rad a line and wrte a line
    string line;
    while(getline(cin, line))
        cout << line << endl;
    return 0;
}
