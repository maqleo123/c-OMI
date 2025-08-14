/*funcion de suma con punteros*/
#include <iostream>
using namespace std;
void suma(int*a,int*b,int*r){
    *r=*a+*b;
}

int main(){
    int a=2, b=5,r;
    suma(&a,&b,&r);
    cout<<r;

}