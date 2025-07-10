#include <iostream>
using namespace std;

int main(){
	int n1,n2,resultado, respuesta;
	cout<<"\tJUEGO DE LA SUMA \n";
	cout<<endl<<"ingresa el primer numero: ";
	cin>>n1;
	cout<<"ingresa el segundo  numero: ";
	cin>>n2;
	cout<<endl<<"cual seria tu respuesta: ";
	cin>>respuesta;

	resultado=n1+n2;

	if(resultado==respuesta){
		cout<<endl<<"as asertado con tu respuesta";
	}else{
		cout<<endl<<"tu respuesta no a sido correcta intentalo de nuevo";
	}
	

}