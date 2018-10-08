#include <iostream>
#include "tadmercado.h"
#include "tadfila.h"
using namespace std;

int main()
{
    int qtdCaixa, ptotal, pTempo, saida = 0, tempo;
    double controle =0;
    cout << "Digite a quantidade de caixas: " << endl;
    cin >> qtdCaixa;




    TFila<int> fila[qtdCaixa];

    for(int i=0; i< qtdCaixa; i++)
        inicializa(fila[i]);

    cout << endl << "Quantidade de pessoas na fila: " << endl;
    cin >> ptotal;
    cout <<endl << "Quantidade de pessoas que chegam por unidade de tempo: " << endl;
    cin >> pTempo;
    cout << endl << "Tempo de simulacao(unidade de tempo): " << endl;
    cin >> tempo;

    distribuir(fila, ptotal, tempo); //Distribui os torcedores conforme as probabilidades;

    double media1 = 0, media2 = 0;

    while (tempo >0){
        imprimir(fila, qtdCaixa, tempo);

        for(int i=0; i<qtdCaixa; i++){
            if(fila[i].qtd != 0){
                media1++;
                fila[i].inicio->dado --;
                if(fila[i].inicio->dado == 0){
                    remove_inicio(fila[i]);
                    saida++;
                    cout << "Caixa[" << i+1 <<"]-------Atendidos:"<< saida <<endl;
                }
            }
        }

        distribuir(fila, ptotal, tempo);
        system("pause");
        tempo--;
    }
    resultado(fila, qtdCaixa, saida, media1, media2);
}
