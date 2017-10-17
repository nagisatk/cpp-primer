#include "../commheader.h"

// define a class and overload the IO operators
class Book {
    friend ostream &operator<<(ostream&, const Book&);
    friend istream &operator>>(istream&, Book&);
public:
    Book(): name(""), author(""), isbn(""), count(0) { }
    Book(const string &name, const string &author, const string &isbn, const unsigned count):
        name(name), author(author), isbn(isbn), count(count) { }
private:
    string name;
    string author;
    string isbn;
    unsigned count;
};

ostream &operator<<(ostream &os, const Book &b) {
    os << b.name << " " << b.author << " "
       << b.isbn << " " << b.count;
    return os;
}

istream &operator>>(istream &is, Book &b) {
    is >> b.name >> b.author >> b.isbn >> b.count;
    if(!is)
        b = Book();
    return is;
}

int main() {
    Book b("C++ Primer", "Lippman", "978-7-121-15535-2", 19);
    cout << b << endl;
    Book b2;
    cin >> b2;
    cout << b2;
}