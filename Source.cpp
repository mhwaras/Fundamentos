#include <stdlib.h>
#include <stdio.h>
#include "iostream"
#include "string"
#include <conio.h>

using namespace std;

struct lista_elementos
{
	char dato;
	int siguiente;
	int Status;

};

typedef struct lista_elementos Estado;

void tTransiciones(Estado **Qn, int estados, int k)
{
	Estado R;
	int j = 0, i = 0, x = 0;
	char *a;

	a = (char *)malloc((k + 1) * sizeof(char));

	for (i = 0; i < k; i++)
	{
		cout<<"Ingrese el elemento "<<i<<" del alfabeto: ";
		cin>>a[i];
	}
	a[k] = 0;

	do
	{
		cout << "Ingrese el Estado Final ";
		cin >> x;
	} while (x<0 || x >= estados);

	for (j = 0; j < k; j++)
	{
		Qn[x][j].siguiente = 2;
	}	
	
	cout<<endl<<"Ingrese la Tabla de Transiciones del Automata Finito Determinista: ";
	for (i = 0; i < estados; i++)
	{
		cout<<endl<<"Estado"<< i<<endl;
		for (j = 0; j < k; j++)
		{
			Qn[i][j].dato = a[j];
			do
			{
				cout<<"ESTADO siguiente Q(0-"<<estados-1<<") de Q"<<i<<" con entrada en "<<a[j]<<" : ";
				cin>>x;
			} while (x<0 || x>=estados);
			Qn[i][j].siguiente = x;
		}
	}
//	R = Qn;
	//return Qn;
}
int validar(Estado **Qn, char s, int estados, int k)
{
	int i, j;
	int R;
	for (i = 0; i < estados; i++)
	{
		for (j = 0; j < k; j++)
		{
			if (s=Qn[i][j].dato)
			{
				R = Qn[i][j].Status;
			}
		}
	}
	return R;
}
int main()
{
	int j = 0, i = 0, k = 0, l=0, x= 0, estados;
	char a[50];
	char y,s;
	Estado **Qn;
	int R;

	cout<<"Ingrese el numero de Estados del Automata Finito Determinista: ";
	cin>>estados;
	cout<<"Ingrese el numero de elementos del Alfabeto: ";
	cin>>k;

	Qn = (Estado **)malloc(estados * sizeof(Estado *));
	for (i = 0; i < estados; i++)
	{
		Qn[i] = (Estado *)malloc((k + 1) * sizeof(Estado));
		for (j = 0; j < k; j++)
		{
			Qn[i][j].dato = ' ';
			Qn[i][j].siguiente = 0;
			Qn[i][j].Status = 1;
		}
		Qn[i][k].dato = 0;
	}
	x = 0;
	for (j = 0; j < k; j++)
	{
		Qn[x][j].Status = 0;
	}

	tTransiciones(Qn, estados, k);

	do
	{
		cout << "Ingresa una cadena para validar : ";
		cin>>a;
		l = 0;
//		while (a[i] != 0)
//		{
		s = a[l];
		R=validar(Qn, s, estados, k);
		l++;
//		}
		if (R == 2)
		{
			cout << endl << "Cadena valida";
		}
		else
		{
			cout << endl << "Cadena invalida";
		}

		cout << endl<<"Presione: " << endl;
		cout << "S - SALIR " << endl;
		cout << "Presione cualquier tecla para Nueva Consulta : ";
		cin >> y;
	} while (y != 'S'&&y != 's');

	return(0);
}
