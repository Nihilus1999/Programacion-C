#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(){
    int n,i,j,aux,vector[10],min;
    printf("introduzca la cantidad del arreglo(max 10): ");
    scanf("%i",&n);

    for(i=0;i<n;i++){
        printf("\n\nelemento %i: ",i);
        scanf("%i",&vector[i]);
    }
    system("cls");
    for(i=0;i<n;i++){
        printf("[%i] ",vector[i]);
    }
    getch();

    for(i=0;i<n-1;i++){
        min = i;
        for(j=i+1;j<n;j++){
            if(vector[j]<vector[min]){
                min=j;
            }
        }
        aux = vector[i];
        vector[i] = vector[min];
        vector[min]=aux;
    }

    printf("\n\n------APLICANDO METODO DE SELECCION----\n\n");
    for(i=0;i<n;i++){
        printf("[%i] ",vector[i]);
    }

    getch();
    return 0;
}