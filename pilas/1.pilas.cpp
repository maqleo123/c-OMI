/*
Realiza un programa que permita gestionar una pila de letras, donde el usuario pueda insertar letras una por una, eliminarlas en orden inverso, ver todas las letras almacenadas y consultar cuál fue la última letra agregada.
*/
#include <iostream>
using namespace std;

const int TAM_PILA = 38;

struct Pila {
    int Tope;
    char Elementos[TAM_PILA];
};

// Inisializar
void Inicializar(Pila &pila) {
    pila.Tope = -1;
    for (int i = 0; i < TAM_PILA; i++)
        pila.Elementos[i] = '\0';
}

// Emty
bool Empty(Pila &pila) {
    return pila.Tope == -1;
}

// Full
bool Full(Pila &pila) {
    return pila.Tope == TAM_PILA - 1;
}

// Pussh
void Push(Pila &pila, char letra) {
    if (Full(pila)) {
        cout << "pila lllena" << endl;
    } else {
        pila.Tope++;
        pila.Elementos[pila.Tope] = letra;
    }
}

// Pop
char Pop(Pila &pila) {
    if (Empty(pila)) {
        cout << "Pila vacia" << endl;
        return '\0';
    } else {
        char letra = pila.Elementos[pila.Tope];
        pila.Tope--;
        return letra;
    }
}

// Imprimier
void Imprimir(Pila &pila) {
    if (Empty(pila)) {
        cout << "pila vacia" << endl;
        return;
    }
    cout << "etras en la pila : ";
    for (int i = 0; i <= pila.Tope; i++) {
        cout << pila.Elementos[i] << " ";
    }
    cout << endl;
}

// Mostrar ultimo
char MostrarUltimo(Pila &pila) {
    if (Empty(pila)) {
        cout << "pila vacia" << endl;
        return '\0';
    } else {
        return pila.Elementos[pila.Tope];
    }
}

int main() {
    Pila pila;
    Inicializar(pila);
    int opcion;

    do {
        cout << "\n===== menu =====" << endl;
        cout << "1. insertar letras" << endl;
        cout << "2. quitar letras" << endl;
        cout << "3. imprimir letras" << endl;
        cout << "4. Mostrar ultimo" << endl;
        cout << "5. salir" << endl;
        
        cout << "elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int cantidad;
                cout << "cuantas letras quieres meter? ";
                cin >> cantidad;
                for (int i = 0; i < cantidad; i++) {
                    if (Full(pila)) {
                        cout << "no hay espacio" << endl;
                        break;
                    }
                    char letra;
                    cout << "letra " << i + 1 << ": ";
                    cin >> letra;
                    Push(pila, letra);
                }
                break;
            }
            case 2: {
                int cantidad;
                cout << "cuantas letras quieres quitar? ";
                cin >> cantidad;
                for (int i = 0; i < cantidad; i++) {
                    if (Empty(pila)) {
                        cout << "no hay letras" << endl; 
                        break;
                    }
                    char letra = Pop(pila);
                    cout << "letra quitada " << letra << endl;
                }
                break;
            }
            case 3:
                Imprimir(pila);
                break;
            case 4: {
                char ultimo = MostrarUltimo(pila);
                if (ultimo != '\0') {
                    cout << "Ultimo elemento: " << ultimo << endl;
                }
                break;
            }
            case 5:
                cout << "saliendo" << endl;
                break;
            default:
                cout << "opcion no valida" << endl;
        }

    } while (opcion != 5);

    return 0;
}
