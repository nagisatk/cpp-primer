#include "../commheader.h"
#include <bitset>
using std::bitset;

int main() {
    // Exercise 17.10
    vector<int> idx = { 1, 2, 3, 5, 8, 13, 21 };
    bitset<32> bs1;
    for (const auto &i : idx)
        bs1.set(i);
    cout << bs1 << endl;
    // Exercise 17.11
    typedef struct {
        unsigned int idx = 0U;
    } IntAnswer;
    typedef bitset<100> BitAnswer;
    // Exercise 17.12
    IntAnswer ia;
    BitAnswer ba;
    auto modify_answer = [&ia, &ba](unsigned no, bool ans) {
        if (no < 10)        ia.idx |= unsigned(ans) << no;
        if (no < ba.size()) ba.set(no, ans);
    };
    modify_answer(1, true);
    modify_answer(5, true);
    modify_answer(7, true);
    for (int i = 0; i < 10; ++i)
        cout << "Answer to question # " << i + 1 << "\tis: "
             << ((ia.idx >> i) & 1U) << " " << ba[i] << endl;
}