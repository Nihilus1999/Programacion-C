#include <stdio.h>
#include <conio.h>
#include <windows.h>

// Hacer una estructura llamada corredor, en la cual se tendrán los siguientes campos: 
//Nombre, edad, sexo, club, pedir datos al usuario para un corredor, y asignarle una categoría de competición:
//Juvenil menor o = 18 años
//Señor menor o = 40 años
//Veterano mayor a 40 años
//Posteriormente imprimir todos los datos del corredor, incluida su categoría de competición.*/

struct corredor{
    char nombre[20];
    int  edad;
    char sexo[20];
    char club[20];
} persona[20];

int main(){
    int n,i,a=0,b=0,c=0,t;
    printf("introduzca la cantidad de competidores(max 20): ");
    scanf("%i",&n);

    for(i=0,t=1;i<n;i++,t++) {
        system("cls");
        printf("\n\n-----COMPETIDOR %i-----\n\n",t);
        printf("\nNombre: ");
        scanf("%s",&persona[i].nombre);
        printf("\nEdad: ");
        scanf("%i",&persona[i].edad);
        printf("\nSexo(M/F): ");
        scanf("%s",&persona[i].sexo);
        printf("\nclub: ");
        scanf("%s",&persona[i].club);
    }
    system("cls");
    for(i=0,t=1;i<n;i++,t++){
        if (persona[i].edad<=18){
        printf("el competidor %i es de la categoria JUVENIL\n\n",t);
        a++;
        }
        else if (persona[i].edad>18 && persona[i].edad<=40){
        printf("\n\nel competidor %i es de la categoria SEÑOR\n\n",t);
        b++;
        }
        else if(persona[i].edad>40 && persona[i].edad<=100){
        printf("\n\nel competidor %i es de la categoria MAYOR\n\n",t);
        c++;
        }
        printf("\nNombre: %s\n",persona[i].nombre);
        printf("Sexo: %s\n",persona[i].sexo);
        printf("Edad: %i\n",persona[i].edad);
        printf("Club: %s\n\n", persona[i].club);
    }

    total:
    printf("\n\n\n\nTotal: %i\n\n",n);
    printf("Juvenil: %i\n",a);
    printf("Adulto: %i\n",b);
    printf("Mayor: %i\n",c);

    getch();
    return 0;
    
}