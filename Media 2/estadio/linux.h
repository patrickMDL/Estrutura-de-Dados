#ifndef LINUX_H
#define LINUX_H
#include <iostream>
using namespace std;

#include <ostream>


namespace Color {
    enum Code {
        FG_RED      = 31,
        FG_GREEN    = 32,
        FG_BLUE     = 34,
        FG_DEFAULT  = 39,
        BG_RED      = 41,
        BG_GREEN    = 42,
        BG_BLUE     = 44,
        BG_DEFAULT  = 49
    };
    class Modifier {
        Code code;
    public:
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream&
        operator<<(std::ostream& os, const Modifier& mod) {
            return os << "\033[" << mod.code << "m";
        }
    };
}

void gotoxy(int x,int y)
 {
    printf("%c[%d;%df",0x1B,y,x);
 }

/*inline void gotoxy(int x, int y){
  putp(tparm(cursor_address, y, x));
}*/



#endif // LINUX_H