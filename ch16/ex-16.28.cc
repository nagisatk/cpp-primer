#include "../commheader.h"
#include <functional>

struct Deleter {
    template <typename T>
    void operator() (T *t) const {
        delete t;
    }
};

template <typename T>
class shared_pointer;

template <typename T>
void swap(shared_pointer<T> &lhs, shared_pointer<T> &rhs) {
    using std::swap;
    swap(lhs.refcnt, rhs.refcnt);
    swap(lhs.ptr, rhs.ptr);
    swap(lhs.del, rhs.del);
}

template <typename T>
class shared_pointer {
    // friend void swap(shared_pointer<T> &lhs, shared_pointer<T> &rhs);
public:
    // default constructor
    shared_pointer(): refcnt(new size_t(1)), ptr(nullptr), del(Deleter()) { }
    // explicit constructor
    explicit shared_pointer(T *t): refcnt(new size_t(1)), ptr(t), del(Deleter()) { }
    // copy constructor
    shared_pointer(shared_pointer const &other):
        refcnt(other.refcnt), ptr(other.ptr), del(other.del) {
        ++*refcnt;
    }
    // move constructor
    shared_pointer(shared_pointer &&other) noexcept :
        refcnt(other.refcnt), ptr(other.ptr), del(std::move(other.del)) {
        other.refcnt = nullptr;
        other.ptr = nullptr;
    }
    // copy assignment
    shared_pointer& operator=(shared_pointer const &rhs) noexcept {
        swap(*this, rhs);
        ++*rhs.refcnt;
        decrement_n_destoy();
        ptr = rhs.ptr;
        refcnt = rhs.refcnt;
        del = rhs.del;
        return *this;

    }
    // move assignment
    shared_pointer& operator=(shared_pointer &&rhs) noexcept {
        swap(*this, rhs);
        rhs.decrement_n_destoy();
        return *this;
    }
    // conversion operator to bool
    operator bool() const {
        return ptr ? true : false;
    }
    // dereference
    T& operator*() const {
        return *ptr;
    }
    // arrow
    T* operator->() const {
        return &*ptr;   // ?
    }
    // use count
    size_t use_count() const {
        return *refcnt;
    }
    // get underlying pointer
    T* get() const {
        return ptr;
    }
    // check if this is unique
    bool unique() const {
        return *refcnt == 1;
    }
    // swap
    void swap(shared_pointer &rhs) {
        swap(*this, rhs);
    }
    // free the object if unique
    void reset() {
        decrement_n_destoy();
    }
    // reset with the new raw pointer(裸指针)
    void reset(T *t) {
        if (ptr != t) {
            decrement_n_destoy();
            ptr = t;
            refcnt = new size_t(1);
        }
    }
    // reset with new raw pointer and deleter
    void reset(T *t, const std::function<void(T*)> &del) {
        reset(t);
        del = del;
    }
    // destructor
    ~shared_pointer() {
        decrement_n_destoy();
    }

private:
    size_t *refcnt;
    T      *ptr;
    std::function<void(T*)> del;
    void decrement_n_destoy() {
        if (ptr && --refcnt == 0) {
            del(ptr);
            delete refcnt;
        } else if (!ptr) {
            delete refcnt;
        }
        refcnt = nullptr;
        ptr = nullptr;
    }
};

template <typename T>
class unique_pointer {
public:
    unique_pointer(): pointer(nullptr) { }
    explicit unique_pointer(T *t): pointer(t) { }
    unique_pointer(const unique_pointer &p) = delete;
    unique_pointer& operator=(const unique_pointer &p) = delete;
    ~unique_pointer() {
        if (pointer)
            delete pointer;
    }
    T* release() {
        T *p = pointer;
        pointer = nullptr;
        return p;
    }
    void reset(T *t = nullptr) {
        if(t != pointer)
            delete pointer;
        pointer = t;
    }
    T& operator*() {
        return *pointer;
    }
    T& operator*() const {
        return *pointer;
    }
private:
    T *pointer;
};

int main() {
    shared_pointer<int> i(new int(0));
    unique_pointer<double> d(new double(.0));
}