#include "Sales_data.h"
#include "Person.h"

int main() {
    // exercise 7.11
    Sales_data item1("X123-456-789");
    Sales_data item2("X987-654-321", 10, 3.14);
    Sales_data item3(cin);
    print(print(print(cout, item1) << endl, item2) << endl, item3) << endl;
    // exercise 7.15
    Person p1("1stPerson");
    Person p2("2ndPerson", "Somewhere");
    Person p3(cin);
    print(print(print(cout, p1) << endl, p2) << endl, p3) << endl;
}