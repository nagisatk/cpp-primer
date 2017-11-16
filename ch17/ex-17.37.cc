#include "../commheader.h"

// Exercise 17.36
#include <fstream>
using std::ifstream;
// if LINESIZE < line.length
// the program cannot work.
#define LINESIZE (80)
void ex_17_36() {
    ifstream file("words.txt");
    string s;
    char line[LINESIZE];
    while (file.getline(line, 100)) {
        cout << line << endl;
    }
}

int main() {
    ex_17_36();
}