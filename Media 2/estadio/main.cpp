#include <windows.h>
#include <conio.h>
#include <iostream>
using namespace std;
///Minhas bibliotecas;
#include "tadfila.h"
#include "tad_estadio.h"
#include "design.h"

void fila (){
    int qtdN, qtdST, ptotal, pturno, saidaN = 0, saidaST = 0, tempo;
    double controle =0;
    cout << "Digite a quantidade de guiches normais: " << endl;
    cin >> qtdN;
    cout << endl << "Digite a quantidade de guiches socio torcedors: " << endl;
    cin >> qtdST;

    if (qtdN <=0)
        qtdN = 1;
    if(qtdST <=0)
        qtdST =1;

    TFila<int> filaN[qtdN];
    TFila<int> filaST[qtdST];

    for(int i=0; i< qtdN; i++)
        inicializa(filaN[i]);
    for(int i=0; i<qtdST; i++)
        inicializa(filaST[i]);

    cout << endl << "Quantidade de torcedores Iniciais: " << endl;
    cin >> ptotal;
    cout <<endl << "Quantidade de torcedores que chegam por turno: " << endl;
    cin >> pturno;
    cout << endl << "Tempo de simulacao(unidade de tempo): " << endl;
    cin >> tempo;

    distribui(ptotal, filaN, filaST, qtdST, qtdN, controle); //Distribui os torcedores conforme as probabilidades;

    double media1 = 0, media2 = 0;

    while (tempo >0){
        imprimir(filaN, filaST, qtdN, qtdST, tempo);

        for(int i=0; i<qtdN; i++){
            if(filaN[i].qtd != 0){
                media1++;
                filaN[i].inicio->dado --;
                if(filaN[i].inicio->dado == 0){
                    remove_inicio(filaN[i]);
                    saidaN++;
                    cout << "GUICHE NORMAL[" << i+1 <<"]-------Atendidos:"<< saidaN <<endl;
                }
            }
        }
        for (int i=0; i <qtdST; i++){
            if(filaST[i].qtd !=0){
                media2++;
                filaST[i].inicio->dado--;
                if(filaST[i].inicio->dado == 0){
                    remove_inicio(filaST[i]);
                    saidaST++;
                    cout << "GUICHE SOCIO TORCEDOR["<< i+1 << "]-------Atendidos:" << saidaST << endl;
                }
            }
        }
        distribui(pturno, filaN, filaST, qtdST, qtdN, controle);
        system("pause");
        tempo--;
    }
    resultado(filaN, filaST, qtdN, qtdST, saidaN, saidaST, media1, media2);

}

void selection (int realPosition, int arrowPosition) ///Função para seta no menu;
{
    if (realPosition == arrowPosition)
    {
        textcolor(12,0);
        printf ("       --->   ");
    }
    else
    {
        textcolor(15,0);
        printf ("       ");
    }
}

int main()
{
    int key=0, position=1, sair=1;
    hide();
    do{
        while(key!=13){
            system("cls");
            gotoxy(0,0);
            textcolor(9,0);
            cout << "TRABALHO M2" << endl;
            selection (1,position);
            cout << "Estadio" << endl;
            selection (2,position);
            cout << "Creditos" << endl;
            selection (3,position);
            cout << "Sair" << endl;
            key = getch();

            if (key == 80 && position != 3)
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
            textcolor(9,0);
            gotoxy(9,0);
            cout << "Alexandre Fernandes Da Silva" << endl;
            textcolor(9,0);
            gotoxy(9,1);
            cout << "Patrick Medeiros De Luca" << endl;

            system("pause");
            main();
            break;
        case 3:
            exit(0);
        }
    }while (sair!=0);
    return 0;
}
