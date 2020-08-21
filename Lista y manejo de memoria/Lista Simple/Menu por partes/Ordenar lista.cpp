#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct lista{
    int valor;
    lista *prox;
};

void crear(struct lista **p, int x);
void ordenar(struct lista **p);
void mostrarlista(struct lista **p, int x);


int main(){
    int x, op;
    lista *p;
    p = NULL;

    while(op!=0){
        printf("1. crear lista (colas)\n");
        printf("2. ordenar lista\n");
        printf("3. mostrar lista\n");
        printf("0. Salir\n\n");
        printf("introduzca una opcion: ");
        scanf("%i",&op);

        switch(op){
            case 1:
            system("cls");
            printf("introduzca el elemento: ");
            scanf("%i", &x);
            crear(&p,x);
            system("cls");
            break;

            case 2:
            ordenar(&p);
            system("cls");
            break;

            case 3:
            system("cls");
            mostrarlista(&p,x);
            getch();
            system("cls");
        }  

    }
    
}

void crear(struct lista **p, int x){
    lista *aux = *p, *u;
    if(aux==NULL){
        aux = new struct lista;
        aux->valor = x;
        aux->prox = NULL;
        *p = aux;
    } else {
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        u = new struct lista;
        u->valor = x;
        u->prox = NULL;
        aux->prox = u;
    }
}

void ordenar(struct lista **p){
    int y = 0;
    lista *aux = *p;
    while(aux != NULL){
        lista *u = aux->prox;
        while(u != NULL){
            if(aux->valor > u->valor){
                y = aux->valor;
                aux->valor = u->valor;
                u->valor = y;
            }
            u = u->prox;
        }
        aux = aux->prox;
    }
}

void mostrarlista(struct lista **p, int x){
    lista *aux = *p;
    if(aux == NULL){
        printf("usted no ha creado una lista\n\n");
    } else{
        while(aux!=NULL){
        printf("[%i]->",aux->valor);
        aux = aux->prox;
        }
    }
}