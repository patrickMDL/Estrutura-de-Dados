#ifndef TADHEAP_H
#define TADHEAP_H

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
    if (no==nullptr){
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
    heap_binary(no, dado, chave);
    heap_binary(no, dado, chave);///Chamando a segunda vez caso a primeira não tenha trocado todos os elementos necessários;
}

template <typename TIPO>
void heap_binary(THeap<TIPO> *&no, TIPO dado, int chave){
    if (no!=nullptr){
        THeap<TIPO> *aux = no;
        if (aux->esquerda->dado <= no->dado && no->esquerda!=nullptr){
            TIPO dado_aux;
            dado_aux = aux->esquerda->dado;
            aux->esquerda->dado = no->dado;
            no->dado=dado_aux;
        }
        heap_binary(no->esquerda, dado, chave && no->direita!=nullptr);
        if (aux->esquerda->dado <= no->dado && no->esquerda!=nullptr){
            TIPO dado_aux;
            dado_aux = aux->esquerda->dado;
            aux->esquerda->dado = no->dado;
            no->dado=dado_aux;
        }
        if (aux->direita->dado <= no->dado){
            TIPO dado_aux;
            dado_aux=aux->direita->dado;
            aux->direita->dado=no->dado;
            no->dado=dado_aux;

        }
        heap_binary(no->direita, dado, chave);
        if (aux->direita->dado <= no->dado){
            TIPO dado_aux;
            dado_aux=aux->direita->dado;
            aux->direita->dado=no->dado;
            no->dado=dado_aux;

        }
    }

}



#endif // TADHEAP_H
