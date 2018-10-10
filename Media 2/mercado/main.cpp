#include <iostream>
#include "tadmercado.h"
#include "tadfila.h"
#include "menu.h"
using namespace std;

void fila(){
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
            cout << "Clientes atendidos: "<< saida << endl;
            for (int i=0; i<qtdCaixas; i++){
                if (caixas[i].qtd!=0){
                    media++;
                    caixas[i].inicio->dado--;
                    if(caixas[i].inicio->dado == 0){
                        remove_inicio(caixas[i]);
                        caixas[i].qtd--;
                        saida++;
                    }
                }
            }

            distribuir(caixas, pessoasPturno, qtdCaixas, controle);
            system("pause");
            tempo--;
        }
        resultado(caixas, qtdCaixas, saida, media);
}

void selection (int realPosition, int arrowPosition) ///Função para seta no menu;
{

    if (realPosition == arrowPosition)
    {
        textcolor(10,0);
        cout << "       --->   " ;
    }
    else
    {
        textcolor(15,0);
        cout <<"       " ;
    }
}

int main()
{

    int key=0, position=1, sair=1;
        HideCursor();
        do{
            while(key!=13){
                system("cls");
                gotoxy(0,0);
                textcolor(8,0);
                cout <<  "TRABALHO M2"  << endl;
                selection (1,position);
                cout <<  "Mercado"  << endl;
                selection (2,position);
                cout << "Creditos" <<  endl;
                selection (3,position);
                cout <<"Sair" << endl;
                selection (4,position);
                key = getch();
                if (key == 80 && position != 4)
                    position ++;
                else if (key == 72 && position !=1)
                    position --;

                }
            switch(position){
            case 1:
                system ("cls");
                fila();
                main();
                break;
            case 2:
                system("cls");
                gotoxy(9,0);
                cout <<  "Alexandre Fernandes Da Silva" << endl;
                gotoxy(9,1);
                cout << "Patrick Medeiros De Luca" <<  endl;
                system("PAUSE");
                main();
                break;
            case 3:
                exit(0);
            }
        }while (sair!=0);


}
