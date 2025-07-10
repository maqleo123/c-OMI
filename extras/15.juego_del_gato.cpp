#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

char tablero[3][3];
int turno = 0;
string jugador1 = "pro";
string jugador2 = "haker";

/*construimos el tablero # */
void crear_tablero()
{
	int x = 0, y = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << " " << (tablero[i][j] == '\0' ? ' ' : tablero[i][j]) << " ";
			if (j < 2)
				cout << "|";
		}
		cout << endl;

		if (i < 2)
		{
			cout << "---+---+---" << endl;
		}
	}
}

char posibles_jugadas()
{
	cout << "OPCIONES DE JUEGO: " << endl<<endl;
	int contador = 0;
	string opc = "abcdefghi";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << opc[contador] << ") [" << i << "," << j << "]";
			if (tablero[i][j] != NULL)
			{
				cout << "OCUPADO";
			}
			cout << endl;
			contador++;
		}
	}

	if (turno % 2 == 0)
	{
		cout << jugador1;
	}
	else
	{
		cout << jugador2;
	}
	cout << ", Elige una jugada: ";
	return getch();
}

void actualizar_turno(int x, int y)
{
	if (turno % 2 == 0)
	{
		tablero[x][y] = 'x';
	}
	else
	{
		tablero[x][y] = 'o';
	}
	turno++;
}

int verificar_jugada(char jugada)
{
	if (jugada >= 'a' && jugada <= 'i')
	{
		switch (jugada)
		{
		case 'a':
			if (tablero[0][0] == NULL)
			{
				actualizar_turno(0, 0);
				return 1;
			}

			break;
		case 'b':
			if (tablero[0][1] == NULL)
			{
				actualizar_turno(0, 1);
				return 1;
			}
			break;
		case 'c':
			if (tablero[0][2] == NULL)
			{
				actualizar_turno(0, 2);
				return 1;
			}
			break;
		case 'd':
			if (tablero[1][0] == NULL)
			{
				actualizar_turno(1, 0);
				return 1;
			}
			break;
		case 'e':
			if (tablero[1][1] == NULL)
			{
				actualizar_turno(1, 1);
				return 1;
			}
			break;
		case 'f':
			if (tablero[1][2] == NULL)
			{
				actualizar_turno(1, 2);
				return 1;
			}
			break;
		case 'g':
			if (tablero[2][0] == NULL)
			{
				actualizar_turno(2, 0);
				return 1;
			}
			break;
		case 'h':
			if (tablero[2][1] == NULL)
			{
				actualizar_turno(2, 1);
				return 1;
			}
			break;
		case 'i':
			if (tablero[2][2] == NULL)
			{
				actualizar_turno(2, 2);
				return 1;
			}
			break;

		default:
			break;
		}
	}
	return 0;
}

int verificar_ganador()
{
	if (tablero[0][0] != NULL && tablero[0][0] == tablero[0][1] && tablero[0][0] == tablero[0][2])
	{
		return 1;
	}
	if (tablero[1][0] != NULL && tablero[1][0] == tablero[1][1] && tablero[1][0] == tablero[1][2])
	{
		return 1;
	}
	if (tablero[2][0] != NULL && tablero[2][0] == tablero[2][1] && tablero[2][0] == tablero[2][2])
	{
		return 1;
	}
	if (tablero[0][0] != NULL && tablero[0][0] == tablero[1][0] && tablero[0][0] == tablero[2][0])
	{
		return 1;
	}
	if (tablero[0][1] != NULL && tablero[0][1] == tablero[1][1] && tablero[0][1] == tablero[2][1])
	{
		return 1;
	}
	if (tablero[0][2] != NULL && tablero[0][2] == tablero[1][2] && tablero[0][2] == tablero[2][2])
	{
		return 1;
	}
	if (tablero[0][0] != NULL && tablero[0][0] == tablero[1][1] && tablero[0][0] == tablero[2][2])
	{
		return 1;
	}
	if (tablero[0][2] != NULL && tablero[0][2] == tablero[1][1] && tablero[0][2] == tablero[2][0])
	{
		return 1;
	}
	return 0;
}
void identificar_ganador(int turno_anterior)
{
	cout <<endl<< "!Felicitaciones¡";
	if (turno_anterior % 2 == 0)
	{
		cout << "el ganador es \" " << jugador1 << "\" [x]";
	}
	else
	{
		cout << "el ganador es \" " << jugador2 << "\" [o]";
	}
	turno++;
}

int main()
{
	int numero_turno = 0;
	int bandera_jugada = 0;
	int bandera_ganador = 0;

	system("cls");
	cout<<"\t EL JUEGO DEL GATO"<<endl<<endl
	<<"Ingrese nombre del jugador 1: ";
	cin>>jugador1;
	cout<<"Ingrese nombre del jugador 2: ";
	cin>>jugador2;
    system("cls");

	while (numero_turno < 9 && bandera_ganador == 0)
	{
		system("cls");
		crear_tablero();
		bandera_jugada = verificar_jugada(posibles_jugadas());
		if (bandera_jugada == 1)
		{
			bandera_ganador = verificar_ganador();
			numero_turno++;
		}
	}
	cout << endl;
	system("cls");
	crear_tablero();
	if (bandera_ganador == 1)
	{
		identificar_ganador(numero_turno - 1);
	}
	else
	{
		cout << "EL juego termino en un empate";
	}

	return 0;
}