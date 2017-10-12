#include "../commheader.h"

// Exercise 12.23
#include<cstring>
using std::strcpy;
using std::strlen;
using std::strcat;
char* concat_chars(const char* s1, const char* s2) {
    char *cp = new char[strlen(s1) + strlen(s2) + 1]();
    strcat(cp, s1);
    strcat(cp, s2);
    return cp;
}

char* concat_strs(const string& s1, const string& s2) {
    const string& s(s1 + s2);
    char *cp = new char[s.size() + 1];
    strcpy(cp, s.c_str());
    return cp;
}

// Exercise 12.24
char* read_console() {
    string line;
    cin >> line;
    char *cp = new char[line.size() + 1];
    strcpy(cp, line.c_str());
    // int size = 10;
    // char *cp = new char[size + 1]();
    // int index = 0;
    // char c;
    // while((c = getchar()) != EOF) {
    //     // deal with
    //     if(index >= size) {
    //         size *= 2;
    //         char *t = new char[size + 1]();
    //         strcat(t, cp);
    //         delete [] cp;
    //         cp = t;
    //     }
    //     cp[index] = c;
    //     ++index;
    // }
    return cp;
}

int main() {
    char *cp = concat_chars("Hello, ", "World.");
    cout << cp << endl;  // Hello, World.
    delete [] cp;
    cp = concat_strs("Nice to ", "meet you.");
    cout << cp << endl;   // Nice to meet you.
    delete [] cp;
    cp = read_console();
    cout << cp << endl;
    delete [] cp;
}