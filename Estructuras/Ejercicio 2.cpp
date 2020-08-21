#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

//Hacer 2 estructuras una llamada promedio que tendrá los siguientes campos: nota1, nota2, nota3; 
//y otro llamada alumno que tendrá los siguientes miembros: nombre, sexo, edad; 
//hacer que la estructura promedio este anidada en la estructura alumno, 
//luego pedir todos los datos para un alumno, luego calcular su promedio, 
//y por ultimo imprimir todos sus datos incluidos el promedio.

struct promedio{
   int nota1;
   int nota2;
   int nota3;
};
struct alumno{
    char nombre[20];
    char sexo[20];
    char edad[20];
    struct promedio notast;
} estudiante[50];


int main(){
    int i, n, promedio,t=1;
    printf("introduzca la cantidad de alumnos: ");
    scanf("%i",&n);
    system("cls");
    for(i=0;i<n;i++,t++){
        fflush(stdin);
        printf("----alumno %i----\n\n",t);
        printf("Nombre: ");
        scanf("%s",&estudiante[i].nombre);
        printf("Edad: ");
        scanf("%s",&estudiante[i].edad);
        printf("Sexo: ");
        scanf("%s",&estudiante[i].sexo);
        printf("nota 1: ");
        scanf("%i",&estudiante[i].notast.nota1);
        printf("nota 2: ");
        scanf("%i",&estudiante[i].notast.nota2);
        printf("nota 3: ");
        scanf("%i",&estudiante[i].notast.nota3);
        system("cls");
    }
    system("cls");
    for(i=0,t=0;i<n;i++,t++){
        promedio = (estudiante[i].notast.nota1 + estudiante[i].notast.nota2 + estudiante[i].notast.nota3 )/3;
        printf("----ESTUDIANTE %i----\n\n",t);
        printf("Nombre: %s\n",estudiante[i].nombre);
        printf("Edad: %s\n",estudiante[i].edad);
        printf("sexo: %s\n",estudiante[i].sexo);
        printf("promedio: %i\n\n",promedio);
    }

    getch();
    return 0;
}