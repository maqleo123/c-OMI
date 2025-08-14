/*modifica el valor desde su puntero*/
#include <iostream>
using namespace std;

int main(){
    int a=5;
    int* p=&a;
    *p=30;

    cout<<a;
}