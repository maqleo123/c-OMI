/*Crea una funcion que intercambie los valores de dos variables utilizando punteros*/
#include <iostream>
using namespace std;

void intercambiar(int* a, int* b){
    int temporal= *a;
    *a=*b;
    *b=temporal;
}
int main(){
    int x=12, y=21;
    intercambiar(&x,&y);
    cout<<x<<" "<<y;
}