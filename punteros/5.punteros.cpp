/*funciones con punteros*/
#include <iostream>
using namespace std;

void cambiar(int* p){
    *p=30;
}

int main(){
    int x=20;
    cambiar(&x);
    cout<<x;
}