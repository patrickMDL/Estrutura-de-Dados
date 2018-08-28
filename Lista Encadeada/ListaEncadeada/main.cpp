#include <iostream>
using namespace std;
#include "tadlistaencadeada.h"
#include "tadpoker.h"

//Falta o bubble e o quicksorbt;
int main()
{
    TLista<TipoCarta> dealer;
    inicializa_listaE (dealer);
    monta_baralho(dealer);
    embaralha(dealer);
    imprime(dealer.inicio);
    cout << "worked" << endl;


    return 0;
}
