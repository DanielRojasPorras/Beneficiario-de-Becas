#include "Lista.h"
Lista::Lista() : plista(nullptr)
{
    //ctor
}

bool Lista::Actual() { return plista != nullptr; }
//Estudiante* Lista::ValorActual() { return plista->valor; }
bool Lista::ListaVacia() { return plista == nullptr; }

Lista::~Lista()
{
    pnodo aux;

    Primero();
    while (plista) {
        aux = plista;
        plista = plista->siguiente;
        delete aux;
    }
}

void Lista::Insertar(Estudiante *e)
{
    pnodo nuevo;

    PrimeroAux();
    // Si la lista está vacía
    if (ListaVacia() || plista->valor->getId() > e->getId()) {
        // Asignamos a lista un nuevo nodo de valor v y
        // cuyo siguiente elemento es la lista actual
        nuevo = new Nodo(e, plista);
        if (!plista) plista = nuevo;
        else plista->anterior = nuevo;
    }
    else {
        // Buscar el nodo de valor menor a v
        // Avanzamos hasta el último elemento o hasta que el siguiente tenga
        // un valor mayor que v
        while (plista->siguiente && plista->siguiente->valor->getId() <= e->getId()) Siguiente();
        // Creamos un nuevo nodo después del nodo actual
        nuevo = new Nodo(e, plista->siguiente, plista);
        plista->siguiente = nuevo;
        if (nuevo->siguiente) nuevo->siguiente->anterior = nuevo;
    }
}

void Lista::Borrar(int id)
{
 bool encontrado = false;
    if(!ListaVacia()){
        pnodo N;
        pnodo nAux;
        nAux = Primero();
        Primero();
        N = plista;
        encontrado = false;
        while(N){
            if(N->valor->getId()== id){
               delete N;
               N = nullptr;
               nAux = nAux->siguiente;
               encontrado = true;
               cout<<"Los datos han sido eliminados \n";
               break;

            }
            else{
                N = N->siguiente;
            }

        }
    }
}

void Lista::Mostrar(int orden)
{
    pnodo nodo;
    if (orden == ASCENDENTE) {
        PrimeroAux();
        nodo = plista;
        while (nodo) {
            cout << nodo->valor->toString() << "\n";
            nodo = nodo->siguiente;
        }
    }
    else {
        Ultimo();
        nodo = plista;
        while (nodo) {
            cout << nodo->valor->toString() << "\n";
            nodo = nodo->anterior;
        }
    }


    cout << endl;
}
void Lista::Modificar(int id){
     bool encontrado = false;
     pnodo nodo = plista;

        string nombre;
        string apellido;
        string telefono;
        string correo;
        string responsable;
        string numCuenta;
        string tipoBeca;
 //   string idAux;


    do {
        if (id == nodo->valor->getId()) {
         cout << "Encontrado!!!\n";

            cout << nodo->valor->toString() << "\n";
            encontrado = true;
           // idAux = nodo->valor->getId();
            system("pause");
            system("cls");

            cout << "Ingrese los nuevos datos del Estudiante\n";
            cout << "Nombre: \n";
            cin >> nombre;
            nodo->valor->setNombre(nombre);

            cout << "Apellido\n";
            cin >> apellido;
            nodo->valor->setApellido(apellido);

            cout << "Telefono\n";
            cin >> telefono;
            nodo->valor->setTelefono(telefono);

            cout << "Correo\n";
            cin >> correo;
            nodo->valor->setCorreo(correo);

            cout << "Responsable\n";
            cin >> responsable;
            nodo->valor->setResponsable(responsable);

            cout << "Numero de Cuenta\n";
            cin >> numCuenta;
            nodo->valor->setNumCuenta(numCuenta);

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
         nodo->valor->setTipoBeca(tipoBeca);

    }
    else if(opcion ==2 )
    {
         tipoBeca = " Beca tipo B \n Ayuda economica de: 50.000 colones";
         nodo->valor->setTipoBeca(tipoBeca);

    }
    else if(opcion == 3)
    {
        tipoBeca =" Beca tipo C \n Ayuda economica de: 25.000 colones";
        nodo->valor->setTipoBeca(tipoBeca);

    }
            cout<<"Modificado!!!\n";
            break;
        }
        nodo = nodo->siguiente;
    } while (nodo != plista);
    if (!encontrado) {
        cout << "El estudiante no existe en el sistema";
    }
    cout << endl;
}
Estudiante* Lista::Buscar(int id){
    pnodo nodo;
    Ultimo();
    nodo = plista;
    if(BuscarEstudiante(id)){
        while(nodo){
            if(nodo->valor->getId() == id){
                return nodo->valor;
            }
            nodo = nodo->anterior;
        }
    }
}
void Lista::Eliminar(Estudiante * e){
    pnodo nodo;
    nodo = plista;
    while(nodo && nodo->valor->getId() < e->getId())
        nodo = nodo->siguiente;
    while(nodo && nodo->valor->getId() > e->getId())
        nodo = nodo->anterior;

    if(!nodo || nodo->valor->getId() != e->getId())
        return ;
    if(nodo->anterior)
        nodo->anterior->siguiente = nodo->siguiente;
    if(nodo->siguiente)
        nodo->siguiente->anterior = nodo->anterior;
    delete nodo;
}

bool Lista::BuscarEstudiante(int id){
    pnodo nodo;
    Ultimo();
    nodo = plista;
    while(nodo){
        if(nodo->valor->getId() == id){
            return true;
        }
        nodo = nodo->anterior;
    }
    return false;
}
void Lista::Siguiente()
{
    if (plista) plista = plista->siguiente;
}

void Lista::Anterior()
{
    if (plista) plista = plista->anterior;
}

Nodo* Lista::Primero()
{
    while (plista && plista->anterior) plista = plista->anterior;
}
void Lista::PrimeroAux()
{
    while (plista && plista->anterior) plista = plista->anterior;
}

void Lista::Ultimo()
{
    while (plista && plista->siguiente) plista = plista->siguiente;
}
void Lista::CrearArchivo(int id)
{
    string Archivo = "Estudiante "+ to_string(id)+".bin";
    ofstream archivo (Archivo, ios::binary);
    archivo<< Ben(id)<<endl;
    archivo.close();
}
string Lista::Ben(int c)
{
    stringstream x;
    Primero();
    pnodo N = plista;

        while(N->valor->getId()!= c)
        {
            N = N->siguiente;
        }

    x<<N->valor->toString()<<"\n";
    return x.str();
}
