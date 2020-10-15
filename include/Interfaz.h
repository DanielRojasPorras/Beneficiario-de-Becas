#ifndef INTERFAZ_H
#define INTERFAZ_H
#include "Lista.h"

class Interfaz
{
    public:
        Interfaz();
        virtual ~Interfaz();
        Interfaz(const Interfaz& other);

        void Insertar();
        void Menu();
        Lista *l = new Lista();

    protected:

    private:
};

#endif // INTERFAZ_H
