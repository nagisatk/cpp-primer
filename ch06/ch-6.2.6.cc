#include<iostream>
#include<string>


using std::cout;
using std::endl;
using std::string;
using std::initializer_list;

void error_msg(initializer_list<string> lst) {
    for(auto beg = lst.begin(); beg != lst.end(); ++beg)
        cout << *beg << " ";
    cout << endl;
}


int main(int argc, char **argv) {
    string expected = "Expected";
    string actual  = "Actual";
    if(expected != actual)
        error_msg({"FunctionX", expected, actual});
    else
        error_msg({"FunctionX", "okay"});
}