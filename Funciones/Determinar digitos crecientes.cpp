#include <stdio.h>
#include <stdlib.h>

int determinar_creciente(int x){
    int xAux;

    while(x>0){
        xAux = x % 10;
        x = x/10;
        if(x % 10 >xAux){
            return 0;
        }
    }
    return 1;
}

int main(){
    int x;
    printf("introduzca un numero: ");
    scanf("%i",&x);
    system("cls");
    if(determinar_creciente(x)==1){
        printf("el numero crece en sus digitos\n\n");
    } else {
        printf("el numero no crece en sus digitos\n\n");
    }
    system("pause");
    return 0;
}