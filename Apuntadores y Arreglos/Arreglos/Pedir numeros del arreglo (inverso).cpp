#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(){
    int peso[50],a,i=0;
    printf("cantidad de elementos de la matriz: ");
    scanf("%i",&a);

    for (i = a-1; i >=0; i--)
    {
        printf("\nvalor del elemento: ");
        scanf("%i",&peso[i]);
    }
    system("cls");
    printf("El resultado es: \n\n");
    printf("POSICION-VALOR\n");
    for (i = 0; i < a; i++) {
        printf("[%i]   ->   %i\n",i,peso[i]);
    }
    getch();
    return 0;
}