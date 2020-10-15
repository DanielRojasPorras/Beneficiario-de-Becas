#include "Interfaz.h"

Interfaz::Interfaz()
{
    //ctor
}

Interfaz::~Interfaz()
{
    //dtor
}

Interfaz::Interfaz(const Interfaz& other)
{
    //copy ctor
}
void Interfaz::Menu()
{

    int opcion;


    do
    {
        system("cls");        // Para limpiar la pantalla

        // Texto del menú que se verá cada vez

        cout << "\n\nMenu de Opciones" << endl;
        cout << "1. Ingresar" << endl;
        cout << "2. Mostrar" << endl;
        cout << "3. Editar" << endl;
        cout << "4. Borrar" << endl;
        cout << "5. SALIR" << endl;

        cout << "\nIngrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            // Lista de instrucciones de la opción 1
            Insertar();
            system("pause>nul"); // Pausa
            break;

        case 2:
            // Lista de instrucciones de la opción 2
            l->Mostrar(1);
            system("pause>nul"); // Pausa
            break;

        case 3:{
            // Lista de instrucciones de la opción 3
            int id;
            cout<<"Identificacion del estudiante\n";
            cin>>id;
            l->Modificar(id);
            system("pause>nul"); // Pausa
            break;
        }
        case 4:
            // Lista de instrucciones de la opción 4
            int id;
            cout<<"Identificacion del Estudiante\n";
            cin>>id;
            l->Borrar(id);
            system("pause>nul"); // Pausa
            break;
        }
    }
    while (opcion != 5);              // En vez de 5 pones el número de la opción de SALIDA

//Basado en: https://algoritmosyalgomas.com/plantilla-de-un-menu-de-opciones-en-c/
}
void Interfaz::Insertar()
{
    int id;
    string nombre;
    string apellido;
    string telefono;
    string correo;
    string responsable;
    string numCuenta;
    string tipoBeca;

    cout<<"Identificacion: \n";
    cin>>id;
    cout<<"Nombre\n";
    cin>>nombre;
    cout<<"Apellido\n";
    cin>>apellido;
    cout<<"Telefono\n";
    cin>>telefono;
    cout<<"Correo\n";
    cin>>correo;
    cout<<"Responsable\n";
    cin>>responsable;
    cout<<"Numero de Cuenta\n";
    cin>>numCuenta;
    cout<<"Tipo de Beca\n\n";
    int opcion=0;
    cout<<"**TIPO DE BENEFICIO*\n";
    cout<<"1- Beca tipo A \n";
    cout<<"2- Beca tipo B \n";
    cout<<"3- Beca tipo C \n";
    cout<<" Seleccione la opcion que desea \n";
    cin>>opcion;
    if(opcion == 1)
    {
         tipoBeca =" Beca tipo A \n Ayuda economica de: 100.000 colones";

    }
    else if(opcion ==2 )
    {
         tipoBeca = " Beca tipo B \n Ayuda economica de: 50.000 colones";

    }
    else if(opcion == 3)
    {
        tipoBeca =" Beca tipo C \n Ayuda economica de: 25.000 colones";

    }


    Estudiante *e = new Estudiante(id,nombre,apellido,telefono,correo,responsable,numCuenta,tipoBeca);

    l->Insertar(e);
    l->CrearArchivo(id);

}
