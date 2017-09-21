#include "../commheader.h"

struct Person;
istream &read(istream &in, Person &one);

struct Person {
    Person() { }
    Person(const string &s): name(s) { }
    Person(const string &name, const string &address): name(name), address(address) { }
    Person(istream &in) {
        read(in, *this);
    }
    string name;
    string address;
    string call() const;
    string livein() const;
};


string Person::call() const {
    return name;
}
string Person::livein() const {
    return address;
}

istream &read(istream &in, Person &one) {
    return in >> one.name >> one.address;
}

ostream &print(ostream &out, const Person &one) {
    return out << one.name << " " << one.address;
}
