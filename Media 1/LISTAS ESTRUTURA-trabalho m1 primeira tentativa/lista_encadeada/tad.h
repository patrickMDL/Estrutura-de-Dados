#ifndef TAD_H
#define TAD_H
#include <iostream>
#include "tadespecifico.h"
using namespace std;

template <typename TIPO>
struct TElemento{
    TIPO dado;
    TElemento<TIPO>*proximo;
};

template <typename TIPO>
struct TLista{
    TElemento<TIPO>*inicio;
};

template <typename TIPO>
void Inicializa(TLista <TIPO> &lista){
    lista.inicio=NULL;
}

template<typename TIPO>
TElemento<TIPO>*novo_elemento_lista(TIPO dado){
    TElemento<TIPO>*novo=new TElemento<TIPO>;
    novo->dado=dado;
    novo->proximo=NULL;
    return novo;
}

template <typename TIPO>
bool InsereFim(TLista <TIPO> &lista,TIPO dado){
    TElemento<TIPO>*nav=lista.inicio;
    TElemento<TIPO>*novo=novo_elemento_lista(dado);
    if(lista.inicio!=NULL){
        while(nav->proximo!=NULL){
            nav=nav->proximo;
        }
            nav->proximo=novo;
            novo->proximo=NULL;
            return true;
    }else{
        novo->proximo=lista.inicio;
        lista.inicio=novo;
        return true;

    }
}

template<typename TIPO>
void InsereInicio(TLista<TIPO>&lista,TIPO dado){
    TElemento<TIPO>*novo=novo_elemento_lista(dado);
    novo->proximo=lista.inicio;
    lista.inicio=novo;
}

template<typename TIPO>
bool InserePosicao(TLista<TIPO>&lista,int pos,TIPO dado){
    if(pos==0){
        TElemento<TIPO>*novo=novo_elemento_lista(dado);
        novo->proximo=lista.inicio;
        lista.inicio=novo;
        return true;
    }else{
        TElemento<TIPO>*nav=lista.inicio;
        int i=0;
        while(i<pos-1 && nav!=NULL){
            nav=nav->proximo;
            i++;
        }
        if(nav!=NULL){
            TElemento<TIPO>*novo=novo_elemento_lista(dado);
            novo->proximo=nav->proximo;
            nav->proximo=novo;
            return true;
        }else{
            return false;
        }
    }
}

template<typename TIPO>
bool RemoveFim(TLista<TIPO>&lista){
    TElemento<TIPO>*nav=lista.inicio;
    if(lista.inicio==NULL)
        return false;
    if(lista.inicio->proximo==NULL)
        lista.inicio=NULL;

    while(nav->proximo->proximo!=NULL){
        nav=nav->proximo;
    }
        nav->proximo=NULL;
        return true;
}
template<typename TIPO>
bool RemoveInicio(TLista<TIPO>&lista){
    if(lista.inicio==NULL)
        return false;
    else{
        TElemento<TIPO>*nav=lista.inicio;
        lista.inicio=lista.inicio->proximo;
        delete nav;
        return true;
    }
}


template<typename TIPO>
bool RemovePosicao(TLista<TIPO>&lista,int pos){
    TElemento<TIPO>*nav=lista.inicio;
    if(pos==0){
        lista.inicio=lista.inicio->proximo;
        delete nav;
        return true;
    }else{
        int i=1;
        while(i<pos && nav!=NULL){
            nav=nav->proximo;
            i++;
        }
        if(nav==NULL)
            return false;
        nav->proximo=nav->proximo->proximo;
        return true;

    }
}

template<typename TIPO>
void imprime_lista(TLista<TIPO>lista){
    TElemento<TIPO> *nav=lista.inicio;
    //TMusica aux;
    while(nav!=NULL){
        //aux = nav->dado;
        //cout<< aux.artista<<endl;
        //cout<< aux.nome<<endl;
        cout << nav->dado << endl;
        nav=nav->proximo;
    }
}

template <typename TIPO>
void bubblesort(TLista<TIPO>&lista){
    TElemento<TIPO> *nav=lista.inicio;
    TElemento<TIPO> *cont=lista.inicio;
    while(cont!=NULL){
        while(nav->proximo!=NULL) {
            TElemento<TIPO> *prox = nav->proximo;
            if(nav->dado > prox->dado) {
                TIPO aux;
                aux=nav->dado;
                nav->dado=prox->dado;
                prox->dado=aux;
            }
            nav=nav->proximo;
        }
        nav = lista.inicio;
        cont=cont->proximo;
    }
}

template <typename Tipo>
int obterTamanho(TLista<Tipo>&lista) {
    TElemento<Tipo> *nav = lista.inicio;
    int tam = 0;
    while(nav->proximo!=NULL) {
        nav=nav->proximo;
        tam++;
    }
    return tam+1;
}
// retorna a posicao do elemento na lista
template <typename Tipo>
int obterElementoPosicao(TLista<Tipo>&lista, TElemento<Tipo> *elem) {
    TElemento<Tipo> *nav = lista.inicio;
    int pos = 0;
    while(nav != elem) {
        nav=nav->proximo;
        pos++;
    }
    return pos;
}

// retorna o elemento correspondente a posicao informada
template <typename Tipo>
TElemento<Tipo>* obterElementoPorPosicao(TLista<Tipo>&lista, int pos) {
    TElemento<Tipo> *nav = lista.inicio;
    int cont = 0;
    while(nav->proximo != NULL && cont != pos) {
        nav = nav->proximo;
        cont++;
    }
    return nav;
}


template <typename Tipo>
void quicksort(TLista<Tipo>&lista, int inicio, int fim)
{
    int metade = (inicio + fim)  / 2;
    TElemento<Tipo> *esq = obterElementoPorPosicao(lista, inicio);
    TElemento<Tipo> *pivo = obterElementoPorPosicao(lista, metade);
    TElemento<Tipo> *dir = obterElementoPorPosicao(lista, metade);
    cout << inicio << " - " << fim << endl;
    while(esq != pivo) {
        while(pivo->dado > esq->dado && obterElementoPosicao(lista, esq) < fim)
        {
            esq = esq->proximo;
        }
        while (dir->dado > pivo->dado && obterElementoPosicao(lista, dir) > inicio && dir->proximo != NULL) {
            dir = dir->proximo;
        }
        if(esq != pivo) {
            cout << dir->dado << " TROCANDO " << esq->dado << endl;
            swap(dir->dado, esq->dado);
        }
    }
    if(obterElementoPosicao(lista, dir) > inicio && inicio < metade - 1)
        quicksort(lista, inicio, metade);
    if(obterElementoPosicao(lista, esq) < fim && metade < fim - 1)//-1 pra inicio e fim nao serem iguais
        quicksort(lista, metade, fim);
}


#endif // TAD_H

