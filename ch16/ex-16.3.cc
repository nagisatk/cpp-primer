#include "../commheader.h"
#include <sstream>
using std::ostringstream;
// Exercise 16.48
template <typename T>
string debug_rep(const T &t) {
    ostringstream ret;
    ret << t;
    return ret.str();
}

template <>
string debug_rep(const string &s) {
    cout << "const string&:" << endl;
    ostringstream ret;
    ret << s;
    return ret.str();
}

string debug_rep(char *p) {
    cout << "char *:" << endl;
    return debug_rep(string(p));
}
string debug_rep(const char *p) {
    cout << "char *:" << endl;
    return debug_rep(string(p));
}



template <typename T> std::string debug_rep(T *p)
{
	ostringstream ret;
	ret << "pointer: " << p;
	if (p)
		ret << " " << debug_rep(*p);
	else
		ret << " null pointer";
	return ret.str();
}

string debug_rep(const string &s) {
    return '"' + s + '"';
}

// Exercise 16.49 16.50
template <typename T>
void f(T t) {
    cout << "f(T) is called." << endl;
}
template <typename T>
void f(const T*) {
    cout << "f(const T*) is called." << endl;
}

template <typename T>
void g(T) {
    cout << "g(T) is called." << endl;
}
template <typename T>
void g(T*) {
    cout << "g(T*) is called." << endl;
}


int main() {
    // Exercise 16.48
    string s("hi");
    char a[] = "hello";
    cout << debug_rep(s) << endl;
    cout << debug_rep(&s) << endl;
    cout << debug_rep(a) << endl;
    cout << debug_rep(&a[0]) << endl;
    // Exercise 16.49
    int i = 42, *p = &i;
    const int ci = 0, *p2 = &ci;
    g(42);
    g(p);
    g(ci);
    g(p2);
    f(42);  // f(T)
    f(p);   // f(T)
    f(ci);  // f(T)
    f(p2);  // f(const T*)
}