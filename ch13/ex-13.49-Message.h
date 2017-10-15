#include "../commheader.h"

#ifndef _CP5_EX_13_49_Message__
#define _CP5_EX_13_49_Message__

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
    Message(Message&&);
    Message& operator=(Message&&);
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

    void move_Folders(Message *m);
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

#endif