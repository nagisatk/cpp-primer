#include "../commheader.h"
#include <regex>
using std::regex;
using std::regex_match;
using std::regex_search;
using std::smatch;

int main() {
    string pattern("[^c]ei");
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    regex r(pattern);
    string test_str = "receipt freind theif receive";
    smatch results;
    if (regex_search(test_str, results, r))
        cout << results.str() << endl;
}