#include "../commheader.h"

class Quote {
public:
    Quote() = default;
    Quote(const string &book, double sales_price): bookNo(book), price(sales_price) { }
    string isbn() const { return bookNo; }
    // 返回给定数量的书籍的销售总额
    // 派生类负责改写并使用不同的折扣计算方法
    virtual double net_price(size_t n) const { return n * price; }
    // Exercise 15.11
    virtual void debug() {
        cout << "members: " << endl
             << "bookNo: " << bookNo << endl
             << "price:  " << price << endl;
    }
    virtual ~Quote() = default; // 对析构函数进行动态绑定
private:
    string bookNo;              // 书记的ISBN编号
protected:
    double price = 0.0;         // 代表普通状态下不打折的价格
};

double print_total(ostream &os, const Quote &item, size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()   // 调用Quote::isbn()
       << " # sold: " << n << " total due: " << ret << endl;
}

// Exercise 15.5
class Bulk_quote : public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const string&, double, size_t, double);
    // Exercise 15.11
    void debug() override {
        this->Quote::debug();
        cout << "min quantity: " << min_qty << endl
             << "discount: " << discount << endl;
    }
    // 覆盖基类的函数版本以实现基于大量购买的折扣政策
    double net_price(size_t) const override;
private:
    size_t min_qty = 0;         // 适用折扣政策的最低购买量
    double discount = 0.0;      // 以小数表示的折扣额
};

Bulk_quote::Bulk_quote(const string &bookNo, double price, size_t qty, double disc):
    Quote(bookNo, price), min_qty(qty), discount(disc) { }

double Bulk_quote::net_price(size_t cnt) const {
    if(cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

// Exercise 15.7
class LimitedQuote : public Quote {
public:
    LimitedQuote(const string &book, double price, size_t qty, double disc):
        Quote(book, price), limited_qty(qty), discount(disc) { }
    // Exercise 15.11
    void debug() override {
        Quote::debug();
        cout << "limited quantity: " << limited_qty << endl
                << "discount: " << discount << endl;
    }
    double net_price(size_t cnt) const override;
private:
    size_t limited_qty = 0;
    double discount = 0.0;
};

double LimitedQuote::net_price(size_t cnt) const {
    if(cnt > limited_qty)
        return limited_qty * price * (1 - discount) + (cnt - limited_qty) * price;
    else
        return cnt * price * (1 - discount);
}



int main() {
    Quote q("990-90-0-9", 99.9);
    print_total(cout, q, 14);
    // Exercise 15.6
    Bulk_quote bquote("I009-909-11", 99.9, 12, 0.12);
    print_total(cout, bquote, 14);
    // Exercise 15.7
    LimitedQuote l("00-009-8765", 99.9, 12, 0.12);
    print_total(cout, l, 14);
    // Exercise 15.11
    q.debug();
    bquote.debug();
    l.debug();
}