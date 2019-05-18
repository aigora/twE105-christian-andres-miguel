#include "Libreria.h"

void printLista(productos lista[10], int n){///Funcion que imprime cada lista
	int i;
	sleep(1);
	printf("Numero\t\t Nombre\t\t\t Precio\t Cantidad\n");
	for (i=0; i<n; i++){
		printf("%d\t %s\t %.2f\t %i\n",lista[i].numero, lista[i].nombre, lista[i].precio, lista[i].cantidad);
	}
};

void printListaRegalos(regalos lista[10],int n){
	int i;
	sleep(1);
	printf("Numero\t\t Nombre\t\t\t Puntos\n");
	for (i=0; i<n; i++){
		printf("%i\t %s\t %i\n",lista[i].numero, lista[i].nombre, lista[i].puntos);	
	}
};


void precioTotal(productos *lugarLista, int elementosComprados,float parking, int descuento){//Funcion que imprime el precio total
	int i=0;
	float sumaPrecioProductos=0;//Cantidad que comprara cliente 
	float paga=0;//Cantidad que pagara el cliente
	float descuento095=0.95;
	for (i=0; i<elementosComprados; i++){
		sumaPrecioProductos+=(lugarLista->precio);//suma los precios de los productos
		lugarLista++;
	}
	if (descuento==0){
		printf("Total a pagar: %.2f\n", sumaPrecioProductos+parking);
		printf("Pague querido cliente\n");
		fflush( stdin );
		scanf("%f",&paga);
		while (paga<sumaPrecioProductos+parking){//Mientres lo que pagua el cliente sea menor que lo que ha comprado, se vuelve a pedir el dinero
			printf("La compra supera esa cantidad, introduce la cantidad a pagar\n");
			fflush( stdin );
			scanf("%f",&paga);	
		}
		printf("Le devolvemos %.2f, tenga un buen dia\n",paga-(sumaPrecioProductos+parking));//Muestra la cantidad a devolver
		sleep(10);
	}
	else{
		printf("Total a pagar: %.2f\n", sumaPrecioProductos*descuento095+parking);
		printf("Pague querido cliente\n");
		fflush( stdin );
		scanf("%f",&paga);
		while (paga<sumaPrecioProductos*descuento095+parking){//Mientres lo que pagua el cliente sea menor que lo que ha comprado, se vuelve a pedir el dinero
			printf("La compra supera esa cantidad, introduce la cantidad a pagar\n");
			fflush( stdin );
			scanf("%f",&paga);	
		}
		printf("Le devolvemos %.2f, tenga un buen dia\n",paga-(sumaPrecioProductos*descuento095+parking));//Muestra la cantidad a devolver
	}
	sleep(1);
};
void anadir_a_lista(productos nLista[1000], productos *lugarLista, int elementosComprados,int nProducto){//Funcion que incrementa cada articulo a la lista de la compra
	int numeroProducto,cantidad;
	int i=1;
	printf("Escoja el producto que quiera:\t");
	while (i==1){//Al equivocarte al elegir numero del producto te lo vuelve a pedir
		scanf("%i",&numeroProducto);//Te pide el numero del producto
		if (numeroProducto>0 && numeroProducto<nProducto+1){
			*lugarLista=nLista[numeroProducto-1];//Rellena el puntero lugarLista con los datos del producto seleccionado
			lugarLista->numero=elementosComprados+1;//Cambia el numero del producto por el del numero de productos que lleves comprados
			i=0;//Para salir del while
			}
		else
			printf("Numero incorrecto, escriba en numero entre el 1 y el 10\n");
			fflush( stdin );
	}
	printf("Escribe la cantidad necesitada\n");
	scanf("%i",&cantidad);//Te pide la cantidad del producto
	while(cantidad<1){//Evitar cantidades negativas y cantidad 0      
				printf("Cantidad invalida escriba una nueva\n");
				fflush( stdin );
				scanf("%i",&cantidad);//Te pide la cantidad del producto
	}
	nLista[numeroProducto-1].cantidad+=cantidad;//Al comprar varias veces un producto se va mostrando la cantidad
	lugarLista->cantidad=cantidad;//Escribe la cantidad en su lugar
	lugarLista->precio=cantidad*(lugarLista->precio);//Multiplica la cantidad por el precio para mostrar el precio total
};
int puntos(productos *lugarLista, int elementosComprados){
	int i=0;
	float sumaPrecioProductos=0;//Precio a pagar por el cliente
	for (i=0; i<elementosComprados; i++){
		sumaPrecioProductos+=(lugarLista->precio);
		lugarLista++;//puntero que ira apuntando a los productos de la lista de la compra
	}
	if (sumaPrecioProductos>50)
		return sumaPrecioProductos/5;
	else 
		return sumaPrecioProductos/10;
};
