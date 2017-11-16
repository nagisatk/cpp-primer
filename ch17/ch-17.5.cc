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

// Ch 17.5.3
#include <fstream>
using std::fstream;
void ch17_5_3() {
    fstream inOut("copyOut", fstream::ate | fstream::in | fstream::out);
    if (!inOut) {
        std::cerr << "Unable to open file." << endl;
        return;
    }
    auto end_mark = inOut.tellg();
    inOut.seekg(0, fstream::beg);
    size_t cnt = 0;
    string line;
    while (inOut && inOut.tellg() != end_mark && getline(inOut, line)) {
        cout << line << endl;
        cnt += line.size() + 1;
        auto mark = inOut.tellg();
        inOut.seekp(0, fstream::end);
        if (mark != end_mark) inOut << " ";
        inOut.seekg(mark, fstream::beg);
    }
    inOut.seekg(0, fstream::end);
    inOut << "\n";
}

int main() {
    ch17_5_1();
    ch17_5_3();
}