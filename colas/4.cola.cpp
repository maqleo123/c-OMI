/*
Crea un programa que almacene registros de temperatura en una cola, y pueda mostrar la temperatura más alta y la más baja que se haya ingresado.
*/
#include <iostream>
using namespace std;

const int LIMITE = 38;

struct Cola {
    float temp[LIMITE];
    int frente;
    int fin;
};

void IniciarCola(Cola &c) {
    c.frente = 0;
    c.fin = -1;
}

bool Vacia(Cola &c) {
    return c.frente > c.fin;
}

bool Llena(Cola &c) {
    return c.fin == LIMITE - 1;
}

void Agregar(Cola &c, float valor) {
    if (!Llena(c))
        c.temp[++c.fin] = valor;
    else
        cout << "cola llena\n";
}

void VerTodo(Cola &c) {
    if (Vacia(c)) {
        cout << "vacia\n";
        return;
    }
    for (int i = c.frente; i <= c.fin; i++)
        cout << c.temp[i] << " ";
    cout << endl;
}

void VerMaxMin(Cola &c) {
    if (Vacia(c)) {
        cout << "no hay datos\n";
        return;
    }
    float max = c.temp[c.frente];
    float min = c.temp[c.frente];
    for (int i = c.frente + 1; i <= c.fin; i++) {
        if (c.temp[i] > max) max = c.temp[i];
        if (c.temp[i] < min) min = c.temp[i];
    }
    cout << "Mayor: " << max << " | Menor: " << min << endl;
}

int main() {
    Cola c;
    IniciarCola(c);
    int op;

    do {
        cout << "\n1. Agregar temperatura\n2. Ver todas\n3. Ver max y min\n4. Salir\nOpcion: ";
        cin >> op;

        switch (op) {
            case 1: {
                float t;
                cout << "Temperatura: ";
                cin >> t;
                Agregar(c, t);
                break;
            }
            case 2:
                VerTodo(c);
                break;
            case 3:
                VerMaxMin(c);
                break;
            case 4:
                cout << "Fin del programa\n";
                break;
            default:
                cout << "Invalido\n";
        }

    } while (op != 4);

    return 0;
}
