/*punteros y memoria dinamica*/
#include <iostream>
using namespace std;

int main(){
    int*p=new int;
    *p=60;
    cout<<*p;
    delete p; //libera la memoria
    
}