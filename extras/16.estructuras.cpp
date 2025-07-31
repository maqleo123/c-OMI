#include <iostream>
#include <string>
using namespace std;

struct Bebida
{
    string nombre;
    float precio;
    string marca;
};

int main()
{
    //     int numero=15;
    //     struct Bebida bebida;
    //     bebida.precio=2;
    //     cout<<"El precio es "<<bebida.precio;
    //     cout<<"Ingresa el nombre de la bebida ";
    //     cin>>bebida.nombre;
    //     cout<<endl<<"El nombre que ingresaste es "<<bebida.nombre<<endl;
    int numero[15];
    struct Bebida bebida[5];
    for (int i = 0; i < 3; i++)
    {
        cout << "Ingrese nombre de la bebida ";
        cin >> bebida[i].nombre;
        cout << "Ingrese la marca de la bebida ";
        cin >> bebida[i].marca;
        cout << "Ingresa el precio de la bebida ";
        cin >> bebida[i].precio;
    }

    for (int i = 0; i < 3; i++)
    {
        cout << "el nombre de la bebida es ";
        cout << bebida[i].nombre << endl;
        cout << "la marca de la bebida es ";
        cout << bebida[i].marca << endl;
        cout << "el precio de la bebida es ";
        cout << bebida[i].precio << endl;
    }
}