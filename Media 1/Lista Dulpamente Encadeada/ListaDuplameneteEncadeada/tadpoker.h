#ifndef TADPOKER_H
#define TADPOKER_H
#include <iostream>
using namespace std;
#include "tadduplamenteencadeada.h"
#include <time.h>
#include <stdlib.h>
int const TAM = 52;

struct TipoCarta{
    int valor;
    int naipe;//naipe em int, na hora de imprimir eu converto pra string;
};

template <typename TIPO>
void monta_baralho(TListaDE<TIPO> &lista){
    TipoCarta carta;
    for(int i=0; i<7; i+=2){//Naipe
        for (int j=1; j<14; j++){//Valor da carta
            carta.naipe=i;
            carta.valor=j;
            insereFinal(lista, carta);
        }
    }
}

template <typename TIPO>
void distribuir (TListaDE<TIPO> &dealer, TListaDE<TIPO> &jogador, int quantidade){
    for (int i=0; i<quantidade; i++){
        TElementoDE<TIPO> *aux=dealer.inicio;
        TipoCarta carta = (aux->dado);
        insereFinal(jogador, carta);
        removeInicio(dealer);
    }
}

template <typename TIPO>
void embaralhar(TListaDE<TIPO> baralho){
    TElementoDE<TIPO> *aux = baralho.inicio;
    TIPO aux2;
    srand(time(NULL));
    for (int i=0; i<TAM; i++){
        aux2=aux->dado;
        int r = rand()%51 + 1;
        inserePos(baralho,r,aux2);
        removeInicio(baralho);
        aux=baralho.inicio;
    }
}

template <typename TIPO>
void imprime(TElementoDE<TIPO> *lista){
    TElementoDE<TIPO> *nav=lista;
    while(nav!=NULL){
        string simbolo;
        int valor=nav->dado.valor;
        switch(nav->dado.naipe){
        case 0:
            simbolo="Espadas";
            break;
        case 2:
            simbolo="Copas";
            break;
        case 4:
            simbolo="Ouros";
            break;
        case 6:
            simbolo="Paus";
            break;
        }
        cout << "Naipe: " << simbolo << endl;
        cout << "Valor: " << valor << endl;
        nav=nav->proximo;
    }
    cout << "_________________________________________________________" << endl;
}

bool operator < (TipoCarta um, TipoCarta dois){ return um.valor < dois.valor;}
bool operator > (TipoCarta um, TipoCarta dois){ return um.valor > dois.valor;}
bool operator >= (TipoCarta um, TipoCarta dois){ return um.valor >= dois.valor;}
bool operator <= (TipoCarta um, TipoCarta dois){ return um.valor <= dois.valor;}


#endif // TADPOKER_H
