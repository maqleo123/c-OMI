#include <iostream>
#include <string>
using namespace std;

int main() {
    string palabra, palindroma;
    cout << "Ingrese una palabra: ";
    cin >> palabra;

    for (int i = palabra.size() - 1; i >= 0; i--) {
        palindroma += palabra[i];
    }

    if (palabra == palindroma) {
        cout << "La palabra \"" << palabra << "\" es palindroma" << endl;
    } else {
        cout << "La palabra \"" << palabra << "\" no  es palindroma" << endl;
    }

    return 0;
}
