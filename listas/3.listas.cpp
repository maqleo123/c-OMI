/*
Realiza un programa que cree una lista enlazada de enteros, donde el usuario pueda eliminar un valor específico si existe en la lista.
*/
#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* sig;
};

void AgregarFinal(Nodo* &inicio, int valor) {
    Nodo* nuevo = new Nodo{valor, nullptr};
    if (!inicio) {
        inicio = nuevo;
    } else {
        Nodo* temp = inicio;
        while (temp->sig)
            temp = temp->sig;
        temp->sig = nuevo;
    }
}

void Eliminar(Nodo* &inicio, int valor) {
    if (!inicio) return;

    if (inicio->dato == valor) {
        Nodo* borrar = inicio;
        inicio = inicio->sig;
        delete borrar;
        cout << "Valor eliminado\n";
        return;
    }

    Nodo* actual = inicio;
    while (actual->sig && actual->sig->dato != valor)
        actual = actual->sig;

    if (actual->sig) {
        Nodo* borrar = actual->sig;
        actual->sig = borrar->sig;
        delete borrar;
        cout << "Valor eliminado\n";
    } else {
        cout << "Valor no encontrado\n";
    }
}

void Ver(Nodo* inicio) {
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
        cout << "\n1. Agregar\n2. Ver\n3. Eliminar\n4. Salir\nOpcion: ";
        cin >> op;
        switch (op) {
            case 1: {
                int num;
                cout << "Numero: ";
                cin >> num;
                AgregarFinal(lista, num);
                break;
            }
            case 2:
                Ver(lista);
                break;
            case 3: {
                int num;
                cout << "Valor a eliminar: ";
                cin >> num;
                Eliminar(lista, num);
                break;
            }
            case 4:
                cout << "Fin\n";
                break;
            default:
                cout << "Opcion no valida\n";
        }

    } while (op != 4);

    return 0;
}
