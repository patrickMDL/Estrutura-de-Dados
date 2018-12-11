#ifndef TADHEAP_H
#define TADHEAP_H
#include <string>
#include <iostream>
#include "design.h"
using namespace std;

template <typename TIPO>
struct THeap{
    TIPO dado;
    int chave;
    int bal;
    THeap<TIPO> *direita;
    THeap<TIPO> *esquerda;
};

template <typename TIPO>
struct TArvore{
    THeap<TIPO> *raiz;
};

template <typename TIPO>
void inicializa_arvore(TArvore<TIPO> &arvore){
    arvore.raiz=nullptr;
}

template <typename TIPO>
void esquerda_esquerda(THeap<TIPO> *&no){
    THeap<TIPO> *b = no;
    THeap<TIPO> *a = b->esquerda;

    b->esquerda= a->direita;
    a->direita=b;

    a->bal=0;
    b->bal=0;
    no = a;
}

template <typename TIPO>
void direita_direita(THeap<TIPO> *&no){
    THeap<TIPO> *b=no;
    THeap<TIPO> *a=b->direita;

    b->direita=a->esquerda;
    a->esquerda=b;

    a->bal=0;
    b->bal=0;
    no = a;
}
template <typename TIPO>
void esquerda_direita(THeap<TIPO> *&nav){//cu
    THeap<TIPO> *b = nav->esquerda;
    THeap<TIPO> *a = b->direita;
    if (a!= nullptr && b!=nullptr){
        b->direita = a->esquerda;
        nav->esquerda = a->direita;
        a->esquerda = b;
        a->direita = nav;
        a->bal=0;
        b->bal=0;
        nav = a;
    }

}

template <typename TIPO>
void direito_esquerda(THeap<TIPO> *&nav){
    THeap<TIPO> *b = nav->direita;//cu
    THeap<TIPO> *a = b->esquerda;
    if (a != nullptr && b != nullptr){
        b->esquerda = a->direita;
        nav->direita = a->esquerda;
        a->direita = b;
        a->esquerda = nav;
        a->bal=0;
        b->bal=0;
        nav = a;
    }
}




template <typename TIPO>
int insere_arvore(THeap<TIPO> *&no, int chave, TIPO dado){
    if (no==nullptr){
        no = new THeap<TIPO>;
        no->chave=chave;
        no->dado=dado;
        no->bal=0;
        no->direita=NULL;
        no->esquerda=NULL;
        return 1;
    }
    if(chave > no->chave){

        int n = insere_arvore(no->direita, chave, dado);
        no->bal=no->bal+n;
        if(no->bal>1){
            if (no->direita->chave>chave){
                direito_esquerda(no);
            }else{
                direita_direita(no);
            }
            return 0;
        }else{
            if(no->bal==0){
                return 0;
            }else{
                return 1;
            }
        }
    }else{
        if (chave < no->chave){
            int n = insere_arvore(no->esquerda, chave, dado);
            no->bal =no->bal - n;
            if (no->bal<-1){
                if (no->esquerda->chave > chave){
                    esquerda_esquerda(no);
                }else {
                    esquerda_direita(no);
                } return 0;
            } else {
                if (no->bal == 0 ){
                    return 0;
                } else {
                    return 1;
                }
            }
        }
        else{
            return 0;
        }
    }
}


void heapify(int vetor[], int n, int i)
{
    int maior = i; // Initialize maior as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2

    ///Se o 'filho' esquerdo for maior que a raiz;
    if (l < n && vetor[l] > vetor[maior])
        maior = l;

    ///Se o 'filho' direito for maior que a raiz;
    if (r < n && vetor[r] > vetor[maior])
        maior = r;

    ///Se o maior elemento não for a raiz;
    if (maior != i)
    {
        swap(vetor[i], vetor[maior]);

        heapify(vetor, n, maior);
    }
}

void heapSort(int vetor[], int n)
{
    ///Constroi o heap (reorganiza o vetor);
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(vetor, n, i);


    for (int i=n-1; i>=0; i--)
    {
        ///Move a raiz pro fim;
        swap(vetor[0], vetor[i]);
        heapify(vetor, i, 0);
    }
}

void printVetor(int vetor[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << vetor[i] << " ";
    cout << "\n";
}

template <typename TIPO>
void plottree(THeap<TIPO> *arvore,int h,int H,int mid,int Y)  /// Printar a árvore;
{
  if(arvore==NULL)
    return;

    int x=mid,i;
    int y=Y+1+(H*(H+1))/2 - (h*(h+1))/2;
    gotoxy(x,y);
    cout <<arvore->dado << "[" << arvore->bal << "]";
    if(arvore->direita!=NULL)
    {
        for(i=1;i<=(h-1);i++)
        {
            gotoxy(mid+i,y+i);
            cout << "\\";
        }
        plottree(arvore->direita,h-1,H,mid+(h),Y);
    }
    if(arvore->esquerda!=NULL)
    {
        for(i=1;i<=(h-1);i++)
        {
            gotoxy(mid-i,y+i);
            cout << "/";
        }
        plottree(arvore->esquerda,h-1,H,mid-(h),Y);
    }

}


#endif // TADHEAP_H
