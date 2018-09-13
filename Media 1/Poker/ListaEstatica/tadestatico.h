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
bool insere_fim(Tlista<TIPO, MAX> &lista, TIPO dado){
    int tamanho=lista.tamanho;
    if(lista.tamanho<MAX){
        lista.elemento[tamanho].dado=dado;
        lista.tamanho++;

    }
     return true;
}

template <typename TIPO, int MAX>
void insere_posicao(Tlista<TIPO, MAX> &lista, TIPO dado, int position){
    if(lista.tamanho<MAX){
        if(lista.tamanho==0){
            lista.elemento[0]=dado;
            lista.tamanho++;
        }
        else{
            for(int i=lista.tamanho; i>position; i--){
                lista.elemento[i]=lista.elemento[i-1];
            }
            lista.elemento[position]=dado;
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
bool bubblesort (Tlista<TIPO, MAX> &lista){
    TElemento<TIPO> aux;
    for (int i; i<lista.tamanho-1; i++){
        for (int j=0; j<lista.tamanho-1; j++){
            if(lista.elemento[j].dado > lista.elemento[j+1].dado){
                aux = lista.elemento[j];
                lista.elemento[j] = lista.elemento[j+1];
                lista.elemento[j+1] =aux;
            }
        }
    }
    return true;
}

template <typename TIPO, int MAX>
bool quicksort (Tlista<TIPO, MAX> &lista, int inicio, int fim){
    int i=inicio, j=fim;
    int metade=(i+j)/2;
    TIPO pivo = lista.elemento[metade].dado;
    TElemento<TIPO> aux;
    while(i<=j){
        while(lista.elemento[i].dado < pivo && i<inicio)
            i++;
        while (lista.elemento[j].dado > pivo && j> fim)
            j--;
        aux = lista.elemento[i];
        lista.elemento[i] = lista.elemento[j];
        lista.elemento[j] = aux;
        i++;
        j--;
    }
    if(inicio<j)
        quicksort(lista, inicio, j);
    if (i < fim)
        quicksort(lista, j, fim);
    return true;
}

#endif // TADESTATICO_H
