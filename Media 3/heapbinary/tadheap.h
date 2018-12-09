#ifndef TADHEAP_H
#define TADHEAP_H
#include <iostream>
using namespace std;
int POS_VETOR=0;

template <typename TIPO>
struct THeap{
    TIPO dado;
    int chave;
    int n_filhos; ///Para manter os elementos sempre mais a esquerda e não aumentar a altura da árvore desnecessáriamente;
    THeap<TIPO> *direita;
    THeap<TIPO> *esquerda;
};

template <typename TIPO>
struct TArvore{
    THeap<TIPO> *raiz;
};

template <typename TIPO>
void inicializa_arvora(TArvore<TIPO> &arvore){
    arvore.raiz=nullptr;
}

template <typename TIPO>
void insere_arvore(THeap<TIPO> *&no, int vetor[], int i){ ///Insere na árvore, mas não deixa de acordo com o Heap;
    if ((no->esquerda==nullptr || no->direita == nullptr) && i<sizeof *(vetor)){
        no = new THeap<TIPO>;
        int esq = 2*i+1;
        int dir = 2*i+2;
        if (no->esquerda==nullptr){
            no->esquerda->dado=vetor[esq];
            no->esquerda->chave=esq;
            no->esquerda->esquerda=nullptr;
            no->esquerda->direita=nullptr;
        }
        if (no->direita==nullptr){
            no->direita->dado=vetor[dir];
            no->direita->chave=dir;
            no->direita->esquerda=nullptr;
            no->direita->direita=nullptr;
        }
    }else{
        insere_arvore(no->esquerda, vetor, POS_VETOR);
    }
    POS_VETOR++;

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

//template <typename TIPO>
//void plottree(THeap<TIPO> *arvore,int h,int H,int mid,int Y)  /// Printar a árvore;
//{
//  if(arvore==NULL)
//    return;

//    int x=mid,i;
//    int y=Y+1+(H*(H+1))/2 - (h*(h+1))/2;
//    gotoxy(x,y);
//    cout <<arvore->dado;
//    if(arvore->direita!=NULL)
//    {
//        for(i=1;i<=(h-1);i++)
//        {
//            gotoxy(mid+i,y+i);
//            cout << "\\";
//        }
//        plottree(arvore->direita,h-1,H,mid+(h),Y);
//    }
//    if(arvore->esquerda!=NULL)
//    {
//        for(i=1;i<=(h-1);i++)
//        {
//            gotoxy(mid-i,y+i);
//            cout << "/";
//        }
//        plottree(arvore->esquerda,h-1,H,mid-(h),Y);
//    }

//}

template <typename TIPO>
void prefixo(THeap<TIPO> *no){
    if(no!=NULL){
        cout << no->dado <<"[" <<no->chave<< "]" <<"[" <<no->n_filhos << "]" << " - ";
        prefixo(no->esquerda);
        prefixo(no->direita);

    }
}



#endif // TADHEAP_H
