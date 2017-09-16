#include<vector>
#include<iostream>
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main() {
    // Exercise 3.25
    vector<int> scores = {
        45, 45, 12, 19, 87, 
        91, 100, 4, 56, 66,
        12, 34, 77, 89, 59
    };
    vector<unsigned> grade(11, 0);
    auto beg = grade.begin();
    for(auto it = scores.begin(); it != scores.end(); ++it)
        (*(beg + (*it)/10))++;
    for(int g : grade)
        cout << g << ' ';
    cout << endl;
    return 0;
}
