#include "Person.h"

int main() {
    Person p;
    p.address = "11th Ave. Chika";
    p.name = "Nagisa";
    cout << p.livein() << endl
         << p.call() << endl;
}