#include "../commheader.h"
#include <tuple>
#include <map>
using std::tuple;
using std::get;
using std::tuple_size;
using std::pair;

int main() {
    // Exercise 17.1
    tuple<int, int, int> three_ints(10, 20, 30);
    cout << get<0>(three_ints) << endl;
    cout << get<1>(three_ints) << endl;
    cout << get<2>(three_ints) << endl;
    // Exercise 17.2
    tuple<string, vector<string>, pair<string, int>> ttuple("string", vector<string>{ "vector", "string" }, pair<string, int>("pair", 1));
}
