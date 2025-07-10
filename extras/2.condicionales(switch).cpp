#include <iostream>
using namespace std;

int main(){
	int dia;
	cout<<"ingrese el numero de dia: ";
	cin>>dia;
	switch( dia){
		case 1:
		cout<<"el dia "<<dia<<" es lunes";
		break;
		case 2:
		cout<<"el dia "<<dia<<" es martes";
		break;
		case 3:
		cout<<"el dia "<<dia<<" es miercoles";
		break;
		case 4:
		cout<<"el dia "<<dia<<" es jueves";
		break;
		case 5:
		cout<<"el dia "<<dia<<" es viernes";
		break;
		case 6:
		cout<<"el dia "<<dia<<" es sabado";
		break;
		case 7:
		cout<<"el dia "<<dia<<" es domingo";
		break;
		default:
		cout<<"el numero que ingreso es incorrecto";
	}

	return 0;
}