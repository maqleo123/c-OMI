#include <iostream>
using namespace std;

int sumar(int n1, int n2){
	int r=n1+n2;
	return r;
}

int main(){
	int n1, n2;
	cout<<"Ingresa el numero 1: ";
	cin>>n1;
	cout<<"Ingresa el numero 2: ";
	cin>>n2;
	cout<<"El resultado es: "<<sumar(n1, n2);
}