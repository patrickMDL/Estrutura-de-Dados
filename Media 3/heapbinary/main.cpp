#include <iostream>

using namespace std;
#include "tadheap.h"
#include "design.h"


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


void teste (TArvore<int> &arvore){
    int dado, chave;
    int position =1;
    int sair=0;
    int key=0;
    system("cls");

    do{
        while (key != 13) ///ENQUANTO O ENTER NÃO FOR PRESSIONADO
        {
            system ("cls");
            textcolor(9,0);
            cout <<"\n\n\tHeapBinary \n\n";
            selection (1, position);///A POSIÇÃO DA OPÇÃO / A POSIÇÃO DA FLECHA
            cout <<"Inserir Numero\n";
            selection (2, position);
            cout <<"Remover Numero";
            selection (3, position);
            cout <<"Mostrar TOPO";
            selection (4, position);
            cout <<"Mostrar arvore";
            selection ( 5, position);
            cout <<"Atualizar chave pelo dado" << endl;
            selection ( 6, position);
            cout <<"Voltar";

            key = getch();

            if (key == 80 && position != 6) ///Detecta o precionamento da seta pra baixo;
            {
                position ++; ///Movimenta a seta pra baixo;
            }
            else if (key == 72 && position != 1) ///Detecta o precionamento da seta pra cima;
            {
                position --; ///Movimenta seta pra cima;
            }
            if (key == 27){
                sair =1;
            }
        }
        switch(position){
        case 1:
            system("cls");
            cout << "Digite o dado[int]: ";
            cin >> dado;
            cout << "Digite a chave[int]: ";
            cin >> chave;
            insere_arvore(arvore.raiz, chave, dado);
            teste(arvore);
            break;
        case 2:
        {
            system("cls");
            cout << "Digite a chave do nó que deseja remover[int]: " << endl;
            cin >> chave;
            procura_remove(arvore.raiz, chave);
        }
            system("pause");
            teste(arvore);
            break;
        case 3:
        {
            system("cls");
            if (arvore.raiz == nullptr){
                cout << "Arvore vazia." << endl;
                system("pause");
                teste(arvore);
                break;
            }
            THeap<int> *no = arvore.raiz;
            cout << "Dado: " << no->dado << "\nChave: " << no->chave << endl;
            system("pause");
            teste(arvore);
        }
            break;
        case 4:
        {
            system("cls");
            if (arvore.raiz == nullptr){
                cout << "Arvore vazia." << endl;
                system("pause");
                teste(arvore);
                break;
            }
            int h=alturaArvore(arvore.raiz)+1;
            ordena_arvore(arvore.raiz);///É necessário chamar duas vezes, pois as vezes uma comparação entre '1' e '2' por exemplo, faz o 2 ficar numa posição errada ja que posteriormente o
            ordena_arvore(arvore.raiz);///'1' vai continuar subindo e o '2' pode acabar filho de um '4'. O que estaria errado para um HeapBinary;
            cout << "\n\n\n\n\n";
            plottree(arvore.raiz,h,h,h*(h+1)/2, gety()); ///Imprime a árvore pronta e ordenada;
            cout << "\n\n\n\n\n";
            cout << endl;
            system("pause");///Pause no programa para vizualisar a árvore;
            teste(arvore);
        }
        break; case 5:
        {
            system("cls");
            if (arvore.raiz==nullptr){
                cout << "Arvore vazia." << endl;
                break;
            }
            cout << "Digite o dado para a procura: ";
            cin >> dado;
            cout << "Digite a nova chave: ";
            int novachave=0;
            cin >> novachave;
            THeap<int> *aux=arvore.raiz;
            procura_remove(arvore.raiz, aux->chave);
            insere_arvore(arvore.raiz, novachave, dado);
            teste(arvore);
        }
        break; case 6:
        {
            break;
        }
        }
        sair=1;





    }while (sair == 0);

}

int main()
{

    SetConsoleTitleA("HeapBinary");
        hide();
        TArvore<int> arvore;
        inicializa_arvore(arvore);
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
                cout <<"Inserir Dados\n";
                selection (2, position);
                cout <<"Creditos\n";
                selection (3, position);
                cout <<"Sair";

                key = getch();

                if (key == 80 && position != 3) ///Detecta o precionamento da seta pra baixo;
                {
                    position ++; ///Movimenta a seta pra baixo;
                }
                else if (key == 72 && position != 1) ///Detecta o precionamento da seta pra cima;
                {
                    position --; ///Movimenta seta pra cima;
                }
        }
            switch(position){
            case 1:
                system("cls");
                teste(arvore);
                main();
                break;
            case 2:
                {
                    system("cls");
                    textcolor(12,0);
                    cout << "Criado por Alexandre Fernandes da Silva e Patrick M. De Luca." << endl;
                }
                system("pause");
                main();
                break;
            case 3:
                system("cls");
                exit(0);
            }
            sair=1;
        }while (sair == 0);


    return 0;
}
