#include "../commheader.h"

// Exercise 9.43
string &replace1(string &s, const string oldVal, const string newVal) {
    auto iter = s.begin();
    auto size = oldVal.size();
    while(iter <= s.end() - size) {
        if(string(iter, iter + size) == oldVal) {
            iter = s.erase(iter, iter + size);
            iter = s.insert(iter, newVal.cbegin(), newVal.cend());
            iter += newVal.size();
        } else
            ++iter;
    }
    return s;
}

// Exercise 9.44
string &replace2(string &s, const string oldVal, const string newVal) {
    decltype(s.size()) index = 0;
    auto size = oldVal.size();
    // result of substr contents the char at index
    while(index <= s.size() - size) {
        if(s.substr(index, size) == oldVal) {
            s.replace(index, size, newVal);
            index += size;
        } else
            ++index;
    }
    return s;
}

// Exercise 9.45
string &replace3(string &name, const string &prefix, const string &suffix) {
    string tp = prefix + " ";
    // string ts = ;
    name.insert(name.begin(), tp.begin(), tp.end());
    // name.insert(name.end(), ts.begin(), ts.end());
    name.append(" " + suffix);
    return name;
}


// Exercise 9.46
string &replace4(string &name, const string &prefix, const string &suffix) {
    string tp = prefix + " ";
    string ts = " " + suffix;
    name.insert(name.begin(), tp.begin(), tp.end());
    name.insert(name.end(), ts.begin(), ts.end());
    return name;
}

int main() {
    string s("tho, thru the ix...thru");
    s = replace1(s, "tho", "though");
    cout << s << endl;
    s = replace2(s, "thru", "through");
    cout << s << endl;
    string name("John");
    name = replace3(name, "Mr.", "Jr.");
    cout << name << endl;
    name = "Julia";
    cout << replace4(name, "Miss", "III");
}