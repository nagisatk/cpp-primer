#include "ex-13.49-String.h"


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

String::String(String &&s) noexcept : s(s.s), end(s.end) {
    cout << "rvalue reference, move copy" << endl;
    s.s = s.end = nullptr;
}

String& String::operator=(String &&rhs) noexcept {
    if(this != &rhs) {
        free();
        s = rhs.s;
        end = rhs.end;
        rhs.s = rhs.end = nullptr;
    }
    cout << "move copy operator" << endl;
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

int main() {
    // Exercise 13.50
    vector<String> vec;
    vec.push_back(String("Hello"));
    String s1 = "Yoho~";
    vec.push_back(std::move(s1));
    return 0;
}