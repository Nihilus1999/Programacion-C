#include <stdio.h.>
#include <stdlib.h>
#include <conio.h>

struct lista{
    int valor;
    lista *prox;
};
void crear_lista(struct lista **p, int x);
void mostrarlista(struct lista **p, int x);
void eliminar(struct lista **p, int x);

int main(){
    int op = -1,x=0;
    lista *p = NULL;
    while(op!=0){
        printf("-----BUSCAR ELEMENTO EN LA LISTA-----\n\n");
        printf("1. Crear lista\n");
        printf("2. Eliminar elemento\n");
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
            printf("introduzca el elemento a eliminar ");
            scanf("%i",&x);
            eliminar(&p,x);
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

void eliminar(struct lista **p, int x){
    lista *aux = *p, *q;
    if(aux){
        if(aux->valor == x){
            *p = aux->prox;
            delete aux;
        } else {
            while(aux->prox != NULL && aux->prox->valor != x){
                aux = aux->prox;
            }
            if(aux->prox == NULL){
                printf("\n\nno se pudo encontrar el numero\n\n");
                system("pause");

            } else{

                q = aux->prox;
                aux->prox = q->prox;
                delete q;
            }
        }
    } else {
        printf("\n\nusted no ha creado una lista\n\n");
        system("pause");
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