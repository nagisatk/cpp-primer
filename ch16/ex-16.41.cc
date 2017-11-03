#include "../commheader.h"

template <typename T1, typename T2>
auto sum(T1 t1, T2 t2) -> decltype(t1 + t2) {
    return t1 + t2;
}

int main() {
    auto a1 = sum(1, 1);
    cout << a1 << " " << sizeof(a1) << endl;
    auto a2 = sum(1, 1.1);
    cout << a2 << " " << sizeof(a2) << endl;
    auto a3 = sum(1, 1.1f);
    cout << a3 << " " << sizeof(a3) << endl;
    auto a4 = sum(1, ~0ul);
    cout << a4 << " " << sizeof(a4) << endl;
}