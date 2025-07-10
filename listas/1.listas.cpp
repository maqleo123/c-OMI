/*
Realiza un programa que permita crear una lista enlazada simple de números enteros. El usuario podrá insertar números al final de la lista y mostrar todo el contenido en orden.
*/
#include <iostream>
using namespace std;

struct Nodo {
    int valor;
    Nodo* sig;
};

void Agregar(Nodo* &inicio, int num) {
    Nodo* nuevo = new Nodo;
    nuevo->valor = num;
    nuevo->sig = nullptr;

    if (inicio == nullptr) {
        inicio = nuevo;
    } else {
        Nodo* temp = inicio;
        while (temp->sig != nullptr)
            temp = temp->sig;
        temp->sig = nuevo;
    }
}

void Mostrar(Nodo* inicio) {
    if (inicio == nullptr) {
        cout << "Lista vacia\n";
        return;
    }

    cout << "Elementos: ";
    Nodo* temp = inicio;
    while (temp != nullptr) {
        cout << temp->valor << " ";
        temp = temp->sig;
    }
    cout << endl;
}

int main() {
    Nodo* lista = nullptr;
    int op;

    do {
        cout << "\n1. Agregar numero\n2. Mostrar lista\n3. Salir\nOpcion: ";
        cin >> op;

        switch (op) {
            case 1: {
                int num;
                cout << "Numero: ";
                cin >> num;
                Agregar(lista, num);
                break;
            }
            case 2:
                Mostrar(lista);
                break;
            case 3:
                cout << "Fin\n";
                break;
            default:
                cout << "Opcion invalida\n";
        }

    } while (op != 3);

    return 0;
}
