#include <iostream>
using namespace std;

#include "tadlistaencadeada.h"
#include "tadhash.h"

int main()
{
    int const m=10;

//    Tabela hash com lista encadeada;
    Hash *tabela[m];
    inicializa_hash(tabela, m);
    TLista<string> lista1;
    inicializa_listaE(lista1);
    insere_hash()




//    Tabela Hash normal;
//    Hash tabela[m];
//    inicializa_hash(tabela, m);
//    insere_hash(tabela, m, 115);
//    insere_hash(tabela, m, 57);
//    insere_hash(tabela, m, 5);
//    insere_hash(tabela, m, 15);
//    insere_hash(tabela, m, 23);
//    insere_hash(tabela, m, 25);
//    insere_hash(tabela, m, 29);
//    insere_hash(tabela, m, 27);
//    imprimi_hash(tabela, m);
//    cout << "-----------------------------------" << endl;
//    remove_hash(tabela, m,115);
//    imprimi_hash(tabela, m);

    return 0;
}
