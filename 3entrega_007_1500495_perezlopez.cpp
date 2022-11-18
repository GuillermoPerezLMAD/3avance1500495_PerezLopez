#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include<locale.h>

using namespace std;
int* item, * año, registros, decision, n = 1;
string* nombre, * clasificacion, * caracteristica, * genero, * descripcion;
float* subtotal, * iva, * total;

void Alta();
void Eliminar();
void Lista();
void Modificar();
void Archivo();


int main()
{
	setlocale(LC_CTYPE, "SPANISH");
	int opcion;
	printf("\t ***GAMESTORE***\n");
	printf("1.-Alta\n 2.-Modificar\n 3.-Eliminar\n 4.-Lista\n 5.-Limpiar\n 6.-Archivo\n 7.-Salir\n");
	scanf_s("%d", &opcion);

	switch (opcion)
	{
	case 1:
		Alta();
		system("pause");
		system("cls");
		return main();
		break;
	case 2:
		Modificar();
		system("pause");
		system("cls");
		return main();
		break;

	case 3:
		Eliminar();
		system("pause");
		system("cls");
		return main();
		break;
	case 4:
		Lista();
		system("pause");
		system("cls");
		return main();
		break;

	case 5:
		system("cls");
		return main();
		break;

	case 6:
		Archivo(); 
		system("pause");
		system("cls");
		return main();
		break;

	case 7:
		Salir();
		exit(1);
	    break;

	default:
		system("pause");
		return main();
		break;

	}
}

void Alta()
{
	printf("Cuantos registros desa dar de alta \n");
	scanf_s("%d", &registros);
	item = new int[registros];
	año = new int[registros];
	nombre = new string[registros];
	clasificacion = new string[registros];
	caracteristica = new string[registros];
	genero = new string[registros];
	descripcion = new string[registros];
	subtotal = new float[registros];
	iva = new float[registros];
	total = new float[registros];

	for (int i = 0; i < registros; i++)
	{
		printf("ingrese el item \n");
		scanf_s("%d", &item[i]);
		/*do
		{
			if (item[i] != item[i - n])
			{
				n = n - 1;
			}
			else
			{
				printf("el articulo ya existe\n");
				printf("ingrese el articulo\n");
				scanf_s("%d", &item[i]);
			}
		} while (n < registros);*/
		printf("ingrese el año \n");
		scanf_s("%d", &año[i]);
		printf("ingrese el nombre \n");
		cin.ignore();
		getline(cin, nombre[i]);
		printf("ingrese la clasificacion \n");
		getline(cin, clasificacion[i]);
		printf("ingrese la caracteristica \n");
		getline(cin, caracteristica[i]);
		printf("ingrese el genero \n");
		getline(cin, genero[i]);
		printf("ingrese la descripcion \n");
		getline(cin, descripcion[i]);
		printf("ingrese el subtotal \n");
		scanf_s("%f", &subtotal[i]);
		iva[i] = subtotal[i] * 0.16;
		total[i] = subtotal[i] + iva[i];
	}
}

void Modificar()
{
	int modificar;
	do
	{
		printf("ingrese el numero del articulo a modificar \n");
		scanf_s("%d", &modificar);
	} while (modificar <= 0);

	for (int i = 0; i < registros; i++)
	{
		if (modificar == item[i])
		{
			printf("ingrese el año \n");
			scanf_s("%d", &año[i]);
			printf("ingrese el nombre \n");
			cin.ignore();
			getline(cin, nombre[i]);
			printf("ingrese la clasificacion \n");
			getline(cin, clasificacion[i]);
			printf("ingrese la caracterisica \n");
			getline(cin, caracteristica[i]);
			printf("ingrese el genero \n");
			getline(cin, genero[i]);
			printf("ingrese la descripcion \n");
			getline(cin, descripcion[i]);
			printf("ingrese el subtotal \n");
			scanf_s("%f", &subtotal[i]);
			iva[i] = subtotal[i] * 0.16;
			total[i] = subtotal[i] + iva[i];
		}
	}
}

void Eliminar()
{
	int eliminar;
	printf("ingrese el numero de archivos a eliminar \n");
	scanf_s("%d", &eliminar);

	for (int i = 0; i < registros; i++)
	{
		if (eliminar == item[i])
		{
			item[i] = 0;
		}
	}
}

void Lista()
{
	int op2;
	string busc;

	printf("1.-Clasificacion \n 2.-Genero \n 3.-Salir");
	scanf_s("%d", &op2);
	switch (op2)
	{
	case 1:
		printf("ingrese la clasificacion a buscar \n");
		cin.ignore();
		getline(cin, busc);
		for (int i = 0; i < registros; i++)
		{
			if (clasificacion[i] == busc)
			{
				if (item[i] != 0)
				{
					printf("articulo: %d \n", item[i]);
					printf("año: %d \n", año[i]);
					printf("videojuego: %s \n", nombre[i].c_str());
					printf("clasificacion: %s \n", clasificacion[i].c_str());
					printf("genero: %s \n", genero[i].c_str());
					printf("caracteristica: %s \n", caracteristica[i].c_str());
					printf("descripcion: %s \n", descripcion[i].c_str());
					printf("subtotal: %f \n", subtotal[i]);
					printf("iva: %f \n", iva[i]);
					printf("total: %f \n", total[i]);
				}
			}
		}

	case 2: 	
		printf("ingrese el genero a buscar \n");
		cin.ignore();
		getline(cin, busc);
		for (int i = 0; i < registros; i++)
		{
			if (genero[i] == busc)
			{
				if (item[i] != 0)
				{
					printf("articulo: %d \n", item[i]);
					printf("año: %d \n", año[i]);
					printf("videojuego: %s \n", nombre[i].c_str());
					printf("clasificacion: %s \n", clasificacion[i].c_str());
					printf("genero: %s \n", genero[i].c_str());
					printf("caracteristica: %s \n", caracteristica[i].c_str());
					printf("descripcion: %s \n", descripcion[i].c_str());
					printf("subtotal: %f \n", subtotal[i]);
					printf("iva: %f \n", iva[i]);
					printf("total: %f \n", total[i]);
				}
			}
		}
		break;
	case 3: 
		break;
	}
}

void Archivo()
{
	ofstream PIA;
	string nombre;

	nombre = "PROYECTOFINAL.txt";
	PIA.open(nombre.c_str(), ios::out);

	if (PIA.fail())
	{
		printf("ERROR NO SE GENERA ARCHIVO \n");
		system("pause");
		exit(1);
	}
	PIA << "\t INFORMACION \n";
	for (int i = 0; i < registros; i++)
	{
		if (item[i] != 0)
		{
			PIA << "Dato \n" << i + 1 << endl;
			PIA << "Articulo:" << item[i] << endl;
			PIA << "Año:" << año[i] << endl;
			PIA << "Videojuego:" << nombre[i] << endl;
			PIA << "Clasificacion:" << clasificacion[i] << endl;
			PIA << "Genero:" << genero[i] << endl;
			PIA << "Caracteristica:" << caracteristica[i] << endl;
			PIA << "Descripcion:" << descripcion[i] << endl;
			PIA << "Subtotal:" << subtotal[i] << endl;
			PIA << "IVA:" << iva[i] << endl;
			PIA << "Total:" << total[i] << endl;
			
		}
		
	}
}