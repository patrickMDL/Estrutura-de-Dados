#include <iostream>
using namespace std;
#include "tadheap.h"

int main()
{
    int vetor[] = { 4, 2, 5, 3, 6 };
    TArvore<int> arvore;
    inicializa_arvora(arvore);
    int n = sizeof(vetor) / sizeof(vetor[0]);
    int i = n / 2 - 1;
    heapify(vetor,i, 0);
    cout << "Vetor organizado => ";
    printVetor(vetor, i);
    //construir_heap(arvore.raiz, vetor, tam);
    //cout << "arvore => ";
    //prefixo(arvore.raiz);
    cout << endl;
    return 0;
}
