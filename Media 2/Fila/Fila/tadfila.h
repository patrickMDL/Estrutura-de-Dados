#ifndef TADFILA_H
#define TADFILA_H
#include <iostream>
using namespace std;

template <typename TIPO>
struct TItem{
  TIPO dado;
  ///int tempo;  Depois eu implemento com unidade de tempo;
  TItem<TIPO> *proximo;
};

template <typename TIPO>
struct TFila{
  TItem<TIPO> *primeiro;
};

template <typename TIPO>
void inicializa(TFila<TIPO> &fila){
    fila.primeiro=NULL;
}

template<typename TIPO>
TItem<TIPO> *novo_elemento_lista(TIPO dado){
    TItem<TIPO>*novo=new TItem<TIPO>;
    novo->dado=dado;
    novo->proximo=NULL;
    return novo;
}


template <typename TIPO>
bool Queue(TFila<TIPO> &fila, TIPO dado){
    TItem<TIPO> *aux = fila.primeiro;
    TItem<TIPO> *novo= novo_elemento_lista(dado);
    if (aux==NULL){
        fila.primeiro=novo;
    }else{
        while(aux->proximo!=NULL){
            aux=aux->proximo;
        }
        aux->proximo=novo;
    }
    return true;
}

template <typename TIPO>
TIPO DeQueue(TFila<TIPO> &fila){
    if (fila.primeiro==NULL)
        cout << "Fila vazia." << endl;
    else{
        TItem<TIPO> *deletar = fila.primeiro;
        TIPO dado = deletar->dado;
        fila.primeiro=deletar->proximo;
        delete deletar;
        return dado;
    }
    return "Tente Novamente.";
}


#endif // TADFILA_H
