#ifndef LISTA_DUPLAMENTE_ENCADEADA_H
#define LISTA_DUPLAMENTE_ENCADEADA_H
#include <windows.h>
#include <iostream>
using namespace std;

template <typename TIPO>
struct TElemento{
    TIPO dado;
    TElemento<TIPO> *proximo;
    TElemento<TIPO> *anterior;
};

template <typename TIPO>
struct TListaDE{
    TElemento<TIPO>*inicio;
    TElemento<TIPO>*fim;
};

template <typename TIPO>
void inicializa_lista_DE(TListaDE<TIPO>&lista){
    lista.inicio=NULL;
    lista.fim=NULL;
}

template<typename TIPO>
TElemento<TIPO>*novo_elemento_lista_DE(TIPO dado){
    TElemento<TIPO>*novo=new TElemento<TIPO>;
    novo->dado=dado;
    novo->proximo=NULL;
    novo->anterior=NULL;
    return novo;
}

template<typename TIPO>
bool insereInicio(TListaDE<TIPO>&lista, TIPO dado){
    TElemento<TIPO>*novo=novo_elemento_lista_DE(dado);
    TElemento<TIPO>*nav=lista.inicio;

    if(lista.inicio==NULL){
        lista.inicio=novo;
        lista.fim=novo;
        return true;
    }else{
        novo->proximo=nav;
        nav->anterior=novo;
        lista.inicio=novo;
        return true;
    }
    return false;
}

template <typename TIPO>
bool insereFinal(TListaDE<TIPO>&lista,TIPO dado){
    TElemento<TIPO> *nav=lista.fim;
    TElemento<TIPO>*novo=novo_elemento_lista_DE(dado);
    if(lista.inicio==NULL){
        lista.inicio=novo;
        lista.fim=novo;
        return true;
    }else{
        nav->proximo=novo;
        novo->anterior=nav;
        lista.fim=novo;
        return true;
    }
    return false;
}

template<typename TIPO>
bool inserePos(TListaDE<TIPO>&lista,TIPO dado, int pos){
    TElemento<TIPO> *nav=lista.inicio;
    TElemento<TIPO> *novo=novo_elemento_lista_DE(dado);
    int i = 0;
    if(pos == 0){
        novo->proximo=nav;
        nav->anterior=novo;
        lista.inicio=novo;
        return true;
    }else if(lista.inicio==NULL){
        lista.inicio=novo;
        lista.fim=novo;
        return true;
    }
    while(i<pos-1 && nav!=NULL){
        nav=nav->proximo;
        i++;
    }
    if(nav==NULL){
        lista.fim->proximo=novo;
        novo->anterior=lista.fim;
        novo->proximo=NULL;
        lista.fim=novo;
        return true;
    }
    if(nav->proximo == NULL)
        lista.fim = novo;
    novo->proximo=nav->proximo;
    nav->proximo=novo;
    novo->anterior=nav;
    novo->proximo->anterior = novo;
    return true;


}

template<typename TIPO>
bool removeFim(TListaDE<TIPO>&lista){
    if(lista.inicio==NULL){
        return false;
    }
    /*cout << lista.fim->dado << endl;
    cout << lista.fim->anterior->dado << endl;
    system("PAUSE");*/
    TElemento<TIPO>*antigo=lista.fim;
    lista.fim=antigo->anterior;
    lista.fim->proximo=NULL;
    delete antigo;
    return true;
}


template <typename TIPO>
bool removeInicio(TListaDE<TIPO> &lista){
    if(lista.inicio==NULL){
        return false;
    }else{
    TElemento<TIPO>*nav=lista.inicio;
    TElemento<TIPO>*nav1=nav->proximo;
    nav1->anterior=NULL;
    lista.inicio=nav1;
    delete nav;
    return true;
    }
}

template<typename TIPO>
void imprime_lista(TListaDE<TIPO>lista){
    TElemento<TIPO> *nav1=lista.inicio;
    while(nav1!=NULL){
        cout<< nav1->dado<<endl;
        nav1=nav1->proximo;
    }
}

template<typename TIPO>
bool removePosicao(TListaDE<TIPO> &lista,int pos){
    TElemento<TIPO> *nav=lista.inicio;
    int i=0;
    while(i<pos && nav!=NULL)
    {
        nav=nav->proximo;
        i++;
    }
    if(nav->anterior != NULL) {
        nav->anterior->proximo = nav->proximo;
    } else {
        lista.inicio=nav->proximo;
    }
    if(nav->proximo != NULL) {
        nav->proximo->anterior=nav->anterior;
    } else {
        lista.fim=nav->anterior;
    }
    delete nav;
    return true;

}

template <typename TIPO>
void bubblesort(TListaDE<TIPO>&lista){
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
template <typename TIPO>
int obterTamanho(TListaDE<TIPO>&lista) {
    TElemento<TIPO> *nav = lista.inicio;
    int tam = 0;
    while(nav->proximo!=NULL) {
        nav=nav->proximo;
        tam++;
    }
    return tam+1;
}
// retorna a posicao do elemento na lista
template <typename TIPO>
int obterElementoPosicao(TListaDE<TIPO>&lista, TElemento<TIPO> *elem) {
    TElemento<TIPO> *nav = lista.inicio;
    int pos = 0;
    while(nav != elem) {
        nav=nav->proximo;
        pos++;
    }
    return pos;
}

// retorna o elemento correspondente a posicao informada
template <typename TIPO>
TElemento<TIPO>* obterElementoPorPosicao(TListaDE<TIPO>&lista, int pos) {
    TElemento<TIPO> *nav = lista.inicio;
    int cont = 0;
    while(nav->proximo != NULL && cont != pos) {
        nav = nav->proximo;
        cont++;
    }
    return nav;
}


template <typename TIPO>
void quicksort(TListaDE<TIPO>&lista, int inicio, int fim)
{
    int metade = (inicio + fim)  / 2;
    TElemento<TIPO> *esq = obterElementoPorPosicao(lista, inicio);
    TElemento<TIPO> *pivo = obterElementoPorPosicao(lista, metade);
    TElemento<TIPO> *dir = obterElementoPorPosicao(lista, fim);
    cout << inicio << " - " << fim << endl << endl;
    while(esq != pivo) { //direita para qnd prox da direita é esquerda dps inverte eles
        while(pivo->dado > esq->dado && obterElementoPosicao(lista, esq) < fim)
        {
            esq = esq->proximo;
        }
        while (dir->dado > pivo->dado && obterElementoPosicao(lista, dir) > inicio) { // modificar pra direita ir pra esquerda
            dir = dir->anterior;
        }
        if(esq != pivo) {
            //cout << dir->dado << " TROCANDO " << esq->dado << endl;
            swap(dir->dado, esq->dado);
        }
    }
    if(obterElementoPosicao(lista, dir) > inicio && inicio < metade - 1)
        quicksort(lista, inicio, metade);
    if(obterElementoPosicao(lista, esq) < fim && fim > metade + 1)//-1 pra inicio e fim nao serem iguais
        quicksort(lista, metade, fim);
}
#endif // LISTA_DUPLAMENTE_ENCADEADA_H
