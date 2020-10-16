#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"
#define ASCENDENTE 1
#define DESCENDENTE 0
#include <stdlib.h>
#include <fstream>
class Lista
{
public:
    Lista();
    ~Lista();

    void Insertar(Estudiante *e);
    void Borrar(int v);
    void Eliminar(Estudiante *e);
    void Modificar(int id);
    void Mostrar(int);
    Estudiante* Buscar(int id);
    bool BuscarEstudiante(int);
    bool ListaVacia();
    void Siguiente();
    void Anterior();
    Nodo* Primero();
    void Ultimo();
    bool Actual();
    void CrearArchivo(int);
    Estudiante* ValorActual();
    string Ben(int);

    void PrimeroAux();

private:
    pnodo plista;
};

#endif // LISTA_H
