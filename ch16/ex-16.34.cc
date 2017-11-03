#include "../commheader.h"

template <typename T>
int compare(const T&, const T&) {
    return 1;
}


int main() {
    // no instance of function template "compare" matches the argument list -- argument types are: (const char [3], const char [2])
    // compare("h1", "o");
}