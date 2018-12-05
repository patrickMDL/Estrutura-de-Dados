/**
-------------------------------------------------------------------------------
|                UNIVALI - Universidade do Vale do Itajaí;                    |
|                    Engenharia de Computação - 2018/1;                       |
|                               ALUNOS:                                       |
|            Leonardo Grando, Diogo Marchi e Patrick M. De Luca.              |
|                                                                             |
|                             Estrutura de Dados                              |
-------------------------------------------------------------------------------
*/
#include <iostream>
using namespace std;
#include "arvore.h"
#include "pilha.h"
#include <string>
#include "design.h"


bool naoENumero(char c) {
    if(c == '+' || c == '-' ||c == '/' ||c == '*' ||c == '(' ||c == ')' || c == ' ')
        return true;
    return false;
}
bool naoENumero2(char c) {
    if(c == '+' || c == '-' ||c == '/' ||c == '*')
        return true;
    return false;
}


int main()
{
    SetConsoleTitle ("Expression Tree");
    hide();
    int position =1;
    int sair=0;
    int key=0;

    do{
            while (key != 13) ///ENQUANTO O ENTER NÃO FOR PRESSIONADO
        {
            system ("cls");
            textcolor(9,0);
            cout <<"\n\n\tExpression Tree \n\n";
            selection (1, position);///A POSIÇÃO DA OPÇÃO / A POSIÇÃO DA FLECHA
            cout <<"Try new expression\n";
            selection (2, position);
            cout <<"Credits\n";
            selection (3, position);
            cout <<"Quit";

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
            {
                system("cls");
                string exp;




                    cout << "Type a expression: " << endl;
                    getline(cin,exp);
                    cout << exp << endl;

                string Y = "";
                Tpilha<char> pilha;
                Inicializa(pilha);
                Inseretopo(pilha,'(');
                exp+=")";


                for (unsigned i=0; i<exp.length(); i++) /// exp.length() isso pega tamanho da string
                {///função para arrumar expressão





                    char c = exp.at(i);///pega a posição da string
                int tam;
                tam = exp.length();


                    if(c == '+'||c == '-'||c == '*'||c == '/'||c == '('||c == ')'||c == '.'||c == '0'||c == ' '||c == '1'||c == '2'||c == '3'||c == '4'||c == '5'||c == '6'||c == '7'||c == '8'||c == '9'){


                        if (exp.at(tam-2) == '+' || exp.at(tam-2) == '-' || exp.at(tam-2) == '*' || exp.at(tam-2) == '/' || exp.at(tam-2) == '.'){

                            system("cls");
                            cout<<"SYNTAXE ERROR!"<<endl;
                            system("pause");
                            main();
                        }
                        if(exp.at(0)==')' || exp.at(0)=='.')
                        {
                            system("cls");
                            cout<<"SYNTAXE ERROR!"<<endl;
                            system("pause");
                            main();
                        }
                        if(exp.at(i)=='.' && (naoENumero(exp.at(i+1))==true))
                        {
                            system("cls");
                            cout<<"SYNTAXE ERROR!"<<endl;
                            system("pause");
                            main();
                        }

                        if(exp.at(0)=='*' || exp.at(0)=='/'){
                            system("cls");
                            cout<<"SYNTAXE ERROR!"<<endl;
                            system("pause");
                            main();
                        }
                        if(naoENumero2(exp.at(i))==true && naoENumero2(exp.at(i+1))==true)
                        {
                            system("cls");
                            cout<<"SYNTAXE ERROR!"<<endl;
                            system("pause");
                            main();
                        }



                        if(c == ' ')///se for espaço, continua
                            continue;
                            if (c=='('){
                            Inseretopo(pilha,c);///insere no topo da pilha se for 'abre parenteses'
                        } else if(c==')') {///e se for fecha parenteses
                            while(pilha.topo->dado!='('){///se a pilha for diferente de abre parenteses
                                Y += pilha.topo->dado;///expressao 'arrumada' recebe o dado
                                Removetopo(pilha);/// enquanto for diferente de abre parenteses remove da pilha e adiciona na expressao
                            }
                            Removetopo(pilha);///por fim, remove da pilha
                        } else if(c=='/'||c=='*') { /// operadores de mais importancia
                            while(pilha.topo->dado!='+' && pilha.topo->dado !='-' && pilha.topo->dado!='('){///enquanto topo da pilha for diferente de '+','-', e '('
                                Y += pilha.topo->dado;///expressao recebe o dado
                                Removetopo(pilha);///remove topo
                            }
                            Inseretopo(pilha,c);///insere no topo da pilha
                        }else if(c=='-'||c=='+') { /// operadores
                                while(pilha.topo!=NULL && pilha.topo->dado!='('){///enquanto topo for diferente de nulo e for diferente de '('
                                Y += pilha.topo->dado;///adiciona da expressao o dado
                                Removetopo(pilha);///remove da pilha
                            }
                            Inseretopo(pilha,c);///insere na pilha
                        }else {
                            Y += c;///se nao for nada, é numero, ai adiciona na expressao

                            if(i + 1 == exp.size() || naoENumero(exp.at(i+1))) { /// se o proximo nao for numero

                                Y+=255; /// delimitar quando um numero acaba
                            }
                        }
                    }
                    else{

                        cout << "LEXICAL ERROR !There`s something wrong in the expression. Try again." << endl;
                        system("pause");
                        main();
                    }
                }

                cout << Y << endl;

                Tpilha<Pno<string>* > pilha2;
                Inicializa(pilha2);
                int h=0;
                int largura=Y.length();
                for (int i=0; i<largura; i++) /// Y.length() isso pega tamanho da string
                {///criar arvore
                    char c = Y.at(i);///pega a posicao da string e coloca no char 'c'
                    Pno<string> *P = new Pno<string>;///declara novo nó
                    P->dado = c;///dado vai ser o char na posição
                    P->direita = NULL;///direita nulo
                    P->esquerda = NULL;///esquerda nulo
                    if(c == '/'||c == '*'||c == '+'||c == '-') {///se for operador
                        P->direita = pilha2.topo->dado;///dirieta recebe dado
                        Removetopo(pilha2);///remove um dado da pilha
                        P->esquerda = pilha2.topo->dado;///esquerda recebe outro dado
                        Removetopo(pilha2);///remove outro dado
                    } else {
                        float sep = Y.find(255, i); /// encontra posicao do primeiro espaco começando da pos i
                        string num = Y.substr(i, sep - i); /// pega um pedaço da string começando em i e tirando (sep - i) letras
                        P->dado = num;///dado do no sera o numero
                        i = sep; /// continua a partir do delimitador do numero
                    }
                    Inseretopo(pilha2, P);///insere o no com as folhas
                    h++;


                }

                plottree(pilha2.topo->dado,h,h,h*(h+1)/2,gety());
                textcolor(12,0);
                for (int i=0; i<h; i++)
                    cout << "\n";
                cout << "\nResultado:";
                cout << resolve_exp(pilha2.topo->dado) << endl; /// começa a resolver a partir da raiz que esta no topo da pilha
        }
            system("pause");
            main();
            break;
        case 2:
            {
                system("cls");

                cout << "Created by Leonardo Grando, Diogo Marchi e Patrick M. De Luca" << endl;
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
