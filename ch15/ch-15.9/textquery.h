#ifndef _TEXTQUERY_H__
#define _TEXTQUERY_H__

#include "strblob.h"
#include<map>
#include<set>
#include<string>
#include<memory>
#include<fstream>

using std::map;
using std::set;
using std::ifstream;

class QueryResult;

class TextQuery {
public:
    typedef StrBlob::size_type line_no;
    // constructor
    TextQuery(ifstream &fin);
    // query operation
    QueryResult query(const string&) const;
private:
    // data member
    StrBlob file;
    map<string, shared_ptr<set<line_no>>> word_map;
};

#include<iostream>
using std::ostream;

class QueryResult {
    friend ostream& print(ostream&, const QueryResult&);
public:
    // constructor
    QueryResult(string s, shared_ptr<set<TextQuery::line_no>> sp_l, StrBlob f):
        sought(s), sp_lines(sp_l), file(f) { }
    const StrBlob& get_file() const { return file; }
    set<TextQuery::line_no>::iterator begin() { return sp_lines->begin(); }
    set<TextQuery::line_no>::iterator end()   { return sp_lines->end();   }
private:
    // data members
    string sought;
    shared_ptr<set<TextQuery::line_no>> sp_lines;
    StrBlob file;
};

using std::getline;
#include<sstream>
using std::stringstream;

TextQuery::TextQuery(ifstream &fin):
file(StrBlob()), word_map(map<string, shared_ptr<set<line_no>>>()) {
    string line;
    while (getline(fin, line)) {
        file.push_back(line);
        auto index = file.size() - 1;   // current line number
        stringstream ssline(line);
        string word;
        while(ssline >> word) {
            shared_ptr<set<line_no>> &sp_lines = word_map[word];
            // if null
            if(!sp_lines)
                sp_lines.reset(new set<line_no>());
            sp_lines->insert(index);
        }
    }
}

QueryResult TextQuery::query(const string &sought) const {
    // dynamicaly allocated set used for the word not appear.
    static shared_ptr<set<line_no>> no_data(new set<line_no>);
    // fetch the iterator to the matching element in the map<word, lines>
    // map<string, shared_ptr<set<line_no>>>::const_iterator
    auto iter = word_map.find(sought);
    if (iter == word_map.end())
        return QueryResult(sought, no_data, file);
    else
        return QueryResult(sought, iter->second, file);
}

using std::endl;
ostream& print(ostream& os, const QueryResult &res) {
    os  << res.sought << " occurs " << res.sp_lines->size()
        << " time(s)" << endl;
    // print each line in which the word appears
    for (auto &index : *(res.sp_lines)) {
        os  << "\t(line " << index + 1 << ") ";
        const StrBlobPtr wq(res.file, index);
        os  << wq.deref() << endl;
    }
    return os;
}


#endif