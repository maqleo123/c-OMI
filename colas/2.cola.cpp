/*
Crea un programa que convierta una palabra en una cola de caracteres y permita eliminar todas las vocales de ella.
*/
#include <iostream>
using namespace std;

const int TAM = 50;

struct Cola {
    char letras[TAM];
    int frente;
    int fin;
};

void Iniciar(Cola &c) {
    c.frente = 0;
    c.fin = -1;
}

bool Vacia(Cola &c) {
    return c.frente > c.fin;
}

bool Llena(Cola &c) {
    return c.fin == TAM - 1;
}

void Insertar(Cola &c, char letra) {
    if (!Llena(c)) {
        c.letras[++c.fin] = letra;
    } else {
        cout << "cola llena\n";
    }
}

char Sacar(Cola &c) {
    if (!Vacia(c)) {
        return c.letras[c.frente++];
    } else {
        cout << "cola vacia\n";
        return '\0';
    }
}

bool EsVocal(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void EliminarVocales(Cola &c) {
    Cola nueva;
    Iniciar(nueva);

    while (!Vacia(c)) {
        char letra = Sacar(c);
        if (!EsVocal(letra))
            Insertar(nueva, letra);
    }
    c = nueva;
}

void VerCola(Cola &c) {
    if (Vacia(c)) {
        cout << "cola vacia\n";
        return;
    }
    cout << "contenido: ";
    for (int i = c.frente; i <= c.fin; i++)
        cout << c.letras[i];
    cout << endl;
}

int main() {
    Cola c;
    Iniciar(c);
    string palabra;

    cout << "Escribe una palabra: ";
    cin >> palabra;

    for (char letra : palabra) {
        Insertar(c, letra);
    }

    VerCola(c);
    EliminarVocales(c);
    cout << "Sin vocales: ";
    VerCola(c);

    return 0;
}
