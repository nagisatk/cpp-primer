#include "../commheader.h"
#include <regex>
using std::regex;
using std::regex_match;
using std::regex_search;
using std::smatch;
using std::sregex_iterator;

// Ch 17.3.1
void ch17_3_1(const string &s) {
    string pattern("[^c]ei");
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    regex r(pattern);
    smatch results;
    if (regex_search(s, results, r))
        cout << results.str() << endl;
}

// Ch 17.3.2
using std::begin;
using std::end;
void ch17_3_2(const string &s) {
    string pattern("[^c]ei");
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    regex r(pattern, regex::icase);
    for (sregex_iterator it(s.begin(), s.end(), r), end_it;
            it != end_it; ++it) {
        auto pos = it->prefix().length();
        pos = pos > 40 ? pos - 40 : 0;
        cout << it->prefix().str().substr(pos)
             << "\n\t\t>>> " << it->str() << " <<<\n"
             << it->suffix().str().substr(0, 40)
             << endl;
    }
}

#include <fstream>
#include <sstream>
using std::ifstream;
using std::stringstream;
#define BUFSIZE (2048)
int main() {
    string test_str = "receipt freind theif receive";
    ch17_3_1(test_str);
    ifstream f("ch-17.3.cc");
    char ch;
    string s;
    while (f.get(ch)) {
        s += ch;
    }
    ch17_3_2(s);
}