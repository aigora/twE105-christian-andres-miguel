#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
	int fin=1;
	int entendido;
char lugar;
char sn;//si o no

printf("Bienvenido a nuestro supermecado, tenemos varias seccion donde usted podra comprarlo que quiera.\n");

while (fin!=0){
	
	printf(" Desea ir a la panaderia(d),pescaderia(p),fruteria(f) o carniceria(c)?\n");
	fflush( stdin );
	scanf(" %c",&lugar);
	switch (lugar){
		case 'd':
			printf("Elija el articulo que desee de la seccion de panaderia\n");
			break;
		case 'p':
			printf("Elija el articulo que desee de la seccion de pescaderia\n");
			break;
		case 'f':
			printf("Elija el articulo que desee de la seccion de fruteria\n");
			break;
		case 'c':
			printf("Elija el articulo que desee de la seccion de carniceria\n");
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
		if (sn=='s')
		{
			fin=0; entendido=0;
		}
		else if(sn=='n')
			{
				fin=1; entendido=0;
			}
		else
			{
		printf("No le he entendido, le preguntaremos de nuevo.\n");
			}
	}
}
}
