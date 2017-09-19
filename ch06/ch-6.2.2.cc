#include<string>
#include<iostream>
using std::string;
using std::cout;
using std::endl;

string::size_type find_char(const string &s, char c, string::size_type &occur) {
    auto ret = s.size();
    occur = 0;
    for(decltype(ret) i = 0; i != s.size(); ++i) {
        if(s[i] == c) {
            if(ret == s.size())
                ret = i;
            ++occur;
        }
    }
    return ret;
}

// test function for ref
void to10(int &a) {
    a = 10;
}

int main() {
    string s = "Hello, my name is Nagisa.";
    auto occur = s.size();
    char c = 'm';
    auto ret = find_char(s, c, occur);
    cout << "charactor 'm' occured in the string \""
         << s << "\" " << occur << " times." << endl
         << "the first position is " << ret << endl;
    int a = 0;
    to10(a);
    cout << a << endl;  // 10
}