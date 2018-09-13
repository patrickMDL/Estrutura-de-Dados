#ifndef TAD
#define TAD
#include <iostream>
using namespace std;

struct TMusica{
    string artista;
    string nome;
};
bool operator> (TMusica a, TMusica b) {
    if (a.nome > b.nome)
    {
    return true;
    }
    else
        return false;
}

ostream& operator<< (ostream& os, TMusica musica)
{
    os << "Musica: " << musica.nome << ", Artista: " << musica.artista;
    return os;
}



#endif // TAD
