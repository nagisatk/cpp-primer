#include "../commheader.h"
#include<fstream>
using std::ifstream;
using std::ofstream;

// Exercise 8.4
void read_lines_from_file(string &filename) {
    ifstream in(filename);
    if(in.is_open()) {
        string line;
        vector<string> lines;
        while(getline(in, line))
            lines.push_back(line);
        for(string line : lines)
            cout << line << endl;
        in.close();
    } else {
        cout << "Open file failed." << endl;
    }
}

// Exercise 8.5
void read_words_from_file(string &filename) {
    ifstream in(filename);
    if(in.is_open()) {
        string w;
        vector<string> words;
        while(in >> w)
            words.push_back(w);
        for(string word : words)
            cout << word << endl;
        in.close();
    } else {
        cout << "Open file failed." << endl;
    }
}

int main() {
    string fname("./ch08/file.txt");
    read_lines_from_file(fname);
    read_words_from_file(fname);
}