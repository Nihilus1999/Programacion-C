#include <stdio.h>
#include <stdlib.h>

int main(){
    int i,aux,posi,n,vector[10];

    printf("introduzca la cantidad de elementos de la matriz(max 10): ");
    scanf("%i",&n);
    system("cls");
    for(i=0;i<n;i++){
        printf("\nPosicion %i: ",i);
        scanf("%i",&vector[i]);
    }
    system("cls");
    for(i=0;i<n;i++){
        printf("[%i] ",vector[i]);
    }
        
    printf("\n\n");
    system("pause");

    //Metodo de intercambio simple

    printf("\n\n-----APLICANDO METODO DE INSERCION-----\n\n");

    for(i=0;i<n;i++){
        posi = i;
        aux = vector[i];
        while(posi >0 && (vector[posi-1]>aux)){
            vector[posi] = vector[posi-1];
            posi--;
        }
        vector[posi]= aux;
    }

    for(i=0;i<n;i++){
        printf("[%i] ",vector[i]);
    }

    printf("\n\n");
    system("pause");
    return 0;
}