#ifndef _CP5_EX_12_3__
#define _CP5_EX_12_3__

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ostream;
using std::istringstream;
using std::string;

class QueryResult;
class TextQuery {
public:
    TextQuery(ifstream& ifs): b(0) { }
    QueryResult query(const string& s);
private:
    int b;
};

class QueryResult {
public:
    QueryResult(): a(0) { }
private:
    int a;
};


QueryResult TextQuery::query(const string& s) {
    return QueryResult();
}

ostream& print(ostream& os, QueryResult qr) {
    return os;
}

#endif