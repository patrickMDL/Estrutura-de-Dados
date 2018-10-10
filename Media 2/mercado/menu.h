#ifndef MENU_H
#define MENU_H
#include <time.h>
#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
COORD coord={0,0};

void HideCursor()
{
  CONSOLE_CURSOR_INFO cursor = {1, FALSE};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void gotoxy(int x, int y)
{
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){static_cast<SHORT>(x),static_cast<SHORT>(y)});
}

void textcolor (int forecolor, int backcolor) {
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), (WORD) (forecolor | backcolor<<4));
}

#endif // MENU_H
