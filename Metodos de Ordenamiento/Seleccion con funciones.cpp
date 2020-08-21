#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int datos(int *a, int *b);
void mostrar(int *a, int b);
void seleccion(int *a, int b);

int main(){
    int op = 1,vector[10],n = 0;

    while(op != 0) {
		system("cls");
		printf("1. pedir datos del vector\n");
		printf("2. realizar ordenamiento por seleccion\n");
		printf("3. mostrar resultado\n");
		printf("0. Salir\n");
		printf("\nIntroduzca una opcion: ");
		scanf("%i",&op);
		system("cls");
		switch(op){
			case 1: 
				datos(&vector[0],&n);
			break;
			case 2:
				seleccion(&vector[0],n);
			break;
			case 3:
				mostrar(&vector[0], n);
			break;
		}
	}
}

int datos(int *a,int *b){
    int i;
    while(1)
    {
        printf("introduzca la cantidad de elementos(1-10): ");
        scanf("%i",b);
        system("cls");
        if(*b>0 && *b<11){
            for(i=0;i<*b; i++){
                printf("\n[%i] = ",i+1);
                scanf("%i", a+i);
            }
            return 0;
        }else{
            system("cls");
            printf("el valor no es el correcto");
            getch();
            system("cls");
        }
    }
    return 1;
}

void seleccion(int *a, int b){
    int i,min=0,j,aux;
    for(i=0;i<b-1;i++){
        min=i;
        for(j=i+1;j<b;j++){
            if(a[j]<a[min]){
                min = j;
            }
        }
        aux = a[min];
        a[min] = a[i];
        a[i] = aux;
    }
    system("cls");
    system("pause");
}


void mostrar(int *a, int b){
    int i;
    for(i=0;i<b;i++,a++){
    printf("[%i] ",*a);
    } 
    getch();
}