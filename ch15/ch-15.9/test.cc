#include<cassert>
#include "strblob.h"

// test StrBlob and StrBlobPtr
void test_strblob() {
    StrBlob sb1();
    StrBlob sb2({ "Hello", "World", "Okay" });
    auto beg = sb2.begin();
    assert(eq(beg.incr().incr().incr(), sb2.end()));
    assert(!neq(sb2.begin(), sb2.end().decr().decr().decr()));
}

#include "textquery.h"
using std::cout;
// test TextQuery and QueryResult
void test_text() {
    ifstream fin("a.txt");
    TextQuery tq(fin);
    auto qr = tq.query("is");
    print(cout, qr);
}

#include "querys.h"

void test_querys() {
    ifstream fin("a.txt");
    TextQuery tq(fin);
    Query q1("is");
    Query q2("web");
    Query q3("purpose");
    Query q4("domain");
    print(
        print(
            print(
                print(cout, q1.eval(tq)),
                q2.eval(tq)),
            q3.eval(tq)), 
        q4.eval(tq)
    );
    Query q5 = ~q1;
    Query q6 = q2 & q3;
    Query q7 = q3 | q4;
    print(
        print(
            print(cout, q5.eval(tq)),
        q6.eval(tq)),
    q7.eval(tq));
}

int main() {
    // test_strblob();
    // test_text();
    test_querys();
}