#ifndef _QUERYS_H__
#define _QUERYS_H__

#include "querybase.h"

class WordQuery : public Query_base {
    friend class Query;
    WordQuery(const string &s): query_word(s) { }
    // 具体的类：WordQuery将定义所有继承而来的纯虚函数
    QueryResult eval(const TextQuery &t) const {
        return t.query(query_word);
    }
    string rep() const {
        return query_word;
    }
    string query_word;  // 要查找的单词
};

inline
Query::Query(const string &s): q(new WordQuery(s)) { }

class NotQuery : public Query_base {
    friend Query operator~(const Query&);
    NotQuery(const Query &q): query(q) { }
    string rep() const {
        return "~(" + query.rep() + ")";
    }
    QueryResult eval(const TextQuery &t) const;
    Query query;
};

inline
Query operator~(const Query &operand) {
    return shared_ptr<Query_base>(new NotQuery(operand));
}

class BinaryQuery : public Query_base {
protected:
    BinaryQuery(const Query &l, const Query &r, string s):
        lhs(l), rhs(r), opSym(s) { }
    string rep() const {
        return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
    }
    Query lhs, rhs;
    string opSym;
};

class AndQuery : public BinaryQuery {
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query &left, const Query &right):
        BinaryQuery(left, right, "&") { }
    QueryResult eval(const TextQuery &t) const;
};

inline
Query operator&(const Query &lhs, const Query &rhs) {
    return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

class OrQuery : public BinaryQuery {
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query &left, const Query &right):
        BinaryQuery(left, right, "|") { }
    QueryResult eval(const TextQuery &t) const;
};

inline
Query operator|(const Query &lhs, const Query &rhs) {
    return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

// 返回运算对象查询结果set的并集
QueryResult OrQuery::eval(const TextQuery &text) const {
    // 通过Query成员lhs和rhs进行虚调用
    // 调用eval返回每个运算对象的QueryResult
    auto right = rhs.eval(text), left = lhs.eval(text);
    // 将左侧运算对象的行号拷贝到结果set中
    auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
    // 插入右侧运算对象的所得的行号
    ret_lines->insert(right.begin(), right.end());
    // 返回一个新的QueryResult，它表示lhs和rhs的并集
    return QueryResult(rep(), ret_lines, left.get_file());
}

#include<algorithm>
#include<iterator>
QueryResult AndQuery::eval(const TextQuery &text) const {
    // 通过Query运算对象进行的虚调用，以获得运算对象的查询结果set
    auto left = lhs.eval(text), right = rhs.eval(text);
    // 保存left和right交集的set
    auto ret_lines = make_shared<set<line_no>>();
    // 将两个范围的交集写入一个目的迭代器中
    // 本次调用的目的迭代器向ret中添加元素
    std::set_intersection(left.begin(), left.end(), right.begin(), right.end(), std::inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult NotQuery::eval(const TextQuery &text) const {
    // 通过query运算对象对eval进行虚调用
    auto result = query.eval(text);
    // 开始时set为空
    auto ret_lines = make_shared<set<line_no>>();
    // 我们必须在运算对象出现的所有行中进行迭代
    auto beg = result.begin(), end = result.end();
    // 对于输入文件的每一行，如何该行不在result中，则将其添加到ret_lines中
    auto sz = result.get_file().size();
    for (size_t n = 0; n != sz; ++n) {
        // 如果我们没有处理完result的所有行
        // 检查当前行是否存在
        if (beg == end || *beg != n)
            ret_lines->insert(n);   // 如果不在result当中，添加这一行
        else if(beg != end)
            ++beg;                  // 否则继续获取result的下一行，如果有的话
    }
    return QueryResult(rep(), ret_lines, result.get_file());
}

#endif