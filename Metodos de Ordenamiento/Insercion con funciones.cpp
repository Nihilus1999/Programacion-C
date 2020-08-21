#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int datos(int *a, int *b);
void insercion(int *a, int b);
void mostrar(int *a, int b);

int main(){
    int op,vector[10],n;
    while(op!=0){
        printf("1. pedir valores del arreglo\n");
        printf("2. aplicar metodo de insercion\n");
        printf("3. mostrar elementos del vector\n");
        printf("0. salir\n\n");
        printf("introduzca una opcion: ");
        scanf("%i",&op);

        switch(op){
            case 1:
            system("cls");
            datos(&vector[0],&n);
            break;

            case 2:
            system("cls");
            insercion(&vector[0],n);
            break;

            case 3:
            system("cls");
            mostrar(&vector[0],n);
            break;
        }
    }
    return 0;
}

int datos(int *a, int *b){
    int i;
    while(1){
        printf("introduzca la cantidad de elementos(1-10): ");
        scanf("%i",b);

        if(*b>0 && *b<11){

            for(i=0;i<*b;i++,a++){
            printf("\n[%i]: ",i+1);
            scanf("%i",a);
            }
            system("cls");
            return 0;
        } 
        else{
            printf("\n\nel numero no coincide en el parametro");
            getch();
            system("cls");
        }
    } return 1;

}
void insercion(int *a, int b){
    int i, j,aux;

    for(i=1;i<b;i++){
        for(j=i;j>0;j--){
            if(a[j]<a[j-1]){
                aux = a[j];
                a[j]= a[j-1];
                a[j-1]=aux;
            }else{
                break;
            }
        }
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
    system("cls");

}