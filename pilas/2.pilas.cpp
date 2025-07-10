/*
Realiza un programa que permita almacenar números enteros en una pila, quitar elementos cuando se desee, mostrar los valores actuales, y obtener la suma total de todos los números que están en la pila en ese momento
*/
#include <iostream>
using namespace std;

const int TAM = 38;

struct Pila {
    int tope;
    int datos[TAM];
};

void Iniciar(Pila &p) {
    p.tope = -1;
    for (int i = 0; i < TAM; i++)
        p.datos[i] = 0;
}

bool Vacia(Pila &p) {
    return p.tope == -1;
}

bool Llena(Pila &p) {
    return p.tope == TAM - 1;
}

void Agregar(Pila &p, int num) {
    if (Llena(p)) {
        cout << "la pila esta llena\n";
    } else {
        p.tope++;
        p.datos[p.tope] = num;
    }
}

int Sacar(Pila &p) {
    if (Vacia(p)) {
        cout << "la pila esta vacia\n";
        return -1;
    } else {
        return p.datos[p.tope--];
    }
}

void Mostrar(Pila &p) {
    if (Vacia(p)) {
        cout << "no hay datos\n";
        return;
    }
    cout << "numeros: ";
    for (int i = 0; i <= p.tope; i++)
        cout << p.datos[i] << " ";
    cout << endl;
}

int SumarTodo(Pila &p) {
    int suma = 0;
    for (int i = 0; i <= p.tope; i++)
        suma += p.datos[i];
    return suma;
}

int main() {
    Pila pila;
    Iniciar(pila);
    int op;

    do {
        cout << "\n1. agregar num\n2. quitar num\n3. ver pila\n4. sumar todos\n5. salir\nopcion: ";
        cin >> op;

        switch (op) {
            case 1: {
                int n, val;
                cout << "cuantos quieres meter? ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    cout << "num " << i+1 << ": ";
                    cin >> val;
                    Agregar(pila, val);
                }
                break;
            }
            case 2:
                cout << "sacado: " << Sacar(pila) << endl;
                break;
            case 3:
                Mostrar(pila);
                break;
            case 4:
                cout << "suma total: " << SumarTodo(pila) << endl;
                break;
            case 5:
                cout << "adios\n";
                break;
            default:
                cout << "no existe esa opcion\n";
        }

    } while (op != 5);

    return 0;
}
