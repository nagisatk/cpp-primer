#include "../commheader.h"

#include<algorithm>

// Exercise 10.27
#include<list>
using std::list;
void unique_copy_test() {
    vector<int> vec = { 1, 2, 3, 4, 5, 3, 4, 4 };
    // vector<int> des;
    list<int> des;
    // auto iter = back_inserter(des);     // create a back inserter using push_back()
    auto iter = front_inserter(des);       // create a front inserter using push_front()
    std::sort(vec.begin(), vec.end());
    std::unique_copy(vec.cbegin(), vec.cend(), iter);
    for(auto i : des) {
        cout << i << " ";   // 1 2 3 4 5 or 5 4 3 2 1
    }
}

// Exercise 10.28
#include<deque>
using std::deque;
void copy_three() {
    vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    vector<int> iv;     // no push_front
    list<int> il;
    deque<int> id;
    copy(v.cbegin(), v.cend(), back_inserter(iv));          // 123..
    copy(v.cbegin(), v.cend(), inserter(il, il.begin()));   // 123..
    copy(v.cbegin(), v.cend(), front_inserter(id));         // 987..
}

// Exercise 10.29
#include<iterator>
#include<fstream>
using std::istream_iterator;
using std::ostream_iterator;
using std::ifstream;
void read_strings() {
    ifstream ifs("i.txt");
    istream_iterator<string> iter(ifs), eof;
    vector<string> sv;
    copy(iter, eof, back_inserter(sv));
    // output
    copy(sv.cbegin(), sv.cend(), ostream_iterator<string>(cout, " "));
}

// Exercise 10.30
void read_ints1() {
    istream_iterator<int> iter(cin), eof;
    vector<int> iv;
    while(iter != eof)
        iv.push_back(*iter++);
    sort(iv.begin(), iv.end());
    copy(iv.cbegin(), iv.cend(), ostream_iterator<int>(cout, " "));
}

// Exercise 10.31
void read_ints2() {
    istream_iterator<int> iter(cin), eof;
    vector<int> iv;
    while(iter != eof)
        iv.push_back(*iter++);
    sort(iv.begin(), iv.end());
    unique_copy(iv.cbegin(), iv.cend(), ostream_iterator<int>(cout, " "));
}

// Exercise 10.33
using std::ofstream;
void split_sort_int(const string &infile, const string &oddfile, const string &evenfile) {
    ifstream ifs(infile);
    istream_iterator<int> iter(ifs), eof;
    vector<int> vec;
    while(iter != eof)
        vec.push_back(*iter++);
    ofstream ofs1(oddfile);
    ostream_iterator<int> odd_outer(ofs1, " ");
    ofstream ofs2(evenfile);
    ostream_iterator<int> even_outer(ofs2, "\n");
    for(int i : vec) {
        if(i % 2)
            *odd_outer++ = i;
        else
            *even_outer++ = i;
    }
}

// Exercise 10.34
void reverse_print1(vector<int> vec) {
    auto iter = vec.crbegin();
    while(iter != vec.crend())
        cout << *iter++ << " ";
    cout << endl;
}

// Exercise 10.35
void reverse_print2(vector<int> vec) {
    auto iter = vec.cend();
    while(iter != vec.begin())
        cout << *(--iter) << " ";
    cout << endl;
}
// Exercise 10.36
void find_last_zero(list<int> lst) {
    auto index = find(lst.crbegin(), lst.crend(), 0);
    cout << std::distance(index, lst.crend()) << endl;
}
// Exercise 10.37
void copy_reverse(vector<int> vec) {
    list<int> lst(8 - 3);
    // copy(vec.crend() - 8, vec.crend() - 3, lst.begin());
    copy(vec.cbegin() + 3, vec.cbegin() + 8, lst.rbegin());
    for(auto i : lst)
        cout << i << " ";
    cout << endl;
}

int main() {
    // unique_copy_test();
    // copy_three();
    // read_strings();
    // read_ints2();
    // split_sort_int("all.nums", "odd.nums", "even.nums");
    vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    // reverse_print1(vec);
    // reverse_print2(vec);
    list<int> lst = { 1, 2, 3, 4, 5, 0, 6, 7, 8, 9 };
    // find_last_zero(lst);
    copy_reverse(vec);
}