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
int comparado;//Para comparar usuarios
char lugar;
char sn;//si o no
int i,j;
float precioParking=0;
float sumaPrecioProductos=0;
int numeroProducto;
int elementosComprados=0;
int segundos;
int minutos;
int nUsuario=0;//numero de usuarios
int k,z=0;
usuariocontrasena usuarios;
usuariocontrasena registro[100];
productos ListaCompra[20];
productos *lugarLista;
lugarLista=ListaCompra;
int nPan=0,nPes=0,nFru=0,nCa=0,nReg=0;//Numero de productos en listas
productos lista_pan[100],lista_pescado[100], lista_fruta[100], lista_carne[100];//Lista de prouctos de cada seccion
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
	while(fscanf(pf,"%i;%[^;];%f;%i",&lista_pescado[nPes].numero,&lista_pescado[nPes].nombre,&lista_pescado[nPes].precio,&lista_pescado[nPes].cantidad)!= EOF){//mete los productos de la pescaderia
		nPes++;
	}
	while(fscanf(pf2,"%i;%[^;];%f;%i",&lista_pan[nPan].numero,&lista_pan[nPan].nombre,&lista_pan[nPan].precio,&lista_pan[nPan].cantidad)!= EOF){
		nPan++;
	}
	while(fscanf(pf3,"%i;%[^;];%f;%i",&lista_fruta[nFru].numero,&lista_fruta[nFru].nombre,&lista_fruta[nFru].precio,&lista_fruta[nFru].cantidad)!= EOF){
		nFru++;
	}
	while(fscanf(pf4,"%i;%[^;];%f;%i",&lista_carne[nCa].numero,&lista_carne[nCa].nombre,&lista_carne[nCa].precio,&lista_carne[nCa].cantidad)!= EOF){
		nCa++;
	}
	while(fscanf(pf5,"%i;%[^;];%i",&lista_regalos[nReg].numero,&lista_regalos[nReg].nombre,&lista_regalos[nReg].puntos)!= EOF){
		nReg++;
	}
	while(fscanf(pregistro,"%i;%[^;];%i", &registro[nUsuario].contrasena,registro[nUsuario].usuario,&registro[nUsuario].puntos) != EOF)	{
		nUsuario++;
	}

	fclose(pf),fclose(pf2),fclose(pf3),fclose(pf4),fclose(pregistro);//Cierra los ficheros
}
system("Color F");
printf("Desea usted comprar(c) o canjear articulos con los puntos(p)?\n");
fflush( stdin );
scanf(" %c",&lugar);
	switch (lugar){
		case 'c':
		case 'C':
			system("cls");//Limpiamos pantalla
			system("Color B");//Cambio de color
			printf("Bienvenido a nuestro supermecado, tenemos varias secciones donde usted podra comprar lo que quiera.\n");
			while (fin!=0){
				printf("Desea ir a la panaderia(d),pescaderia(p),fruteria(f) o carniceria(c)?\n");
				fflush( stdin );
				scanf(" %c",&lugar);
				switch (lugar){
					case 'd':
					case 'D':
						printf("Elija el articulo que desee de la seccion de panaderia\n");
						printLista(lista_pan, nPan);
						anadir_a_lista(lista_pan, (lugarLista+elementosComprados), elementosComprados,nPan);
						break;
					case 'p':
					case 'P':
						printf("Elija el articulo que desee de la seccion de pescaderia\n");
						printLista(lista_pescado, nPes);
						anadir_a_lista(lista_pescado, (lugarLista+elementosComprados), elementosComprados,nPes);
						break;
					case 'f':
					case 'F':
						printf("Elija el articulo que desee de la seccion de fruteria\n");
						printLista(lista_fruta, nFru);
						anadir_a_lista(lista_fruta, (lugarLista+elementosComprados), elementosComprados,nFru);
						break;
					case 'c':
					case 'C':
						printf("Elija el articulo que desee de la seccion de carniceria\n");
						printLista(lista_carne, nCa);
						anadir_a_lista(lista_carne, (lugarLista+elementosComprados), elementosComprados,nCa);
						break;
					default:
						printf("No tenemos esa seccion\n");
						elementosComprados--;//Evitamos la suma de un articulo nulo
						break;
				}
				elementosComprados++;//Pasar a la siguiente posicion de la lista de la compra
				entendido=1;	
				while (entendido==1){
					printf("Ha terminado su compra?  (si o no)\n");
					fflush( stdin );
					scanf(" %c", &sn );
					if (sn=='s' || sn=='S'){
					fin=0; entendido=0; park=1;//Muestra la cantidad a pagar
					lugarLista++;
					}
					else if(sn=='n' || sn=='N'){
					fin=1; entendido=0;park=0;//Vuelve a preguntar la seccion
					}
					else{
					printf("No le he entendido, le preguntaremos de nuevo.\n");
					}
				}//Pregunta si quieres mas cosas
				if (elementosComprados==0){
				break;
				}
				while(park==1){
					printf("Has usado parking?  (si o no)\n");
					fflush( stdin );
					scanf(" %c", &sn );
					if (sn=='s' || sn=='S'){
						fint = time(NULL);
   						delta = fint - inicio;//delta sera la diferencia te tiempo entre que el usuario empieza a comprar hasta que termina
   						minutos=delta/60;
   						segundos=delta-minutos*delta;
						if(minutos>=2){//Si han pasado 2 minutos se cobrara el parking
							printf("Ha usado el parking durante %d minutos y %d segundos \n", minutos, segundos);
							precioParking=2+(delta-120)*0.005;
							sleep(2);
							printf("Al ser mas de dos minutos su uso tiene un coste de: %.2f\n",precioParking);
							fin=0; entendido=0; park=0;
						}
						else{
							if(minutos==0)
								printf("Ha usado el parking durante %d segundos\n", segundos);
							else
								printf("Ha usado el parking durante %d minutos y %d segundos \n", minutos, segundos);
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
			if (elementosComprados==0)
				break;
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
						for (k=0;k<nUsuario;k++){
							if(strcmp(usuarios.usuario,registro[k].usuario)==0){ 
								comparado++;
								z=k; //Guarda la posicion en la cual esta el usuario
							}
						}	
						if (comparado==1 && registro[z].contrasena==usuarios.contrasena){//Comparara las contrasenas cuando escribimos bien el usuario
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
								for(i=0;i<nUsuario;i++){ //Vuelve a escribir el fichero con los nuevos puntos del usuario tras la compra
									if(strcmp(usuarios.usuario, registro[i].usuario)==0)
									fprintf(paux,"%i;%s;%i\n",usuarios.contrasena,usuarios.usuario,usuarios.puntos);//Introduce al usuario con sus puntos actualizados
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
						else{
							if (comparado==0)
							printf("El nombre de usuario %s no esta registrado\n",usuarios.usuario);
							else
							printf("Error al introducir contrasena\n");
						}
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
								for (k=0;k<nUsuario;k++){
									if(strcmp(usuarios.usuario,registro[k].usuario)==0){  //Compara el usuario introducido con los usuarios que ya existian
										comparado++;
									}
								}
								if (comparado==0){
									usuarionuevo=1;
								}
								else{
									printf("El usuario %s ya existe, escribe otro usuario y contrasena\n",usuarios.usuario);//Si coincide con un usuario existente, te pide que escribas uno nuevo
									scanf("%s %i",usuarios.usuario,&usuarios.contrasena);
									comparado=0;
								}
							}
							registrado=1;
							usuarios.puntos=puntos(ListaCompra,elementosComprados);//Se asignan los puntos obtenidos por la compra
							printf("Ha obtenido %i puntos\n",usuarios.puntos);
							paux = fopen("auxiliar.txt", "w");
							if (paux == NULL){
								printf("Error al abrir el fichero.\n");
								return -1;	
							}
							else{
								for(i=0;i<nUsuario+1;i++){ //Vuelve a escribir el fichero con los nuevos puntos del usuario tras la compra
									if(i<nUsuario)
										fprintf(paux,"%i;%s;%i\n",registro[i].contrasena,registro[i].usuario,registro[i].puntos);//Copia los usuarios que ya estaban en su mismo lugar
									else 
										fprintf(paux,"%i;%s;%i\n",usuarios.contrasena,usuarios.usuario,usuarios.puntos);//Agrega el nuevo usuario
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
						else if(sn=='n' || sn=='N'){
							registrado=1;
						}
						break;
					default:
						printf("No le hemos entendido\n");
						break;
				}
			}//Acaba while registro
			system("cls");//Limpia pantalla
			if (elementosComprados==0)
				break;
			printLista(ListaCompra, elementosComprados);//Imprime la lista de la compra
			sleep(2);
			if (elementosComprados==0)
				break;
			precioTotal(ListaCompra, elementosComprados, precioParking, aplicadescuento);//Indica la cantidad a pagar
			break;
		case 'p':
		case 'P':
			system("cls");//Limpiamos pantalla
			system("Color E");//Cambiamos de color
			printf("Introduce tu usuario y contraseņa (Ejemplo: pepe 239)\n");
			while(registrado==0){
				scanf("%s %i",usuarios.usuario,&usuarios.contrasena);
				comparado=0;
				for (k=0;k<nUsuario;k++){
					if(strcmp(usuarios.usuario,registro[k].usuario)==0){
					comparado++;
					z=k; //Guarda la posicion en la cual esta el usuario
					}
				}
				if (comparado==1 && registro[z].contrasena==usuarios.contrasena){
					aplicadescuento=1;
					registrado=1;
					printf("Bienvenido %s, usted tiene %i puntos\n",usuarios.usuario,registro[z].puntos);
					printListaRegalos(lista_regalos,nReg);
					printf("Elige un articulo\n");
					j=0;
					while(j==0){
						fflush( stdin );
						scanf("%i",&numeroProducto);//Te pide el numero del producto
						if (numeroProducto>0 && numeroProducto<nReg+1){
							if(registro[z].puntos>=lista_regalos[numeroProducto-1].puntos){
								registro[z].puntos-=lista_regalos[numeroProducto-1].puntos;//Resta los puntos al usuario tras la compra
								paux = fopen("auxiliar.txt", "w");
								if (paux == NULL){
									printf("Error al abrir el fichero.\n");
									return -1;	
								}
								else{
									for(i=0;i<nUsuario;i++){ //Vuelve a escribir el fichero con los nuevos puntos del usuario tras la compra
										if(strcmp(usuarios.usuario, registro[i].usuario)==0)
											fprintf(paux,"%i;%s;%i\n",usuarios.contrasena,usuarios.usuario,registro[z].puntos);
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
								j=1;
								printf("Ha obtenido %s",lista_regalos[numeroProducto-1].nombre);
								sleep(2);	
							}
							else
								printf("Puntos insuficientes\n");
								sleep(2);
								j=1;
							}
						else
							printf("Numero incorrecto\n");
							printf("Vuelve a introducir numero\n");
							sleep(2);
						}
					}
				else{
					printf("Error al introducir usuario y contrasena");
					registrado=1;
					sleep(2);
				}
			}
			break;
		default:
			printf("No le hemos entendido\n");
			sleep(1);
	}//switch comprar regalos
}//while repetitivo
}//Acaba main


