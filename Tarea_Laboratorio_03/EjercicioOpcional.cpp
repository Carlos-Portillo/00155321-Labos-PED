#include <iostream>
#include <string>
using namespace std;

void menu(void)
{
    cout << endl;
    cout <<" REGISTRO DE ORDENES"<<endl<<endl;
    cout <<"1. INGRESAR ORDEN" << endl;
    cout <<"2. MOSTRAR ORDENES" << endl;
    cout <<"3. SALIR Y DEJAR DE ORDENAR" << endl;

    cout << "Ingrese opcion: ";
}

struct nodo{
    int pupusas;
    string tipoPupusas;
    string bebida;
    string ingrediente;
    nodo *sig;
};

class ListaSimple{

    private:
        nodo *pInicio;
    
    public:
        ListaSimple();
        void registroOrdenes(void);
        void insInicio(void);
        void mostrarOrdenes(void);
};

ListaSimple::ListaSimple(void)
{
    pInicio = NULL;
}

void ListaSimple::insInicio(void)
{
    int pupusas, n;
    string tipoPupusas, bebida, ingrediente;
    nodo *nuevo;
    nuevo = new nodo;

    cout << endl;
    cout << "Registro de orden de pupusas" << endl; cin.ignore();

    cout << "Ingrese la cantidad de pupusas que pedira: ";
    cin >> nuevo->pupusas; cin.ignore();

    cout << "Escriba los ingrediente de las pupusas: ";
    getline(cin, nuevo->ingrediente);

    cout << "Escriba 1 si quiere ordenar sus pupusas de arroz o 2 de maiz: ";
    cin >> n;
    if(n == 1)
        nuevo->tipoPupusas = "Arroz";
    else if(n == 2)
        nuevo ->tipoPupusas = "Maiz";

    cout << "Escriba 1 si quiere ordenar su comida con coca cola y 2 sin coca cola: ";
    cin >> n;
    if(n == 1)
        nuevo->bebida = "Con coca cola";
    else if(n == 2)
        nuevo ->bebida = "Sin coca cola";

    nuevo ->sig = pInicio;
    pInicio = nuevo;
}

void ListaSimple::mostrarOrdenes(void)
{
    int i = 1;
    nodo *saltarin;
    saltarin = pInicio;
    while(saltarin != NULL)
    {
        cout << endl;
        cout << "ORDEN DE LA PERSONA NUMERO " << i << endl;
        cout << "Numero de pupusas: " << saltarin->pupusas << endl;
        cout << "El ingrediente de las pupusas es: " << saltarin->ingrediente << endl;
        cout << "Arroz o maiz: " << saltarin->tipoPupusas << endl;
        cout << "Con o sin Coca cola: " << saltarin->bebida << endl;
        cout << endl;

        saltarin = saltarin->sig;
        i++;
    }
}

int main(void)
{
    ListaSimple objListaSimple;
    
    int opcion = 0;
    cout << "Lista de ordenes de pupusas" << endl;

    do{
        menu();
        cin >> opcion;
        switch(opcion)
        {
            case 1:
                objListaSimple.insInicio();
                break;
            case 2:
                objListaSimple.mostrarOrdenes();
                break;
            case 3:
            return 0;
        }
    }while(opcion != 3);
}