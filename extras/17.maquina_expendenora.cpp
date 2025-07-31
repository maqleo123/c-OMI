/*
Desarroya un sofware de una maquina expendedora de bebidas
en el lenguage c++
-->insertar bebida
-->mostrar menu de bebidas
-->comprar bebida
-->reporte de compras
*/
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

// enter es el 13
// escape es el 27

struct Bebida
{
    int codigo;
    string nombre;
    float precio;
    int stok;
    int cantidadVendida;
};

struct Bebida arrayBebida[10];
int contadorTipoBebida = 0;
void menu_principal();
void menu_bebidas();

int verificar_codigo(int temporalCodigo)
{
    for (int i = 0; i < contadorTipoBebida; i++)
    {
        if (arrayBebida[i].codigo == temporalCodigo)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

void registrar_bebida()
{

    int respuesta = 0;
    int temporalCodigo;
    system("cls");
    if (contadorTipoBebida < 10)
    {
        do
        {
            system("cls");
            cout << "\n";
            cout << "\t***************************************" << endl;
            cout << "\t*      REGISTRO DE NUEVA BEBIDA       *" << endl;
            cout << "\t*-------------------------------------*" << endl;

            cout << "\t  Registra bebida " << contadorTipoBebida + 1 << endl;

            cout << "\t* Ingrese codigo de la bebida: ";
            cin >> temporalCodigo;

            if (verificar_codigo(temporalCodigo) == 0)
            {
                arrayBebida[contadorTipoBebida].codigo = temporalCodigo;

                cout << "\t* Ingrese nombre de la bebida: ";
                cin >> arrayBebida[contadorTipoBebida].nombre;

                cout << "\t* Ingrese precio de la bebida: $";
                cin >> arrayBebida[contadorTipoBebida].precio;

                cout << "\t* Ingrese stock de la bebida: ";
                cin >> arrayBebida[contadorTipoBebida].stok;

                arrayBebida[contadorTipoBebida].cantidadVendida = 0;
                contadorTipoBebida++;

                cout << "\t*-------------------------------------*" << endl;

                if (contadorTipoBebida < 10)
                {
                    cout << "\t* Desea registrar otra bebida? [Enter]*" << endl;
                    cout << "\t***************************************" << endl;
                    respuesta = getch();
                    cout << endl
                         << endl;
                    if (respuesta != 13)
                    {
                        menu_principal();
                    }
                }
                else
                {
                    cout << "\t* Se alcanzo el limite de registros (10)" << endl;
                    cout << "\t***************************************" << endl
                         << endl;
                    respuesta = 27;
                }
            }
            else
            {
                cout << "\t*-------------------------------------*" << endl;
                cout << "\t* ¡Codigo duplicado! Intente con otro *" << endl;
                cout << "\t***************************************" << endl;
                respuesta = 13;
                getch();
            }

        } while (respuesta == 13);
    }
    else
    {
        cout << "\t***************************************" << endl;
        cout << "\t* Se alcanzo el limite de registros (10)" << endl;
        cout << "\t***************************************" << endl;
        getch();
        menu_principal();
    }
}
void comprar_bebida(int seleccion)
{
    while (true)
    {
        system("cls");
        int cantidad;
        char seguircomprando;
        float dinero, dinerocompra;
        int stockdisponible = arrayBebida[seleccion].stok - arrayBebida[seleccion].cantidadVendida;

        cout << "\n\t*----------------------------------*" << endl;
        cout << "\t|         >> COMPRAR BEBIDA <<      |" << endl;
        cout << "\t*----------------------------------*" << endl;
        cout << "\n-> Bebida seleccionada : " << arrayBebida[seleccion].nombre << endl;
        cout << "-> Precio por unidad    : $" << arrayBebida[seleccion].precio << " pesos" << endl;
        cout << "-> Stock disponible     : " << stockdisponible << endl;
        cout << "\n> ¿Cuántas bebidas desea comprar? ";
        cin >> cantidad;

        if (cantidad > stockdisponible || cantidad <= 0)
        {
            cout << "\n> La cantidad ingresada no está disponible. Intente de nuevo." << endl;
            system("pause");
            continue;
        }

        cout << "> Ingrese el dinero: $";
        cin >> dinero;

        dinerocompra = arrayBebida[seleccion].precio * cantidad;

        if (dinero < dinerocompra)
        {
            cout << "\n> Dinero insuficiente. Se requieren $" << dinerocompra << endl;
            system("pause");
            continue;
        }

        arrayBebida[seleccion].cantidadVendida += cantidad;

        cout << "\n> ¡Compra realizada correctamente!" << endl;
        cout << "\n-----------------------------------------" << endl;
        cout << "> Bebida        : " << arrayBebida[seleccion].nombre << endl;
        cout << "> Codigo        : " << arrayBebida[seleccion].codigo << endl;
        cout << "> Precio Unidad : $" << arrayBebida[seleccion].precio << endl;
        cout << "> Cantidad      : " << cantidad << endl;
        cout << "> Total         : $" << dinerocompra << endl;
        cout << "> Dinero        : $" << dinero << endl;
        cout << "> Cambio        : $" << (dinero - dinerocompra) << endl;
        cout << "-----------------------------------------" << endl;

        cout << "\n> ¿Desea comprar otra vez la misma bebida? (s/n): ";
        cin >> seguircomprando;

        if (tolower(seguircomprando) != 's')
        {
            break;
        }
    }

    menu_bebidas();
}

void menu_bebidas()
{
    system("cls");
    char opc;

    cout << "\n";
    cout << "\t***************************************" << endl;
    cout << "\t*         >> BEBIDAS DISPONIBLES <<    *" << endl;
    cout << "\t***************************************" << endl;

    if (contadorTipoBebida == 0)
    {
        cout << "\t*  No hay bebidas registradas aún...  *" << endl;
        cout << "\t***************************************" << endl;
        cout << "\n> Presione cualquier tecla para regresar al menú principal..." << endl;
        getch();
        menu_principal();
        return;
    }

    for (int i = 0; i < contadorTipoBebida; i++)
    {
        cout << "\t* " << i << ". "
             << arrayBebida[i].nombre
             << " --> $" << arrayBebida[i].precio
             << "  (" << arrayBebida[i].stok << " disponibles)" << endl;
    }

    cout << "\t***************************************" << endl;
    cout << "\t* [ESC] Regresar - Seleccione [0-" << (contadorTipoBebida - 1) << "]" << endl;

    opc = getch();

    if (opc == 27)
    {
        menu_principal();
    }
    else if (isdigit(opc))
    {
        int seleccion = opc - '0';
        if (seleccion >= 0 && seleccion < contadorTipoBebida)
        {
            comprar_bebida(seleccion);
        }
        else
        {
            cout << "\n> Selección fuera de rango. Intente de nuevo.\n";
            system("pause");
            menu_bebidas();
        }
    }
    else
    {
        cout << "\n> Opción inválida. Intente de nuevo.\n";
        system("pause");
        menu_bebidas();
    }
}

void reporte_ventas()
{
    system("cls");

    cout << "\n";
    cout << "\t***************************************" << endl;
    cout << "\t*         >> REPORTE DE VENTAS <<      *" << endl;
    cout << "\t***************************************" << endl;

    float totalGeneral = 0;
    bool hayVentas = false;

    for (int i = 0; i < contadorTipoBebida; i++)
    {
        int cantidad = arrayBebida[i].cantidadVendida;

        if (cantidad > 0)
        {
            hayVentas = true;
            float total = cantidad * arrayBebida[i].precio;
            totalGeneral += total;

            cout << "\n\t-----------------------------------" << endl;
            cout << "\t Bebida       : " << arrayBebida[i].nombre << endl;
            cout << "\t Codigo       : " << arrayBebida[i].codigo << endl;
            cout << "\t Vendidas     : " << cantidad << endl;
            cout << "\t Precio unidad: $" << arrayBebida[i].precio << endl;
            cout << "\t Total venta  : $" << total << endl;
            cout << "\t-----------------------------------" << endl;
        }
    }

    if (!hayVentas)
    {
        cout << "\n\t> No se han registrado ventas aun." << endl;
    }
    else
    {
        cout << "\n\t***************************************" << endl;
        cout << "\t TOTAL GENERAL DE INGRESOS: $" << totalGeneral << endl;
        cout << "\t***************************************" << endl;
    }

    cout << "\n> Presione cualquier tecla para volver al menu principal..." << endl;
    getch();
    menu_principal();
}


void menu_principal()
{
    system("cls");
    int opc;
    cout << "\n";
    cout << "\t******************************" << endl;
    cout << "\t*    MAQUINA EXPENDEDORA     *" << endl;
    cout << "\t*----------------------------*" << endl;
    cout << "\t* 1. Registrar bebidas       *" << endl;
    cout << "\t* 2. Lista de bebidas        *" << endl;
    cout << "\t* 3. Reporte de ventas       *" << endl;
    cout << "\t* 4. Salir                   *" << endl;
    cout << "\t******************************" << endl;
    cout << "\tIngrese una opcion: ";
    opc = getch();
    switch (opc)
    {
    case '1':
        registrar_bebida();
        break;
    case '2':
        menu_bebidas();
        break;
    case '3':
        reporte_ventas();
        break;
    case '4':
        cout <<endl<< "A desidido finalizar el programa :)";
        break;
    default:
        menu_principal();
        break;
    }
}

int main()
{
    menu_principal();
    // registrar_bebida();
    // menu_bebidas();
}