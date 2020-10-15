#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <iostream>
#include <sstream>

using namespace std;

class Estudiante
{
    public:
        Estudiante();
        Estudiante(int,string,string,string,string,string,string,string);
        virtual ~Estudiante();

        void setId(int);
        void setNombre(string);
        void setApellido(string);
        void setTelefono(string);
        void setCorreo(string);
        void setResponsable(string);
        void setNumCuenta(string);
        void setTipoBeca(string);

        int getId();
        string getNombre();
        string getApellido();
        string getTelefono();
        string getCorreo();
        string getResponsable();
        string getNumCuenta();
        string getTipoBeca();

        string toString();


    protected:

    private:
        int id;
        string nombre;
        string apellido;
        string telefono;
        string correo;
        string responsable;
        string numCuenta;
        string tipoBeca;
};

#endif // ESTUDIANTE_H
