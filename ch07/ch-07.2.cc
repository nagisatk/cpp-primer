#include "../commheader.h"

class Sales_data;
Sales_data add(const Sales_data&, const Sales_data&);
ostream &print(ostream&, const Sales_data&);
istream &read(istream&, Sales_data&);

class Sales_data {
friend Sales_data add(const Sales_data&, const Sales_data&);
friend ostream &print(ostream&, const Sales_data&);
friend istream &read(istream&, Sales_data&);
public:
    Sales_data() = default;
    Sales_data(const string &s): bookNo(s) { }
    Sales_data(const string &s, unsigned n, double p):
        bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(istream &in) {
        read(in, *this);
    }
    string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
private:
    double avg_price() const {
        return units_sold ? revenue/units_sold : 0;
    }
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0;
};

Sales_data& Sales_data::combine(const Sales_data& rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}
ostream &print(ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
    return os;
}


istream &read(istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

int main() {
    Sales_data item1("X123-456-789");
    Sales_data item2("X987-654-321", 10, 3.14);
    Sales_data item3(cin);
    print(print(print(cout, item1) << endl, item2) << endl, item3) << endl;
}