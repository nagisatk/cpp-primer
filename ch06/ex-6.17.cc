#include<iostream>
#include<string>
#include<cctype>

using std::string;
using std::cout;
using std::endl;

bool has_upper(const string& s) {
    for(auto c : s)
        if(isupper(c))
            return true;
    return false;
}

void to_lowercase(string& s) {
    // must use a reference here to change the case
    for(auto& c : s)
        if(isupper(c))
            c = tolower(c);
}

int main() {
    string s = "my name is Nagisa.";
    string t = "all lower case";
    bool res = has_upper(s);
    bool re  = has_upper(t);
    cout << res << endl << re << endl;
    to_lowercase(s);
    cout << s << endl;
    return 0;
}