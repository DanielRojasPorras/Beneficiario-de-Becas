#ifndef NODO_H
#define NODO_H
#include "Estudiante.h"

class Nodo
{
  public:
    Nodo(Estudiante *v, Nodo* sig = nullptr, Nodo* ant = nullptr) :
        valor(v), siguiente(sig), anterior(ant) {}

/*    Estudiante getValor() { return valor; };
    void setValor(Estudiante v) { this->valor = v; };

    Nodo* getSig() { return siguiente; };
    void setSig(Nodo* s) { this->siguiente = s; };
    Nodo* getAnterior() { return anterior; };
    void setAnterior(Nodo* a) { this->anterior = a; };
*/

private:


    Estudiante *valor;
    Nodo* siguiente;
    Nodo* anterior;

    friend class Lista;
};
typedef Nodo* pnodo;
#endif // NODO_H
