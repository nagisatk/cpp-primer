#include "../commheader.h"
#include<memory>
using std::initializer_list;
using std::shared_ptr;
using std::make_shared;
using std::out_of_range;

class StrBlob {
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
}