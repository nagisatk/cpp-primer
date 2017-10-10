#include "../commheader.h"

// Exercise 11.31
// #include<multimap>
using std::multimap;

multimap<string, string> authors = {
        { "Toriyama Akira", "Dragon Ball" },
        { "Toriyama Akira", "Dr. Slump" },
        { "Arakawa Hiromu", "Silver Spoon" },
        { "Arakawa Hiromu", "Fullmetal Alchemist" },
        { "Arakawa Hiromu", "Jūshin Enbu" },
        { "Suzuki Nakaba", "Seven Deadly Sins" }
    };
void erase_authors() {
    // auto work = "Dr. Slump";
    auto work = "Dr. slump";
    auto found = authors.find("Toriyama Akira");
    auto count = authors.count("Toriyama Akira");
    while(count--) {
        if(found->second == work) {
            authors.erase(found);
            break;
        }
        ++found;
    }
    for (auto& iter : authors)
        cout << iter.first << " : " << iter.second << endl;
}

// Exercise 11.32
void print_alphally() {
    map<string, vector<string>> oredered_authors;
    for(const auto& author : authors)
        oredered_authors[author.first].push_back(author.second);
    for(const auto& author : oredered_authors) {
        cout << author.first << " : [  ";
        for(auto& work : author.second)
            cout << work << "  ";
        cout << "]" << endl;
    }
}

int main() {
    // erase_authors();
    print_alphally();
}