#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Escribe un programa que lea de la entrada estándar un vector de números 
//y muestre en la salida estándar los números del vector con sus índices asociados.

int main(){
    int array[50];
    int i=0,n;

    printf("digite la cantidad de elementos del arreglo: ");
    scanf("%i",&n);
    do
    {
        printf("\nescriba el valor de elementos del arreglo: ");
        scanf("%i",&array[i]);
        i++;
    } while (i<n);
    system("cls");

    printf("el resultado es: \n\n");

    for (i = 0; i < n; i++){
        printf("[%i]   ->   %i\n",i,array[i]);
    }
    getch();
    return 0;
}