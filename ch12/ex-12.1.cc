#include "../commheader.h"

vector<int>* dynamic_int_vector() {
    return new vector<int>;
}

void read_ints(vector<int> *pv) {
    int a;
    while(cin >> a)
        pv->push_back(a);
}

void print_ints(vector<int> *pv) {
    for(auto i : *pv) {
        cout << i << " ";
    }
    cout << endl;
}

// ------- //

#include<memory>
using std::shared_ptr;
using std::make_shared;

shared_ptr<vector<int>> make_vector_ptr() {
    return make_shared<vector<int>>();
}

void read_to_vector(shared_ptr<vector<int>> sv) {
    int a;
    while(cin >> a)
        sv->push_back(a);
}

void print_vector(shared_ptr<vector<int>> sv) {
    for(auto i : *sv)
        cout << i << " ";
    cout << endl;
}

int main() {
    // Exercise 12.6
    // auto pv = dynamic_int_vector();
    // read_ints(pv);
    // print_ints(pv);
    // delete pv;
    // Exercise 12.7
    auto sv = make_vector_ptr();
    read_to_vector(sv);
    print_vector(sv);
}