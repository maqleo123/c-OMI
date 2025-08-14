/*puntero apuntando a puntero*/
#include <iostream>
using namespace std;
int main(){
    int x=5;
    int* p=&x;
    int** pp=&p;

    cout<<**pp;
}