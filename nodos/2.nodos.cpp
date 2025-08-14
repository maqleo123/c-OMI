/*Recoore el sistema de nodos (while)*/
#include <iostream>
using namespace std;

struct Nodo
{
    int dato;
    Nodo *siguiente;
};

int main()
{
    Nodo *nodo1 = new Nodo();
    nodo1->dato = 1;

    Nodo *nodo2 = new Nodo();
    nodo2->dato = 2;

    nodo1->siguiente = nodo2;
    nodo2->siguiente = NULL;

    Nodo *actual = nodo1;

    while (actual != NULL)
    {
        cout << actual->dato << "->";
        actual = actual->siguiente;
    }
    cout << "NULL";
}