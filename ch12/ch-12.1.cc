#include "../commheader.h"
#include<memory>
using std::initializer_list;
using std::shared_ptr;
using std::make_shared;
using std::out_of_range;

// Chapter 12.1.1
class StrBlobPtr;
class StrBlob {
    // Chapter 12.1.6
    friend class StrBlobPtr;
public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    // add or remove element
    void push_back(const string &s) { data->push_back(s); }
    void pop_back();
    // access element
    string& front();
    string& back();
    const string& front() const;
    const string& back() const;
    StrBlobPtr begin();
    StrBlobPtr end();
private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};

StrBlob::StrBlob(): data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il): data(make_shared<vector<string>>(il)) {}

void StrBlob::check(size_type i, const string &msg) const {
    if(i >= data->size())
        throw out_of_range(msg);
}

void StrBlob::pop_back() {
    check(0, "pop_back() on empty StrBlob.");
    data->pop_back();
}


string& StrBlob::front() {
    cout << "non-const front();" << endl;
    check(0, "front() on empty StrBlob.");
    return data->front();
}

string& StrBlob::back() {
    cout << "non-const back();" << endl;
    check(0, "back() on empty StrBlob.");
    return data->back();
}

const string& StrBlob::front() const {
    cout << "const front();" << endl;
    check(0, "front() on empty StrBlob.");
    return data->front();
}

const string& StrBlob::back() const {
    cout << "const back();" << endl;
    check(0, "back() on empty StrBlob.");
    return data->back();
}


// Chapter 12.1.16
using std::weak_ptr;
class StrBlobPtr {
public:
    StrBlobPtr(): curr(0) { }
    StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) { }
    string& deref() const;
    StrBlobPtr& incr();

    // for iteration
    // but this definition has a problem.
    // even if two StrBlobPtrs pointered to different StrBlobs
    // with the curr of the same value can be considered as 'equal'
    bool operator!=(const StrBlobPtr& p) { return p.curr != curr; }
private:
    shared_ptr<vector<string>> check(size_t , const string&) const;
    weak_ptr<vector<string>> wptr;
    size_t curr;
};

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string& msg) const {
    auto ret = wptr.lock();
    if(!ret)
        throw std::runtime_error("unbound StrBlobPtr!");
    if(i >= ret->size())
        throw out_of_range(msg);
    return ret;
}


string& StrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end.");
    return (*p)[curr];
}


StrBlobPtr& StrBlobPtr::incr() {
    check(curr, "increment past end of StrBlobPtr.");
    ++curr;
    return *this;
}


StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() {
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

// Exercise 12.20
#include<fstream>
using std::ifstream;
void read_to_blob(const string& name) {
    ifstream ifs(name);
    string line;
    StrBlob sb;
    while(getline(ifs, line)) {
        sb.push_back(line);
        cout << line << endl;
    }
    StrBlobPtr beg(sb.begin());
    StrBlobPtr end(sb.end());
    while(beg != end) {
        cout << beg.deref() << endl;
        beg.incr();
    }
}

int main() {
    // non const StrBlob
    StrBlob sb;
    sb.push_back("about");
    string &msg = sb.front();
    // const StrBlob
    const StrBlob sb2 = { "non-about" };
    const string &mge = sb2.front();
    // Badly Error.
    // sb2.pop_back();
    read_to_blob("i.txt");
}