#ifndef TADDUPLAMENTEENCADEADA_H
#define TADDUPLAMENTEENCADEADA_H

#include<iostream>
using namespace std;

template <typename TIPO>
struct TElementoDE{
    TIPO dado;
    TElementoDE<TIPO> *proximo;
    TElementoDE<TIPO> *anterior;
};

template <typename TIPO>
struct TListaDE{
    TElementoDE<TIPO> *inicio;
    TElementoDE<TIPO> *fim;
};

template <typename TIPO>
void inicializa (TListaDE<TIPO> &lista){
    lista.inicio=NULL;
    lista.fim=NULL;
}

template <typename TIPO>
TElementoDE<TIPO> *novo_elemento_lista_DE(TIPO dado){
    TElementoDE<TIPO>*novo=new TElementoDE<TIPO>;
    novo->dado=dado;
    novo->proximo=NULL;
    novo->anterior=NULL;
    return novo;
}



template<typename TIPO>
bool insereInicio(TListaDE<TIPO> &lista, TIPO dado){
    TElementoDE<TIPO>*novo=novo_elemento_lista_DE(dado);
    TElementoDE<TIPO>*nav=lista.inicio;
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
    TElementoDE<TIPO> *nav=lista.fim;
    TElementoDE<TIPO>*novo=novo_elemento_lista_DE(dado);
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
void inserePos(TListaDE<TIPO>&lista,int pos, TIPO dado){
    TElementoDE<TIPO> *novo=novo_elemento_lista_DE(dado);
    TElementoDE<TIPO> *nav=lista.inicio;
    if (pos==0){
        novo->proximo=lista.inicio;
        novo->anterior=NULL;
        lista.inicio=novo;
    }
    else{
        int i=0;
        while ( i<pos && nav->proximo!=NULL){
            nav=nav->proximo;
            i++;
        }
        if (nav->proximo==NULL){
            if((i+1) == pos){
                nav->proximo=novo;
                novo->anterior=nav;
                lista.fim=novo;
            }
            else{
                novo->proximo = nav->proximo;
                novo->anterior=nav;
                nav->proximo=novo;
                nav=novo->proximo;
                nav->anterior = novo;
            }
        }
}
}
template<typename TIPO>
bool removeFim(TListaDE<TIPO>&lista){
    if(lista.inicio!=NULL){
        TElementoDE<TIPO> *nav = lista.fim;
        if(lista.inicio->proximo == NULL){
            delete nav;
            lista.fim=NULL;
            lista.inicio=NULL;
            return true;
        }
        else {
            lista.fim = nav->anterior;
            lista.fim->proximo = NULL;
            delete nav;
            return true;
        }
    }
    return false;
}
template <typename TIPO>
bool removeInicio(TListaDE<TIPO> &lista){
    if(lista.inicio==NULL){
        return false;
    }else{
        TElementoDE<TIPO>*nav=lista.inicio;
        TElementoDE<TIPO>*nav1=nav->proximo;
        nav1->anterior=NULL;
        lista.inicio=nav1;
        delete nav;
        return true;
    }
}

template<typename TIPO>
bool removePosicao(TListaDE<TIPO> &lista,int pos){
    if(lista.inicio!=NULL){
            TElementoDE<TIPO> *nav1 = lista.inicio;
            if(pos==0){
                if(lista.inicio->proximo == NULL){
                    delete nav1;
                    lista.fim = NULL;
                    lista.inicio = NULL;
                    return true;
                }else{
                    lista.inicio = nav1->proximo;
                    lista.inicio->anterior = NULL;
                    delete nav1;
                    return true;
                }
            }else{
                TElementoDE<TIPO> *nav2 = nav1->proximo;
                int i=0;
                while(i!=pos-1 && nav2->proximo!=NULL){
                    nav1 = nav1->proximo;
                    nav2 = nav2->proximo;
                    i++;
                }
                if(nav2->proximo == NULL){
                    if(i == pos-1){
                        lista.fim = nav1;
                        nav1->proximo = NULL;
                        delete nav2;
                        return true;
                    }
                    return false;
                }else{
                    nav1->proximo = nav2->proximo;
                    nav1 = nav2->proximo;
                    nav1->anterior = nav2->anterior;
                    delete nav2;
                    return true;
                }
            }
        }
        return false;
}

template <typename TIPO>
void bubblesort (TListaDE<TIPO> &lista){
    TElementoDE<TIPO> *nav=lista.inicio;
    TElementoDE<TIPO> *aux;
    TIPO aux2;
    while (nav!=NULL){
        aux=nav->proximo;
        while (aux!=NULL){
            if(nav->dado>aux->dado){
                aux2=nav->dado;
                nav->dado=aux->dado;
                aux->dado=aux2;
            }
        aux=aux->proximo;
        }
        nav=nav->proximo;
    }
}

template <typename TIPO>
TElementoDE<TIPO> *obterElementoPorPosicao(TListaDE<TIPO> &lista, int pos){
    TElementoDE<TIPO> *nav = lista.inicio;
    for(int i=0; i<pos;i++){
        nav=nav->proximo;
    }
    return nav;
}

template <typename TIPO>
int tamanho(TListaDE<TIPO> &lista){
    TElementoDE<TIPO> *aux=lista.inicio;
    int t=0;
    while(aux->proximo!=NULL){
        aux=aux->proximo;
        t++;
    }
    return ++t;
}

template <typename TIPO>
void quicksort(TListaDE<TIPO> &lista, int inicio, int fim){
    int i=inicio, f=fim;
    int metade = (i+f)/2;
    TElementoDE<TIPO> *pivo;
    pivo=obterElementoPorPosicao(lista,metade);
    while (i!=f){
        TElementoDE<TIPO> *esq = obterElementoPorPosicao(lista, i);
        TElementoDE<TIPO> *dir = obterElementoPorPosicao(lista, f);
        for (i=0; i<f; ++i){
            esq=obterElementoPorPosicao(lista, i);
            if(esq->dado >= pivo->dado)
                break;
        }
        for (f=fim; f>i; --f){
            dir = obterElementoPorPosicao(lista, f);
            if (dir->dado <= pivo->dado)
                break;
        }
        if (i<f)
            swap(esq->dado, dir->dado);

    }
    i++;
    if(inicio<f)
        quicksort(lista, inicio, f);
    if(i<fim)
        quicksort(lista,i,fim);
}

#endif // TADDUPLAMENTEENCADEADA_H
