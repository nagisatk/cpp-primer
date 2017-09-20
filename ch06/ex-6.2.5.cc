#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;

// exercise 6.25
void firstmain(int argc, char **argv) {
    string s1(argv[1]);
    string s2(argv[2]);
    s1 += s2;
    cout << s1 << endl;
}

// exercise 6.26
void secondmain(int argc, char **argv) {
    cout << argc << endl;
    for(int i = 0; i <= argc; ++i)
        if(argv[i] != 0)    
            cout << argv[i] << endl;
        else
            cout << '0' << endl;
}

int main(int argc, char **argv) {
    // firstmain(argc, argv);
    secondmain(argc, argv);
}