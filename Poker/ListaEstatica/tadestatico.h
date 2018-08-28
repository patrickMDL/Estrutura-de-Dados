#ifndef TADESTATICO_H
#define TADESTATICO_H
#include <iostream>
using namespace std;



template <typename TIPO>
struct TElemento{
    TIPO dado;
};

template <typename TIPO, int MAX>
struct Tlista{
    TElemento<TIPO> elemento[MAX];
    int tamanho;
};

template <typename TIPO, int MAX>
void inicializa_lista_estatica (Tlista<TIPO, MAX> &lista){
    lista.tamanho=0;
}

template <typename TIPO, int MAX>
bool insere_inicio(Tlista<TIPO, MAX> &lista, TElemento<TIPO> carta){
    if(lista.tamanho<MAX){
        if (lista.tamanho==0){
            lista.elemento[0]=carta;
            lista.tamanho++;
            return true;
        }
        else{
            for(int i=lista.tamanho;i>=0; i--){
                lista.elemento[i+1]=lista.elemento[i];
            }
            lista.elemento[0]=carta;
            return true;
        }
    }
    else
        return false;
}

template <typename TIPO,int MAX>
bool insere_fim(Tlista<TIPO, MAX> &lista, TElemento<TIPO> carta){
    if(lista.tamanho<MAX){
        lista.elemento[lista.tamanho]=carta;
        lista.tamanho++;

    }
     return true;
}

template <typename TIPO, int MAX>
void insere_posicao(Tlista<TIPO, MAX> &lista, TElemento<TIPO> Carta, int position){
    if(lista.tamanho<MAX){
        if(lista.tamanho==0){
            lista.elemento[0]=Carta;
            lista.tamanho++;
        }
        else{
            for(int i=lista.tamanho; i>position; i--){
                lista.elemento[i]=lista.elemento[i-1];
            }
            lista.elemento[position]=Carta;
            lista.tamanho++;
        }
    }
}

template <typename TIPO, int MAX>
void remove_inicio(Tlista<TIPO, MAX> &lista){
    if (lista.tamanho >0){
        for (int i=0; i< lista.tamanho-1; i++)
            lista.elemento[i]=lista.elemento[i+1];
        lista.tamanho--;
    }
}

template <typename TIPO, int MAX>
bool remove_fim(Tlista<TIPO, MAX> &lista){
    if (lista.tamanho==0){
        cout << "Lista Vazia" << endl;
        return true;
    }
    lista.tamanho--;
    return true;
}

template <typename TIPO, int MAX>
bool remove_position(Tlista<TIPO, MAX> &lista, int position){
    if(lista.tamanho<MAX){
        for (int i=position; i< lista.tamanho-1; i++)
            lista.elemento[i]=lista.elemento[i+1];
        lista.tamanho--;
        return true;
    }
    else
        return false;
}

template <typename TIPO, int MAX>
void bubblesort (Tlista<TIPO, MAX> &lista, int tam){
    int i, j;
    TElemento<TIPO> aux;
        TElemento<TIPO> aux2;
    for (i=0; i<tam; i++){
        for (j=0; j<tam-1; j++){
            aux=lista.elemento[j];
            aux2=lista.elemento[j+1];
            if (aux.dado >= aux2.dado){ //Organiza pelo valor
                aux=lista.elemento[j];
                lista.elemento[j]=lista.elemento[j+1];
                lista.elemento[j+1]=aux;
            }
        }
    }
}



template <typename TIPO, int MAX>
int partition(Tlista<TIPO, MAX> &lista, int left, int right) {
    int i, j;
    i = left;
    TElemento<TIPO> aux1=lista.elemento[left], aux2;
    for (j = left + 1; j <= right; ++j) {
        aux2=lista.elemento[j];
        if (aux2.dado < aux1.dado) {
            ++i;
            TElemento<TIPO> aux = lista.elemento[i];
            lista.elemento[i] = lista.elemento[j];
            lista.elemento[j] = aux;
        }
    }
    TElemento<TIPO> aux = lista.elemento[left];
    lista.elemento[left] = lista.elemento[i];
    lista.elemento[i]= aux;
    return i;
}

template <typename TIPO, int MAX>
void quicksort(Tlista<TIPO, MAX> &lista, int left, int right) {
    int r;
    if (right > left) {
        r =partition(lista, left, right);
        quicksort(lista, left, r - 1);
        quicksort(lista, r + 1, right);
    }
}



#endif // TADESTATICO_H
