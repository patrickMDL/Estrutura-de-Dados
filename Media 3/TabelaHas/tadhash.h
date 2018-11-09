#ifndef TADHASH_H
#define TADHASH_H

#include <iostream>
using namespace std;

struct Hash{
    char status; //L => Livre // O => Ocupado // R => Removido;
    int chave;
    Hash *proximo;
};

void inicializa_hash(Hash *tabela[], int tamanho){
    for (int i=0; i<tamanho; i++){
        tabela[i]->chave=NULL;
        tabela[i]->status='L';
    }
}


void inicializa_hash(Hash tabela[], int tamanho){
    for (int i=0; i<tamanho; i++){
        tabela[i].chave=NULL;
        tabela[i].status='L';
    }
}

int funcao_hash (int chave, int tamanho){
    int h=0;
    h=(chave)%tamanho;
    return h;
}

int funcao_hash(int chave, int tamanho, int i){
    int h=0;
    h=(chave+i)%tamanho;
    return h;
}


void insere_hash(Hash *tabela[],int  tamanho,int  chave){
    int i=0;
    while(i<tamanho){
        int h=funcao_hash(chave, tamanho);
        if (tabela[h]->status == 'O')
            tabela[h];
        if (tabela[h]->status == 'L' || tabela[h]->status == 'R'){
            tabela[h]->chave=chave;
            tabela[h]->status='O';
            break;
        }
        else
            i++;
    }
}

void insere_hash(Hash tabela[],int  tamanho,int  chave){
    int i=0;
    while(i<tamanho){
        int h=funcao_hash(chave, tamanho);
        if (tabela[h].status == 'O')
            h=funcao_hash(chave, tamanho, i+1);
        if (tabela[h].status == 'L' || tabela[h].status == 'R'){
            tabela[h].chave=chave;
            tabela[h].status='O';
            break;
        }
        else
            i++;
    }
}

void remove_hash(Hash tabela[],int tamanho, int chave){
    int i=0;
    while (i<tamanho){
        if (tabela[i].chave == chave){
            tabela[i].status='R';
            break;
        }
        else{
            i++;
        }
    }
}

void imprimi_hash(Hash tabela[], int tamanho){
    int i=0;
    cout << " STATUS || CHAVE" <<endl;
    while (i<tamanho){
        cout << i << "|" << tabela[i].status << "|" << tabela[i].chave << endl;
        i++;
    }
}



#endif // TADHASH_H
