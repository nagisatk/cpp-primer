#include "../commheader.h"

class Quote {
public:
    Quote() = default;
    Quote(const string &book, double sales_price): bookNo(book), price(sales_price) { }
    string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const { return n * price; }
    virtual void debug() {
        cout << "members: " << endl
             << "bookNo: " << bookNo << endl
             << "price:  " << price << endl;
    }
    virtual ~Quote() = default;
private:
    string bookNo;
protected:
    double price = 0.0;
};

double print_total(ostream &os, const Quote &item, size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
       << " # sold: " << n << " total due: " << ret << endl;
}


class Disc_quote : public Quote {
public:
    Disc_quote(const string &bookNo, double price, size_t qty, double disc):
    Quote(bookNo, price), min_qty(qty), discount(disc) { }
    double net_price(size_t) const = 0;
protected:
    size_t min_qty;
    double discount;
};

class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const string &book, double price, size_t qty, double disc):
        Disc_quote(book, price, qty, disc) { }
    void debug() override {
        this->Quote::debug();
        cout << "min quantity: " << min_qty << endl
             << "discount: " << discount << endl;
    }
    double net_price(size_t) const override;
};

double Bulk_quote::net_price(size_t cnt) const {
    if(cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}


int main() {
    Quote q("990-90-0-9", 99.9);
    print_total(cout, q, 14);
    Bulk_quote b("I009-909-11", 99.9, 12, 0.12);
    print_total(cout, b, 14);
    q.debug();
    b.debug();
    // Disc_quote d("I009-909-11", 99.9, 12, 0.12);
}