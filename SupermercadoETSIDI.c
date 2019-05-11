#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
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

int puntos(productos nLista[1000], int nelementos);

void printLista(productos nlista[1000], int nelementos);
//Funcion para imprimir lista

void precioTotal(productos nLista[1000], int nelementos,float parking,int descuento);
//Funcion que suma los precios de una lista
void anadir_a_lista(productos nLista[1000], productos *lugarLista, int elementosComprados);
//Anade los elementos seleccionados a la lista final con sus respectivas cantidades

int main(int argc, char** argv){
while(1)
{
system("cls");//Limpiar pantalla
	time_t inicio;
    time_t fint;
    time_t delta;//Para indicar la diferencia de tiempo entre el inicio y el fin de la compra
	
    inicio = time(NULL);//Comienza cronometro
int fin=1;
int registrado=0;
int usuarionuevo=0;
int aplicadescuento=0;
int entendido;
int park;
int comparar,comparado;
char lugar;
char sn;//si o no
int i,j;
char x;
float precioParking=0;
float sumaPrecioProductos=0;
int numeroProducto;
int elementosComprados=0;
int segundos;
int minutos;
int nLineas;
usuariocontrasena usuarios;
usuariocontrasena registro[100];
productos ListaCompra[10];
productos *lugarLista;
lugarLista=ListaCompra;
productos lista_pan[10],lista_pescado[10], lista_fruta[10], lista_carne[10];//Lista de productos de cada seccion
FILE *pf,*pf2,*pf3,*pf4,*pregistro;//punteros para ficheros
pf = fopen("pescaderia.txt", "r");
pf2 = fopen("panaderia.txt", "r");
pf3 = fopen("fruteria.txt", "r");
pf4 = fopen("carniceria.txt", "r");
pregistro = fopen("usuarios.txt", "r");

if (pf == NULL || pf2 == NULL || pf3 == NULL || pf4 == NULL || pregistro == NULL){
	printf("Error al abrir el fichero.\n");
	return -1;	
}
else
{
	for(j=0;j<10;j++)//-------------Deberiamos cambiar el 10 por una variable------------------
	{
		fscanf(pf,"%i;%[^;];%f;%i",&lista_pescado[j].numero,&lista_pescado[j].nombre,&lista_pescado[j].precio,&lista_pescado[j].cantidad);//mete los productos de la pescaderia
		fscanf(pf2,"%i;%[^;];%f;%i",&lista_pan[j].numero,&lista_pan[j].nombre,&lista_pan[j].precio,&lista_pan[j].cantidad);
		fscanf(pf3,"%i;%[^;];%f;%i",&lista_fruta[j].numero,&lista_fruta[j].nombre,&lista_fruta[j].precio,&lista_fruta[j].cantidad);
		fscanf(pf4,"%i;%[^;];%f;%i",&lista_carne[j].numero,&lista_carne[j].nombre,&lista_carne[j].precio,&lista_carne[j].cantidad);
	}
	i=0;
	while(fscanf(pregistro,"%[^;];%i;%i)",&registro[i].usuario,&registro[i].contrasena,&registro[i].puntos) != EOF)
	{
		i++;
	}
	nLineas=i;
//	printf("%i",nLineas);
	fclose(pf),fclose(pf2),fclose(pf3),fclose(pf4),fclose(pregistro);//Cierra los ficheros
}
	printf("Bienvenido a nuestro supermecado, tenemos varias secciones donde usted podra comprar lo que quiera.\n");
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
			elementosComprados--;//Evitamos la suma de un articulo nulo
			break;
	}
	elementosComprados++;//Pasar a la siguiente posicion de la lista de la compra
	entendido=1;	
		while (entendido==1)
	{
	printf("Ha terminado su compra?  (si o no)\n");
	fflush( stdin );
	scanf(" %c", &sn );
		if (sn=='s' || sn=='S'){
			fin=0; entendido=0;park=1;//Muestra la cantidad a pagar
			lugarLista++;
		}
		else if(sn=='n' || sn=='N'){
				fin=1; entendido=0;park=0;//Vuelve a preguntar la seccion
			}
		else{
		printf("No le he entendido, le preguntaremos de nuevo.\n");
			}
	}//Pregunta si quieres mas cosas
	while(park==1)
		{
			printf("Ha usado parking?  (si o no)\n");
			fflush( stdin );
			scanf(" %c", &sn );
		if (sn=='s' || sn=='S'){
			fint = time(NULL);
   			delta = fint - inicio;//delta sera la diferencia te tiempo entre que el usuario empieza a comprar hasta que termina
   			minutos=delta/60;
   			segundos=delta-minutos*delta;
   			
			if(delta>120){
			printf("Ha usado el parking durante %d minutos y %d segundos \n", minutos, segundos);
			precioParking=2+(delta-120)*0.005;
			sleep(2);
			printf("Al ser mas de dos minutos su uso tiene un coste de: %.2f\n",precioParking);
			fin=0; entendido=0; park=0;
			}
		else{
			if(minutos==0){
				printf("Ha usado el parking durante %d segundos\n", segundos);
				}
				else{
				printf("Ha usado el parking durante %d minutos y %d segundos \n", minutos, segundos);
				}
			sleep(2);
			printf("Al ser menos de dos minutos su uso es gratuito\n");
			fin=0; entendido=0; park=0;
			}
		}
		else if(sn=='n' || sn=='N'){
			fint = time(NULL);
    		delta = fint - inicio;
			fin=0; entendido=0; park=0;
			}
		else{
		printf("No le he entendido, le preguntaremos de nuevo.\n");
			}
		}
	}
	while(registrado==0){
		printf("Tienes tarjeta de descuento?  (si o no)\n");
		fflush( stdin );
		scanf(" %c", &sn );
		int k;
		switch (sn){
			case 's':
			case 'S':
				printf("Escribe tu Usuario y Contrasena (Ejemplo: pepito 5656)\n");
				scanf("%s %i",&usuarios.usuario,&usuarios.contrasena);
				comparar=0;
				comparado=0;
				for (k=0;k<nLineas;k++){
					comparar=strcmp(usuarios.usuario, registro[k].usuario);
					if (comparar==0)
					comparado++;
				}
				if (comparado==1 && registro[k].contrasena==usuarios.contrasena){
					aplicadescuento=1;
					registrado=1;
					printf("Usuario Correcto\n");
					printf("Obtienes %i puntos por tu compra\n",puntos(ListaCompra,elementosComprados));						
					usuarios.puntos=puntos(ListaCompra,elementosComprados)+registro[k].puntos;
					pregistro = fopen("usuarios.txt", "w");
					if (pregistro == NULL){
						printf("Error al abrir el fichero.\n");
						return -1;	
					}
					else{
						for(i=0;i<=100;i++){
							comparar=strcmp(usuarios.usuario, registro[i].usuario);
							if(comparar==0)
							fprintf(pregistro,"%s;%i;%i\n",usuarios.usuario,usuarios.contrasena,usuarios.puntos);
							else 
							fprintf(pregistro,"%s;%i;%i\n",registro[i].usuario,registro[i].contrasena,registro[i].puntos);
						}
					}
					fclose(pregistro);	
				}
				else
				printf("Error al introducir Usuario y contrasena\n");
				break;
			case 'n':
			case 'N':
				printf("Quieres una tarjeta de descuento? (si o no)\n");
				fflush( stdin );
				scanf(" %c", &sn );
				if(sn=='s' || sn=='S'){
					printf("Escribe un nuevo Usuario y Contrasena (Ejemplo: pepitonuevo 56565)\n");
					scanf("%s %i",&usuarios.usuario,&usuarios.contrasena);
					comparar=0;
					comparado=0;
						while (usuarionuevo==0){//Pide nuevo usuario mientras el nombre de usuario este ya cogido
							for (k=0;k<nLineas;k++){
								comparar=strcmp(usuarios.usuario,registro[k].usuario);
							//	printf("%s\t",registro[k].usuario);
							//	printf("%s\t",usuarios.usuario);
								if (comparar==0){   // Mirar porque solo funciona con el primer usuario
									comparado++;
								}
							}
							if (comparado==0){
								usuarionuevo=1;
							}
							else{
								printf("El usuario %s ya existe, escribe otro usuario y contrasena\n",usuarios.usuario);
								scanf("%s %i",&usuarios.usuario,&usuarios.contrasena);
								comparado=0;
							}
						}
						pregistro = fopen("usuarios.txt", "a");
						if (pregistro == NULL){
							printf("Error al abrir el fichero.\n");
						return -1;	
						}
						else{
						usuarios.puntos=puntos(ListaCompra,elementosComprados);
						fprintf(pregistro,"\n%s;%i;%i",usuarios.usuario,usuarios.contrasena,usuarios.puntos);
						registrado=1;
						aplicadescuento=1;
						printf("Usuario nuevo creado\n");
						printf("Obtienes %i puntos por tu compra\n",usuarios.puntos);
						}
				}
				else if(sn=='n' || sn=='N'){
					registrado=1;
					}
					break;
			default:
			printf("No le hemos entendido\n");
			break;
		}
	}//Acaba while registro
