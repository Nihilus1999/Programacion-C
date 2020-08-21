#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct lista{
    int valor;
    lista *prox;
};

void crearlista(struct lista **p,int x);
void voltearlista4(struct lista **p);
void mostrarlista(struct lista *p, int x);

int main(){
    int op = -1,x;
    lista *p = NULL;

    while(op!=0){

        printf("-----VOLTEAR UNA LISTA-----\n\n");
        printf("1. crear una lista\n");
        printf("2. voltear una lista\n");
        printf("3. Mostrar la lista\n");
        printf("0. salir\n\n");
        printf("introduzca una opcion: ");
        scanf("%i",&op);

        switch(op){
            case 1:
            system("cls");
            printf("introduzca un elemento: ");
            scanf("%i",&x);
            crearlista(&p,x);
            system("cls");
            break;

            case 2:
            voltearlista4(&p);
            system("pause");
            system("cls");
            break;

            case 3:
            system("cls");
            mostrarlista(p,x);
            getch();
            system("cls");
            break;

            case 0:

            break;
        }

    }
    return 0;
   
}

void crearlista(struct lista **p,int x){
    lista *aux = *p;
    if(aux == NULL){
        aux = new struct lista;
        aux->valor = x;
        aux->prox = NULL;
        *p = aux;
    } else {
        lista *t;
        t = new struct lista;
        t->valor = x;
        t->prox = aux;
        *p = t;
    }
}

void voltearlista4(lista **cab)
{
	lista *u;   
    lista *aux=*cab; 
    while ((aux)&&(aux->prox!=NULL)){
        u=aux->prox; 
		aux->prox=u->prox;
		u->prox=*cab;
		*cab=u; 
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
