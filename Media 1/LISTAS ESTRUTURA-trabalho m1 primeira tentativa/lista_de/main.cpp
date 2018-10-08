#include <iostream>
#include "musica.h"
#include "lista_duplamente_encadeada.h"
using namespace std;
#include <windows.h>

int main()
{
    TListaDE<TMusica> lista;
    inicializa_lista_DE(lista);
    TMusica musica1,musica2,musica;
    musica.artista="aaaa";
    musica.nome="ca";
    musica1.artista="aaaaaaa";
    musica1.nome="bab";
    musica2.artista="aaa";
    musica2.nome="abc";

    insereFinal(lista, musica);
    insereFinal(lista, musica1);
    insereFinal(lista,musica2);


    imprime_lista(lista);
    system("pause");
    //bubblesort(lista);
    bubblesort(lista);
    imprime_lista(lista);

    return 0;
}
