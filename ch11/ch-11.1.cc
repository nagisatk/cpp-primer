#include "../commheader.h"

int main() {
    // use map
    map<string, size_t> words_count;
    string word;
    while(cin >> word)
        ++words_count[word];
    for(const auto &w : words_count)
        cout << w.first << " occurs " << w.second
             << ((w.second > 1) ? " times" : "time") << endl;
    // use set
    map<string, size_t> words_count2;
    set<string> exclude = {
        "The", "But", "And", "Or", "An", "A",
        "the", "but", "and", "or", "an", "a"
    };
    while(cin >> word)
        if(exclude.find(word) == exclude.end())
            ++words_count2[word];
    for(const auto &w : words_count2)
        cout << w.first << " occurs " << w.second
                << ((w.second > 1) ? " times" : " time") << endl;
}