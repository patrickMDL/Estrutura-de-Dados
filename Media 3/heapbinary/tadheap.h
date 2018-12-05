#ifndef TADHEAP_H
#define TADHEAP_H
#include <iostream>
using namespace std;
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
void insere_arvore(THeap<TIPO> *&no, TIPO dado, int chave){ ///Insere na árvore, mas não deixa de acordo com o Heap;
    if (no==nullptr ){
        no = new THeap<TIPO>;
        no->chave=chave;
        no->dado=dado;
        no->n_filhos=0;
        no->direita=nullptr;
        no->esquerda=nullptr;
    }else{
        if(no->esquerda==nullptr && no->n_filhos<=1){
            insere_arvore(no->esquerda, chave, dado);
            no->n_filhos++;
        }
        else if (no->direita==nullptr && no->n_filhos<=1){
            insere_arvore(no->direita, chave, dado);
            no->n_filhos++;
        }
        else if (no->n_filhos>1){
            if(no->esquerda==nullptr)
                insere_arvore(no->esquerda, chave, dado);
            else if (no->direita==nullptr)
                insere_arvore(no->direita, chave, dado);
        }
    }

}

template <typename TIPO>
void construir_heap(THeap<TIPO> *&no, int vetor[], int tamanho){
    int i;
    int l=(2*i)+1;
    int r=(2*i)+2;
    for (i=tamanho; i>-1; i++){
        insere_arvore(no, vetor[i], i);
    }

}

void heapify(int vetor[], int n, int i)
{
    int menor = i; ///Inicializa o menor como raiz;
    int l = 2 * i + 1; /// esquerda = 2*i + 1
    int r = 2 * i + 2; /// direita = 2*i + 2

    ///Se o 'filho' esquerdo for menor q a raiz;
    if (l < n && vetor[l] < vetor[menor])
        menor = l;

    ///Se o 'filho' direito for menor q a raiz;
    if (r < n && vetor[r] < vetor[menor])
        menor = r;

    ///Se o menor é diferente da raiz;
    if (menor != i) {
        swap(vetor[i], vetor[menor]);

        ///Recursivamente aplica o efeito nas sub-árvores.
        heapify(vetor, n, menor);
    }
}

void heapSort(int vetor[], int n)
{
    // Build heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(vetor, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(vetor[0], vetor[i]);

        // call max heapify on the reduced heap
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
