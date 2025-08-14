/*crea dos nodos y enlazalos*/
#include <iostream>
using namespace std;
struct Nodo
{
    int dato;
    Nodo* siguiente;
};

int main(){
    Nodo* nodo1= new Nodo();
    nodo1->dato=1;

    Nodo* nodo2= new Nodo();
    nodo2->dato=8;

    nodo1->siguiente=nodo2;
    nodo2->siguiente=NULL;

}