#include "../commheader.h"

string numbers = "0123456789";
string alphas = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
// Exercise 9.47
void find_numbers_and_alphas1(const string &s) {
    cout << "find numbers: " << endl;
    string::size_type ix = 0;
    while((ix = s.find_first_of(numbers, ix)) != string::npos) {
        cout << "found numbers at index: " << ix
             << " element is " << s[ix] << endl;
        ++ix;
    }
    cout << "find alphas: " << endl;
    ix = 0;
    while((ix = s.find_first_of(alphas, ix)) != string::npos) {
        cout << "found numbers at index: " << ix
             << " element is " << s[ix] << endl;
        ++ix;
    }
}


void find_numbers_and_alphas2(const string &s) {
    cout << "find numbers: " << endl;
    string::size_type ix = 0;
    while((ix = s.find_first_not_of(alphas, ix)) != string::npos) {
        cout << "found numbers at index: " << ix
             << " element is " << s[ix] << endl;
        ++ix;
    }
    cout << "find alphas: " << endl;
    ix = 0;
    while((ix = s.find_first_not_of(numbers, ix)) != string::npos) {
        cout << "found numbers at index: " << ix
             << " element is " << s[ix] << endl;
        ++ix;
    }
}

// Exercise 9.49
#include<fstream>
using std::ifstream;
string ascender = "bdfhklt";
string descender = "gjpqy";
void find_max_no_scender(const string &name) {
    ifstream ifs(name);
    string word;
    string max_word;
    string::size_type max = 0;
    while(ifs >> word) {
        if(word.find_first_of(ascender) == string::npos &&
            word.find_first_of(descender) == string::npos) {
                if(max < word.size()) {
                    max = word.size();
                    max_word = word;
                }
            }
    }
    cout << "the word without ascender or desender which has the max lenght is: '" << max_word
         << "', the length is " << max << "." << endl;
}

int main() {
    string s("ab2c3d7R4E6");
    find_numbers_and_alphas1(s);
    find_numbers_and_alphas2(s);
    find_max_no_scender("./ch09/words.txt");    // Exercise
}