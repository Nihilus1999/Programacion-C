#include <stdio.h>
#include <stdlib.h>

int main(){
    int i,j,n,aux,vector[10];

    printf("introduzca la cantidad de elementos: ");
    scanf("%i",&n);

    for(i=0;i<n;i++){
        printf("\n\nElemento %i: ",i);
        scanf("%i",&vector[i]);
    }

    system("cls");
    for(i=0;i<n;i++){
        printf("[%i] ",vector[i]);
    }

    for(i=0;i<n;i++){
        for(j=0;j<(n-1);j++){
            if(vector[j]>vector[j+1]){
                aux = vector[j];
                vector[j]=vector[j+1];
                vector[j+1]=aux;
            }
        }
    }
    printf("\n\n-----APLICANDO METODO DE BURBUJA-----\n\n");
    for(i=0;i<n;i++){
        printf("[%i] ",vector[i]);
    }

    getch();
    return 0;
}