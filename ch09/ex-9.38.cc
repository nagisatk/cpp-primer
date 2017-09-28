#include "../commheader.h"

int main() {
    vector<int> ivec;
    cout << "ivec: size: " << ivec.size() << endl
         << "  capacity: " << ivec.capacity() << endl;
    for(int i = 0; i < 24; ++i) {
        ivec.push_back(i);
        cout << "ivec: size: " << ivec.size() << endl
             << "  capacity: " << ivec.capacity() << endl;
    }
    vector<int> ivec2(50);
    cout << "ivec2: size: " << ivec2.size() << endl
         << "   capacity: " << ivec2.capacity() << endl;
    ivec2.push_back(0);
    cout << "ivec2: size: " << ivec2.size() << endl
         << "   capacity: " << ivec2.capacity() << endl;
}