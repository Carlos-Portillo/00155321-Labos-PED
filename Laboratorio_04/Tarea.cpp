#include <iostream>
#include <string>

using namespace std;

int menu(){
    int opcion = 0;
    cout << endl << "1) Agregar un usuario." << endl;
    cout << "2) Agregar un usuario al final de la lista." << endl;
    cout << "3) Mostrar usuarios de inicio a fin." << endl;
    cout << "4) Mostrar usuarios de fin a inicio." << endl;
    cout << "5) Eliminar usuario." << endl;
    cout << "6) Buscar usuario." << endl;
    cout << "7) Salir." << endl;
    cout << "Opcion: ";
    cin >> opcion; cin.ignore();
    return opcion;
}

struct Lista{
    string usuario;
    int id;
    string perfil;
};

Lista solicitarLista(void){
    Lista p;
    int aux;
    cout << "Nombre del usuario: "; 
    getline(cin, p.usuario);
    cout << "ID: ";
    cin >> p.id; cin.ignore();
    cout << "Perfil del usuario"<< endl;
    cout << "\n1. Administrador \n2. Cliente \n3. Trabajador" << endl;
    cin >> aux;
        switch(aux)
    {
        case 1:
            p.perfil = "Administrador";
            break;
        case 2:
            p.perfil = "Cliente";
            break;
        case 3:
            p.perfil = "Trabajador";
    }
    return p;
}

void mostrarLista(Lista p){
    cout << "usuario: " << p.usuario << endl;
    cout << "ID (" << p.id << ")." << endl;
    cout << "Perfil: " << p.perfil << endl;
    cout << endl;
}

//Uso de typedef para generalizar la lista doble con una plantilla

typedef Lista T;
const T noValido = {"",0,""};

struct nodo{
    T dato;
    nodo *sig;
    nodo *ant;
};

class ListaDoble{
    private:
        nodo *pInicio;
    public:
        ListaDoble();
        ~ListaDoble();
        void insertFront(T);
        void insertBack(T);
        void traversalForwardDirection(void);
        void traversalReverseDirection(void);
        void deleteItem(T);
        bool empty(void);
        bool searchItem(T);
};

ListaDoble::ListaDoble(void){
    pInicio = NULL;
}

ListaDoble::~ListaDoble(void){
    nodo *p;
    while(pInicio){
        p = pInicio;
        pInicio = pInicio->sig;
        delete p;
    }
}

void ListaDoble::insertFront(T dato){
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->sig = pInicio;
    if(pInicio != NULL)
        pInicio->ant = nuevo;
    pInicio = nuevo;
}

void ListaDoble::insertBack(T dato){
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    if(!pInicio){
        pInicio = nuevo;
        pInicio->sig = pInicio->ant = NULL;
    }
    else{
        nodo *saltarin = pInicio;
        while(saltarin->sig != NULL)
            saltarin = saltarin->sig;
        saltarin->sig = nuevo;
        nuevo->ant = saltarin;
        nuevo->sig = NULL;
    }
}

void ListaDoble::traversalForwardDirection(void){
    nodo *saltarin = pInicio;
    while(saltarin != NULL){
        mostrarLista(saltarin->dato);//cout << saltarin->dato << endl;
        saltarin = saltarin->sig;
    }
}

void ListaDoble::traversalReverseDirection(void){
    if(!pInicio)
        return;
    nodo *p = pInicio;
    nodo *q = NULL;
    while(p){
        q = p;
        p = p->sig;
    }
    while(q){
        mostrarLista(q->dato);//cout << q->dato << endl;
        q = q->ant;
    }
}

void ListaDoble::deleteItem(T datoB){
    if(!pInicio){ // Lista vacía.
        cout << "Actualmente no hay uusarios." << endl;
    }
    else{ // Si la lista no está vacía, entonces:
        nodo *saltarin = pInicio;
        while(saltarin && (saltarin->dato).usuario.compare(datoB.usuario)!=0) // Saltar.
            saltarin = saltarin->sig; // Luego de saltar hay varias posibilidades:
        if(!saltarin) // a) saltarín se salió (el dato no está en la lista).
            cout << "El usuario no esta en la lista" << endl;
        else{ // Si saltarín no se salió (está sobre el dato a eliminar):
              // el nodo puede estar al principio, puede estar al final,
              // puede estar entre dos nodos, puede ser el único nodo.
            if(!saltarin->ant && saltarin->sig){ // Al principio (y hay más nodos).
                pInicio = pInicio->sig;
                pInicio->ant = NULL;
                delete saltarin;
            }
            else
                if(saltarin->ant && !saltarin->sig){
                    saltarin->ant->sig = NULL;
                    delete saltarin;
                }
                else
                    if(saltarin->ant && saltarin->sig){
                        saltarin->ant->sig = saltarin->sig;
                        saltarin->sig->ant = saltarin->ant;
                        delete saltarin;
                    }
                    else{
                        pInicio = NULL;
                        delete saltarin;
                    }
            cout << "Usuario eliminado exitosamente!" << endl;
        }
    }
}

bool ListaDoble::empty(void){
    return pInicio == NULL;
}

bool ListaDoble::searchItem(T datoB){
    if(!pInicio){ // Lista vacía.
        cout << "Actualmente no hay usuarios." << endl;
        return false;
    }
    else{ // Si la lista no está vacía, entonces:
        nodo *saltarin = pInicio;
        while(saltarin && (saltarin->dato).usuario.compare(datoB.usuario)!=0) // Saltar.
            saltarin = saltarin->sig; // Luego de saltar hay varias posibilidades:
        if(!saltarin) // a) saltarín se salió (el dato no está en la lista).
            return false;
        else
            return true;
    }
}

int main(void){
    ListaDoble usuario;
    
    bool continuar = true;
    Lista p;
    Lista pref;
    do{
        switch(menu()){
            case 1: 
                p = solicitarLista();
                usuario.insertFront(p);
                cout << "Usuario almacenado exitosamente!" << endl;
                break;
            case 2: 
                p = solicitarLista();
                usuario.insertBack(p);
                cout << "Usuario almacenado exitosamente!" << endl;
                break;
            case 3: 
                usuario.traversalForwardDirection();
                break;
            case 4: 
                usuario.traversalReverseDirection();
                break;
            case 5: 
                if(usuario.empty())
                    cout << "No hay usuarios por eliminar" << endl;
                else{
                    p = solicitarLista();
                    usuario.deleteItem(p);
                }
                break;
            case 6: 
                if(usuario.empty())
                    cout << "No hay usuarios por buscar" << endl;
                else{
                    p = solicitarLista();
                    cout << "Dicho usuario " << (usuario.searchItem(p)?"SI":"NO");
                    cout << " se encuentra en la lista." << endl;
                }
                break;
            case 7:
                continuar = false;
                break;
            default: 
                cout << "La opcion no es valida, favor intente denuevo." << endl;
                break;
        }
    }while(continuar);
    
    return 0;
}
