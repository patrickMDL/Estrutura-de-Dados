#ifndef TADFILA_H
#define TADFILA_H
#include <iostream>
using namespace std;

template <typename TIPO>
struct TElemento{
    TIPO dado;
    TElemento<TIPO> *proximo;
};

template <typename TIPO>
struct TFila{
    TElemento<TIPO> *inicio;
    int qtd; //Controlar o número de pessoas na fila;
};

template <typename TIPO>
void inicializa(TFila<TIPO> &fila){
    fila.inicio=NULL;
    fila.qtd=0;    //Inicializa a fila vazia;
}

template<typename TIPO>
TElemento<TIPO>*novo_elemento_fila(TIPO dado){
    TElemento<TIPO>*novo=new TElemento<TIPO>;
    novo->dado=dado;
    novo->proximo=NULL;
    return novo;
}

template <typename TIPO>
bool insere_fim (TFila<TIPO> &fila, TIPO dado){
    TElemento<TIPO> *novo = novo_elemento_fila(dado);
    if (fila.inicio==NULL)
        fila.inicio=novo;
    else{
        TElemento<TIPO> *nav = fila.inicio;
        while (nav->proximo!=NULL)
            nav=nav->proximo;
        nav->proximo=novo;
    }
    fila.qtd++;
}

template <typename TIPO>
TIPO remove_inicio (TFila<TIPO> &fila){
    if (fila.inicio!=NULL){
        TElemento<TIPO> *deletar = fila.inicio;
        TIPO dado = deletar->dado;
        if (deletar->proximo ==NULL){
            fila.inicio=NULL;
            fila.qtd--;
            delete deletar;
            return dado;
        }
        else{
            fila.inicio=deletar->proximo;
            fila.qtd--;
            delete deletar;
            return dado;
        }
    }
}

#endif // TADFILA_H
