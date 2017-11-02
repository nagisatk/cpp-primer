#include "../commheader.h"
#include <memory>
#include <stdexcept>

using std::shared_ptr;
using std::make_shared;
using std::initializer_list;
using std::runtime_error;

template <typename T>
class blob {
public:
    typedef T value_type;
    typedef typename vector<T>::size_type size_type;
    // constructor
    blob(): data(make_shared<vector<T>>()) { }
    blob(initializer_list<T> il): data(make_shared<vector<T>>(il)) { }
    template <typename It>
    // Exercise 16.24
    blob(It a, It b): data(make_shared<vector<T>>(a, b)) { }
    // element num of the blob
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    // add or remove element
    void push_back(const T &t) { data->push_back(t); }
    void push_back(T&& t) { data->push_back(std::move(t)); }
    void pop_back();
    // element access
    T& back();
    T& operator[] (size_type i);
private:
    shared_ptr<vector<T> > data;
    void check(size_type i, const string &msg) const;
};

template <typename T>
void blob<T>::check(size_type i, const string &msg) const {
    if (i >= data->size())
        throw runtime_error(msg);
}

template <typename T>
T& blob<T>::back() {
    check(0, "back on empty blob.");
    return data->back();
}

template <typename T>
void blob<T>::pop_back() {
    check(0, "pop_bak on empty blob.");
    data->pop_back();
}

template <typename T>
T& blob<T>::operator[](size_type i) {
    check(i, "subscript out of range.");
    return (*data)[i];
}

int main() {
    blob<int> b1 = { 1, 2, 3, 5 };
    cout << b1.back() << endl;
    // Exercise 16.24
    vector<double> dvec = { 1.1, 2.2, 3.3, 4.4 };
    blob<double> b2(dvec.begin(), dvec.end());
    cout << b2.back() << endl;
}
