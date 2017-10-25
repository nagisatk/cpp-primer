#include "../commheader.h"
#include <memory>
using std::shared_ptr;
using std::make_shared;

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
    virtual Quote* clone() const & {
        return new Quote(*this);
    }
    virtual Quote* clone() && {
        return new Quote(std::move(*this));
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
    return ret;
}


class Bulk_quote : public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const string&, double, size_t, double);
    virtual Bulk_quote* clone() const & {
        return new Bulk_quote(*this);
    }
    virtual Bulk_quote* clone() const && {
        return new Bulk_quote(std::move(*this));
    }
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

// Chapter 15.8.1
class Basket {
public:
    // Basket使用合成的默认构造函数和拷贝控制成员
    void add_item(const shared_ptr<Quote> &sale) {
        items.insert(sale);
    }
    void add_item(const Quote &sale) {
        items.insert(shared_ptr<Quote>(sale.clone()));
    }
    void add_item(Quote &&sale) {
        items.insert(shared_ptr<Quote>(std::move(sale).clone()));
    }
    // 打印每本书的总价和购物车中所有书的总价
    double total_receipt(ostream&) const;
private:
    static bool compare(const shared_ptr<Quote> &lhs,
                        const shared_ptr<Quote> &rhs) {
        return lhs->isbn() < rhs->isbn();
    }
    std::multiset<shared_ptr<Quote>, decltype(compare)*> items{compare};
};

double Basket::total_receipt(ostream &os) const {
    double sum = .0;    // 保存实时计算出来的总价格
    // iter指向ISBN相同的一批元素中的第一个
    // upper_bound返回一个迭代器，该迭代器指向这批元素的尾后位置
    for(auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)) {
        // 我们知道在当前的Basket中至少有一个该关键字的元素
        // 打印该书籍对应的项目
        sum += print_total(os, **iter, items.count(*iter));
    }
    os << "Total Sale: " << sum << endl;
    return sum;
}

int main() {
    vector<Quote> vec;
    Bulk_quote b1("0000-000-99", 90, 10, .25);
    Bulk_quote b2("8888-000-88", 80, 20, .30);
    vec.push_back(b1);
    vec.push_back(b2);
    // Exercise 15.28
    double sum1 = 0.0, sum2 = 0.0;
    sum1 += b1.net_price(30);
    sum1 += b2.net_price(30);
    cout << "Real sum is: " << sum1 << endl;    // 3705
    for(auto b : vec) {
        sum2 += b.net_price(30);
    }
    cout << "Invec sum is: " << sum2 << endl;   // 5100
    // Exercise 15.29
    vector<shared_ptr<Quote>> sec;
    sec.push_back(make_shared<Bulk_quote>(b1));
    sec.push_back(make_shared<Bulk_quote>(b2));
    double sum3 = .0;
    for(auto b : sec)
        sum3 += b->net_price(30);
    cout << "Insec sum is: " << sum3 << endl;   // 3705
    // Exercise 15.30
    Basket bsk;
    for(int i = 0; i < 10; ++i) {
        bsk.add_item(b1);
    }
    for(int i = 0; i < 5; ++i) {
        bsk.add_item(b2);
    }
    bsk.total_receipt(cout);
}