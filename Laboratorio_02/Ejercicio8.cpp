#include <iostream>
using namespace std;

void contarRec(int, int);

int main(void)
{
    int n;
    cout << endl;
    cout << "Ingrese el numero tope hasta el cual desea hacer el conteo: ";
    cin >> n;

    contarRec(1, n);
    return 0;
}

void contarRec(int i, int n)
{
    if(n == 0)
    {
        return;
    }
    if(i <= n){
        cout << i << endl;
        i = i + 1;
        contarRec(i, n);
    }
    else if(n > 1)
    {
        n = n - 1;
        cout << n << endl;
        contarRec(i, n);
    }
}







