#include "../commheader.h"

// Exercise 11.7
map<string, vector<string>> families;

void add_family(const string &last_name, vector<string> &children) {
    families[last_name] = children;
}

void add_child(const string &last_name, const string &childname) {
    families[last_name].push_back(childname);
}

void display_families() {
    for(auto family : families) {
        cout << "The family's name is " << family.first
             << ", all children:";
        for(auto child : family.second)
            cout << " " << child;
        cout << endl;
    }
}

// Exercise 11.12
#include<utility>
using std::pair;
void read_strint() {
    string name;
    int value;
    vector<pair<string, int>> vec;
    while(cin >> name >> value) {
        // vec.push_back({name, value});
        // vec.push_back(pair<string, int>(name, value));
        // vec.push_back(pair<string, int>{name, value});
        vec.push_back(std::make_pair(name, value));
        vec.emplace_back(name, value);  //!!
    }
    for(auto &a : vec)
        cout << a.first << " : " << a.second << endl;
}

int main() {
    // string name = "John";
    // vector<string> sv = { "Joyce", "Anna" };
    // add_family(name, sv);
    // add_child(name, "Nia");
    // vector<string> v2 = { "Johua", "Estelle" };
    // add_family("Bright", v2);
    // display_families();
    read_strint();
}