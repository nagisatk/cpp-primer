#include "ex-13.49-Message.h"

// this source file is auto-formatted

// implementation of class Message
Message::Message(const Message &m) : contents(m.contents), folders(m.folders)
{
    cout << "call Message::Message(const Message& m)" << endl;
    add_to_Folders(m);
}

Message &Message::operator=(const Message &rhs)
{
    cout << "call Message::operator=(const Message &rhs)" << endl;
    // delete the pointer and insert it to resolve the self-assign
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

Message::Message(Message &&m) : contents(std::move(m.contents))
{
    move_Folders(m);
}

Message &operator=(Message &&rhs)
{
    if (this != &rhs)
    {
        remove_from_Folders();
        contents = std::move(rhs.contents);
        move_Folders(&rhs);
    }
    return *this;
}

Message::~Message()
{
    remove_from_Folders();
}

void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &m)
{
    // auto *f : m.folders is also okay.
    for (auto f : m.folders)
        f->addMsg(this);
}

void Message::remove_from_Folders()
{
    for (auto f : folders)
        f->remMsg(this);
}

void Message::show()
{
    cout << contents << " in folders:";
    for (auto f : folders)
        cout << " " << f->name;
    cout << endl;
}

void Message::move_Folders(Message *m)
{
    folders = std::move(m->folders); // 使用set的移动赋值运算符
    for (auto f : folders)
    {                    // 对于每个folder
        f->remMsg(m);    // 从Folder中删除原Message
        f->addMsg(this); // 将本Message加入到Folder中
    }
    m->folders.clear(); // 确保销毁m是无害的
}

// implementation of class Folder
Folder::Folder(const Folder &rhs) : name(rhs.name), messages(rhs.messages)
{
    add_to_Message(rhs);
}

Folder &Folder::operator=(const Folder &rhs)
{
    remove_from_Message();
    messages = rhs.messages;
    name = rhs.name;
    add_to_Message(rhs);
    return *this;
}

void Folder::add_to_Message(const Folder &f)
{
    for (auto m : f.messages)
        m->addFldr(this);
}

void Folder::remove_from_Message()
{
    for (auto m : messages)
        m->remFldr(this);
}

void Folder::show()
{
    cout << name << " including messages:";
    for (auto m : messages)
        cout << " " << m->contents;
    cout << endl;
}

Folder::~Folder()
{
    remove_from_Message();
}

// classes are over
// tool function(s)

void swap(Message &lhs, Message &rhs)
{
    using std::swap;
    for (auto f : lhs.folders)
        f->remMsg(&lhs);
    for (auto f : rhs.folders)
        f->remMsg(&rhs);
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    for (auto f : lhs.folders)
        f->addMsg(&lhs);
    for (auto f : rhs.folders)
        f->remMsg(&rhs);
}

int main()
{
    return 0;
}