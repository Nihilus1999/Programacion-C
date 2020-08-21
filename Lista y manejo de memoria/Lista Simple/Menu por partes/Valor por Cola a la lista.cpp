#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct lista{
    int valor;
    struct lista *prox;
};

int main(){
    int x=-1;
    struct lista *p, *aux,*t;
    p=NULL;

    while(x!=0){
        printf("introduzca un numero a la lista(0 para salir): ");
        scanf("%i",&x);
        if(x!=0){
            if(p==NULL){
                p = new struct lista;
                (*p).valor =x;
                (*p).prox = NULL;
                t = p;
            }else{
                p = t;
                while((*p).prox){
                    p = (*p).prox;
                }
                aux = new struct lista;
                (*aux).valor = x;
                (*aux).prox = NULL;
                (*p).prox = aux;
            }
        }
    }
    p = t;
    system("cls");
    printf("-----LISTA-----\n\n");
    while(p != NULL){
        printf("[%i]->",(*p).valor);
        p = (*p).prox;
    }
    getch();
    return 0;
}