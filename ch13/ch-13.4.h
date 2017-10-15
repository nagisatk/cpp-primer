#include "../commheader.h"

#ifndef _CP5_EX_13_4__
#define _CP5_EX_13_4__

class Folder;
// declare of class Message
class Message {
    friend class Folder;
    friend void swap(Message&, Message&);
public:
    explicit Message(const string &str = ""): contents(str) {
        cout << "call explicit Message::Message(const string &str = \"\")" << endl;    
    }
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();
    void save(Folder&);
    void remove(Folder&);
    void show();
private:
    string contents;
    set<Folder*> folders;

    void add_to_Folders(const Message&);
    void remove_from_Folders();

    void addFldr(Folder *f) { folders.insert(f); }
    void remFldr(Folder *f) { folders.erase(f); }
};

// declare of class Folder
class Folder {
    friend class Message;
    friend void swap(Message&, Message&);
public:
    explicit Folder(const string &name = ""): name(name) { }
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    ~Folder();
    void show();
private:
    string name;
    set<Message*> messages;

    void add_to_Message(const Folder&);
    void remove_from_Message();

    void addMsg(Message *m) { messages.insert(m); }
    void remMsg(Message *m) { messages.erase(m); }
};

// implementation of class Message
Message::Message(const Message& m):
    contents(m.contents), folders(m.folders)
{
    cout << "call Message::Message(const Message& m)" << endl;
    add_to_Folders(m);
}

Message& Message::operator=(const Message &rhs) {
    cout << "call Message::operator=(const Message &rhs)" << endl;
    // delete the pointer and insert it to resolve the self-assign
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

Message::~Message() {
    remove_from_Folders();
}

void Message::save(Folder &f) {
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f) {
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &m) {
    // auto *f : m.folders is also okay.
    for(auto f : m.folders)
        f->addMsg(this);
}

void Message::remove_from_Folders() {
    for(auto f : folders)
        f->remMsg(this);
}

void Message::show() {
    cout << contents << " in folders:";
    for(auto f : folders)
        cout << " " << f->name;
    cout << endl;
}

// implementation of class Folder
Folder::Folder(const Folder& rhs):
    name(rhs.name), messages(rhs.messages)
{
    add_to_Message(rhs);
}

Folder& Folder::operator=(const Folder& rhs) {
    remove_from_Message();
    messages = rhs.messages;
    name = rhs.name;
    add_to_Message(rhs);
    return *this;
}

void Folder::add_to_Message(const Folder &f) {
    for(auto m : f.messages)
        m->addFldr(this);
}

void Folder::remove_from_Message() {
    for(auto m : messages)
        m->remFldr(this);
}

void Folder::show() {
    cout << name << " including messages:";
    for(auto m : messages)
        cout << " " << m->contents;
    cout << endl;
}

Folder::~Folder() {
    remove_from_Message();
}

// classes are over
// tool function(s)

void swap(Message &lhs, Message &rhs) {
    using std::swap;
    for(auto f : lhs.folders)
        f->remMsg(&lhs);
    for(auto f : rhs.folders)
        f->remMsg(&rhs);
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    for(auto f : lhs.folders)
        f->addMsg(&lhs);
    for(auto f : rhs.folders)
        f->remMsg(&rhs);
}

#endif