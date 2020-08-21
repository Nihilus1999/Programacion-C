#include <stdio.h.>
#include <stdlib.h>
#include <conio.h>

struct lista{
    int valor;
    lista *prox;
};
void crear_lista(struct lista **p, int x);
void mostrarlista(struct lista **p, int x);
int buscarelemento(struct lista **p, int x);

int main(){
    int op=-1,x=0;
    lista *p = NULL;
    while(op!=0){
        printf("-----BUSCAR ELEMENTO EN LA LISTA-----\n\n");
        printf("1. Crear lista\n");
        printf("2. Buscar elemento\n");
        printf("3. Mostrar lista\n");
        printf("0. salir\n\n");
        printf("introduzca una opcion: ");
        scanf("%i",&op);

        switch(op){
            case 1:
            system("cls");
            printf("introduzca el elemento de la lista: ");
            scanf("%i",&x);
            crear_lista(&p,x);
            system("cls");
            break;
            case 2:
            system("cls");
            printf("introduzca el elemento a buscar: ");
            scanf("%i",&x);
            buscarelemento(&p,x);
            if(buscarelemento(&p,x) != 0){
                printf("\n\nel numero es: %i y se ha repetido %i en la lista\n\n",x,buscarelemento(&p,x));
            }
            else {
                printf("\n\nel valor no esta en la listan\n\n");
            }
            system("pause");
            system("cls");
            break;
            case 3:
            system("cls");
            mostrarlista(&p,x);
            getch();
            system("cls");
            break;
        }
    }
    
}

void crear_lista(struct lista **p, int x){
    lista *aux = *p;
    if(aux == NULL){
        aux = new struct lista;
        aux->valor = x;
        aux -> prox = NULL;
        *p = aux;
    } else {
        lista *t;
        t = new struct lista;
        t->valor = x;
        t->prox = aux;
        *p = t;
    }
}

int buscarelemento(struct lista **p, int x){
    int cont=0;
    lista *aux = *p;
    while(aux!=NULL){
        if(aux->valor == x){
            cont++;
        } 
        aux=aux->prox;
    }
    return cont;
}

void mostrarlista(struct lista **p, int x){
    lista *aux = *p;
    while(aux!=NULL){
        printf("[%i]->",aux->valor);
        aux = aux->prox;
    }
}