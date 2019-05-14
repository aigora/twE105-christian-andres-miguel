#include "Libreria.h"



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
int k,z=0;
usuariocontrasena usuarios;
usuariocontrasena registro[100];
productos ListaCompra[10];
productos *lugarLista;
lugarLista=ListaCompra;
productos lista_pan[10],lista_pescado[10], lista_fruta[10], lista_carne[10];//Lista de prouctos de cada seccion
regalos lista_regalos[10];
FILE *pf,*pf2,*pf3,*pf4,*pf5,*pregistro,*paux;//punteros para ficheros
pf = fopen("pescaderia.txt", "r");
pf2 = fopen("panaderia.txt", "r");
pf3 = fopen("fruteria.txt", "r");
pf4 = fopen("carniceria.txt", "r");
pf5 = fopen("regalos.txt", "r");
pregistro = fopen("usuarios.txt", "r");

if (pf == NULL || pf2 == NULL || pf3 == NULL || pf4 == NULL || pf5==NULL || pregistro == NULL){
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
		fscanf(pf5,"%i;%[^;];%i",&lista_regalos[j].numero,&lista_regalos[j].nombre,&lista_regalos[j].puntos);
	}
	i=0;
	while(fscanf(pregistro,"%i;%[^;];%i", &registro[i].contrasena,registro[i].usuario,&registro[i].puntos) != EOF)	{
		i++;
	}
	nLineas=i;
