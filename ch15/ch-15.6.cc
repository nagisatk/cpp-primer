#include "../commheader.h"

struct Base {
    Base(): mem(0) { }
    virtual int fcn() {
        cout << "Base::fcn();" << endl;
        return 0;
    }
protected:
    int mem;
};

struct Derived : Base {
    Derived(int i): mem(i) { }      // 用i初始化Derived::mem
                                    // Base::mem执行默认初始化
    int get_mem() { return mem; }   // 返回Derived::mem
    // 作用域运算符将覆盖掉原有的查找规则，并指示编译器从Base类的作用域开始查找mem。
    /**
     * Best Practice:
     * 除了覆盖继承而来的虚函数之外，派生类最好不要重用其他定义在基类中的名字。
     */
    int get_base_mem() { return Base::mem; }
protected:
    int mem;
};

struct D1 : public Base {
    // 隐藏基类的fcn，这个fcn不是虚函数
    // D1继承了Base::fcn()的定义
    int fcn(int i) {                        // 形参列表与Base::fcn不一致
        cout << "D1::fcn(int);" << endl;
        return 0;
    }
    virtual void f2() {                     // 是一个新的虚函数，在Base中不存在
        cout << "D1::f2();" << endl;
    }
};

struct D2 : public D1 {
    // 是一个非虚函数，隐藏了D1::fcn(int)
    int fcn(int i) {
        cout << "D2::fcn(int);" << endl;
        return 0;
    }
    // 覆盖了Base中的虚函数fcn
    int fcn() {
        cout << "D2::fcn();" << endl;
        return 0;
    }
    // 覆盖了D1的虚函数f2
    void f2() {
        cout << "D2::f2();" << endl;
    }
};


int main() {
    Derived d(42);
    cout << d.get_mem() << endl;    // 42
    cout << d.get_base_mem() << endl; // 0

    /**
     * 通过基类调用隐藏的虚函数
     */
    Base bobj; D1 d1obj; D2 d2obj;
    /**
     * 动态绑定会在对象的实际作用域中查找fcn
     * D1没有覆盖掉Base::fcn()，所以也会调用Base::fcn()
     */
    Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
    bp1->fcn();     // 虚调用，将在运行时调用Base::fcn();
    bp2->fcn();     // 虚调用，将在运行时调用Base::fcn();
    bp3->fcn();     // 虚调用，将在运行时调用D2::fcn();

    /**
     * 由于fcn(int)不是虚函数所以不会发生动态绑定
     */
    Base *p1 = &d2obj; D1 *p2 = &d2obj; D2 *p3 = &d2obj;
    // p1->fcn(42);     // no matching function for call to 'Base::fcn(int)
    p2->fcn(42);        // 静态绑定，调用D1::fcn(int)
    p3->fcn(42);        // 静态绑定，调用D2::fcn(int)
}