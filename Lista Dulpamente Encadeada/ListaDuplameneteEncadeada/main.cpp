#include "tadduplamenteencadeada.h"
#include "tadpoker.h"

int main()
{
    TListaDE<TipoCarta> dealer, jogador1, jogador2, mesa;
    inicializa (dealer);
    inicializa(jogador1);
    inicializa(jogador2);
    inicializa (mesa);
    monta_baralho(dealer);
    embaralhar(dealer);
    distribuir(dealer, jogador1, 2);
    imprime(jogador1.inicio);
    distribuir(dealer, jogador2, 2);
    imprime(jogador2.inicio);
    distribuir(dealer, mesa, 5);
    imprime(mesa.inicio);
    cout << "Depois do Bubblesort" << endl;
    bubblesort(jogador1);
    imprime(jogador1.inicio);
    cout << "Depois do Quicksort" << endl;
    quicksort(jogador2,0, tamanho(jogador2)-1);
    imprime(jogador2.inicio);
    cout << "worked" << endl;
    return 0;
}
