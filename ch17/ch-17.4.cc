#include "../commheader.h"
#include <random>

using std::default_random_engine;
using std::uniform_int_distribution;
// Ch 17.4.1
void ch17_4_1() {
    default_random_engine e;
    for (int i = 0; i < 10; ++i)
        cout << e() << endl;
    
        uniform_int_distribution<unsigned> u(0, 9);
    for (size_t i = 0; i < 10; ++i)
        cout << u(e) << endl;
    
    cout << "min: " << e.min() << "; max: " << e.max() << endl;

    default_random_engine e1;
    default_random_engine e2(2147483646);
    default_random_engine e3;
    e3.seed(32767);
    default_random_engine e4(32767);
    for (size_t i = 0; i < 10; ++i) {   // no output
        if (e1() == e2())
            cout << "unseeded match at iteration: " << i << endl;
        if (e3() != e4())
            cout << "seeded differs at iteration:  " << i << endl;
    }
}
#define FORLOOPTO(x) for (size_t i = 0; i < (x); ++i)
using std::uniform_real_distribution;
using std::normal_distribution;
using std::lround;
// Ch 17.4.2
void ch17_4_2() {
    default_random_engine e;
    uniform_real_distribution<double> u(0, 1);
    FORLOOPTO(10) {
        cout << u(e) << endl;
    }

    normal_distribution<> n(4, 1.5);
    vector<unsigned> vals(9);
    FORLOOPTO(200) {
        unsigned v = lround(n(e));
        if (v < vals.size()) ++vals[v];
    }
    FORLOOPTO(vals.size()) {
        cout << i << ": " << string(vals[i], '*') << endl;
    }
}

// rough game
using std::bernoulli_distribution;
void rough_game() {
    string resp;
    default_random_engine e;
    bernoulli_distribution b;
    size_t win = 0, lost = 0;
    do {
        bool first = b(e);
        cout << (first ? "We go first" : "You get to go first") << endl;
        bool flag = b(e);
        if (flag) {
            ++lost;
            cout << "sorry, you lost" << endl;
        } else {
            ++win;
            cout << "congrats, you won" << endl;
        }
        cout << "play again? Enter 'yes' or 'no': " << endl;
    } while (cin >> resp && resp[0] == 'y');
    cout << "You lost for " << lost << " time(s)." << endl
         << "You win for "  << win  << " time(s)." << endl;
}


int main() {
    ch17_4_1();

    ch17_4_2();
    rough_game();
}