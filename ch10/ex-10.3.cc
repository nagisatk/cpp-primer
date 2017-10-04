#include "../commheader.h"

#include<algorithm>

// Exercise 10.11
bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

void elimDups(vector<string> &words) {
    std::sort(words.begin(), words.end());
    auto end_unique = std::unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
    stable_sort(words.begin(), words.end(), isShorter);
    for(string &word : words)
        cout << word << " ";
    cout << endl;
}

// Exercise 10.13
bool shorterThan5(const string &s) {
    return s.size() < 5;
}

void resort_str(vector<string> &words) {
    auto iter = std::partition(words.begin(), words.end(), shorterThan5);
    while(iter != words.end())
        cout << *iter++ << " ";
    cout << endl;
}

int lambda_sum() {
// Exercise 10.14
    auto f = [](int a, int b) { return a + b; };
    int a = 1, b = 1;
    cout << f(a, b) << endl;    // 2
// Exercise 10.15
    auto g = [a](int b) {return a + b; };
    cout << g(11) << endl; // 12
}

// Exercise 10.16
string make_plural(int count, string word, string suf) {
    return count ? word + suf : word;
}
void biggies(vector<string> &words, vector<string>::size_type sz) {
    elimDups(words);
    auto com = [](const string &s1, const string &s2) -> bool {
        return s1.size() < s2.size();
    };
    std::stable_sort(words.begin(), words.end(), com);
    auto longer = [sz](const string &s) -> bool {
        return s.size() >= sz;
    };
    auto wc = std::find_if(words.begin(), words.end(), longer);
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s")
         << " of length " << sz << " or longer" << endl;
    std::for_each(wc, words.end(), [](const string &s){ cout << s << " "; });
    cout << endl;
}

// Exercise 10.18
void biggies2(vector<string> &words, vector<string>::size_type sz) {
    elimDups(words);
    auto longer = [sz](const string &s) -> bool {
        return s.size() >= sz;
    };
    // auto wc = std::partition(words.begin(), words.end(), longer);
// Exercise 10.19
    auto wc = std::stable_partition(words.begin(), words.end(), longer);
    auto count = wc - words.begin();
    cout << count << " " << make_plural(count, "word", "s")
         << " of length " << sz << " or longer" << endl;
    std::for_each(words.begin(), wc, [](const string &s){ cout << s << " "; });
    cout << endl;
}

// Exercise 10.20
void biggies3(vector<string> &words, vector<string>::size_type sz) {
    elimDups(words);
    auto longer = [sz](const string &s) -> bool {
        return s.size() >= sz;
    };
    auto count = std::count_if(words.begin(), words.end(), longer);
    cout << count << " " << make_plural(count, "word", "s")
         << " of length " << sz << " or longer" << endl;
    std::for_each(words.begin(), words.end(), [sz](const string &s){ cout << (s.size() >= sz ? s + " " : ""); });
    cout << endl;
}

// Exercise 10.21
void exer_10_21() {
    int a = 3;
    auto decrease = [&a]() {
        if (a > 0) {
            --a;
            return false;
        } else 
            return true;
    };
    auto test = [&a, &decrease]() {
        cout << "a is: " << a << ", is it equal to 0: ";
        if(decrease())
            cout << "true";
        else
            cout << "false";
        cout << endl;
    };
    while(a) {
        test();
    }
    test();
}

// Exercise 10.22
#include<functional>
using namespace std::placeholders;
bool check_size(const string &s, string::size_type sz) {
    return s.size() >= sz;
}

void shorties(vector<string> &words, vector<string>::size_type sz) {
    elimDups(words);
    auto com = [](const string &s1, const string &s2) -> bool {
        return s1.size() < s2.size();
    };
    std::stable_sort(words.begin(), words.end(), com);
    auto shorter = bind(check_size, _1, sz);
    auto wc = std::find_if(words.begin(), words.end(), shorter);
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s")
         << " of length which is shorter than " << sz << endl;
    std::for_each(words.begin(), wc, [](const string &s){ cout << s << " "; });
    cout << endl;
}

// Exercise 10.24
int find_size(const string &s, const vector<int> ivec) {
    auto f = bind(check_size, s, _1);
    for(int i : ivec) {
        if(!f(i))
            return i;
    }
    return -1;
}

int main() {
    vector<string> words = { "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };
    // elimDups(words);
    // resort_str(words);
    // lambda_sum();
    // biggies2(words, 5);
    // biggies3(words, 5);
    // exer_10_21();
    // shorties(words, 5);
    const string &s = "hello, world.";
    const vector<int> ivec = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int r = find_size(s, ivec);
    if(r == -1)
        cout << "don't find any int bigger than the size of string: " << s << endl;
    else
        cout << "first int bigger than the size of string: " << s << " is " << r << endl;
}