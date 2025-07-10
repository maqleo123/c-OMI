#include <iostream>
using namespace std;

int main(){
	int numero;
	cout<<"ingresa el numero que desea revisar: ";
	cin>>numero;
	if(numero==0){
		cout<<endl<<"el numero es nulo";
	}else if(numero%2==0){
		cout<<endl<<"el numero es par";
	}else{
		cout<<endl<<"el numero es inpar";
	}

	return 0;
}