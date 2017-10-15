#include "ch-13.4.h"

void test_message_class() {
    cout << "msg1: ";
    Message msg1("Msg1");
    cout << "msg2: ";
    Message msg2(msg1);
    cout << "msg3: ";
    Message msg3 = msg1;
}

void test_message_folder() {
    Message m1("m1");
    Message m2("m2");
    Message m3("m3");
    Folder f1("f1");
    Folder f2("f2");
    Folder f3("f3");
    vector<Message*> ms = { &m1, &m2, &m3 };
    vector<Folder*> fs = { &f1, &f2, &f3 };
    m1.save(f1);
    m2.save(f2);
    m3.save(f1);
    m3.save(f2);
    m3.save(f3);
    for(auto m : ms)
        m->show();
    for(auto f : fs)
        f->show();
    m3.remove(f1);
    m3.show();
    for(auto f : fs)
        f->show();
}

int main() {
    // test_message_class();
    test_message_folder();
}