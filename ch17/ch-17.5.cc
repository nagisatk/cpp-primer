#include "../commheader.h"

#include <cmath>
#include <iomanip>
// Ch 17.5.1
void ch17_5_1() {
    cout << "default bool values: " << true << " " << false << endl
         << "alpha bool values: " << std::boolalpha
         << true << ' ' << false << std::noboolalpha << endl;

    cout << std::showbase << std::uppercase;
    cout << "default: " << 20 << " " << 1024 << endl;
    cout << "octal: " << std::oct << 20 << " " << 1024 << endl;
    cout << "hex: " << std::hex << 20 << " " << 1024 << endl;
    cout << "decimal: " << std::dec << 20 << " " << 1024 << endl
         << std::noshowbase << std::nouppercase;

    cout << "Precision: " << cout.precision()
         << ", Value: " << std::sqrt(2.0) << endl;
    cout.precision(12);
    cout << "Precision: " << cout.precision()
         << ", Value: " << std::sqrt(2.0) << endl
         << std::setprecision(3)
         << "Precision: " << cout.precision()
         << ", Value: " << std::sqrt(2.0) << endl;
}

int main() {
    ch17_5_1();
}