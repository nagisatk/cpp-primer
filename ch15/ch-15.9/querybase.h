#ifndef _QUERYBASE_H__
#define _QUERYBASE_H__

#include "textquery.h"

class Query_base {
    friend class Query;
protected:
    typedef TextQuery::line_no line_no;
    virtual ~Query_base() = default;
private:
    virtual QueryResult eval(const TextQuery&) const = 0;
    virtual string rep() const = 0;
};

class Query {
    friend Query operator~(const Query&);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);
public:
    Query(const string&);
    // 接口函数：调用对应的Query_base操作
    QueryResult eval(const TextQuery &t) const {
        return q->eval(t);
    }
    string rep() const {
        return q->rep();
    }
private:
    Query(shared_ptr<Query_base> query): q(query) { }
    shared_ptr<Query_base> q;
};


ostream& operator<<(ostream &os, const Query &query) {
    os << query.rep();
    return os;
}

#endif