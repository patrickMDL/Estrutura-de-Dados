#ifndef GENERICO_H
#define GENERICO_H
#include <iostream>
using namespace std;
#include "tad.h"
#include <string.h>
#include <algorithm>


template <typename Tipo>
struct TElemento{
    Tipo dado;
};

template <typename Tipo, int MAX>
struct TLista{
    TElemento<Tipo> elemento[MAX];
    int quantidade;
};

template<typename Tipo,int MAX>
int qtd(TLista<Tipo,MAX>&lista){
    return lista.quantidade;
}

template<typename Tipo, int MAX>
void IniciaListaG(TLista<Tipo,MAX> &lista){
        lista.quantidade=0;
}

template<typename Tipo,int MAX >
bool InsereFinalG(TLista<Tipo,MAX>&lista,Tipo dado){
    if(lista.quantidade>=MAX)
        return false;
    else{
        TElemento<Tipo>aux;
        aux.dado=dado;
        lista.elemento[lista.quantidade]=aux;
        lista.quantidade++;
        return true;
    }
}

template<typename Tipo,int MAX>
void RemoveFinalG(TLista<Tipo,MAX>&lista){
    if(lista.quantidade>0)
        lista.quantidade-=1;
}

template<typename Tipo,int MAX>
void RemoveInicioG(TLista<Tipo,MAX>&lista){
    int i;
    if(lista.quantidade>0){
        for(i=0;i<lista.quantidade-1;i++){
            lista.elemento[i]=lista.elemento[i+1];
        }
        lista.quantidade--;
    }
}

template<typename Tipo,int MAX>
void InsereInicioG(TLista<Tipo,MAX>&lista,Tipo dado){
    int i;
    if(lista.quantidade<MAX){
        TElemento<Tipo>aux;
        aux.dado=dado;
        for(i=lista.quantidade;i>0;i--){
            lista.elemento[i]=lista.elemento[i-1];
        }
        lista.elemento[0]=aux;
        lista.quantidade++;
    }
}

template<typename Tipo,int MAX>
void RemovePosicaoG(int pos,TLista<Tipo,MAX> &lista)
{
    int i;
    if(lista.quantidade>0){
    for(i=pos;i<lista.quantidade;i++)
        lista.elemento[i]=lista.elemento[i+1];
     lista.quantidade--;
    }
}

template<typename Tipo,int MAX>
void InserePosicaoG(int pos,TLista<Tipo,MAX> &lista,Tipo dado)
{
    int i;
    for(i=lista.quantidade;i>pos;i--){
        lista.elemento[i]=lista.elemento[i-1];
    }
    TElemento<Tipo>aux;
    aux.dado=dado;
    lista.elemento[pos]=aux;
    lista.quantidade+=1;

}

template <typename Tipo,int MAX>
void imprimeLista(TLista<Tipo,MAX>lista)
{

    for(int i=0;i<lista.quantidade;i++){
        cout <<lista.elemento[i].dado<< endl;

    }
}

template<typename Tipo,int MAX>
void bubblesort(TLista<Tipo,MAX>&lista){
    int i,j;
    Tipo auxe;
    for(i = 0; i < lista.quantidade; i++){
        for(j = 0; j < lista.quantidade - 1; j++)
        {
            if(lista.elemento[j].dado > lista.elemento[j+1].dado)
            {
                auxe = lista.elemento[j].dado;
                lista.elemento[j].dado = lista.elemento[j+1].dado;
                lista.elemento[j+1].dado = auxe;
            }
        }
    }
}
template <typename Tipo, int MAX>
void quicksort(TLista<Tipo,MAX>&lista, int inicio, int fim)
{
	int esq, dir;
	esq = inicio;
	dir = fim-1;

	TElemento<Tipo> pivo = lista.elemento[(inicio + fim) / 2];
	while(esq <= dir)
	{
		while(pivo.dado > lista.elemento[esq].dado && esq < fim)
			esq++;
		// lista.elemento[esq] será MAIOR que pivo
		while(lista.elemento[dir].dado > pivo.dado && dir > inicio)
			dir--;
        // lista.elemento[dir] será MENOR que pivo
		if(esq <= dir)
		{
			TElemento<Tipo> aux = lista.elemento[esq];
			lista.elemento[esq] = lista.elemento[dir];
			lista.elemento[dir] = aux;
			esq++;
			dir--;
		}
	}
	if(dir > inicio)
		quicksort(lista, inicio, dir+1);
	if(esq < fim)
		quicksort(lista, esq, fim);

}
#endif // GENERICO_H
