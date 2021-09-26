#include <iostream>
using namespace std;

int mcd(int, int);

int main(void)
{
    int mayor = 0, menor = 0;

    cout << "Ingrese el numero mayor para sacar el MCD: " << endl;
    cin >> mayor;
    cout << "Ingrese el numero menor para sacar el MCD: " << endl;
    cin >> menor;

    cout << "El MCD es: " << mcd(mayor, menor);
}

int mcd(int mayor, int menor)
{
    if(menor > mayor)
        return 0;
    
    if(menor == 0)
        return mayor;
    else
    {
        mcd(menor, mayor%menor);
    }
    
}


