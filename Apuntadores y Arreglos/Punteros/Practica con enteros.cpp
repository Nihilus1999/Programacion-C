#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//practica de punteros con valores enteros

void cambio(int *i,int *y);
void cambio2(int *i, int *y);

int main(){
    int a=1,b=2,c=3;
    int *pa,*pb,*pc;
    printf("valor de a: %i------Direccion de memoria: %p",a,&a);
    printf("\nvalor de b: %i------Direccion de memoria: %p",b,&b);
    printf("\nvalor de C: %i------Direccion de memoria: %p\n",c,&c);
    pa = &a;
    pb = &b;
    pc = &c;
    printf("direccion de a(con puntero pa): %p\n",pa);
    printf("direccion de b(con puntero pb): %p\n",pb);
    printf("direccion de c(con puntero pc): %p\n\n",pc);
    printf("------CAMBIAR VALORES DE A POR B-------\n\n");
    cambio(&a,&b);
    printf("valor de a: %i\n",a);
    printf("valor de b: %i\n\n",b);
    printf("------CAMBIAR VALORES DE b POR c-------\n\n");
    cambio2(pb,pc);
    printf("valor de b: %i\n",b);
    printf("valor de c: %i\n\n",c);
    printf("-------VALOR DEL PUNTERO------\n\n");
    printf("valor de a: %i-------con direccion: %p\n\n",*pa,&a);
    *pb = *pa;
    printf("el valor de b(despues de apuntar a 'a'): %i------con direccion: %p\n\n",*pb,&b);
    system("pause");
    return 0;
}

void cambio(int *i,int *y){
    int temp;
    temp = *i;
    *i = *y;
    *y = temp;
    printf("realizando cambio\n\n");
    Sleep(3);
}

void cambio2(int *i, int *y){
    int temp;
    temp = *i;
    *i = *y;
    *y = temp;
    printf("realizando cambio\n\n");
    Sleep(3);
}