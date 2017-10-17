#include "../commheader.h"

class CheckStrLen {
public:
    static vector<size_t> rvec;
    CheckStrLen(size_t t): len(t) { }
    bool operator()(const string &s) {
        if(s.size() == len)
            ++rvec[s.size()];
        return false;
    }
private:
    size_t len;
};

vector<size_t> CheckStrLen::rvec = vector<size_t>(11, 0);

#include<fstream>
#include<algorithm>
using std::ifstream;

int main() {
    ifstream ifs("i.txt");
    string word;
    vector<string> vec;
    while(ifs >> word) {
        vec.push_back(word);
    }
    for(auto s : vec) {
        cout << s << endl;
    }
    vector<size_t> uiv(11, 0);
    for(int i = 1; i <= 10; ++i) {
        CheckStrLen csl(i);
        std::for_each(vec.begin(), vec.end(), csl);
    }
    for(auto a : CheckStrLen::rvec) {
        cout << a << endl;
    }
}