#ifndef TADLISTAENCADEADA_H
#define TADLISTAENCADEADA_H
#include <iostream>
using namespace std;

template <typename TIPO>
struct TElemento{
    TIPO dado;
    TElemento<TIPO> *proximo;
};

template <typename TIPO>
struct TLista{
  TElemento<TIPO> *inicio;

};

template <typename TIPO>
void inicializa_listaE(TLista<TIPO> &lista){
    lista.inicio=NULL;
}

template<typename TIPO>
TElemento<TIPO>*novo_elemento_lista(TIPO dado){
    TElemento<TIPO>*novo=new TElemento<TIPO>;
    novo->dado=dado;
    novo->proximo=NULL;
    return novo;
}

template<typename TIPO>
void InsereInicio(TLista<TIPO> &lista,TIPO dado){
    TElemento<TIPO>*novo=novo_elemento_lista(dado);
    novo->proximo=lista.inicio;
    lista.inicio=novo;
}

template <typename TIPO>
void Insere_fim(TLista<TIPO> &lista, TIPO dado){
    TElemento<TIPO> *novo=novo_elemento_lista(dado);
    TElemento<TIPO> *nav=lista.inicio;
    if(lista.inicio==NULL){
        novo->proximo=lista.inicio;
        lista.inicio=novo;
    }
    else{
        while(nav->proximo!=NULL){
            nav=nav->proximo;
        }
        nav->proximo=novo;
        novo->proximo=NULL;
    }
}

template <typename TIPO>
void Insere_position(TLista<TIPO> &lista, int position, TIPO dado){
    TElemento<TIPO> *novo=novo_elemento_lista(dado);
    TElemento<TIPO> *nav=lista.inicio;
    if (position==0){
        novo->proximo=lista.inicio;
        lista.inicio=novo;
    }
    else{
        int i=0;
        while ( i<position && nav->proximo!=NULL){
            nav=nav->proximo;
            i++;
        }
        novo->proximo=nav->proximo;
        nav->proximo=novo;
    }
}

template <typename TIPO>
void remove_fim(TLista<TIPO> &lista){
    TElemento<TIPO> *nav=lista.inicio;
    TElemento<TIPO> *aux=nav;
    while(nav->proximo!=NULL){
        aux=nav;
        nav=nav->proximo;

    }
    aux->proximo=NULL;
    delete nav;
}

template <typename TIPO>
void remove_position(TLista<TIPO> &lista, int pos){
    TElemento<TIPO> *nav=lista.inicio;
    int i;
    while(i<pos && nav->proximo!=NULL){
        nav=nav->proximo;
        i++;
    }
    TElemento<TIPO> *deletar=new TElemento<TIPO>;
    deletar=nav;
    nav->proximo=nav->proximo;
    nav=nav->proximo;
    delete deletar;
}

template <typename TIPO>
void remove_incio(TLista<TIPO> &lista){
    TElemento<TIPO> deletar=new TElemento<TIPO>;
    deletar=lista.inicio;
    lista.inicio=deletar.proximo;
    delete deletar;
}

template <typename TIPO>
void bubblesort (TLista<TIPO> &lista){
    TElemento<TIPO> *aux=lista.inicio;
    TElemento<TIPO> *aux2=aux->proximo;
    TElemento<TIPO> *aux3= new TElemento<TIPO>;
    while (aux->proximo!=NULL){
        if(aux->dado>aux2->dado){
            aux3=aux;
            aux=aux2;
            aux2=aux3;
        }
        aux2->proximo;
    }
}
#endif // TADLISTAENCADEADA_H
