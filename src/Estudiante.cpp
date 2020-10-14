#include "Estudiante.h"

Estudiante::Estudiante()
{
    id = "";
    nombre = "";
    apellido = "";
    telefono = "";
    correo = "";
    responsable = "";
    numCuenta = "";
    tipoBeca = "";
}

Estudiante::~Estudiante()
{
    //dtor
}
Estudiante::Estudiante(string id, string nom, string apellido, string tel, string correo,
                       string resp, string numCuenta, string tipo)
{
    this->id = id;
    this->nombre = nom;
    this->apellido = apellido;
    this->telefono = tel;
    this->correo = correo;
    this->responsable = resp;
    this->numCuenta = numCuenta;
    this->tipoBeca = tipo;
}

void Estudiante::setId(string id)
{
    this->id = id;

}

void Estudiante::setNombre(string nom)
{
    this->nombre = nom;


}

void Estudiante::setApellido(string apellido)
{
    this->apellido = apellido;

}

void Estudiante::setTelefono(string tel)
{
    this->telefono = tel;

}

void Estudiante::setCorreo(string correo)
{
    this->correo = correo;

}
void Estudiante::setResponsable(string resp)
{
    this->responsable = resp;

}

void Estudiante::setNumCuenta(string numCuenta)
{
    this->numCuenta = numCuenta;

}


void Estudiante::setTipoBeca(string tipo)
{
    this->tipoBeca = tipo;
}

string Estudiante::getId()
{
    return id;
}

string Estudiante::getNombre()
{
    return nombre;
}

string Estudiante::getApellido()
{
    return apellido;
}

string Estudiante::getTelefono()
{
    return telefono;
}

string Estudiante::getCorreo()
{
    return correo;
}

string Estudiante::getResponsable()
{
    return responsable;
}

string Estudiante::getNumCuenta()
{
    return numCuenta;
}

string Estudiante::getTipoBeca()
{
    return tipoBeca;
}

string Estudiante::toString()
{
    stringstream s;
    s<<"Identificacion: "<<getId()<<endl;
    s<<"Nombre: "<<getNombre()<<endl;
    s<<"Apellido: "<<getApellido()<<endl;
    s<<"Telefono: "<<getTelefono()<<endl;
    s<<"Correo: "<<getCorreo()<<endl;
    s<<"Nombre del Responsable: "<<getResponsable()<<endl;
    s<<"Numero de Cuenta: "<<getNumCuenta()<<endl;
    s<<"Tipo de Beca: "<<getTipoBeca()<<endl;

    return s.str();
}
