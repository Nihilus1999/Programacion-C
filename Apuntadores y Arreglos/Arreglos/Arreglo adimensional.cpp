#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main (){
    int op = -1;
    int vector[10],i,n,s;
    int *a,*b,*c;
    
    while(op != 0){
        printf("----MENU DE MATRICES----\n\n");
        printf("1. realizar vector\n");
        printf("2. mostrar solo un elemento del vector\n");
        printf("3. mostrar todo el vector\n");
        printf("0. salir\n\n");
        printf("Introduzca una opcion: ");
        scanf("%i",&op);
        switch(op){
            case 1:
            system("cls");
            printf("----ELEMENTOS DE LA MATRIZ----\n\n");
            printf("tamaño del arreglo: ");
            scanf("%i",&n);
            system("cls");
            for(i=0;i<n;i++){
            printf("\nElemento %i: ",i);
            scanf("%i",&vector[i]);
            }
            system("cls");
            for(i=0;i<n;i++){
            printf("[%i] ",vector[i]);
            }
            printf("\n\n");
            system("pause");
            system("cls");
            break;

            case 2:
            system("cls");
            printf("----MOSTRAR SOLO UN ELEMENTO EN LOS ARREGLOS----\n\n");
            printf("introduzca el elemento de la casilla: ");
            scanf("%i",&s);
            i = 0;
            a = &vector[i + s];
            printf("\n[%i]\n\n",*a);
            system("pause");
            system("cls");
            break;

            case 3:
            system("cls");
            printf("----MOSTRAR TODO EL VECTOR----\n\n");
            for(i=0;i<n;i++){
            printf("[%i] ",vector[i]);
            }
            printf("\n\n");
            system("pause");
            system("cls");
            break;

            case 0:
            break;
        }
    }
    return 0;
}