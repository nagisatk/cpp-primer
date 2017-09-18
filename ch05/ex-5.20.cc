#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    string input1, input2;
    while(cin >> input1) {
        if(input2 == input1)
            break;
        else
            input2 = input1;
    }
    if(input1 == input2)
        cout << input1 << endl;
    else
        cout << "No repeated words." << endl;
}