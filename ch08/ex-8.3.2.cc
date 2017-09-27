#include "../commheader.h"
#include<fstream>
#include<sstream>

using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::ostringstream;

struct PersonInfo {
    string name;
    vector<string> phones;
};

int main() {
    string info("./ch08/info.txt");
    ifstream in(info);
    string line;
    vector<PersonInfo> persons;
    while(getline(in, line)) {
        PersonInfo info;
        istringstream record(line);
        record >> info.name;
        string phone;
        while(record >> phone)
            info.phones.push_back(phone);
        persons.push_back(info);
    }
    for(const auto& per : persons) {
        cout << per.name;
        for(const auto& p : per.phones)
            cout << " " << p;
        cout << endl;
    }
}