#include "tadduplamenteencadeada.h"
#include "tadpoker.h"

int main()
{
    TListaDE<int> dealer;
    TipoCarta carta;

    carta.naipe=2;
    carta.valor=10;

    inicializa(dealer);
    insereInicio(dealer, carta);
    return 0;
}
