#ifndef TADARVORE_H
#define TADARVORE_H
#include <iostream>
using namespace std;

template <typename TIPO>
struct TNo{
    int chave;
    TIPO dado;
    TNo<TIPO> *direita;
    TNo<TIPO> *esquerda;
};

template <typename TIPO>
struct TArvore{
    TNo<TIPO> *raiz;
};

template <typename TIPO>
void inicializa_arvore(TArvore<TIPO> &arvore){
    arvore.raiz = NULL;
}

template <typename TIPO>
void insere_arvore(TNo<TIPO> *&no, int chave, TIPO dado){
    if (no==nullptr){
        no = new TNo<TIPO>;
        no->chave=chave;
        no->dado=dado;
        no->direita=NULL;
        no->esquerda=NULL;
    }
    if(chave < no->chave)
        insere_arvore(no->esquerda, chave, dado);
    else{
        if (chave > no->chave)
            insere_arvore(no->direita, chave, dado);
    }
}

template <typename TIPO>
void prefixo(TNo<TIPO> *no){
    if(no!=NULL){
        cout << no->dado << '-';
        prefixo(no->esquerda);
        prefixo(no->direita);

    }
}
template <typename TIPO>
void infixo(TNo<TIPO> *no){
    if(no!=NULL){
        infixo(no->esquerda);
        cout << no->dado << '-';
        infixo(no->direita);
    }
}
template <typename TIPO>
void posfixo(TNo<TIPO> *no){
    if(no!=NULL){
        posfixo(no->esquerda);
        posfixo(no->direita);
        cout << no->dado << '-';
    }
}

template <typename TIPO>
void remover(TNo<TIPO> *&no){
    TNo<TIPO> *apagar;
    TNo<TIPO> *maior = no->esquerda;
    if(maior == NULL){
        apagar = no;
        no = no->direita;
        delete apagar;
        return;
    }
    TNo<TIPO> *pai = NULL;
    while (maior->direita !=NULL){
        pai = maior;
        maior = maior->direita;
    }
    maior->direita = no->direita;
    if (pai != NULL){
        pai->direita = maior->esquerda;
        maior->esquerda = no->esquerda;
    }
    apagar = no;
    no = maior;
    delete apagar;
}

template <typename TIPO>
void procura_remove(TNo<TIPO> *&no, int chave){ ///Procura o item pela chave;
    if(no != NULL){
        if(no->chave == chave){
            remover(no);
        }else{
            if(chave > no->chave){
                procura_remove(no->direita, chave);
            }else{
                procura_remove(no->esquerda, chave);
            }
        }
    }
}


#endif // TADARVORE_H
