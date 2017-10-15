#ifndef _CP5_CH_13_6_H__
#define _CP5_CH_13_6_H__

#include "../commheader.h"
#include<memory>
#include<utility>
using std::allocator;
using std::pair;
using std::uninitialized_copy;
#include<algorithm>
// Exercise 13.44
class String {
public:
    String() { String(""); };
    String(const char *);
    String(const String&);
    String &operator=(const String&);
    ~String() { free(); }
    size_t size() const { return end - s; }
    size_t length() const { return end - s - 1; }
    const char *c_str() const { return s; }
    void range_init(const char*, const char*);
private:
    static allocator<char> alloc;
    void free();
    pair<char*, char*> alloc_n_copy(const char*, const char*);
    char *s;
    char *end;
};

allocator<char> String::alloc;
String::String(const char *s) {
    char *ss = const_cast<char*>(s);
    while(*ss)
        ++ss;
    range_init(s, ++ss);
}

String::String(const String &rhs) {
    range_init(rhs.s, rhs.end);
    cout << "copy-constructor" << endl;
}
String &String::operator=(const String &rhs) {
    auto ns = alloc_n_copy(rhs.s, rhs.end);
    free();
    s = ns.first;
    end = ns.second;
    cout << "copy-assignment" << endl;
    return *this;
}

void String::range_init(const char *b, const char *e) {
    auto data = alloc_n_copy(b, e);
    s = data.first;
    end = data.second;
}

pair<char*, char*>
String::alloc_n_copy(const char *b, const char *e) {
    auto data = alloc.allocate(e - b);
    return { data, uninitialized_copy(b, e, data) };
}

void String::free() {
    if(s) {
        std::for_each(s, end, [this](char &c) { alloc.destroy(&c); });
        alloc.deallocate(s, end - s);
    }
}

#endif