#ifndef DESIGN_H
#define DESIGN_H
#include <stdio.h>
#include <time.h>
#include <iostream>
using namespace std;
COORD coord={0,0};

void textcolor (int forecolor, int backcolor) {/// COR DE TEXTO
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), (WORD) (forecolor | backcolor<<4));
}

void gotoxy(int x, int y) ///DEFINIR COORDENADAS
{
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){static_cast<SHORT>(x),static_cast<SHORT>(y)});
}


void hide()///ESCONDER O CURSOR
{
    CONSOLE_CURSOR_INFO cursor = {1, FALSE};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

#endif // DESIGN_H
