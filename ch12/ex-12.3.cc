#include "ex-12.3.h"

void runQuery(ifstream &infile) {
    TextQuery tq(infile);
    while(true) {
        cout << "enter word to look for, or q for quit: ";
        string s;
        if(!(cin >> s) || s == "q") break;
        print(cout, tq.query(s)) << endl;
    }
}

int main() {
    ifstream ifs;
    runQuery(ifs);
}