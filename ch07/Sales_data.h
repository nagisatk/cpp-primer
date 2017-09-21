#include "../commheader.h"

struct Sales_data;

Sales_data add(const Sales_data&, const Sales_data&);
ostream &print(ostream&, const Sales_data&);
istream &read(istream&, Sales_data&);

struct Sales_data {
    /*
     * 默认情况下，this的类型是指向类类型非常量版本的常量指针。例如在Sales_data成员函数中，
     * this的类型是Sales_data *const。尽管this是隐式的，但它仍然需要遵循初始化规则，意味着
     * （在默认情况下）我们不能把this绑定到一个常量对象上（参见2.4.2节，第56页）。这一情况
     * 也就使得我们不能在一个常量对象上调用普通的成员函数。 -- C++ Primer p.231 (cn.ed)
     */
    /**
    * 默认情况下，this指针不能指向其他的对象，但可以改变指向对象（当前类实例）的值。是一个
    * `top-level const`指针。
    */
    Sales_data() = default;
    Sales_data(const string &s): bookNo(s) { }
    Sales_data(const string &s, unsigned n, double p):
        bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(istream &in) {
        read(in, *this);
    }
    string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};


double Sales_data::avg_price() const {
    if(units_sold)
        return revenue/units_sold;
    else
        return 0;
}

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