//printf("%i",nLineas);
	fclose(pf),fclose(pf2),fclose(pf3),fclose(pf4),fclose(pregistro);//Cierra los ficheros
}
printf(" Desea usted comprar(c) o canjear articulos con los puntos(p)?\n");
fflush( stdin );
scanf(" %c",&lugar);
	switch (lugar){
case 'c':
case 'C':
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
		switch (sn){
			case 's':
			case 'S':
				printf("Escribe tu Usuario y Contrasena (Ejemplo: pepito 5656)\n");
				scanf("%s %i",usuarios.usuario,&usuarios.contrasena);
				comparado=0;
				for (k=0;k<nLineas;k++){
					printf("%s\n",registro[k].usuario);
					printf("%s\n",usuarios.usuario);
					if(strcmp(usuarios.usuario,registro[k].usuario)==0){ 
					comparado++;
					z=k; //Guarda la posicion en la cual esta el usuario
					}
				}
				printf("%i\n",comparado);
				if (comparado==1 && registro[z].contrasena==usuarios.contrasena){
					aplicadescuento=1;
					registrado=1;
					printf("Usuario Correcto\n");
					printf("Obtienes %i puntos por tu compra\n",puntos(ListaCompra,elementosComprados));						
					usuarios.puntos=puntos(ListaCompra,elementosComprados)+registro[z].puntos;
					paux = fopen("auxiliar.txt", "w");
					if (paux == NULL){
						printf("Error al abrir el fichero.\n");
						return -1;	
					}
					else{
						for(i=0;i<nLineas;i++){ //Vuelve a escribir el fichero con los nuevos puntos del usuario tras la compra
							if(strcmp(usuarios.usuario, registro[i].usuario)==0)
							fprintf(paux,"%i;%s;%i\n",usuarios.contrasena,usuarios.usuario,usuarios.puntos);
							else 
							fprintf(paux,"%i;%s;%i\n",registro[i].contrasena,registro[i].usuario,registro[i].puntos);
						} 
					}
					fclose(paux);
					if(remove("usuarios.txt")==0)	//Borramos archivo
						printf("Eliminado con exito\n");
					else
						printf("No se pudo eliminar\n");
					
					if(rename("auxiliar.txt","usuarios.txt")==0)//Cambiamos nombre al archivo
						printf("Cambiado con exito\n");
					else
						printf("No se pudo cambiar\n");
					
				}
				else 
					if (comparado==0)
				printf("El nombre de usuario %s no esta registrado\n",usuarios.usuario);
					else
				printf("Error al introducir contrasena\n");
				break;
			case 'n':
			case 'N':
				printf("Quieres una tarjeta de descuento? (si o no)\n");
				fflush( stdin );
				scanf(" %c", &sn );
				if(sn=='s' || sn=='S'){
					printf("Escribe un nuevo Usuario y Contrasena (Ejemplo: pepitonuevo 56565)\n");
					scanf("%s %i",usuarios.usuario,&usuarios.contrasena);
					comparado=0;
						while (usuarionuevo==0){//Pide nuevo usuario mientras el nombre de usuario este ya cogido
							for (k=0;k<nLineas;k++){
								if(strcmp(usuarios.usuario,registro[k].usuario)==0){   // -----------------Mirar porque solo funciona con el primer usuario-------------------
									comparado++;
								}
							}
							if (comparado==0){
								usuarionuevo=1;
							}
							else{
								printf("El usuario %s ya existe, escribe otro usuario y contrasena\n",usuarios.usuario);
								scanf("%s %i",usuarios.usuario,&usuarios.contrasena);
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
							fprintf(pregistro,"%i;%s;%i\n",usuarios.contrasena,usuarios.usuario,usuarios.puntos);// Anade el nuevo usuario con sus respectivos puntos
							registrado=1;
							aplicadescuento=1;
							printf("Usuario nuevo creado\n");
							printf("Obtienes %i puntos por tu compra\n",usuarios.puntos);
						}
						fclose(pregistro);
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
break;
case 'p':
case 'P':
	printf("Introduce tu usuario y contraseņa (Ejemplo: pepe 239)\n");
//	while(registrado==0){
//		scanf("%s %i",usuarios.usuario,usuarios.contrasena);
//		comparado=0;
//		for (k=0;k<nLineas;k++){
//			printf("%s\n",registro[k].usuario);
//			printf("%s\n",usuarios.usuario);
//			if(strcmp(usuarios.usuario,registro[k].usuario)==0){ 
//			comparado++;
//			z=k; //Guarda la posicion en la cual esta el usuario
//			}
//		}
//		printf("%i\n",comparado);
//		if (comparado==1 && registro[z].contrasena==usuarios.contrasena){
//			aplicadescuento=1;
//			registrado=1;
//			printf("Bienvenido %s, usted tiene %i puntos\n",usuarios.usuario,registro[z].puntos);
//			printListaRegalos(lista_regalos,10);
//			printf("Elige un articulo\n");
//			j=0;
//			while(j==0){
//				fflush( stdin );
//				scanf("%i",&numeroProducto);//Te pide el numero del producto
//				if (numeroProducto>0 && numeroProducto<11){
//					if(registro[z].puntos>lista_regalos[numeroProducto].puntos){
//						registro[z].puntos-=lista_regalos[numeroProducto].puntos;
//						paux = fopen("auxiliar.txt", "w");
//						if (paux == NULL){
//							printf("Error al abrir el fichero.\n");
//							return -1;	
//						}
//						else{
//							for(i=0;i<nLineas;i++){ //Vuelve a escribir el fichero con los nuevos puntos del usuario tras la compra
//								if(strcmp(usuarios.usuario, registro[i].usuario)==0)
//									fprintf(paux,"%i;%s;%i\n",usuarios.contrasena,usuarios.usuario,registro[z].puntos);
//								else 
//									fprintf(paux,"%i;%s;%i\n",registro[i].contrasena,registro[i].usuario,registro[i].puntos);
//							} 
//						}
//						fclose(paux);
//						if(remove("usuarios.txt")==0)	//Borramos archivo
//							printf("Eliminado con exito\n");
//						else
//							printf("No se pudo eliminar\n");
//						
//						if(rename("auxiliar.txt","usuarios.txt")==0)//Cambiamos nombre al archivo
//							printf("Cambiado con exito\n");
//						else
//							printf("No se pudo cambiar\n");
//						j=1;
//					}
//					else
//					printf("Puntos insuficientes\n");
//					j=1;
//				}
//				else
//				printf("Numero incorrecto\n");
//			}
//		}
//		else{
//		printf("Error al introducir usuario y contraseņa");
//		registrado=1;
//		}
//	}
	break;
default:
	printf("No le hemos entendido\n");
	sleep(2);
}//switch comprar regalos
}//while repetitivo
}//Acaba main






//funciones

