#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//practica de punteros con valores enteros

void cambio(char *i,char *y);
void cambio2(char *i, char *y);

int main(){
    char a='a',b='b',c='c';
    char *pa,*pb,*pc;
    printf("valor de a: %c------Direccion de memoria: %p",a,&a);
    printf("\nvalor de b: %c------Direccion de memoria: %p",b,&b);
    printf("\nvalor de C: %c------Direccion de memoria: %p\n",c,&c);
    pa = &a;
    pb = &b;
    pc = &c;
    printf("direccion de a(con puntero pa): %p\n",pa);
    printf("direccion de b(con puntero pb): %p\n",pb);
    printf("direccion de c(con puntero pc): %p\n\n",pc);
    printf("------CAMBIAR VALORES DE A POR B-------\n\n");
    cambio(&a,&b);
    printf("valor de a: %c\n",a);
    printf("valor de b: %c\n\n",b);
    printf("------CAMBIAR VALORES DE b POR c-------\n\n");
    cambio2(pb,pc);
    printf("valor de b: %c\n",b);
    printf("valor de c: %c\n\n",c);
    printf("-------VALOR DEL PUNTERO------\n\n");
    printf("valor de a: %c-------con direccion: %p\n\n",*pa,&a);
    *pa = *pb;
    printf("el valor de a(despues de apuntar a 'b'): %c------con direccion: %p\n\n",*pb,&b);
    system("pause");
    return 0;
}

void cambio(char *i,char *y){
    char temp;
    temp = *i;
    *i = *y;
    *y = temp;
    printf("realizando cambio\n\n");
}

void cambio2(char *i, char *y){
    char temp;
    temp = *i;
    *i = *y;
    *y = temp;
    printf("realizando cambio\n\n");
}