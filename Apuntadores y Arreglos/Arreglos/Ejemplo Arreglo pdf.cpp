#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(){
    int a[6]={10,0,4,6,8,10},i;
    int *ptr; // Declaracion del apuntador
    ptr = &a[0]; // Inicializacion del apuntador. (ptr = a)
    printf("elemento 1: %i\n",*ptr);
    *ptr = 2; // a[0] = 10
    printf("valor 2: %i\n",*ptr);
    ptr = &a[3]; // Ahora ptr esta apuntando al elemento a[3]
    printf("valor 3: %i\n",*ptr);
    ptr = &a[1]; // Ahora ptr esta apuntando al elemento a[1]
    system("pause");
    return 0;
    }