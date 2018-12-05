#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED
#include <iostream>
#include <string.h>
#include <cstdlib>
#include "pilha.h"
#include <windows.h>

using namespace std;
void gotoxy(int x, int y) //MOVER
{
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y});
}



template <typename TIPO>
struct Pno{
        int chave;
        TIPO dado;
        int altura;
        Pno *esquerda;
        Pno *direita;
};

template <typename TIPO>
struct Parvore{
    Pno<TIPO> *raiz;
};

template <typename TIPO>
void inicializaArvore(Parvore<TIPO> &arvore)
{
    arvore.raiz=NULL;
}

template<typename TIPO>
bool *novo_elemento_arvore(TIPO dado)
{
    Pno<TIPO> *novo=new Pno<TIPO>;
    novo->dado = dado;
    novo->direita = NULL;
    novo->esquerda = NULL;
    return true;
}

float resolve_exp(Pno<string> *no)
{
    if(no!=NULL){


        float a = resolve_exp(no->esquerda);
        float b = resolve_exp(no->direita);
        if(no->dado== "+"){
            cout << a << " + " << b << endl;
            return a+b;
        }else if(no->dado == "-"){
            cout << a << " - " << b << endl;
            return a-b;
        }else if(no->dado == "*"){
            cout << a << " * " << b << endl;
            return a*b;
        }else if(no->dado == "/"){
            cout << a << " / " << b << endl;
            return a/b;
        }else{
            string x = no->dado;
            float y = atof(x.c_str());///transforma string em double
            return y;
        }

    }
    return 0;
}


int gety() //to get y-coordinate
{ CONSOLE_SCREEN_BUFFER_INFO csbi;
    int y;
    if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
     {   y = csbi.dwCursorPosition.Y;
     }
     return y;
}


void plottree(Pno<string> *arvore,int h,int H,int mid,int Y)  // to plot the tree graphically
{
  if(arvore==NULL)
    return;

    int x=mid,i;
    int y=Y+1+(H*(H+1))/2 - (h*(h+1))/2;
    gotoxy(x,y);
    cout <<arvore->dado;
    if(arvore->direita!=NULL)
    {
        for(i=1;i<=(h-1);i++)
        {
            gotoxy(mid+i,y+i);
            cout << "\\";
        }
        plottree(arvore->direita,h-1,H,mid+(h),Y);
    }
    if(arvore->esquerda!=NULL)
    {
        for(i=1;i<=(h-1);i++)
        {
            gotoxy(mid-i,y+i);
            cout << "/";
        }
        plottree(arvore->esquerda,h-1,H,mid-(h),Y);
    }

}


/*template <typename TIPO>
void imprime(Pno<TIPO> no){
    int i;
     if(no == NULL)
        return;
     imprime(no->dir, altura+1);
     for(i=0;i<nivel;i++)
        printf("      ");
     cout << "\n\n"<< p->chave;
     imprime(p->esq,nivel+1);
}*/


#endif // ARVORE_H_INCLUDED
