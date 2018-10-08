#include <iostream>
using namespace std;
///Minha Biblioteca;
#include "tadarvore.h"
///Arvore Binária pronta.
int main()
{
    TArvore<char> arvore;
    inicializa_arvore(arvore);
    insere_arvore(arvore.raiz, 50, 'a');
    insere_arvore(arvore.raiz, 30, 'b');
    insere_arvore(arvore.raiz, 70, 'c');
    insere_arvore(arvore.raiz, 20, 'd');
    insere_arvore(arvore.raiz, 40, 'e');
    insere_arvore(arvore.raiz, 60, 'f');
    insere_arvore(arvore.raiz, 80, 'g');
    prefixo(arvore.raiz);
    cout <<"\n";
    infixo(arvore.raiz);
    cout <<"\n";
    posfixo(arvore.raiz);
    cout <<"\n";
    procura_remove(arvore.raiz, 50);
    prefixo(arvore.raiz);
    return 0;
}

