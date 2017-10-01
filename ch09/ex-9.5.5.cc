#include "../commheader.h"

// Exercise 9.50
int sum_int(vector<string> iv) {
    int sum = 0, temp = 0;
    for(string s : iv) {
        sum += stoi(s);
    }
    return sum;
}

double sum_double(vector<string> dv) {
    double sum = 0, temp = 0;
    for(string s : dv) {
        sum += stod(s);
    }
    return sum;
}

class Date {
public:
    Date(string s);
    void output() {
        cout << year << " " << month << " " << date;
    }
private:
    unsigned year = 2001;
    unsigned month = 1;
    unsigned date = 1;
};

string numbers = "0123456789";
string alphas = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
Date::Date(string s) {
    string::size_type pos;
    if(isalpha(s[0])) {
        pos = s.find_first_not_of(alphas);
        auto sub = s.substr(0, pos);
        if(sub == "Jan" || sub == "January")
            month = 1;
        else if(sub == "Feb" || sub == "February")
            month = 2;
        else if(sub == "Mar" || sub == "March")
            month = 3;
        else if(sub == "Apr" || sub == "April")
            month = 4;
        else if(sub == "May")
            month = 5;
        else if(sub == "Jun" || sub == "June")
            month = 6;
        else if(sub == "Jul" || sub == "July")
            month = 7;
        else if(sub == "Aug" || sub == "August")
            month = 8;
        else if(sub == "Sep" || sub == "September")
            month = 9;
        else if(sub == "Oct" || sub == "October")
            month = 10;
        else if(sub == "Nov" || sub == "November")
            month = 11;
        else if(sub == "Dec" || sub == "December")
            month = 12;
    } else if(isdigit(s[0])){
        pos = s.find_first_not_of(numbers);
        month = stoi(s.substr(0, pos));
    }
    auto at = pos + 1;
    pos = s.find_first_not_of(numbers, at);
    date = stoi(s.substr(at, pos));
    year = stoi(s.substr(pos + 1));
    // for test
    output();
    cout << endl;
}


int main() {
    vector<string> sv = { "3", "6", "9", "12", "15", "18" };
    cout << sum_int(sv) << endl;    // 63
    vector<string> dv = { "0.5", "1.0", "1.5", "2.0", "2.5" };
    cout << sum_double(dv) << endl; // 7.5
    Date d1("1/1/1991");        // 1991 1 1
    Date d2("Feb 4, 1993");     // 1993 2 4
    Date d3("March 6 1995");    // 1995 3 6
    Date d4("6-5-2004");        // 2004 6 5

}