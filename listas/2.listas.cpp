/*
Escribe un programa que cree una lista enlazada de números y tenga la opción de contar cuántos nodos contiene actualmente.
*/
#include <iostream>
using namespace std;

struct Nodo {
    int valor;
    Nodo* siguiente;
};

void Insertar(Nodo* &inicio, int valor) {
    Nodo* nuevo = new Nodo;
    nuevo->valor = valor;
    nuevo->siguiente = inicio;
    inicio = nuevo;
}

int Contar(Nodo* inicio) {
    int contador = 0;
    Nodo* actual = inicio;
    while (actual != nullptr) {
        contador++;
        actual = actual->siguiente;
    }
    return contador;
}

void Mostrar(Nodo* inicio) {
    Nodo* actual = inicio;
    while (actual != nullptr) {
        cout << actual->valor << " ";
        actual = actual->siguiente;
    }
    cout << endl;
}

int main() {
    Nodo* lista = nullptr;
    int op;

    do {
        cout << "\n1. Insertar numero\n2. Mostrar lista\n3. Contar elementos\n4. Salir\nOpcion: ";
        cin >> op;

        switch (op) {
            case 1: {
                int val;
                cout << "Valor: ";
                cin >> val;
                Insertar(lista, val);
                break;
            }
            case 2:
                Mostrar(lista);
                break;
            case 3:
                cout << "Total nodos: " << Contar(lista) << endl;
                break;
            case 4:
                cout << "Adios\n";
                break;
            default:
                cout << "Opcion invalida\n";
        }
    } while (op != 4);

    return 0;
}
