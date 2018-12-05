#include <string.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>
#include <iostream>

using namespace std;


void textcolor (int forecolor, int backcolor) {/// COR DE TEXTO
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), (WORD) (forecolor | backcolor<<4));
}

void selection (int realPosition, int arrowPosition) ///MENU: Para saber a posicao da opção e a posição da flecha
{
    if (realPosition == arrowPosition)
    {
        textcolor(12,0);//ONDE TEM A FLECHA FICA VERMELHO
        cout <<"       --->   ";
    }
    else
    {
        textcolor(15,0);//ONDE NÃO TEM A FLECHA FICA BRANCO BRILHANTE
        cout <<"       ";
    }
}





void movimenta (int tecla, int *x, int *y) //MOVER A NAVE
{
    switch(tecla)
    {
        case 72: gotoxy(*x,*y-=5); break;     ///cima
        case 80: gotoxy(*x,*y+=5); break;     ///baixo
    }
}
void hide()
{
    CONSOLE_CURSOR_INFO cursor = {1, FALSE};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

