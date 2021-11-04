#include <iostream>
#include <string>
using namespace std;

void menu(){
    cout << endl << "1) Agregar paciente." << endl;
    cout << "2) Buscar paciente." << endl;
    cout << "3) Eliminar paciente." << endl;
    cout << "4) Salir." << endl;
    cout << "INGRESE OPCION: ";
}

struct nodo
{
    int id;
    string nombreD;
    string raza;
    int peso;
    int edad;
    nodo *sig;
};

class lista_circular
{
    private:
    nodo *pInicio;

    public:
    lista_circular();
    void insPaciente();
    void mostrarLista(void);
    void borrarPaciente(void);
    void buscarPaciente(void);
};

lista_circular::lista_circular(void)
{
    pInicio = NULL;
}

void lista_circular::insPaciente(void)
{
    nodo *nuevo;
    nuevo = new nodo;
    
    cout << "Nombre del duenio: " << endl;
    cin.ignore(); getline(cin, nuevo->nombreD);

    cout << "Ingrese edad de la mascota: " << endl;
    cin >> nuevo->edad;

    cout << "ID de la mascota: " << endl;
    cin >> nuevo->id;

    cout << "Raza de la mascota: " << endl;
    cin.ignore(); getline(cin, nuevo->raza);

    cout << "Peso de la mascota: " << endl;
    cin >> nuevo->peso;

    if(pInicio==NULL)
    {
        pInicio = nuevo;
        pInicio->sig = pInicio;
    }
    else 
    {
        nuevo->sig = pInicio; 
        nodo *saltarin;
        saltarin = pInicio;
        while(saltarin->sig != pInicio) 
        {
            saltarin = saltarin->sig;
        }
        saltarin->sig = nuevo; 
        pInicio = nuevo;
    }
}

void lista_circular::mostrarLista(void)
{
    nodo *saltarin;

    cout << endl;
    if(pInicio) 
    {
        saltarin = pInicio;
        do{
            cout << "Nombre del duenio: " << saltarin->nombreD << endl;
            cout << "Edad de la mascota: "<< saltarin->edad << " anios" << endl;
            cout << "Id del paciente: " << saltarin->id << endl;
            cout << "Raza de la mascota: " << saltarin->raza << endl;
            cout << "Peso de la mascota: " << saltarin->peso << " kilos" << endl << endl;
            saltarin = saltarin->sig; 
        }while(saltarin != pInicio);
    }
}

void lista_circular::borrarPaciente(void)
{
    nodo *saltarin, *auxB;
    saltarin = pInicio;
    int aux = 0;
    int idB = 0;
    
    cout << "Ingrese el ID del paciente a eliminar" << endl;
    cin >> aux;

    if(pInicio)
    {
        saltarin = pInicio;
        do{
            if(saltarin->id == aux)
            {
                delete saltarin;
            }
            saltarin = saltarin->sig;
        }while(saltarin != pInicio);
    }
    else
        cout << "No hay paciente en la lista." << endl;
}

void lista_circular::buscarPaciente(void)
{
    nodo *saltarin;
    int aux = 0;

    cout << "Ingrese el ID del paciente a buscar" << endl;
    cin >> aux;
    
    if(pInicio) 
    {
        saltarin = pInicio;
        do{
            if(saltarin->id == aux)
            {
                cout << endl;
                cout << "Nombre del duenio: " << saltarin->nombreD << endl;
                cout << "Edad de la mascota: "<< saltarin->edad << " anios" << endl;
                cout << "Id del paciente: " << saltarin->id << endl;
                cout << "Raza de la mascota: " << saltarin->raza << endl;
                cout << "Peso de la mascota: " << saltarin->peso << " kilos" << endl << endl;
            }
            saltarin = saltarin->sig;
        }while(saltarin != pInicio);
    }
    else
        cout << "No hay pacientes en la lista." << endl;
}

int main(void)
{
    lista_circular ListaCir;

    int opcion = 0;
    cout << "\n---VETERINARIA---" << endl;

    do{
        menu();
        cin >> opcion;
        switch(opcion)
        {
            case 1:
                ListaCir.insPaciente();
                cout << "Paciente agregado exitosamente :D" << endl;
                break;
            case 2:
                ListaCir.buscarPaciente();
                break;
            case 3:
                ListaCir.borrarPaciente();
                break;
            case 4:
                return 0;
            default:
                cout << "Ingrese una opcion valida." << endl;
        }
    }while(opcion != 4);
}