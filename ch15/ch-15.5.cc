#include "../commheader.h"

class Base {
public:
    void pub_mem();
protected:
    int prot_mem;
private:
    char priv_mem;
};

class Pub_Derv : public Base {
    // 正确：派生类能访问protected成员
    int f() { return prot_mem; }
    // 错误：private成员对于派生类来说是不可访问的
    // char g() { return priv_mem; }   // member "Base::priv_mem" (declared at line 9) is inaccessible    
};

class Priv_Derv : private Base {
    // private不影响派生类的访问权限
    int f1() { return prot_mem; }
};

int main() {
    Pub_Derv d1;    // 继承自Base的成员是public的
    Priv_Derv d2;   // 继承自Base的成员是private的
    d1.pub_mem();   // 正确：pub_mem在派生类中的是public的
    // function "Base::pub_mem" (declared at line 5) is inaccessible
    // d2.pub_mem();   // 错误：pub_mem在派生类中是private的
}