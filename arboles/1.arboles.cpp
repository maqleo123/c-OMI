/*
Realiza un programa que permita insertar números enteros en un árbol binario y los muestre ordenados de menor a mayor (inorden).
*/
#include <iostream>
using namespace std;

struct Nodo {
    int valor;
    Nodo* izq;
    Nodo* der;
};

Nodo* Insertar(Nodo* raiz, int valor) {
    if (raiz == nullptr) {
        Nodo* nuevo = new Nodo{valor, nullptr, nullptr};
        return nuevo;
    }

    if (valor < raiz->valor)
        raiz->izq = Insertar(raiz->izq, valor);
    else
        raiz->der = Insertar(raiz->der, valor);

    return raiz;
}

void Inorden(Nodo* raiz) {
    if (raiz != nullptr) {
        Inorden(raiz->izq);
        cout << raiz->valor << " ";
        Inorden(raiz->der);
    }
}

int main() {
    Nodo* arbol = nullptr;
    int op;

    do {
        cout << "\n1. Insertar\n2. Ver en orden\n3. Salir\nOpcion: ";
        cin >> op;

        switch (op) {
            case 1: {
                int num;
                cout << "Numero: ";
                cin >> num;
                arbol = Insertar(arbol, num);
                break;
            }
            case 2:
                cout << "Inorden: ";
                Inorden(arbol);
                cout << endl;
                break;
            case 3:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion no valida\n";
        }

    } while (op != 3);

    return 0;
}

