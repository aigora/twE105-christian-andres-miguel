
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct{
	int numero;
	char nombre[40];
	float precio;
	int cantidad;
}productos;


void printLista(productos nlista[1000], int nelementos);
//Funcion para imprimir lista

void precioTotal(productos nLista[1000], int nelementos);
//Funcion que suma los precios de una lista
void anadir_a_lista(productos nLista[1000], productos *lugarLista, int elementosComprados);
//Anade los elementos seleccionados a la lista final con sus respectivas cantidades

int main()
{
while(1)
{
system("cls");//Limpiar pantalla
int fin=1;
int entendido;
char lugar;
char sn;//si o n
int i;
int numeroProducto;
int elementosComprados=0;
productos ListaCompra[10];
productos *lugarLista;
lugarLista=ListaCompra;
productos lista_pan[10]={
	{1,"pan blanco", 0.5, 0},
	{2,"pan integral", 0.65, 0},
	{3,"pan de molde", 1.45, 0},
	{4,"palmerea de chocolate", 0.75, 0},
	{5,"bizcochon", 5.99, 0},
	{6,"kg de harina", 0.67, 0},
	{7,"azucar", 1.25, 0},
	{8,"sal",1.15,0},
	{9,"napolitana", 1.05,0},
	{10,"pan de semillas", 0.67,0}
	};
productos lista_pescado[10]={
	{1,"dorada", 7.5},
	{2,"lubina", 7.65},
	{3,"atun rojo", 12.45},
	{4,"pulpo", 10.75},
	{5,"calamar", 11.99},
	{6,"bacalao", 8.67},
	{7,"sargo", 10.25},
	{8,"almeja",9.95},
	{9,"sardina", 7.05},
	{10,"caballa", 5.67}
	};

productos lista_fruta[10]={
	{1,"naranjas", 1.15},
	{2,"tomates", 2.65},
	{3,"pera", 2.45},
	{4,"manzana", 1.25},
	{5,"platano", 1.49},
	{6,"lechuga", 0.67},
	{7,"papas", 1.35},
	{8,"ajos", 1.95},
	{9,"cebolla blanca", 1.55},
	{10,"cebolla roja", 1.67}
	};
productos lista_carne[10]={
	{1,"pechuga pollo", 4.16},
	{2,"filete ternera", 5.65},
	{3,"chuleta cerdo", 4.45},
	{4,"panceta", 4.25},
	{5,"chuleton vaca", 5.49},
	{6,"chuleta pavo", 4.67},
	{7,"bistec cerdo", 3.95},
	{8,"jamon", 7.95},
	{9,"pechuga pavo", 5.53},
	{10,"muslo pollo", 3.67}
	};
	printf("Bienvenido a nuestro supermecado, tenemos varias seccion donde usted podra comprarlo que quiera.\n");
while (fin!=0){
	printf(" Desea ir a la panaderia(d),pescaderia(p),fruteria(f) o carniceria(c)?\n");
	fflush( stdin );
	scanf(" %c",&lugar);
	switch (lugar){
		case 'd':
		case 'D':
			printf("Elija el articulo que desee de la seccion de panaderia\n");
			printLista(lista_pan, 10);
			anadir_a_lista(lista_pan, (lugarLista+elementosComprados), elementosComprados);
			break;
		case 'p':
		case 'P':
			printf("Elija el articulo que desee de la seccion de pescaderia\n");
			printLista(lista_pescado, 10);
			anadir_a_lista(lista_pescado, (lugarLista+elementosComprados), elementosComprados);
			break;
		case 'f':
		case 'F':
			printf("Elija el articulo que desee de la seccion de fruteria\n");
			printLista(lista_fruta, 10);
			anadir_a_lista(lista_fruta, (lugarLista+elementosComprados), elementosComprados);
			break;
		case 'c':
		case 'C':
			printf("Elija el articulo que desee de la seccion de carniceria\n");
			printLista(lista_carne, 10);
			anadir_a_lista(lista_carne, (lugarLista+elementosComprados), elementosComprados);
			break;
		default:
			printf("No tenemos esa seccion\n");
			elementosComprados--;//evitamos la suma de un articulo nulo
			break;
	}
	elementosComprados++;//Pasar a la siguiente posicion de la lista de la compra
	entendido=1;	
		while (entendido==1)
	{
	printf("Ha terminado su compra?  (si o no)\n");
	fflush( stdin );
	scanf(" %c", &sn );
		if (sn=='s'){
			fin=0; entendido=0;//Muestra la cantidad a pagar
			lugarLista++;
		}
		else if(sn=='n'){
				fin=1; entendido=0;//Vuelve a preguntar la seccion
			}
		else{
		printf("No le he entendido, le preguntaremos de nuevo.\n");
			}
	}//Pregunta si quieres mas cosas
}//acaba bucle elegir cosas
printLista(ListaCompra, elementosComprados);

precioTotal(ListaCompra, elementosComprados);
}//while repetitivo
}///acaba main






//funciones
void printLista(productos lista[10], int n){///Funcion que imprime cada lista
	int i=0;
	printf("Numero\t Nombre\t Precio\t Cantidad\n");
	for (i=0; i<n; i++){
		printf("%d\t %s\t %.2f\t %i\n",
		lista[i].numero, lista[i].nombre, lista[i].precio, lista[i].cantidad);
	}
}
void precioTotal(productos *lugarLista, int elementosComprados){//Funcion que imprime el precio total
	int i=0;
	float sumaPrecio=0;//cantidad que comprara cliente 
	float paga=0;//cantidad que pagara el cliente
	for (i=0; i<elementosComprados; i++)
	{
		sumaPrecio+=(lugarLista->precio);
		lugarLista++;
	}
	printf("Total a pagar: %.2f\n", sumaPrecio);
	printf("Pague querido cliente\n");
	fflush( stdin );
	scanf("%f",&paga);
	while (paga<sumaPrecio)//mientres lo que pagua el cliente sea menor que lo que ha comprado, se vuelve a pedir el dinero
	{
		printf("La compra supera esa cantidad, introduce la cantidad a pagar\n");
		scanf("%f",&paga);	
	}
	printf("Le devolvemos %.2f, tengo un buen dia\n",paga-sumaPrecio);//muestra la cantidad a devolver
}




void anadir_a_lista(productos nLista[1000], productos *lugarLista, int elementosComprados)//Funcion que incrementa cada articulo a la lista de la compra
{
	int numeroProducto,cantidad;
	int i=1;
	printf("Escoja el producto que quiera:\t");
	while (i==1)//Al equivocarte al elegir numero del producto te lo vuelve a pedir
	{
		scanf("%i",&numeroProducto);//Te pide el numero del producto

		if (numeroProducto>0 && numeroProducto<11){
			*lugarLista=nLista[numeroProducto-1];//rellena el puntero lugarLista con los datos del producto seleccionado
			lugarLista->numero=elementosComprados+1;//cambia el numero del producto por el del numero de productos que lleves comprados
			i=0;//Para salir del while
			}
		else
			printf("Numero incorrecto, escriba en numero entre el 1 y el 10\n");
	}
	printf("Escribe la cantidad necesitada\n");
	scanf("%i",&cantidad);//Te pide la cantidad del producto
	lugarLista->cantidad=cantidad;//Escribe la cantidad en su lugar
	lugarLista->precio=cantidad*(lugarLista->precio);//Multiplica la cantidad por el precio para mostrar el precio total
}
