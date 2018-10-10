#ifndef TADMERCADO_H
#define TADMERCADO_H
#include <time.h>
#include <iomanip>
#include <windows.h>
///Biblioteca Personalizada;
#include "tadfila.h"

int menor_fila(TFila<int> fila[], int qtd){
  int menor = 0;
    if (qtd == 1)
        return menor;
    else if (qtd>1){
        for(int i=1; i<qtd; i++){
            if(fila[menor].qtd>fila[i].qtd){
                menor = i;
            }
        }
        return menor;
    }
}
void distribuir(TFila<int> filaM[], int pessoas, int qtdDeCaixas, float &sobra){
    if (pessoas == 0){
        cout << "Fila Vazia" << endl;
        return;
    }
    else{
        srand(time(NULL));
        /*if (pessoas >=1){
            pessoas-=1;
            sobra--;
        }*/
        int aux=0;      //Faz o controle do while;
        int aux50=0; //Faz o controle da porcentagem 50;
        int aux30=0;//Faz o controle da porcentagem 30;
        int aux20=0;//Faz o controle da porcentagem 20;
        int aleatorio;
        int menor;
        while (aux<pessoas){ //Esse while mantém as proporções;
            aleatorio = rand()%3; //rand para determinar qual das 3 possibilidades será;
            if(aleatorio==2){
                if(aux50<pessoas* 0.50){ //50% recebe 1 unidade de tempo;
                    menor=menor_fila(filaM, qtdDeCaixas);
                    insere_fim(filaM[menor], 1); // adiciona na menor posição;
                    filaM[menor].qtd++;
                    aux50++;

                }
            }
            else if (aleatorio ==1){
                if (aux30 < pessoas *0.3){ //30% recebe 4 unidades de tempo;
                    menor=menor_fila(filaM,qtdDeCaixas);
                    insere_fim(filaM[menor], 4); //adiciona na menor posição;
                    filaM[menor].qtd++;
                    aux30++;

                }
            }
            else {
                if(aux20<pessoas *0.20){ // 20% recebe 6 unidades de tempo;
                    menor=menor_fila(filaM,qtdDeCaixas);
                    insere_fim(filaM[menor], 6); //insere na menor posição;
                    filaM[menor].qtd++;
                    aux20++;

                }
            }
            aux++;
        }
    }
}

void imprimir (TFila<int> fila[], int qtdDeCaixa, int tempo){
    system("cls");//windows
    //system("clear"); //Linux
    cout << "Unidade de tempo: " << tempo << endl << endl;

    for(int i=0; i<qtdDeCaixa; i++){
        cout << "Caixa " << i+1 << ": " << "Cliente" << "( " << fila[i].inicio->dado << ")" << endl; ///Mostra a quantidade de clientes em cada fila;
        cout << "Na fila: " << fila[i].qtd << endl;

    }
}


void resultado (TFila<int> filaM[], int &qtdCaixa, int saida, double media1){
    int tamanhoCaixas=0;
    for (int i=0; i<qtdCaixa; i++)
        tamanhoCaixas+=filaM[i].qtd;


    system("cls");
    cout << "Clientes atendidos: " << saida << endl;
    cout << "Quantidade de clientes que esperam/caixa: " << setprecision(3) << (tamanhoCaixas-saida)/qtdCaixa << endl;
    cout << "Tempo medio para o atendimento de clientes: " << setprecision(3) << media1/saida << endl;

    system("pause");
    system("cls");
}




#endif // TADMERCADO_H
