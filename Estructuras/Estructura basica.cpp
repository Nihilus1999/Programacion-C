#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct persona{
    char nombre[20];
    char edad[20];
    char cedula[20];
    char trabajo[20];
    int a;
}persona1,persona2;

int main(){
    printf("Introduzca tu nombre: ");
    scanf("%s",&persona1.nombre);
    printf("\nIntroduzca su cedula: ");
    scanf("%s",&persona1.cedula);

    printf("\n\nSus datos son: \n\n");
    printf("Nombre: %s\n",persona1.nombre);
    printf("Cedula: V-%s",persona1.cedula);
    getch();
    return 0;
}