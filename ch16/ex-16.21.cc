#include "../commheader.h"

// Exercise 16.21
class DebugDelete {
public:
    DebugDelete(ostream &os = std::cerr): os(os) { }
    template <typename T>
    void operator()(T *t) const {
        os << "deleting unique_ptr." << endl;
        delete t;
    }
private:
    ostream &os;
};
#include <memory>

int main() {
    std::unique_ptr<string, DebugDelete> ps(new string("Hello World."), DebugDelete());
    cout << *ps << endl;
}