printLista(ListaCompra, elementosComprados);//Imprime la lista de la compra
//printf("%s %i",registro[0].usuario,registro[0].,contrasena); 
sleep(3);
precioTotal(ListaCompra, elementosComprados, precioParking, aplicadescuento);//Indica la cantidad a pagar
}//while repetitivo
}//Acaba main






//funciones
void printLista(productos lista[10], int n){///Funcion que imprime cada lista
	int i=0;
	printf("Numero\t\t Nombre\t\t\t Precio\t Cantidad\n");
	for (i=0; i<n; i++){
		printf("%d\t %s\t %.2f\t %i\n",
		lista[i].numero, lista[i].nombre, lista[i].precio, lista[i].cantidad);
	}
}
void precioTotal(productos *lugarLista, int elementosComprados,float parking, int descuento){//Funcion que imprime el precio total
	int i=0;
	float sumaPrecioProductos=0;//Cantidad que comprara cliente 
	float paga=0;//Cantidad que pagara el cliente
	float descuento095=0.95;
	for (i=0; i<elementosComprados; i++)
	{
		sumaPrecioProductos+=(lugarLista->precio);
		lugarLista++;
	}
	if (descuento==0)
	{
		printf("Total a pagar: %.2f\n", sumaPrecioProductos+parking);
	printf("Pague querido cliente\n");
	fflush( stdin );
	scanf("%f",&paga);
		while (paga<sumaPrecioProductos+parking)//Mientres lo que pagua el cliente sea menor que lo que ha comprado, se vuelve a pedir el dinero
		{
			printf("La compra supera esa cantidad, introduce la cantidad a pagar\n");
			fflush( stdin );
			scanf("%f",&paga);	
		}
		printf("Le devolvemos %.2f, tenga un buen dia\n",paga-(sumaPrecioProductos+parking));//Muestra la cantidad a devolver
		sleep(10);
	}
	else
	{
		printf("Total a pagar: %.2f\n", sumaPrecioProductos*descuento095+parking);
		printf("Pague querido cliente\n");
		fflush( stdin );
		scanf("%f",&paga);
		while (paga<sumaPrecioProductos*descuento095+parking)//Mientres lo que pagua el cliente sea menor que lo que ha comprado, se vuelve a pedir el dinero
		{
			printf("La compra supera esa cantidad, introduce la cantidad a pagar\n");
			fflush( stdin );
			scanf("%f",&paga);	
		}
		printf("Le devolvemos %.2f, tenga un buen dia\n",paga-(sumaPrecioProductos*descuento095+parking));//Muestra la cantidad a devolver
	}
	sleep(3);
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
	while(cantidad<1)//Evitar cantidades negativas y cantidad 0        -----------PREGUNTAR SI SE PUEDE HACER PARA QUE NO SE PILLE PROGRAMA AL PONER UNA LETRA--------------
		{
				printf("cantidad invalida escriba una nueva\n");
				fflush( stdin );
				scanf("%i",&cantidad);//Te pide la cantidad del producto
		}
	lugarLista->cantidad=cantidad;//Escribe la cantidad en su lugar
	lugarLista->precio=cantidad*(lugarLista->precio);//Multiplica la cantidad por el precio para mostrar el precio total
}

int puntos(productos *lugarLista, int elementosComprados){
	int i=0;
	float sumaPrecioProductos=0;//Cantidad que comprara cliente 
	for (i=0; i<elementosComprados; i++)
	{
		sumaPrecioProductos+=(lugarLista->precio);
		lugarLista++;
	}
	printf("%f\n",sumaPrecioProductos);
	if (sumaPrecioProductos>50)
		return sumaPrecioProductos/5;
	else 
		return sumaPrecioProductos/10;
}
