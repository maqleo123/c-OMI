/*
1. Números primos en un rango
>Pide dos números enteros a y b.
>Muestra todos los números primos entre a y b.
>Extra: usa una función bool esPrimo(int n).
*/
#include <iostream>
using namespace std;

bool esPrimo(int n)
{
    if (n <= 1) 
        return false;

    for (int i = 2; i * i <= n; i++) 
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int a, b;
    cout << "ingresa un rango de numeros: ";
    cin >> a >> b;

    cout << "->los numeros primos entre el rangio que ingresaste es: ";
    for (int i = a; i < b; i++)
    {
        if (esPrimo(i))
        {
            cout << i << ", ";
        }
    }
}