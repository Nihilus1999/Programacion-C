#include <stdio.h>
#include <stdlib.h>

void separa_numero(int x);

int main(){
    int x;

    printf("introduzca el numero: ");
    scanf("%i",&x);
    printf("\n");
    separa_numero(x);
    system("pause");
    return 0;
}

void separa_numero(int x){
    int y;

    while(x){
        y = x % 10;
        x = x/10;
        printf("%i\n", y);
    }
    
}