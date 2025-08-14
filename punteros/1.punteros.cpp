#include <iostream>
using namespace std;

int main()
{
    int valor = 5;
    int *puntero = &valor;

    cout<<"valor: "<<*puntero<<endl;
    cout<<"direccion: "<<puntero<<endl;

}