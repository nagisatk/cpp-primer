#include<vector>
#include<iostream>
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main() {
    // Exercise 3.23
    vector<int> ivec = {
        23, 233, 2333, 23333, 23333,
        54, 544, 5444, 54444, 54444
    };
    for(auto it = ivec.begin(); it != ivec.end(); ++it)
        *it *= 2;
    for(int i : ivec)
        cout << i << ' ';
    cout << endl;
}
