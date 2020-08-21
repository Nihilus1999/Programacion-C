#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

struct tipdireccion{
    char pais[20];
    char estado[20];
    char municipio[20];
};

struct personas{
    char nombre[20];
    char cedula[20];
    struct tipdireccion direccion;
    int salario;
} persona[10],salario[10];

int main(){
    int n,i,a;
    printf("cuantas cantidad de personas quiere registrar(max 10): ");
    scanf("%i",&n);
    system("cls");
    for(i=0,a=1;i<n;i++,a++){
        fflush(stdin);
        printf("-----PERSONA %i-----\n\n",a);
        printf("Nombre: ");
        scanf("%s", &persona[i].nombre);
        printf("\ncedula: ");
        scanf("%s", &persona[i].cedula);
        printf("\nDireccion: ");
        scanf("%s", &persona[i].direccion.pais);
        printf("\nsalario: ");
        scanf("%i",&salario[i].salario);
        system("cls");
    }
    system("cls");
    for(i=0,a=1;i<n;i++,a++){
        printf("------PERSONA %i-----\n\n",a);
        printf("Nombre: %s\n",persona[i].nombre);
        printf("cedula: %s\n",persona[i].cedula);
        printf("direccion: %s\n",persona[i].direccion.pais);
        printf("Salario: %i\n\n\n",salario[i].salario);
    }
    getch();
    return 0;
}