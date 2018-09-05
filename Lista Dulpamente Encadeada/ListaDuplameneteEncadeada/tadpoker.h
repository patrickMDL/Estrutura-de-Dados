#ifndef TADPOKER_H
#define TADPOKER_H
#include <iostream>
using namespace std;
#include <iostream>
using namespace std;
#include "tadduplamenteencadeada.h"
#include <time.h>
#include <stdlib.h>

struct TipoCarta{
    int valor;
    int naipe;//naipe em int, na hora de imprimir eu converto pra string;
};

template <typename TIPO>
void monta_baralho(TListaDE<TIPO> &lista){
    TipoCarta carta;
    for(int i=0; i<4; i++){//Naipe
        for (int j=1; j<14; j++){//Valor da carta
            carta.naipe=i;
            carta.valor=j;
            Insere_fim(lista, carta);
        }
    }
}

template <typename TIPO>
void distribuir (TListaDE<TIPO> &dealer, TListaDE<TIPO> &jogador, int quantidade){
    for (int i=0; i<quantidade; i++){
        insere_fim(jogador, dealer);
        remove_inicio(dealer);
    }
}

template <typename TIPO>
void embaralha (TListaDE<TIPO> &lista){
    srand(time(NULL));
    TElementoDE<TIPO> *aux1=lista.inicio;
    TElementoDE<TIPO> *aux2=aux1->proximo;
    TElementoDE<TIPO> *aux3=new TElementoDE<TIPO>;
    int aux=rand()%52;
    while (aux1->proximo!=NULL){
        for (int i=0; i<aux; i++){
            aux2=aux2->proximo;
        }
        aux3=aux1;
        aux1=aux2;
        aux2=aux3;
    }


}

template <typename TIPO>
void imprime(TElementoDE<TIPO> *lista){
    TElementoDE<TIPO> *nav=lista;
    while(nav->proximo!=NULL){
        string simbolo;
        int valor=nav->dado.valor;
        switch(nav->dado.naipe){
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
        nav=nav->proximo;
    }
    cout << "_________________________________________________________" << endl;
}




#endif // TADPOKER_H
