/*
Haz un programa que cree una lista enlazada simple de números y que permita determinar cuál es el valor más alto que contiene la lista.
*/
#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* sig;
};

void Insertar(Nodo* &inicio, int val) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = val;
    nuevo->sig = inicio;
    inicio = nuevo;
}

int Mayor(Nodo* inicio) {
    if (!inicio) return -1;

    int mayor = inicio->dato;
    Nodo* temp = inicio->sig;

    while (temp) {
        if (temp->dato > mayor)
            mayor = temp->dato;
        temp = temp->sig;
    }

    return mayor;
}

void Mostrar(Nodo* inicio) {
    while (inicio) {
        cout << inicio->dato << " ";
        inicio = inicio->sig;
    }
    cout << endl;
}

int main() {
    Nodo* lista = nullptr;
    int op;

    do {
        cout << "\n1. Insertar\n2. Ver lista\n3. Mayor\n4. Salir\nOpcion: ";
        cin >> op;

        switch (op) {
            case 1: {
                int num;
                cout << "Numero: ";
                cin >> num;
                Insertar(lista, num);
                break;
            }
            case 2:
                Mostrar(lista);
                break;
            case 3:
                cout << "Mayor: " << Mayor(lista) << endl;
                break;
            case 4:
                cout << "Adios!\n";
                break;
            default:
                cout << "Opcion incorrecta\n";
        }

    } while (op != 4);

    return 0;
}
