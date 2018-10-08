#ifndef TADMERCADO_H
#define TADMERCADO_H
#include <time.h>
#include <iomanip>
///Biblioteca Personalizada;
#include "tadfila.h"

int menor_fila(TFila<int> fila[], int qtd){
  int menor = 0;
    if (qtd == 1)
        return 0;
    else{
        for(int i=1; i<qtd; i++){
            if(fila[menor].qtd>fila[i].qtd){
                menor = i;
            }
        }
        return menor;
    }
}

void resultado (TFila<int> filaM[], int &qtdCaixa, int saida, double media1, double media2){
    int tamanhoN=0, tamanhoST=0;
    for (int i=0; i<qtdCaixa; i++)
        tamanhoN+=filaM[i].qtd;


    system("clear");
    cout << "Clientes atendidos: " << saida << endl;
    cout << "Quantidade de clientes que esperam por caixa: " << setprecision(3) << (tamanhoN + saida)/qtdCaixa << endl;
    cout << "Tempo medio para o atendimento de torcedor normal: " << setprecision(3) << media1/saida << endl;

    getchar();
    system("clear");
}

void imprimir (TFila<int> fila[], int qtd, int tempo){ ///N = normal, ST = Socio Torcedor;
    cout << "Unidade de tempo: " << tempo << endl << endl;
    for(int i=0; i<qtd; i++)
        cout << "Guiche Normal " << i+1 << ": " << fila[i].qtd << endl; ///Mostra a quantidade de torcedores Normais em cada fila;
    cout << endl;
}

void distribuir(TFila<int> filaM[], int pessoas, int tempo){
    if (pessoas == 0){
        cout << "Fila Vazia" << endl;
        return;
    }
    else{
        int i=0;
        int j=0;
        int k=0;
        int l=0;
        int aux=0;

        while (i<pessoas){ //Esse while mantém as proporções;
            aux = rand()%3; //rand para determinar qual das 3 possibilidades será;
            if(aux==0){
                if(j<pessoas* 0.50){ //25% recebe 1 unidade de tempo;
                    insere_fim(filaM[menor_fila(filaM, filaM->qtd)], 1); // adiciona na menor posição;
                    j++;
                    i++;
                }
            }
            else if (aux ==1){
                if (k < pessoas *0.3){ //30% recebe 4 unidades de tempo;
                    insere_fim(filaM[menor_fila(filaM, filaM->qtd)], 4); //adiciona na menor posição;
                    k++;
                    i++;
                }
            }
            else {
                if(l<pessoas *0.20){ // 45% recebe 6 unidades de tempo;
                    insere_fim(filaM[menor_fila(filaM, filaM->qtd)], 6); //insere na menor posição;
                    l++;
                    i++;
                }
            }
            imprimir(filaM, filaM->qtd, tempo);
            system("pause");
        }
    }
}

#endif // TADMERCADO_H
