#include <iostream>
using namespace std;

int main(){
	int numero;
	cout<<"ingresa el  numero que desea revisar"<<endl;
	cin>>numero;
	if(numero>0){
		cout<<"el numero es positivo";
	}else if(numero==0){
		cout<<"el numero es nulo";
	}else{
		cout<<"el numero es negativo";
	}

	return 0;
}