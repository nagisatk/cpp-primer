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

int main() {
    vector<string> words = { "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };
    // elimDups(words);
    // resort_str(words);
    // lambda_sum();
    biggies2(words, 5);
}