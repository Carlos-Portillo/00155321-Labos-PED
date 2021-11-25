#include <iostream>

using namespace std;

struct nodo {
    int dato;
    nodo *subLeft;
    nodo *subRight;
};

class BinarySearchTree{
    private:
        nodo *pBinarySearchTree;
    public:
    BinarySearchTree();
    ~BinarySearchTree();
    void insertar(void);
    void insertarBST(nodo **, int);
    void showPreorder(nodo *);
    void showInorder(void);
    void showIn(nodo *);
    void showPost(nodo *);
    void showPostOrder(void);
    void showPreorder(void);
    void showPre(nodo *);
    void search(int);
    void searchN(nodo *, int);
    void deleteNode(int);
    void deleteN(nodo **, int);
};

BinarySearchTree::BinarySearchTree(void)
{
    pBinarySearchTree = NULL;
}

BinarySearchTree::~BinarySearchTree()
{
    cout << "Program Execution" << endl;
}

void BinarySearchTree::insertar(void)
{
    int dato;
    char resp;

    do{
        cout << "Escriba y para continuar" << endl;
        cout << "Desea digitar un dato? ";
        cin >> resp;
        if(resp == 'y'){
            cout << "Elemento que desea ingresar: ";
            cin >> dato;
            insertarBST(&pBinarySearchTree, dato);
        }

    }while(resp == 'y');
}

void BinarySearchTree::insertarBST(nodo **p, int dato)
{
    if(!(*p)){
        *p = new nodo;
        (*p)->dato = dato;
        (*p)->subLeft = NULL;
        (*p)->subRight = NULL; 
    }
    else{
        if(dato < (*p)->dato)
            insertarBST(&((*p)->subLeft), dato);
        else
            if(dato > (*p)->dato)
                insertarBST(&((*p)->subRight), dato);
            else
                cout << "El dato ya esta ingresado" << endl << endl;
    }
}

void BinarySearchTree::showInorder(void)
{
    showIn(pBinarySearchTree);
}

void BinarySearchTree::showIn(nodo *p)
{
    if(p){
        showIn(p->subLeft);
        cout << p->dato << " ";
        showIn(p->subRight);
    }
}

void BinarySearchTree::showPreorder(void)
{
    showPre(pBinarySearchTree);
}

void BinarySearchTree::showPre(nodo *p)
{
    if(p){
        cout << p->dato << " ";
        showPre(p->subLeft);
        showPre(p->subRight);
    }
}

void BinarySearchTree::showPostOrder(void)
{
    showPost(pBinarySearchTree);
}

void BinarySearchTree::showPost(nodo *p)
{
    if(p)
    {
        showPost(p->subLeft);
        showPost(p->subRight);
        cout << p->dato << " ";
    }
}

void BinarySearchTree::search(int aux)
{  
    searchN(pBinarySearchTree, aux);
}

void BinarySearchTree::searchN(nodo *p, int aux)
{
    if(!p)
        cout << "Dato no encontrado." << endl;
    else
        if(aux < p->dato)
            searchN(p->subLeft, aux);
        else
            if(aux > p->dato)
                searchN(p->subRight, aux);
            else
                cout << "Dato encontrado." << endl;
}

void BinarySearchTree::deleteNode(int dato)
{
    deleteN(&pBinarySearchTree, dato);
}

void BinarySearchTree::deleteN(nodo **r, int dato)
{
    nodo *p;

    if(!(*r)) 
        cout << "El dato NO está en el árbol" << endl << endl;
    else
        if(dato < (*r)->dato) 
            deleteN(&((*r)->subLeft), dato);
        else
            if(dato > (*r)->dato) 
                deleteN(&((*r)->subRight), dato);
            else{ 
                if(!((*r)->subLeft) && !((*r)->subRight)){ 
                    p = *r;
                    *r = NULL;
                }
                else
                    if(!((*r)->subLeft) && (*r)->subRight){ 
                        p = *r; 
                        *r = (*r)->subRight;
                    }
                    else
                        if((*r)->subLeft && !((*r)->subRight)){ 
                            p = *r; 
                            *r = (*r)->subLeft; 
                        }
                        else
                            if((*r)->subLeft && (*r)->subRight){ 
                                p = (*r)->subLeft; 
                                if(!p->subRight){
                                    (*r)->dato = p ->dato;
                                    (*r)->subLeft = p->subLeft;
                                }
                                else{
                                    nodo *q;
                                    while(p->subRight){
                                        q = p;
                                        p = p->subRight;
                                    }
                                    (*r)->dato = p->dato;
                                    q->subRight = p->subLeft;
                                }
                            }
                delete p;
            }
}

int main(void)
{
    int aux, auxB;
    cout << endl;
    cout << "Binary Search Tree :D" << endl << endl;

    BinarySearchTree objBinarySearchTree;


    cout << "Insertar datos en el arbol:" <<  endl;
    objBinarySearchTree.insertar();

    cout << "Mostrar Pre-orden: " << endl;
    objBinarySearchTree.showPostOrder();
    cout << endl;

    cout << "Mostrar In-Orden: " << endl;
    objBinarySearchTree.showInorder();
    cout << endl;

    cout << "Mostrar Post-Orden: " << endl;
    objBinarySearchTree.showPostOrder();
    cout << endl;

    cout << "Ingrese el dato que desea buscar: " << endl;
    cin >> aux;
    objBinarySearchTree.search(aux);
    cout << endl;

    cout << "Ingrese el dato que desea eliminar: " << endl;
    cin >> auxB;
    objBinarySearchTree.deleteNode(auxB);
    cout << endl;

    cout << "Mostrar Pre-orden: " << endl;
    objBinarySearchTree.showPostOrder();
    cout << endl;

    return 0;
}