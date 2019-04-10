#include <stdio.h>
#include <string.h>
#include <math.h>
typedef struct{
	int numero;
	char nombre[40];
	float precio;
}productos;

void printLista(productos nlista[10]);
productos ListaCompra[10];




///
int main()
{
int fin=1;
int entendido;
char lugar;
char sn;//si o no
int i;
int numeroProducto;

productos lista_pan[10]={
	{1,"pan blanco", 0.5},
	{2,"pan integral", 0.65},
	{3,"pan de molde", 1.45},
	{4,"palmerea de chocolate", 0.75},
	{5,"bizcochon", 5.99},
	{6,"kg de harina", 0.67},
	{7,"azucar", 1.25},
	{8,"sal",1.15},
	{9,"napolitana", 1.05},
	{10,"pan de semillas", 0.67}
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
			printf("Elija el articulo que desee de la seccion de panaderia\n");
			printLista(lista_pan);
			scanf("%i",&numeroProducto);
			if (numeroProducto>0 && numeroProducto<11)
			{
			ListaCompra[i]=lista_pan[numeroProducto-1];
			i++;//Apartar siguiente compra
			}
			else
			printf("Numero incorrecto\n");
			break;
		case 'p':
			printf("Elija el articulo que desee de la seccion de pescaderia\n");
			printLista(lista_pescado);
				scanf("%i",&numeroProducto);
			if (numeroProducto>0 && numeroProducto<11)
			{
			ListaCompra[i]=lista_pescado[numeroProducto-1];
			i++;//Apartar siguiente compra
			}
			else
			printf("Numero incorrecto\n");
			break;
		case 'f':
			printf("Elija el articulo que desee de la seccion de fruteria\n");
			printLista(lista_fruta);
			scanf("%i",&numeroProducto);
			if (numeroProducto>0 && numeroProducto<11)
			{
			ListaCompra[i]=lista_fruta[numeroProducto-1];
			i++;//Apartar siguiente compra
			}
			else
			printf("Numero incorrecto\n");
			break;
		case 'c':
			printf("Elija el articulo que desee de la seccion de carniceria\n");
			printLista(lista_carne);
			scanf("%i",&numeroProducto);
			if (numeroProducto>0 && numeroProducto<11)
			{
			ListaCompra[i]=lista_carne[numeroProducto-1];
			i++;//Apartar siguiente compra
			}
			else
			printf("Numero incorrecto\n");
			break;
		default:
			printf("No tenemos esa seccion\n");
			break;
	}
	
	entendido=1;	
		while (entendido==1)
	{
	printf("Ha terminado su compra?  (si o no)\n");
	fflush( stdin );
	scanf(" %c", &sn );
		if (sn=='s'){
			fin=0; entendido=0;
		}
		else if(sn=='n'){
				fin=1; entendido=0;
			}
		else{
		printf("No le he entendido, le preguntaremos de nuevo.\n");
			}
	}//Pregunta si quieres mas cosas
}//acaba bucle elegir cosas
printLista(ListaCompra);
}///acaba main









//funciones
void printLista(productos lista[10]){
	int i=0;
	printf("Numero\t Nombre\t Precio\n");
	for (i=0; i<10; i++){
		printf("%d\t %s\t %.2f\n",
		        lista[i].numero, lista[i].nombre, lista[i].precio);
		
		
	}
}

