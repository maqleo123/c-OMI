#include <iostream>
using namespace std;
int main(){
	double numeros[20];
	double cantidad;
	double acumulador, promedio=0;
	double menor, mayor;
	cout<<"ingrese el numero de elementos: ";
	cin>>cantidad;
	if(cantidad>0 && cantidad<20){
		for(int i=0;i<cantidad;i++){
			cout<<"Ingrese el numero "<<i<<":";
			cin>>numeros[i];
			acumulador+=numeros[i];
		}
		menor=numeros[0];
		mayor=numeros[0];
		for(int i=0;i<cantidad;i++){
			if(mayor<numeros[i]){
				mayor=numeros[i];
			}
			if(menor>numeros[i]){
				menor=numeros[i];
			}
		}
		promedio=acumulador/cantidad;
		cout<<endl<<"el promedio del array es: "<<promedio;
		cout<<endl<<"El numero menor del arreglo es: "<<menor;
		cout<<endl<<"El numero mayor del arreglo  es: "<<mayor;
	}else{
		cout<<"el numero eccede  la capacidad de elementos.";
	}
}