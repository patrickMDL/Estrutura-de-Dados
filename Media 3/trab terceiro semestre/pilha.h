#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

template <typename TIPO>
struct TElemento{
    TIPO dado;
    TElemento<TIPO>*proximo;
};

template <typename TIPO>
struct Tpilha{
    TElemento <TIPO> * topo;
};


template <typename TIPO>
TIPO topo(Tpilha<TIPO> &pilha)
{
    return pilha.topo->dado;
}

template <typename TIPO>
void Inicializa(Tpilha <TIPO> &pilha){
    pilha.topo=NULL;
}

template<typename TIPO>
TElemento<TIPO>*novo_elemento_pilha(TIPO dado){
    TElemento<TIPO>*novo=new TElemento<TIPO>;
    novo->dado=dado;
    novo->proximo=NULL;
    return novo;
}

template<typename TIPO>
bool Inseretopo(Tpilha<TIPO>&pilha,TIPO dado){
    TElemento<TIPO> *novo=novo_elemento_pilha(dado);
    if(pilha.topo==NULL){
        pilha.topo=novo;
        pilha.topo->proximo=NULL;
        return true;
    }
    else{
    novo->proximo=pilha.topo;
    pilha.topo=novo;
    }
    return true;
}

template<typename TIPO>
bool Removetopo(Tpilha<TIPO>&pilha){
    if(pilha.topo==NULL)
        return false;
    else{
        TElemento<TIPO>*nav=pilha.topo;
        pilha.topo=pilha.topo->proximo;
        delete nav;
        return true;
    }
}
template <typename TIPO>
void tamanho (Tpilha<TIPO> pilha){
    int i;
    Tpilha<TIPO> *nav=pilha.topo;
    while (nav->proximo!=NULL){
        nav=nav->proximo;
        i++;
    }
    return i;
}

template <typename TIPO>
void imprime_pilha (Tpilha<TIPO> pilha)
{
    TElemento<TIPO> *nav=pilha.topo;
    int i, z=tamanho;


    while(nav!=NULL){
        for (int j=0; j<z-i; j++)
            cout << "\t.";
        cout << nav->dado << endl;
        i+=1;
        nav=nav->proximo;
    }
}

template <typename TIPO>
int obterTamanho(Tpilha<TIPO> pilha) {
    TElemento<TIPO> *nav=pilha.topo;
    int tam = 0;
    while(nav!=NULL){
        nav=nav->proximo;
        tam++;
    }
    return tam;
}

#endif // PILHA_H_INCLUDED
