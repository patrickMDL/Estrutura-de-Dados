#include <iostream>
using namespace std;
///Minha Biblioteca
#include "tadavl.h"

int main()
{
    TArvore<char> arvore;
    inicializa_arvore(arvore);

    insere_arvore(arvore.raiz, 100, 'm');
    cout << "." << endl;
    insere_arvore(arvore.raiz, 130, 'r');
    cout << "." << endl;
    insere_arvore(arvore.raiz, 150, 'z');
    cout << "." << endl;
    insere_arvore(arvore.raiz, 80, 'f');
    cout << "." << endl;
    insere_arvore(arvore.raiz, 140, 's');
    cout << "." << endl;
    insere_arvore(arvore.raiz, 110, 'p');
    cout << "." << endl;
    insere_arvore(arvore.raiz, 105, 'n');
    cout << "." << endl;
    insere_arvore(arvore.raiz, 108, 'o');
    cout << "." << endl;
    insere_arvore(arvore.raiz, 120, 'q');
    cout << "." << endl;
    insere_arvore(arvore.raiz, 50, 'a');
    cout << "." << endl;
    prefixo(arvore.raiz);

}
