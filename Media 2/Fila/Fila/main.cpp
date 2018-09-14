#include "tadfila.h"
#include <iostream>
using namespace std;

int main()
{
    TFila<string> fila;
    inicializa(fila);
    Queue(fila, string("Patrick"));
    Queue(fila, string("Alexandre"));
    Queue(fila, string("Carol"));
    Queue(fila, string("Enzo"));

    cout << DeQueue(fila) << endl;
    cout << DeQueue(fila) << endl;
    cout << DeQueue(fila) << endl;
    cout << DeQueue(fila) << endl;


    return 0;
}
