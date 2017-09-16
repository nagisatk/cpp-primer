#include<vector>
#include<iostream>
#include<cctype>
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main() {
    // Iterator
    string cap = "capital";
    if(cap.begin() != cap.end()) {
        auto iter = cap.begin();
        *iter = toupper(*iter);
    }
    cout << cap << endl;
    string allupper = "all upper";
    for(auto it = allupper.begin(); it != allupper.end(); it++)
        *it = toupper(*it);
    cout << allupper << endl;
    return 0;
}
