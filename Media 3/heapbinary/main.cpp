#include <iostream>
using namespace std;
#include "tadheap.h"
//FAZER UM SOMADOR BINÁRIO PRA GERAR O CAMINHO E PREVER O PRÓXIMO;
//USAR STRING PRA SALVAR O CAMINHO E DEPOIS CONVERTER PRA INT;
//DA PRA ARMAZENAR A STRING USANDO 'E' PRA ESQUERDA E 'D' PRA DIREITA;
//FAZER OPÇÃO PRA INSERIR ELEMENTO SOLO OU VETOR;
//OPÇÃO PRA ZERAR A ÁRVORE; (LIBERAR MEMÓRIA);
//OPÇÃO PRA DELETAR A RAIZ; (JOGA NO VETOR, ELIMINA A PRIMEIRA POSIÇÃO E JOGA NA ÁRVORE DNV. NÃO PRECISA MUDAR AS CHAVES, SÓ OS DADOS);
//MUDAR A CHAVE PELO DADO (NA MINHA CABEÇA NÃO FAZ SENTIDO. VOU PRECISAR DE UMA VARIÁVEL PRO CAMINHO);


int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    heapSort(arr, n);
    cout << "Vetor organizado => ";
    printVetor(arr, n);

    string teste="teste";
    teste+="01";//Posso usar isso pra gravar o caminho.
    cout << teste;



    return 0;
}
