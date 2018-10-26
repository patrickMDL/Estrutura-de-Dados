#ifndef TADAVL_H
#define TADAVL_H
#include <iostream>
using namespace std;

template <typename TIPO>
struct TNo{
    int chave;
    int equilibrio;
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
int insere_arvore(TNo<TIPO> *&no, int chave, TIPO dado){
    if (no==nullptr){
        no = new TNo<TIPO>;
        no->chave=chave;
        no->dado=dado;
        no->equilibrio=0;
        no->direita=NULL;
        no->esquerda=NULL;
        return 1;
    }
    if(chave < no->chave){
        insere_arvore(no->esquerda, chave, dado);
        int n = insere_arvore(no->esquerda, chave, dado);
        no->equilibrio=no->equilibrio-n;
        if(no->equilibrio<-1){
            if (no->direita->chave>chave){
                direito_esquerda(no);
            }else{
                direita_direita(no);
            }
        }else{
            if(no->equilibrio==0){
                return 0;
            }else{
                return 1;
            }
        }
    }else{
        if (chave > no->chave){
            int n = insere_arvore(no->esquerda, chave, dado);
            no->equilibrio -= n;
            if (no->equilibrio<-1){
                if (no->esquerda->chave > chave){
                    esquerda_esquerda(no);
                }else {
                    esquerda_direita(no);
                } return 0;
            } else {
                if (no->equilibrio == 0 ){
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
void esquerda_esquerda(TNo<TIPO> *&no){
    TNo<TIPO> *b = no;
    TNo<TIPO> *a = b->esquerda;

    b->esquerda= a->direita;
    a->direita=b;

    a->equilibrio=0;
    b->equilibrio=0;
    no = a;
}

template <typename TIPO>
void direita_direita(TNo<TIPO> *&no){
    TNo<TIPO> *b=no;
    TNo<TIPO> *a=b->direita;

    b->direita=a->esquerda;
    a->esquerda=b;

    a->equilibrio=0;
    b->equilibrio=0;
    no = a;
}
template <typename TIPO>
void esquerda_direita(TNo<TIPO> *&nav){//cu
    TNo<TIPO> *b = nav->esquerda;
    TNo<TIPO> *a = b->direita;
    b->direita = a->esquerda;
    nav->esquerda = a->direita;
    a->esquerda = b;
    a->direita = nav;
    a->equilibrio=0;
    b->equilibrio=0;
    nav = a;
}

template <typename TIPO>
void direito_esquerda(TNo<TIPO> *&nav){
    TNo<TIPO> *b = nav->direita;//cu
    TNo<TIPO> *a = b->esquerda;
    b->esquerda = a->direita;
    nav->direita = a->esquerda;
    a->direita = b;
    a->esquerda = nav;
    a->equilibrio=0;
    b->equilibrio=0;
    nav = a;
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

#endif // TADAVL_H
