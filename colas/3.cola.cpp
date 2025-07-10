/*
Diseña un programa que simule una cola de atención, donde se asignan turnos y se atienden uno a uno. Muestra cuántas personas quedan en espera.
*/
#include <iostream>
using namespace std;

const int MAX_TURNOS = 20;

struct Cola {
    int turnos[MAX_TURNOS];
    int frente;
    int fin;
};

void Crear(Cola &c) {
    c.frente = 0;
    c.fin = -1;
}

bool EstaVacia(Cola &c) {
    return c.frente > c.fin;
}

bool EstaLlena(Cola &c) {
    return c.fin == MAX_TURNOS - 1;
}

void AsignarTurno(Cola &c, int turno) {
    if (!EstaLlena(c))
        c.turnos[++c.fin] = turno;
    else
        cout << "no hay más espacio\n";
}

void Atender(Cola &c) {
    if (!EstaVacia(c))
        cout << "Atendiendo turno: " << c.turnos[c.frente++] << endl;
    else
        cout << "no hay nadie en espera\n";
}

void MostrarEspera(Cola &c) {
    cout << "Turnos en espera: " << (c.fin - c.frente + 1) << endl;
}

int main() {
    Cola cola;
    Crear(cola);
    int turno = 1, op;

    do {
        cout << "\n1. Nuevo turno\n2. Atender\n3. Ver espera\n4. Salir\nOpcion: ";
        cin >> op;

        switch (op) {
            case 1:
                AsignarTurno(cola, turno++);
                break;
            case 2:
                Atender(cola);
                break;
            case 3:
                MostrarEspera(cola);
                break;
            case 4:
                cout << "Fin del sistema de turnos\n";
                break;
            default:
                cout << "Opcion invalida\n";
        }

    } while (op != 4);

    return 0;
}
