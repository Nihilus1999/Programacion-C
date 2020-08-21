#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct circular{
    int dato;
    circular *prox;
};

circular *primero = NULL;
circular *ultimo = NULL;

void insertardato(int dato){
    circular *aux;

    if(primero == NULL){
        aux = new struct circular;
        aux->dato = dato;
        primero = aux;
        primero->prox = primero;
        ultimo = primero;
    } else{
        aux = new struct circular;
        aux->dato = dato;
        ultimo->prox = aux;
        aux->prox = primero;
        ultimo = aux;
    }
}

void mostrar(){
    circular *aux;
    aux = primero;
    printf("----MOSTRAR LISTA CIRCULAR----\n\n");
    if(primero != NULL){
        do{

        printf("[%i]->",aux->dato);
        aux = aux->prox;

        }while(aux != primero);
        printf("\n\n");
    }
    else{
        printf("la lista esta vacia\n\n");
    }
}

void eliminar(int dato){
    circular *aux, *u, *pre;
    
    pre = primero;

    while(pre->prox != ultimo){
        pre = pre->prox;
    }

    if(primero->dato == dato){

        u = primero;
        primero = primero->prox;
        ultimo->prox = primero;
        aux = primero;
        delete(u);

    } 
    else if(ultimo->dato == dato){

        u = ultimo;
        ultimo = pre;
        ultimo->prox = primero;
        delete(u);

    } 
    else{
        aux = primero->prox;
        while(aux->prox != ultimo && aux->prox->dato != dato){
            aux = aux->prox;
        }
        u = aux->prox;
        aux->prox = u->prox;
        delete(u);
    }

}

int main(){
    int x, op = -1;

    while(op != 0){

        printf("---- LISTAS CIRCULARES----\n\n");
        printf("1. insertar un dato\n");
        printf("2. mostrar la lista circular\n");
        printf("3. eliminar dato de la lista\n");
        printf("0. salir\n\n");

        printf("introduzca una opcion: ");
        scanf("%i", &op);

        system("cls");
        switch(op){

            case 1:
            printf("introduzca un dato: ");
            scanf("%i",&x);
            insertardato(x);
            system("cls");
            break;

            case 2:
            mostrar();
            system("pause");
            system("cls");
            break;

            case 3:
            printf("introduzca un dato: ");
            scanf("%i",&x);
            eliminar(x);
            system("cls");
            break;

            case 0:

            break;

        }
    }
    return 0;
}