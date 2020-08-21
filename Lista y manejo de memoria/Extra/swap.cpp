#include <stdio.h>
#include <stdlib.h>

void swap(int *i,int *y){
    int temp;
    temp = *i;
    *i = *y;
    *y = temp;
}

int main(){
    int a = 0, b = 0;
    int op = -1;

    while(op != 0){
        printf("---- USO DEL SWAP----\n\n");
        printf("1. agregar numeros a la variable A y B\n");
        printf("2. intercambiar datos entre A y B\n");
        printf("3. Mostar valores de A y B\n");
        printf("0. salir\n\n");
        printf("introduzca una opcion: ");
        scanf("%i",&op);

        system("cls");
        switch(op){
            case 1:
            printf("introduzca el valor de A: ");
            scanf("%i",&a);
            printf("\n\nintroduzca el valor de B: ");
            scanf("%i",&b);
            system("cls");
            break;

            case 2:
            swap(&a,&b);
            system("pause");
            system("cls");
            break;

            case 3:
            if(a == 0 && b == 0){
                printf("A y B no tienen valores\n\n");
            } 
            else{
                printf("---- VALORES DE A y B----\n\n");
                printf("A = %i\n\n",a);
                printf("B = %i\n\n",b);
            }
            system("pause");
            system("cls");
            break;

            case 0:
            break;

        }

    }
    return 0;
}