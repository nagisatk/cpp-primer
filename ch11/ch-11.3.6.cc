#include "../commheader.h"

const string &transform(const string &s, const map<string, string> &m) {
    const auto map_it = m.find(s);
    if(map_it != m.end())
        return map_it->second;
    return s;
}

#include<fstream>
#include<sstream>
#include<exception>
using std::ifstream;
using std::istringstream;
using std::runtime_error;
map<string, string> buildMap(ifstream &map_file) {
    map<string, string> trans_map;
    string key;
    string value;
    while(map_file >> key && getline(map_file, value))
        if(value.size() > 1)
            // trans_map[key] = value.substr(1);
            trans_map.insert({key, value.substr(1)});
        else
            throw runtime_error("no rule for " + key);
    return trans_map;
}

void word_transform(ifstream &map_file, ifstream &input) {
    auto trans_map = buildMap(map_file);
    string text;
    while(getline(input, text)) {
        istringstream stream(text);
        string word;
        bool first_word = true;
        while(stream >> word) {
            if(first_word)
                first_word = false;
            else
                cout << " ";
            cout << transform(word, trans_map);
        }
        cout << endl;
    }
}

int main() {
    ifstream trans_map("trans_map.txt");
    ifstream input("input.wtxt");
    if(trans_map && input)
        word_transform(trans_map, input);
    else
        throw runtime_error("invalid input file.");
}