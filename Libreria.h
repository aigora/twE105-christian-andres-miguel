#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <conio.h>

typedef struct{
	int numero;
	char nombre[40];
	float precio;
	int cantidad;
}productos;

typedef struct{
	char usuario[40];
	int contrasena;
	int puntos;
}usuariocontrasena;

typedef struct{
	char nombre[40];
	int puntos;
	int numero;
}regalos;

void printLista(productos lista[10], int n);///Funcion que imprime cada lista
void printListaRegalos(regalos lista[10], int n);//Funcion que impreme lista regalos
void precioTotal(productos *lugarLista, int elementosComprados,float parking, int descuento);//Funcion que imprime el precio total
void anadir_a_lista(productos nLista[1000], productos *lugarLista, int elementosComprados,int nProducto);//Funcion que incrementa cada articulo a la lista de la compra
int puntos(productos *lugarLista, int elementosComprados);//Funcion que agrega puntos a los usuarios dependiendo de la cantidad comprada

