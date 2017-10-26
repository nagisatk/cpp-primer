#ifndef _STRBLOB_H__
#define _STRBLOB_H__

#include <vector>
#include <string>
#include <memory>
#include <initializer_list>
#include <stdexcept>

using std::vector;
using std::string;
using std::initializer_list;
using std::make_shared;
using std::shared_ptr;
using std::weak_ptr;

class StrBlobPtr;
class StrBlob {
    friend class StrBlobPtr;
public:
    typedef vector<string>::size_type size_type;
    
    // constructors
    StrBlob(): data(make_shared<vector<string>>()) { }
    StrBlob(initializer_list<string>);
    
    // size operations
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    // add and remove elements
    void push_back(const string &s) { data->push_back(s); }
    void pop_back();

    // elements access
    string& front();
    string& back();

    // interface to StrBlobPtr
    StrBlobPtr begin();
    StrBlobPtr end();
private:
    shared_ptr<vector<string>> data;
    // throw msg if data[i] is not valid
    void check(size_type i, const string &msg) const;
};

// constructor
inline
StrBlob::StrBlob(initializer_list<string> il):
    data(make_shared<vector<string>>(il)) { }

// StrBlobPtr throws an exception on attempts to a nonexistent element
class StrBlobPtr {
    friend bool eq(const StrBlobPtr&, const StrBlobPtr&);
public:
    StrBlobPtr(): curr(0) { }
    StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) { }
    StrBlobPtr(const StrBlob &a, const size_t sz = 0): wptr(a.data), curr(sz) { }
    
    string& deref() const;
    StrBlobPtr& incr();
    StrBlobPtr& decr();
private:
    // check returns a shared_ptr to the vector if the check succeds
    shared_ptr<vector<string>> check(size_t, const string&) const;
    // store a weak_ptr, which means the underlying vector might be destroyed
    weak_ptr<vector<string>> wptr;
    // current position with in the array
    size_t curr;
};

inline
string& StrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end.");
    return (*p)[curr];  // (*p) is the vector which this object points
}

inline
shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const {
    auto ret = wptr.lock(); // is the vector still around?
    if(!ret)
        throw std::runtime_error("unbound StrBlobPtr.");
    if(i >= ret->size())
        throw std::out_of_range(msg);
    return ret; // otherwise, return a shared_ptr to the vector
}

// prefix: return a reference to the incremented object
inline
StrBlobPtr& StrBlobPtr::incr() {
    // if curr already points past the end of container, can't increment it
    check(curr, "increment past end of StrBlobPtr.");
    ++curr;
    return *this;
}

// prefix: return a reference to the decremented object
inline
StrBlobPtr& StrBlobPtr::decr() {
    // if curr is zero, derementing it will yield an invalid subscript
    if(!curr)
        check(-1, "decrement past begin of StrBlobPtr");
    --curr;
    return *this;
}

// begin and end members for StrBob
inline
StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}

inline
StrBlobPtr StrBlob::end() {
    return StrBlobPtr(*this, data->size());
}

// named equality operator for StrBlobPtr
inline
bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if(l == r)
        return (!r || lhs.curr == rhs.curr);
    return false;
}

inline
bool neq(const StrBlobPtr &l, const StrBlobPtr &r) {
    return !eq(l, r);
}
#endif