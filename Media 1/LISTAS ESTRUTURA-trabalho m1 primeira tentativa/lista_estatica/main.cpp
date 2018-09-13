#include <iostream>
using namespace std;
#include <stdlib.h>
#include <ctime>
#include "generico.h"
#include "tad.h"
#include <algorithm>
#define MAX 4
#include <windows.h>


int main()
{
    TElemento<TMusica>elemento;
    TLista<TMusica,4> lista;
    IniciaListaG(lista);

    imprimeLista(lista);

    TMusica m1,m2,m3,m4,m5,m6, m7, m8;
   m1.artista="BMTH";
   m1.nome="Dont Go";
   m2.artista="BMTH";
   m2.nome="Diamonds arent forever";
   m3.artista="Panic at the disco";
   m3.nome="Emperors new clothes";
   m4.artista="Linkin Park";
   m4.nome="In the end";


    InsereFinalG(lista, m1);
    InsereFinalG(lista, m2);
    InsereFinalG(lista, m3);
    InsereFinalG(lista, m4);
    imprimeLista(lista);
    system("pause");

    quicksort(lista,0,lista.quantidade);
   // RemovePosicaoG(2,lista);
    //imprimeLista(lista);



    return 0;
}

