#include <iostream>
#include "tadmercado.h"
#include "tadfila.h"
using namespace std;

int main()
{
    int  qtdCaixas=0, pessoasFila, pessoasPturno, saida=0, tempo;
    float controle;
    while (qtdCaixas<1){
        cout << "Digite a quantidade de caixas: " << endl;
        cin >> qtdCaixas;
    }
    TFila<int> caixas[qtdCaixas];
    for (int i =0; i<qtdCaixas; i++)
        inicializa(caixas[i]);
    cout << "Duracao da simulacao: " << endl;
    cin >> tempo;
    cout << "Quantidade de clientes na fila: " << endl;
    cin >> pessoasFila;
    cout << "Quantidades de clientes por turno: " << endl;
    cin >> pessoasPturno;

    double media=0;
    distribuir(caixas, pessoasFila, qtdCaixas, controle);

    while (tempo > 0){
        imprimir(caixas,qtdCaixas,tempo);
        for (int i=0; i<qtdCaixas; i++){
            if (caixas[i].qtd!=0){
                media++;
                caixas[i].inicio->dado--;
                if(caixas[i].inicio->dado == 0){
                    remove_inicio(caixas[i]);
                    saida++;


                }
            }
        }
        cout << "Clientes atendidos: "<< saida << endl;

        distribuir(caixas, pessoasFila, qtdCaixas, controle);
        system("pause");
        tempo--;
    }
    resultado(caixas, qtdCaixas, saida, media);


}
