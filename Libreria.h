
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <conio.h>
void printLista(productos lista[10], int n);///Funcion que imprime cada lista
void precioTotal(productos *lugarLista, int elementosComprados,float parking, int descuento);//Funcion que imprime el precio total
void anadir_a_lista(productos nLista[1000], productos *lugarLista, int elementosComprados);//Funcion que incrementa cada articulo a la lista de la compra
int puntos(productos *lugarLista, int elementosComprados);

