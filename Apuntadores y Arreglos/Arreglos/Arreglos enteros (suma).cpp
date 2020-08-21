#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//escriba un programa que defina un vector de numeros y calcule la suma de sus elementos.

int main(){
    int numero[5] = {1,2,3,4,5};
    int suma = 0,i=0;

    for(i=0; i<5; i++){
        suma = suma + numero[i];
    }
    printf("el resultado es: %i",suma);

    getch();

}