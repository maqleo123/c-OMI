#include <iostream>
using namespace std;

int main(){
	int numero[10];
	int nuemroabuscar;
	int bandera=0;
	for(int i=0;i<10;i++){
		cout<<"ingrese el numero "<<i<<":";
		cin>>numero[i];
	}
	for(int i=0;i<10;i++){
		cout<<"Numero "<<i<<": "<<numero[i]<<endl;
	}

	cout<<"ingrese numero a buscar: ";
	cin>>nuemroabuscar;
	for(int i=0;i<10 && bandera==0;i++){
		if(numero[i]==nuemroabuscar){
			bandera=1;
		}
	}

	if(bandera==0){
		cout<<"Elemento no encontrado";
	}else{
		cout<<"Elemento encontrado";
	}

}