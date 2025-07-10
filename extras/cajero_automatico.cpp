/*
simulador de cajero automatico
-implementa un programa que simule el funcionamiento de un cajero automatico
-moneda (peso mexicano)
-permitira el reconocimiento debilletes 1000, 500, 200, 100, 50, 20 pesos
-permitira el reconocimiento de monedas de 10, 5, 2, 1 peso(s)
-funcion de depositar y retirar dinero
*/
#include <iostream>
#include <conio.h>
using namespace std;

struct Dinero{
	int valor;
	int cantidad;
};

int cantidad=0;
struct Dinero arrayDinero[10];
void menu_principal();
int obtener_saldo();

void depositar_dinero(){
	system("cls");
	int opc=0, monto=0;
	cout<<"\t DEPOSITAR DINERO"<<endl<<endl;
	for(int i=0;i<cantidad;i++){
	cout<<" "<<i+1<<".Depositar $"<<arrayDinero[i].valor<<endl;
	}
	cout<<" "<<cantidad+1<<".salir"<<endl;
	cout<<"-->>ingrese opcion"<<endl;
	cin>>opc;
	if(opc>=1 && opc<=cantidad){\
		cout<<"Usted a elegido la cantidad de $"<<arrayDinero[opc-1].valor<<endl
		<<"-->Ingrese la cantidad de dinero: ";
		cin>>monto;
		if(monto>0){
			arrayDinero[opc-1].cantidad+=monto;
			cout<<"se a depositado correctamente, presione enter para continuar";
			getch();
			menu_principal();
		}else{
			cout<<"la cantidad ingresada deve ser mayor a 0, precione enter para continuar";
			getch();
			depositar_dinero();
		}


	}else if(opc==11){
		menu_principal();
	}else{
		depositar_dinero();
	}

}

void retirar_dinero(int retirar){
	int temporal_dinero=0;
	int acumulador_de_dinero=0;
	cout<<"Detallado de retiro: "<<endl<<endl;
	for(int i=0;i<cantidad;i++){
	if(arrayDinero[i].cantidad>0){ 
		temporal_dinero=retirar/arrayDinero[i].valor;
		if(temporal_dinero>0){
				if(temporal_dinero>arrayDinero[i].cantidad){
					temporal_dinero=arrayDinero[i].cantidad;
				}
		arrayDinero[i].cantidad-=temporal_dinero;
		retirar-=temporal_dinero*arrayDinero[i].valor;
		acumulador_de_dinero+=temporal_dinero*arrayDinero[i].valor;
		cout<<"."<<temporal_dinero<<" de " <<arrayDinero[i].valor<<" subtotal: $"<<temporal_dinero*arrayDinero[i].valor<<endl;
		}
	}
	}
	if(retirar==0){
    cout<<"Cantidad retirada correctamente, precione enter para continuar";
	}else{
		if(acumulador_de_dinero>0){
        cout<<"solo se pudo retirar $"<<acumulador_de_dinero<<" ya que no avia dinero suficiente, precione enter para continuar";
		}else{
			cout<<"su retiro no se pudo llevar acabo intente con otra cantidad :(, precione enter para continuar";
		}
	
	}
	
	getch();
	menu_principal();
}

void menu_retirar_dinero(){
	system("cls");
	int retirar;
	char letra;
    cout<<"\t RETIRAR DINERO"<<endl<<endl
	<<"-->Cantidad de dinero a retirar: "<<endl;
	cin>>retirar;
	if(retirar>0 && retirar<obtener_saldo()){
		cout<<"Estas seguro de querer retirar esa cantidad ($"<<retirar<<")  (s/n) ";
		letra=getch();
		if(letra=='s'){
        retirar_dinero(retirar);
		}else{
			menu_principal();
		}

	}else{
		cout<<"La cantidad ingresada no es valida ingrese una que si lo sea, precione enter para continuar";
		getch();
		retirar_dinero(retirar);
	}
}


int obtener_saldo(){
	int saldo=0;
	for(int i=0;i<cantidad;i++){
        saldo+=arrayDinero[i].cantidad*arrayDinero[i].valor;
	}
    return saldo;
}

void menu_principal(){
    system("cls");
	char respuesta;
	cout<<"\t SIMULADOR DE CAJERO AUTOMATICO"<<endl<<endl
	<<"-->saldo actual del cajero automatico: $"<<obtener_saldo()<<endl
	<<"1.depositar dinero"<<endl
	<<"2.retirar dinero"<<endl
	<<"3.salir del cajero"<<endl<<endl
	<<"-->ingrese una opcion: ";
	cin>>respuesta;

	switch(respuesta){
		case '1':
		depositar_dinero();
            break;
		case '2':
		menu_retirar_dinero();
            break;
		case '3':
		cout<<endl<<"gracias por usar el cajero :)";
            break;
		default:
		menu_principal();
	}
}

void inicializar_cajero(){
	arrayDinero[0].valor=1000;
	arrayDinero[0].cantidad=5;

	arrayDinero[1].valor=500;
	arrayDinero[1].cantidad=2;

	arrayDinero[2].valor=200;
	arrayDinero[2].cantidad=1;

	arrayDinero[3].valor=100;
	arrayDinero[3].cantidad=2;

	arrayDinero[4].valor=50;
	arrayDinero[4].cantidad=5;

	arrayDinero[5].valor=20;
	arrayDinero[5].cantidad=5;

	arrayDinero[6].valor=10;
	arrayDinero[6].cantidad=5;

	arrayDinero[7].valor=5;
	arrayDinero[7].cantidad=3;

	arrayDinero[8].valor=2;
	arrayDinero[8].cantidad=4;

	arrayDinero[9].valor=1;
	arrayDinero[9].cantidad=20;

	cantidad=10;
}

int main(){
	inicializar_cajero();
    menu_principal();

	return 0;
}