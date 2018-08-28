#ifndef TADPOKER_H
#define TADPOKER_H
#include <iostream>
using namespace std;
#include <time.h> //time;
#include <stdlib.h> //srand, rand;
#include "tadestatico.h"


struct TipoCarta //Carta
{
    int naipe;
    int valor;
};


template <typename TIPO, int MAX>
void monta_baralho(Tlista<TIPO, MAX> &lista){
    TElemento<TipoCarta> carta;
    for(int i=0; i<4; i++){//Naipe
        for (int j=1; j<14; j++){//Valor da carta
            carta.dado.naipe=i;
            carta.dado.naipe=j;
            insere_fim(lista, carta);
        }
    }
}

template <typename TIPO, int MAX>
void embaralha (Tlista<TIPO, MAX> &dealer){

        srand(time(NULL));
        int p;//o 'p' será usado para trocar as posições das cartas e embaralhar o baralho;
        TElemento<TIPO> carta;
        for (int i=0; i<52;i++){
            p=rand()%52;
            carta=dealer.elemento[i];
            dealer.elemento[i]=dealer.elemento[p];
            dealer.elemento[p]=carta;
        }

}

template <typename TIPO, int MAX>
void distribuir (Tlista<TIPO, MAX> &dealer, Tlista<TIPO,MAX> &jogador, int tamanho){//'tamanho' é o tamanho de cartas que o jogador
    for (int i=0; i<tamanho; i++){                             // irá receber;
        insere_fim(jogador, dealer.elemento[0]);
        remove_inicio(dealer);
    }
}

template < int MAX>
void imprime(Tlista<TipoCarta, MAX> lista){
    for (int i=0; i<lista.tamanho; i++){
        string simbolo;
        int valor=lista.elemento[i].dado.valor;
        switch(lista.elemento[i].dado.naipe){
        case 0:
            simbolo="Espadas";
            break;
        case 1:
            simbolo="Copas";
            break;
        case 2:
            simbolo="Ouros";
            break;
        case 3:
            simbolo="Paus";
            break;
        }
        cout << "Naipe: " << simbolo << endl;
        cout << "Valor: " << valor << endl;

    }
    cout << "_________________________________________________________" << endl;
}

bool operator >= (TipoCarta a, TipoCarta b){return a.naipe*10+a.valor<b.naipe*10+b.valor;}
bool operator < (TipoCarta a, TipoCarta b){return a.naipe*10+a.valor<b.naipe*10+b.valor;}


#endif // TADPOKER_H
