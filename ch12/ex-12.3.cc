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

void query_text(ifstream &infile);
int main() {
    // Exercise 12.27
    ifstream ifs("chapter12.txt");
    // runQuery(ifs);
    // Exercise 12.28
    query_text(ifs);
}

vector<string> text;
map<string, set<unsigned>> indexs;
void make_result(ifstream &ifs) {
    string line;
    int i = 0;
    unsigned lineno = 0;
    while(getline(ifs, line)) {
        text.push_back(line);
        istringstream iss(line);
        string word;
        while(iss >> word) {
            while(word[word.size()-1] == '.' || word[word.size()-1] == ',' || word[word.size()-1] == 's')
                word = word.substr(0, word.size() - 1);
            if(isupper(word[0]))
                word[0] = tolower(word[0]);
            indexs[word].insert(lineno);
        }
        ++lineno;
    }
}

ostream& output_result(ostream &os, map<string, set<unsigned>>::iterator res) {
    auto beg = res->second.begin();
    auto end = res->second.end();
    cout << res->first << " occurs " << res->second.size() << " time(s):" << endl;
    while(beg != end) {
        cout << "(line " << *beg + 1 << ") : ";
        cout << text[*(beg++)]
             << endl;
    }
    return os;
}
void query_text(ifstream &ifs) {
    make_result(ifs);
    do {
        cout << "enter word to look for, or q for quit: ";
        string s;
        if(!(cin >> s) || s == "q") break;
        auto res_pair = indexs.find(s);
        if(res_pair != indexs.end())
            output_result(cout, res_pair) << endl;
        else
            cout << s << " doesnot occur in the file." << endl;
    } while(true);
}