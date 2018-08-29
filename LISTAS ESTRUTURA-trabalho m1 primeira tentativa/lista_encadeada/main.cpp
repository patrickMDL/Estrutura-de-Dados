#include <iostream>
#include "tad.h"
using namespace std;
#include <windows.h>
#include <ctime>

int main()
{
    srand(time(NULL));
    TLista<TMusica> lista;

    TMusica m1,m2,m3,m4,m5;
    m1.nome = "cocota";
    m1.artista = "diogo";

    m2.nome = "abcdef";
    m2.artista = "jorge e mateus";

    m3.nome = "abd";
    m3.artista = "felipe araujo";

     m4.nome = "ujs";
    m4.artista = "felipe araujo";

     m5.nome = "fbg";
    m5.artista = "felipe araujo";

    Inicializa(lista);
    string dado="musica";
    string dado1="bola";
    string dado2="bolaaaaa";
    string dado3="leoo";
    InsereFim(lista, m1);
    InsereFim(lista, m2);
    InsereFim(lista,m3);
    InsereFim(lista,m4);
    InsereFim(lista,m5);
    imprime_lista(lista);
    cout<<endl<<endl;
    //bubblesort(lista);
    quicksort(lista, 0, obterTamanho(lista));
    cout<<endl<<endl;
    imprime_lista(lista);
    system("pause");
    //bubblesort(lista);
   // removePosicao(lista,1);

    return 0;
}
