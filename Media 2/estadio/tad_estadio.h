#ifndef TAD_ESTADIO_H
#define TAD_ESTADIO_H
#include "tadfila.h"
#include <time.h>
#include <iomanip>

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

void imprimir (TFila<int> filaN[], TFila<int> filaST[], int qtdN, int qtdST, int tempo){ ///N = normal, ST = Socio Torcedor;
    cout << "Unidade de tempo: " << tempo << endl << endl;
    for(int i=0; i<qtdN; i++)
        cout << "Guiche Normal " << i+1 << ": " << filaN->qtd << endl; ///Mostra a quantidade de torcedores Normais em cada fila;
    cout << endl;
    for (int i=0; i< qtdST; i++)
        cout << "Guiche Socio Torcedor " << i+1 << ": " << filaST[i].qtd << endl;///Mostra a quantidade de Socio Torcedores em cada fila;
}

void resultado (TFila<int> filaN[], TFila<int> filaST[], int &qtdN, int &qtdST, int saidaN, int saidaST, double media1, double media2){
    int tamanhoN=0, tamanhoST=0;
    for (int i=0; i<qtdN; i++)
        tamanhoN+=filaN[i].qtd;
    for (int i=0; i<qtdN; i++)
        tamanhoST+=filaST[i].qtd;


    system("cls");
    cout << "Torcedores normais atendidos: " << saidaN << endl;
    cout << "Socio torcedores atendidos: " << saidaST << endl << endl;

    cout << "Total de pessoas que passaram no guiche normal: " << tamanhoN + saidaN << endl;
    cout << "Total de pessoas que passaram no guie de socio torcedor: " << tamanhoST + saidaST << endl << endl;

    cout << "Quantidade de torcedores normais que esperam por guiche: " << setprecision(3) << (tamanhoN + saidaN)/qtdN << endl;
    cout << "Quantidade de socio torecedores que esperam por guiche: " << setprecision(3) << (tamanhoST + saidaST)/qtdST << endl << endl;

    cout << "Tempo medio para o atendimento de torcedor normal: " << setprecision(3) << media1/saidaN << endl;
    cout << "Tempo medio para o atendimento de socio torcedor: " << setprecision(3) << media2/saidaST << endl << endl;

    system("pause");
    system("cls");
}

void distribui (int pessoas, TFila<int> filaN[], TFila<int> filaST[], int qtdST, int qtdN, double &sobra){
    srand(time(NULL));
    double st = pessoas * 0.05; //qtd socio torcedor;
    double normal = pessoas * 0.95;//qtd torcedores normais;
    double temporario = st; // temp é igual a 5% dos socio torcedores;
    int i=0, j=0, k=0, aux = 0, l=0;

    if(sobra >= 1){ //Variável de controle para manter as probabilidades;
        st+=1;      //Se sobra for igual a 1, significa que, para não sair da probabilidade, 1 torcedor precisa ir para a fila dos socio torcedores;
        normal-=1;  //Diminui um dos normais;
        sobra--;    //Decrementa a sobra;
    }

    while (temporario >=1) //z = 5% dos novos torcedores -- z = tempo;
        temporario--; // decrementa 'temporario' até restar apenas a parte decimal do número;
    sobra += temporario; //acumula a parte decimal de ST(temporario) na sobra)


    while (temporario>=1){
        aux=rand()%2;;
        if(aux == 0){ //adicionar torcedores com tempos aleatórios conforme probabilidades;
            if (j < st * 0.85){  //85% vão com 1 unidade de tempo;
                insere_fim(filaST[menor_fila(filaST, qtdST)], 1); //adiciona na menor posição;
                j++;//aux para sair do if em algum loop;
                i++;//aux para sair do loop;
            }
        }
        else{
            if (k < st * 0.15){
                insere_fim(filaST[menor_fila(filaST, qtdST)], 2); // adiciona na menor posição;
                k++;
                i++;
            }
        }
    }
    i=0;
    j=0;
    k=0;
    aux=0;

    while (i<normal){ //mesma logica anterior mas com a fila normal;
        aux = rand()%3; //rand para determinar qual das 3 possibilidades será;
        if(aux==0){
            if(j<normal* 0.25){ //25% recebe 1 unidade de tempo;
                insere_fim(filaN[menor_fila(filaN, qtdN)], 1); // adiciona na menor posição;
                j++;
                i++;
            }
        }
        else if (aux ==1){
            if (k < normal *0.3){ //30% recebe 2 unidades de tempo;
                insere_fim(filaN[menor_fila(filaN, qtdN)], 2); //adiciona na menor posição;
                k++;
                i++;
            }
        }
        else {
            if(l<normal *0.45){ // 45% recebe 3 unidades de tempo;
                insere_fim(filaN[menor_fila(filaN, qtdN)], 3); //insere na menor posição;
                l++;
                i++;
            }
        }
    }
}



#endif // TAD_ESTADIO_H
