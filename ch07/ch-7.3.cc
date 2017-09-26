#include "../commheader.h"
#include <vector>
using std::vector;

class Screen;
class Window_mgr;


class Window_mgr {
public:
    using ScreenIndex = vector<Screen>::size_type;
    void clear(ScreenIndex);
private:
    vector<Screen> screens;
};

class Screen {
    friend void Window_mgr::clear(ScreenIndex);
public:
    typedef string::size_type pos;
    Screen() = default;
    Screen(pos h, pos w): Screen(h, w, ' ') { }
    Screen(pos ht, pos wd, char c):
        height(ht), width(wd), contents(ht * wd, c) { }
    char get() const {
        return contents[cursor];
    }
    inline char get(pos, pos) const;
    Screen &move(pos, pos);
    Screen &set(char);
    Screen &set(pos, pos, char);
    Screen &display(ostream &os) {
        cout << "normal edition is called." << endl;
        do_display(os);
        return *this;
    }
    const Screen &display(ostream &os) const {
        cout << "const edition is called." << endl;
        do_display(os);
        return *this;
    }
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
    void do_display(ostream &os) const {
        os << contents;
    }
};

inline
Screen &Screen::move(pos r, pos c) {
    cursor = r * width + c;
    return *this;
}

char Screen::get(pos ht, pos wd) const {
    return contents[ht * width + wd];
}

inline
Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline
Screen &Screen::set(pos r, pos w, char c) {
    contents[r * width + w] = c;
    return *this;
}

void Window_mgr::clear(ScreenIndex i) {
    screens[i].contents = string(screens[i].height * screens[i].width, ' ');
}

class X;
class Y;

class X {
public:
    Y* y;
};

class Y {
    X x;
};

int main() {
    Screen sc1(3, 10, '#');
    sc1.display(cout);
    cout << "|<-" << endl;
    Screen sc2(3, 10);
    sc2.display(cout);
    cout << "|<-" << endl;
    for(int i = 0; i < 3; i++)
        switch(i) {
            case 0: {
                for(int j = 0; j < 10; ++j)
                    sc2.move(i, j).set('*');
            }
            break;
            case 1: {
                for(int j = 0; j < 10; ++j)
                    sc2.move(i, j).set('$');
            }
            break;
            case 2: {
                for(int j = 0; j < 10; ++j)
                    sc2.move(i, j).set('+');
            }
            break;
        }
    sc2.display(cout);
    cout << "|<-" << endl;
    Screen sc3(5, 3);
    const Screen sc4(5, 3);
    sc3.display(cout);
    cout << "|<-" << endl;
    sc4.display(cout);
    cout << "|<-" << endl;
}