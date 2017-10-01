#include "../commheader.h"

#include<algorithm>
using std::accumulate;

// Exercise 10.3
void accumulate_int() {
    vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int sum = accumulate(vec.begin(), vec.end(), 0);
    cout << "sum: " << sum << endl; // 55
}

// Exercise 10.4
void accumulate_dbl() {
    vector<double> vec = { 1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1, 10.1 };
    double sum = accumulate(vec.begin(), vec.end(), 0);
    cout << "sum with 0: " << sum << endl;  // 55
    double sum2 = accumulate(vec.begin(), vec.end(), 0.0);
    cout << "sum with 0.0: " << sum2 << endl; // 56
}

// Exercise 10.9
void elimDups(vector<string> &words) {
    for(string &word : words)
        cout << word << " ";
    cout << endl;
    std::sort(words.begin(), words.end());
    for(string &word : words)
        cout << word << " ";
    cout << endl;
    auto end_unique = std::unique(words.begin(), words.end());
    for(string &word : words)
        cout << word << " ";
    cout << endl;
    words.erase(end_unique, words.end());
    for(string &word : words)
        cout << word << " ";
    cout << endl;
}

int main () {
    // accumulate_int();
    // accumulate_dbl();
    vector<string> words = { "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };
    elimDups(words);
}