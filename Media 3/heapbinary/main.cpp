#include <iostream>

using namespace std;
#include "tadheap.h"
#include "design.h"
#include "tadfila.h"

/**
-------------------------------------------------------------------------------
|                UNIVALI - Universidade do Vale do Itajaí;                    |
|                    Engenharia de Computação - 2018/2;                       |
|                               ALUNOS:                                       |
|            Alexandre Fernandes da Silva e Patrick M. De Luca.               |
|                                                                             |
|                             Estrutura de Dados                              |
-------------------------------------------------------------------------------
*/


int gety() //to get y-coordinate
{ CONSOLE_SCREEN_BUFFER_INFO csbi;
    int y;
    if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
     {   y = csbi.dwCursorPosition.Y;
     }
     return y;
}

void teste (){


    TArvore<int> arvore;
    inicializa_arvore(arvore);
    int dado, chave;
    int key=0;
    while (key != 27){
        system("cls");

        cout << "Digite o dado[int]: ";
        cin >> dado;
        cout << "Digite a chave[int]: ";
        cin >> chave;
        insere_arvore(arvore.raiz, chave, dado);
        cout << "Aperte 'esc' para finalizar ou enter para continuar inserindo." << endl;
        key = getch();

    }


    int h=10;
    plottree(arvore.raiz,h,h,h*(h+1)/2,gety());
    cout << endl;
    system("pause");


    //cout << "=============="<< endl;


    int arr[] = {12, 11, 13, 5, 6, 7};
       int n = sizeof(arr)/sizeof(arr[0]);
       heapSort(arr, n);
       //cout << "Vetor organizado => ";
      // printVetor(arr, n);
}

int main()
{

    SetConsoleTitleA("HeapBinary");
        hide();
        int position =1;
        int sair=0;
        int key=0;

        do{
                while (key != 13) ///ENQUANTO O ENTER NÃO FOR PRESSIONADO
            {
                system ("cls");
                textcolor(9,0);
                cout <<"\n\n\tHeapBinary \n\n";
                selection (1, position);///A POSIÇÃO DA OPÇÃO / A POSIÇÃO DA FLECHA
                cout <<"Inserir Numero\n";
                selection (2, position);
                cout <<"Creditos\n";
                selection (3, position);
                cout <<"Sair";

                key = getch();

                if (key == 80 && position != 3) //SETA PARA BAIXO NO TECLADO / não vai mais para baixo que a opção 6
                {
                    position ++; //POSITION ALMENTA E COLOCA A FLECHA PARA BAIXO
                }
                else if (key == 72 && position != 1) //SETA PARA CIMA NO TECLADO / não vai mais para baixo que a opção 1
                {
                    position --; //POSITION DIMINUI E COLOCA A FLECHA PARA CIMA
                }
        }
            switch(position){
            case 1:
                system("cls");
                teste();
                main();
                break;
            case 2:
                {
                    system("cls");

                    cout << "Criado por Alexandre Fernandes da Silva e Patrick M. De Luca." << endl;
                }
                system("pause");
                main();
                break;
            case 3:
                system("cls");
                exit(0);
                break;
            }
            sair=1;
        }while (sair == 0);


    return 0;
}
