/*
Realiza un programa que permita insertar números en una cola, eliminarlos, mostrarlos todos y calcular el promedio de los números almacenados.
*/
#include <iostream>
using namespace std;

const int TAM_COLA = 38;

struct Cola {
    int datos[TAM_COLA];
    int frente;
    int fin;
};

void Inicializar(Cola &cola) {
    cola.frente = 0;
    cola.fin = -1;
}

bool EstaVacia(Cola &cola) {
    return cola.frente > cola.fin;
}

bool EstaLlena(Cola &cola) {
    return cola.fin == TAM_COLA - 1;
}

void Empujar(Cola &cola, int valor) {
    if (EstaLlena(cola)) {
        cout << "Cola llena" << endl;
    } else {
        cola.datos[++cola.fin] = valor;
    }
}

int Quitar(Cola &cola) {
    if (EstaVacia(cola)) {
        cout << "Cola vacía" << endl;
        return -1;
    } else {
        return cola.datos[cola.frente++];
    }
}

void ImprimirCola(Cola &cola) {
    if (EstaVacia(cola)) {
        cout << "Cola vacía" << endl;
        return;
    }
    cout << "Elementos: ";
    for (int i = cola.frente; i <= cola.fin; i++)
        cout << cola.datos[i] << " ";
    cout << endl;
}

float Promedio(Cola &cola) {
    if (EstaVacia(cola)) return 0;
    int suma = 0;
    int cantidad = cola.fin - cola.frente + 1;
    for (int i = cola.frente; i <= cola.fin; i++)
        suma += cola.datos[i];
    return float(suma) / cantidad;
}

int main() {
    Cola cola;
    Inicializar(cola);
    int op;

    do {
        cout << "\n1. Agregar\n2. Quitar\n3. Ver todo\n4. Promedio\n5. Salir\nOpcion: ";
        cin >> op;

        switch (op) {
            case 1: {
                int valor;
                cout << "Numero: ";
                cin >> valor;
                Empujar(cola, valor);
                break;
            }
            case 2:
                cout << "Quitado: " << Quitar(cola) << endl;
                break;
            case 3:
                ImprimirCola(cola);
                break;
            case 4:
                cout << "Promedio: " << Promedio(cola) << endl;
                break;
            case 5:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida\n";
        }

    } while (op != 5);

    return 0;
}
