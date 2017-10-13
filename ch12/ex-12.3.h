#ifndef _CP5_EX_12_3__
#define _CP5_EX_12_3__

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<memory>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ostream;
using std::istringstream;
using std::string;
using std::vector;
using std::map;
using std::set;
using std::shared_ptr;
using std::make_shared;

class QueryResult;
class TextQuery {
public:
    TextQuery(ifstream& ifs);
    QueryResult query(const string& s);
    shared_ptr<vector<string>> shared_text();
    shared_ptr<set<unsigned int>> shared_lineno(const string&);
private:
    vector<string> text;
    map<string, set<unsigned int>> indexs;
    shared_ptr<vector<string>> tp = make_shared<vector<string>>(text);
};

class QueryResult {
public:
    QueryResult() { }
    QueryResult(shared_ptr<vector<string>> tp, shared_ptr<set<unsigned int>> lp, string s)
        : key_word(s), tp(tp), lp(lp), count(lp->size()) { }
    unsigned int count_lines() {
        return count;
    }
    const string& get_keyword() {
        return key_word;
    }
    const string& get_line(unsigned int index) {
        return (*tp)[index];
    }
    set<unsigned int>::iterator result_begin() {
        return lp->begin();
    }
    set<unsigned int>::iterator result_end() {
        return lp->end();
    }
private:
    string key_word;
    shared_ptr<vector<string>> tp;
    shared_ptr<set<unsigned int>> lp;
    unsigned int count;
};

TextQuery::TextQuery(ifstream& ifs) {
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
    // cout << indexs.size() << endl;
    // cout << text.size() << endl;
}


shared_ptr<vector<string>> TextQuery::shared_text() {
    return make_shared<vector<string>>(text);
}
shared_ptr<set<unsigned int>> TextQuery::shared_lineno(const string& word) {
    return make_shared<set<unsigned int>>(indexs.find(word)->second);
}

QueryResult TextQuery::query(const string& s) {
    return QueryResult(shared_text(), shared_lineno(s), s);
}

ostream& print(ostream& os, QueryResult qr) {
    auto beg = qr.result_begin();
    auto end = qr.result_end();
    cout << qr.get_keyword() << " occurs " << qr.count_lines() << " time(s):" << endl;
    while(beg != end) {
        cout << "(line " << *beg + 1 << ") : "
             << qr.get_line(*beg)
             << endl;
             ++beg;
    }
    return os;
}

#endif