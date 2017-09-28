#include "../commheader.h"

#include<list>
using std::list;

int main() {
    vector<string> svec(10);
    // list<char *> cplist = { "123", "234", "345", "456", "567", "678", "789", "890", "901", "012" };
    // svec.assign(cplist.begin(), cplist.end());
    char carray[] = "0987654321";
    char *p = carray;
    list<char *> ll(10, p);
    svec.assign(ll.begin(), ll.end());
}