#include "ch-13.6.h"

int main() {
    // copy-constructor * 7
    String s1 = "hello";
    String s2 = s1;
    vector<String> vec;
    vec.push_back(String("Hello"));
    vec.push_back(s1);
    vec.push_back(s2);
}