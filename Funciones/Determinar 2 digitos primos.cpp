#include <stdio.h>
#include <stdlib.h>

void determinar_primos(int x);

int main(){
    int x;

    printf("introduzca un numero: ");
    scanf("%i",&x);
    determinar_primos(x);
    system("pause");
    return 0;
}

void determinar_primos(int x){
    int y, i, cont, primo = 0;

    while(x){
        cont = 0;
        y = x%10;
        x = x/10;
        for(i = 1; i<=y;i++){
            if(y % i == 0){
                cont++;
            }
        }
        if(cont == 2){
            primo++;
        }
    }

    if(primo>1){
        printf("el numero tiene al menos 2 digitos primos\n\n");
    } else {
        printf("el numero no tiene 2 digitos primos\n\n");
    }
}