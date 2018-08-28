#include "tadpoker.h"
#include "tadestatico.h"

int main()
{

    Tlista<TipoCarta, 52> dealer;
    Tlista<TipoCarta, 52> jogador1, jogador2;
    Tlista<TipoCarta, 5> mesa;
    inicializa_lista_estatica(dealer);
    inicializa_lista_estatica(jogador1);
    inicializa_lista_estatica(jogador2);
    inicializa_lista_estatica(mesa);
    monta_baralho(dealer);
    embaralha(dealer);
    distribuir(dealer, jogador1, 2);
    distribuir(dealer, jogador2, 2);
    cout << "Jogador 1: " << endl;
    imprime(jogador1);
    cout << "Jogador 2: " << endl;
    imprime(jogador2);
    cout << "Mesa: " << endl;
    imprime(mesa);
    quicksort(mesa, 0, mesa.tamanho-1);
    bubblesort(jogador1, jogador1.tamanho);
    bubblesort(jogador2, jogador2.tamanho);
    cout << "Jogador 1: " << endl;
    imprime(jogador1);
    cout << "Jogador 2: " << endl;
    imprime(jogador2);
    cout << "Mesa: " << endl;
    imprime(mesa);



    return 0;
}

