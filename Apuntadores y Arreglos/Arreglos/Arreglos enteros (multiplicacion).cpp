#include <stdio.h.>
#include <stdlib.h>
#include <conio.h>

int main(){
    int numero[6] = {1,2,1,1,1,4};
    int multi=1,i;
    for(i=0;i<=5;i++){
        multi = multi*numero[i];
    }
    printf("el resultado es: %i",multi);
    
    getch();
    return 0;
}