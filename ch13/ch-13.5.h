#include "../commheader.h"

#ifndef _CP5_EX_13_5__
#define _CP5_EX_13_5__

#include<memory>
#include<utility>
using std::allocator;
using std::pair;

// 类vector类内存分配策略的简化实现
using std::initializer_list;
class StrVec {
public:
    StrVec():   // allocator成员执行默认初始化
        elements(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec(const StrVec&);              // 拷贝构造函数
    StrVec &operator=(const StrVec&);   // 拷贝赋值运算符
    ~StrVec();                          // 析构函数
    // Exercise 13.40
    // declaration
    StrVec(initializer_list<string>);
    void push_back(const string&);      // 拷贝元素
    size_t size() const { return first_free - elements; }   // 返回当前真正使用的元素的数目
    size_t capacity() const { return cap - elements; }      // 返回StrVec可以保存的元素的数目
    string *begin() const { return elements; }
    string *end() const { return first_free; }
    // Exercise 13.39
    // declaration
    void reserve(size_t);
    void resize(size_t);
    void resize(size_t, const string&);
private:
    static allocator<string> alloc;     // 分配元素
    // 被添加元素的函数所使用
    void chk_n_alloc() {
        if(size() == capacity())
            reallocate();
    }
    // 工具函数，被拷贝构造函数、赋值运算符和析构函数所使用
    pair<string*, string*> alloc_n_copy(const string*, const string*);
    void free();        // 销毁元素并释放内存
    void reallocate();  // 获得更多内存并拷贝已有元素
    string *elements;   // 指向数组首元素的指针
    string *first_free; // 指向数组第一个空闲元素的指针
    string *cap;        // 指向数组尾后位置的指针

};

// implementation of StrVec

allocator<string> StrVec::alloc;

// Exercise 13.40
StrVec::StrVec(initializer_list<string> lst) {
    auto data = alloc_n_copy(lst.begin(), lst.end());
    elements = data.first;
    first_free = cap = data.second;
}

void StrVec::push_back(const string &s) {
    chk_n_alloc();  // 确保有空间容纳新元素
    // 在first_free指向的内存中构造s的副本
    alloc.construct(first_free++, s);
}

// Exercise 13.39
// implementation
void StrVec::reserve(size_t n) {
    while(n > capacity())
        reallocate();
}

void StrVec::resize(size_t n) {
    resize(n, "");
}

void StrVec::resize(size_t n, const string &s) {
    while(elements + n > cap)
        reallocate();
    while(size() != n)
        push_back(s);
}
// Exercise 13.39 over

using std::uninitialized_copy;

pair<string*, string*>
StrVec::alloc_n_copy(const string *b, const string *e) {
    // 分配空间保存给定范围内的元素
    auto data = alloc.allocate(e - b);
    // 初始化并返回一个pair，该pair由data和uninitialized_copy的返回值构成
    return { data, uninitialized_copy(b, e, data) };
}

#include<algorithm>
void StrVec::free() {
    // 不能传递给deallocate一个空指针，如果elements为0，那就什么都不做
    if(elements) {
        // 逆序销毁旧元素
        // for(auto p = first_free; p != elements; )
        //     alloc.destroy(--p);
        std::for_each(elements, first_free, [this](string &s){ alloc.destroy(&s); });
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec &s) {
    // 调用alloc_n_copy分配空间以容纳与s中同样多的元素
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec() {
    free();
}

StrVec &StrVec::operator=(const StrVec &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::reallocate() {
    // 分配当前大小两倍的内存空间
    auto newcapacity = size() ? 2 * size() : 1;
    // 分配新内存
    auto newdata = alloc.allocate(newcapacity);
    // 将数据从旧内存移动到新内存
    auto dest = newdata;    // 指向新数组中的下一个空闲位置
    auto elem = elements;   // 指向旧数组中的下一个元素
    for(size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free(); // 一旦我们移动完元素就释放旧的内存空间
    // 更新我们的数据结构，执行新元素
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

#endif