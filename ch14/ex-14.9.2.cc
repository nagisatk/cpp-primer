#include "../commheader.h"

struct LongDouble {
    LongDouble(double = 0.0);
    operator double() const;
    operator float() const;
};

void calc(int);
void calc(LongDouble);


int main() {
    LongDouble ldobj;
    /**
     * Exercise 14.50
     * more than one conversion function from "LongDouble" to "int" applies:
     * -- function "LongDouble::operator double() const"
     * -- function "LongDouble::operator float() const"
     */
    // int ex1 = ldobj;
    float ex2 = ldobj;
    double dval;
    /**
     * call void calc(double);
     * 
     */
    calc(dval);
}