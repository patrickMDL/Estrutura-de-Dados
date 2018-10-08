//                  Engenharia de Computação
//  Matéria: Estrutura de dados
//  Alunos: Alexandre Fernandes da Silva // Patrick Medeiros De Luca
//  Email:  alexandre.fernandes@edu.univali.br // pjepk2@gmail.com
//
#include <iostream>
using namespace std;
#include "tadlistaencadeada.h"
#include "tadpoker.h"

//Falta o bubble e o quicksorbt;
int main()
{
    TLista<TipoCarta> dealer, jogador1, jogador2, mesa;
    inicializa_listaE (dealer);
    inicializa_listaE (jogador1);
    inicializa_listaE (jogador2);
    inicializa_listaE (mesa);
    monta_baralho(dealer);
    embaralhar(dealer);
    distribuir(dealer, jogador1, 2);
    imprime(jogador1.inicio);
    distribuir(dealer, jogador2, 2);
    imprime(jogador2.inicio);
    distribuir(dealer, mesa, 5);
    imprime(mesa.inicio);
    cout << "Depois do Bubblesort" << endl;
    bubblesort(jogador1);
    imprime(jogador1.inicio);
    cout << "Depois do Quicksort" << endl;
    quicksort(jogador2,0, tamanho(jogador2)-1);
    imprime(jogador2.inicio);
    cout << "worked" << endl;
    return 0;
}
