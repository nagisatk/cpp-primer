#include "../commheader.h"

int main() {
    // Exercise 9.11
    vector<int> v1;
    vector<int> v2(10);     // 10 0s
    vector<int> v3(10, 10); // 10 10s
    vector<int> v4{ 10, 20, 30, 40, 50, 60, 70, 80, 90 };
    vector<int> v5(v4);
    vector<int> v6(v5.begin(), v5.end());
    vector<vector<int>> v = {v1, v2, v3, v4, v5, v6};
    for(int i = 0; i < v.size(); ++i) {
        cout << i << ": " << endl;
        for(int t : v[i])
            cout << t << " ";
        cout << endl;
    }
}