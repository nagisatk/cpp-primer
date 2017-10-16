#ifndef _CP5_EX_13_49_STRING_H__
#define _CP5_EX_13_49_STRING_H__

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
    String(String&&) noexcept;
    String &operator=(String&&) noexcept;
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

#endif