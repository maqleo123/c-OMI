#include <iostream>
using namespace std;

int main(){
	int n,factorial=1;
	cout<<"Ingrese un numero: ";
	cin>>n;
	if(n==0){
		cout<<"El resultado es: 1"<<endl;
	}else if(n>=1){
		for(int i=1;i<=n;i++){
			factorial=factorial*i;
	}
	cout<<"El factorial es: "<<factorial;
	}else{
		cout<<"numero invalido"<<endl;
	}
}