#include <iostream>
using namespace std;
int main(){
	int a=0, b=1, n, c;
	cout<<"cusntos numeros de la serie desea mostrar: ";
	cin>>n;
	if(n==1){
		cout<<"--> 0";
	}else if(n==2){
		cout<<"--> 0 1";
	}else if(n>2){
		int i=2;
		cout<<"--> 0 1";
		do{
			c=a+b;
			a=b;
			b=c;
			cout<<" "<<c;
			i++;
		}while(i<n);

	}else{
		cout<<"El numero es invalido";
	}
}