#ifndef TADFILA_H
#define TADFILA_H

template <typename TIPO>
struct TElemento{
    TIPO dado;
    TIPO chave;
    TElemento<TIPO> *proximo;
};

template <typename TIPO>
struct TLista{
  TElemento<TIPO> *inicio;

};

template <typename TIPO>
void inicializa_listaE(TLista<TIPO> &lista){
    lista.inicio=nullptr;
}

template<typename TIPO>
TElemento<TIPO>*novo_elemento_lista(TIPO dado, TIPO chave){
    TElemento<TIPO>*novo=new TElemento<TIPO>;
    novo->dado=dado;
    novo->chave=chave;
    novo->proximo=nullptr;
    return novo;
}

template<typename TIPO>
TElemento<TIPO>*novo_elemento_lista(TIPO dado){
    TElemento<TIPO>*novo=new TElemento<TIPO>;
    novo->dado=dado;
    novo->proximo=nullptr;
    return novo;
}


template<typename TIPO>
void InsereInicio(TLista<TIPO> &lista,TIPO dado){
    TElemento<TIPO>*novo=novo_elemento_lista(dado);
    novo->proximo=lista.inicio;
    lista.inicio=novo;
}

template <typename TIPO>
void Insere_fim(TLista<TIPO> &lista, TIPO dado, TIPO chave){
    TElemento<TIPO> *novo=novo_elemento_lista(dado, chave);
    TElemento<TIPO> *nav=lista.inicio;
    if(lista.inicio==nullptr){
        novo->proximo=lista.inicio;
        lista.inicio=novo;
    }
    else{
        while(nav->proximo!=nullptr){
            nav=nav->proximo;
        }
        nav->proximo=novo;
        novo->proximo=nullptr;
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
        while ( i<position && nav->proximo!=nullptr){
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
    while(nav->proximo!=nullptr){
        aux=nav;
        nav=nav->proximo;

    }
    aux->proximo=nullptr;
    delete nav;
}

template <typename TIPO>
void remove_position(TLista<TIPO> &lista, int pos){
    TElemento<TIPO> *nav=lista.inicio;
    int i;
    while(i<pos && nav->proximo!=nullptr){
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
    TElemento<TIPO> *deletar=lista.inicio;
    lista.inicio=deletar->proximo;
    delete deletar;
}

template <typename TIPO>
void bubblesort (TLista<TIPO> &lista){
    TElemento<TIPO> *nav=lista.inicio;
    TElemento<TIPO> *aux;
    TIPO aux2;
    while (nav!=nullptr){
        aux=nav->proximo;
        while (aux!=nullptr){
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
TElemento<TIPO> *obterElementoPorPosicao(TLista<TIPO> &lista, int pos){
    TElemento<TIPO> *nav = lista.inicio;
    for(int i=0; i<pos;i++){
        nav=nav->proximo;
    }
    return nav;
}

template <typename TIPO>
int tamanho(TLista<TIPO> &lista){
    TElemento<TIPO> *aux=lista.inicio;
    int t=0;
    while(aux->proximo!=nullptr){
        aux=aux->proximo;
        t++;
    }
    return ++t;
}

template <typename TIPO>
void quicksort(TLista<TIPO> &lista, int inicio, int fim){
    int i=inicio, f=fim;
    int metade = (i+f)/2;
    TElemento<TIPO> *pivo;
    pivo=obterElementoPorPosicao(lista,metade);
    while (i!=f){
        TElemento<TIPO> *esq = obterElementoPorPosicao(lista, i);
        TElemento<TIPO> *dir = obterElementoPorPosicao(lista, f);
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

#endif // TADFILA_H
