/*cambiar el valor de la variable usando puntero doble*/
#include <iostream>
using namespace std;

void cambiar(int** p){
    **p=3;
}

int main(){
    int x=89;
    int* p=&x;
    cambiar(&p);

    cout<<x;
}