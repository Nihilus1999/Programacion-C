#include <stdio.h>
#include <stdlib.h>

typedef struct lista{

    int dato;
    struct lista *prox;
    struct lista *atras;
}p;

p *crearnodo(int dato){

    lista *nuevo = NULL;

    nuevo = new struct lista;

    if(nuevo != NULL){

        nuevo->dato = dato;
        nuevo->prox = NULL;
        nuevo->atras = NULL;
    }

    return nuevo;
}


int main(){




    return 0;
}