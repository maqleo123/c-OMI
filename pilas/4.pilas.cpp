/*
Diseña un programa que permita insertar palabras en una pila, eliminarlas si se desea, mostrar todas las que se han almacenado, y finalmente identificar cuál es la palabra más larga registrada en la pila.
*/
#include <iostream>
#include <string>
using namespace std;

const int MAXPAL = 38;

struct Pila {
    string palabras[MAXPAL];
    int tope;
};

void Crear(Pila &p) {
    p.tope = -1;
    for (int i = 0; i < MAXPAL; i++)
        p.palabras[i] = "";
}

bool EstaVacia(Pila &p) {
    return p.tope == -1;
}

bool EstaLlena(Pila &p) {
    return p.tope == MAXPAL - 1;
}

void Poner(Pila &p, string palabra) {
    if (EstaLlena(p)) {
        cout << "ya no cabe\n";
    } else {
        p.palabras[++p.tope] = palabra;
    }
}

string Quitar(Pila &p) {
    if (EstaVacia(p)) {
        cout << "vacio\n";
        return "";
    }
    return p.palabras[p.tope--];
}

string MasLarga(Pila &p) {
    string mayor = "";
    for (int i = 0; i <= p.tope; i++)
        if (p.palabras[i].length() > mayor.length())
            mayor = p.palabras[i];
    return mayor;
}

void MostrarTodo(Pila &p) {
    if (EstaVacia(p)) {
        cout << "vacio\n";
        return;
    }
    for (int i = 0; i <= p.tope; i++)
        cout << p.palabras[i] << endl;
}

int main() {
    Pila pila;
    Crear(pila);
    int op;

    do {
        cout << "\n1. meter palabra\n2. quitar\n3. ver todas\n4. palabra mas larga\n5. salir\nopcion: ";
        cin >> op;

        switch (op) {
            case 1: {
                string palabra;
                cout << "palabra: ";
                cin >> palabra;
                Poner(pila, palabra);
                break;
            }
            case 2:
                cout << "quitado: " << Quitar(pila) << endl;
                break;
            case 3:
                MostrarTodo(pila);
                break;
            case 4:
                cout << "mas larga: " << MasLarga(pila) << endl;
                break;
            case 5:
                cout << "bye\n";
                break;
            default:
                cout << "opcion no existe\n";
        }

    } while (op != 5);

    return 0;
}
