#include <stdio.h>
#include <stdlib.h>

void determinar_impares(int x);

int main(){
    int x;

    printf("introduzca el numero: ");
    scanf("%i",&x);
    printf("\n");
    determinar_impares(x);
    system("pause");
    return 0;
}

void determinar_impares(int x){
    int y, impar = 0;

    while(x){
        y = x%10;
        x = x/10;
        if(y % 2 == 1){
            impar++;
        }
    }

    if(impar > 1){
        printf("el numero tiene al menos 2 digito impares\n\n");
    } else {
        printf("el numero no tiene 2 digitos impares\n\n");
    }
}