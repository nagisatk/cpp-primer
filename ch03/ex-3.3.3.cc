#include<vector>
#include<iostream>
#include<cctype>
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

// Exercise 3.17
void read_and_upper() {
    vector<string> words;
    string word;
    while(cin >> word) {
        // using ref to ensure the char changed is the char in the string
        for(auto& c : word)
            c = toupper(c);
        words.push_back(word);
    }
    for(string s : words)
        cout << s << endl;
}

// Exercise 3.20-1
void read_and_sum() {
    vector<int> vec;
    int v;
    while(cin >> v)
        vec.push_back(v);
    for(decltype(vec.size()) i = 0; i < vec.size() - 1; i++)
        cout << "The sum of " << vec[i] << " and " << vec[i+1]
             << " is " << vec[i] + vec[i+1] << endl;
}

// Exercise 3.20-2
void read_and_sum2() {
    vector<int> vec;
    int v;
    while(cin >> v)
        vec.push_back(v);
    for(decltype(vec.size()) i = 0, j = vec.size() - 1; i <= j; i++, j--)
        cout << "The sum of " << vec[i] << " and " << vec[j]
             << " is " << vec[i] + vec[j] << endl;

}

int main() {
    // read_and_upper();
    // read_and_sum();
    read_and_sum2();
    return 0;
}
