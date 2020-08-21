#include <stdio.h>
#include <stdlib.h>

void determinar_pares(int x);

int main(){
    int x;

    printf("introduzca el numero: ");
    scanf("%i",&x);
    printf("\n");
    determinar_pares(x);
    system("pause");
    return 0;
}

void determinar_pares(int x){
    int y, par = 0;

    while(x){
        y = x%10;
        x = x/10;
        if(y % 2 == 0){
            par++;
        }
    }

    if(par > 1){
        printf("el numero tiene al menos 2 digito pares\n\n");
    } else {
        printf("el numero no tiene 2 digitos pares\n\n");
    }
}