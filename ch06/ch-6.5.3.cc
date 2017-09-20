#include<iostream>
#include<string>

using std::cin;
using std::cerr;
using std::endl;
using std::string;

int main() {
    string word;
    cin >> word;
    int threshold = 10;
    if(word.size() < threshold)
        cerr << "Error: " << __FILE__
             << " : in function " << __func__
             << " at line " << __LINE__ << endl
             << "       Compiled on " << __DATE__
             << " at " << __TIME__ << endl
             << "       Word read was \"" << word
             << "\": Length too short" << endl;
}