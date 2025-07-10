/*
Crea un programa que administre una pila de símbolos matemáticos. El usuario podrá insertar y eliminar símbolos, y el sistema debe ser capaz de contar cuántos signos ‘+’ se han ingresado hasta el momento.
*/
#include <iostream>
using namespace std;

const int MAXSIG = 38;

struct Pila {
    char simbolos[MAXSIG];
    int top;
};

void Arrancar(Pila &p) {
    p.top = -1;
    for (int i = 0; i < MAXSIG; i++)
        p.simbolos[i] = '\0';
}

bool EstaVacia(Pila &p) {
    return p.top == -1;
}

bool EstaLlena(Pila &p) {
    return p.top == MAXSIG - 1;
}

void Meter(Pila &p, char s) {
    if (EstaLlena(p))
        cout << "no caben mas\n";
    else
        p.simbolos[++p.top] = s;
}

char Sacar(Pila &p) {
    if (EstaVacia(p)) {
        cout << "no hay signos\n";
        return '\0';
    }
    return p.simbolos[p.top--];
}

int ContarMas(Pila &p) {
    int cont = 0;
    for (int i = 0; i <= p.top; i++)
        if (p.simbolos[i] == '+')
            cont++;
    return cont;
}

void VerPila(Pila &p) {
    if (EstaVacia(p)) {
        cout << "pila vacia\n";
        return;
    }
    for (int i = 0; i <= p.top; i++)
        cout << p.simbolos[i] << " ";
    cout << endl;
}

int main() {
    Pila pila;
    Arrancar(pila);
    int op;

    do {
        cout << "\n1. meter signo\n2. sacar\n3. ver\n4. contar '+'\n5. salir\nelige: ";
        cin >> op;

        switch (op) {
            case 1: {
                char s;
                cout << "signo: ";
                cin >> s;
                Meter(pila, s);
                break;
            }
            case 2:
                cout << "sacado: " << Sacar(pila) << endl;
                break;
            case 3:
                VerPila(pila);
                break;
            case 4:
                cout << "hay " << ContarMas(pila) << " '+' en la pila\n";
                break;
            case 5:
                cout << "saliendo...\n";
                break;
            default:
                cout << "opcion invalida\n";
        }

    } while (op != 5);

    return 0;
}
