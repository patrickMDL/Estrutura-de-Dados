//#include <windows.h>
//#include <conio.h>
#include <iostream>
using namespace std;
///Minhas bibliotecas;
#include "tadfila.h"
#include "tad_estadio.h"
//#include "design.h" Bilioteca gráfica para usar quando rodar o programa em um windows.
// Mas há a necessidade de adaptar o código.
#include "linux.h"


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
        getchar();
        tempo--;
    }
    resultado(filaN, filaST, qtdN, qtdST, saidaN, saidaST, media1, media2);

}

void selection (int realPosition, int arrowPosition) ///Função para seta no menu;
{
    Color::Modifier red(Color::FG_RED);
    Color::Modifier defult(Color::FG_DEFAULT);
    Color::Modifier blue(Color::FG_BLUE);
    if (realPosition == arrowPosition)
    {
        
        cout << red << "       --->   " << defult;
    }
    else
    {
        cout << blue <<"       " << defult;
    }
}

int main()
{
    /*Color::Modifier red(Color::FG_RED);
    Color::Modifier defult(Color::FG_DEFAULT);
    Color::Modifier blue(Color::FG_BLUE);
    system("setterm -cursor off");
    int key=0, position=1, sair=1;
    //hide();
    do{
        while(key!=13){
            system("clear");
            gotoxy(0,0);
            
            cout << blue << "TRABALHO M2" << defult << endl;
            selection (1,position);
            cout << blue << "Estadio" << defult << endl;
            selection (2,position);
            cout << blue << "Creditos" << defult << endl;
            selection (3,position);
            cout << red <<"Sair" << defult << endl;
            key = getchar();
            if (key == 80 && position != 3)
                position ++;
            else if (key == 72 && position !=1)
                position --;

            }
        switch(position){
        case 1:
            system ("clear");
            fila();
            main();
            break;
        case 2:
            system("clear");
            gotoxy(9,0);
            cout << blue << "Alexandre Fernandes Da Silva" << endl;
            gotoxy(9,1);
            cout << "Patrick Medeiros De Luca" << defult << endl;
            system("pause");
            main();
            break;
        case 3:
            exit(0);
        }
    }while (sair!=0); */

    fila();
    return 0;
}
