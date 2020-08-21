#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct lista{
    int valor;
    lista *prox;
};

int main(){
    int x=-1;
    struct lista *p, *aux;

    p = NULL;

    printf("----MANEJO DINAMICO DE MEMORIA----\n\n");
    while(x!=0){
        printf("indique un valor(0 para salir): ");
        scanf("%i",&x);
        if(x!=0){
            if(p==NULL){
            p = new struct lista;
            (*p).valor=x;
            (*p).prox = NULL;
            }
            else{
            aux = new struct lista;
            (*aux).valor = x;
            (*aux).prox = p;
            p = aux;
            }
        }
    }
    system("cls");
    aux = p;
    printf("-----CONTENIDO DE LA LISTA-----\n\n");
    printf("p");
        while(aux!=NULL){
            printf("->%i",(*aux).valor);
            aux = (*aux).prox;
        }
    getch();


    return 0;
}