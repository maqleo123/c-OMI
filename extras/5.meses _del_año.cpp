#include <iostream>
using namespace std;

int main(){
	int n;
	cout<<"Ingresa el numero del mes: ";
	cin>>n;
	switch(n){
		case 1:
		cout<<"el mes "<<n<<" es enero";
		break;
		case 2:
		cout<<"el mes "<<n<<" es febrero";
		break;
		case 3:
		cout<<"el mes "<<n<<" es marzo";
		break;
		case 4:
		cout<<"el mes "<<n<<" es abril";
		break;
		case 5:
		cout<<"el mes "<<n<<" es mayo";
		break;
		case 6:
		cout<<"el mes "<<n<<" es junio";
		break;
		case 7:
		cout<<"el mes "<<n<<" es julio";
		break;
		case 8:
		cout<<"el mes "<<n<<" es agosto";
		break;
		case 9:
		cout<<"el mes "<<n<<" es septiembre";
		break;
		case 10:
		cout<<"el mes "<<n<<" es octubre";
		break;
		case 11:
		cout<<"el mes "<<n<<" es noviembre";
		break;
		case 12:
		cout<<"el mes "<<n<<" es diciembre";
		break;
		default:
		cout<<"El mes ingresado no existe";
	}

	return 0;
}