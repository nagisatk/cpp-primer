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

// Ch 17.3.3

bool valid(const smatch &m) {
    if (m[1].matched)
        return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
    else
        return !m[3].matched && m[4].str() == m[6].str();
}

void ch17_3_3() {
    string filename("phone.list");
    ifstream file(filename);
    string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
    regex r(phone);
    smatch m;
    string s;
    while (getline(file, s)) {
        for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it) {
            if (valid(*it)) {
                cout << "valid: " << it->str() << endl;
            } else {
                cout << "not valid: " << it->str() << endl;
            }
        }
    }
}

using std::regex_replace;
using namespace std::regex_constants;
// Ch 17.3.4
void ch17_3_4() {
    string filename("phone.list");
    ifstream file(filename);
    string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
    regex r(phone);
    string fmt1 = "$2.$5.$7";
    string fmt2 = "$2-$5-$7";
    string s;
    while (getline(file, s))
        cout << regex_replace(s, r, fmt1) << endl;
    cout << "format_no_copy:" << endl;
    file.clear();
    file.seekg(0);
    while (getline(file, s))
        cout << regex_replace(s, r, fmt2, format_no_copy) << endl;
}

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

    ch17_3_3();

    ch17_3_4();
}