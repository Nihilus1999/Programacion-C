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

void ordenar(){
    circular *aux, *u;
    int x;

    aux = primero;

    do{
        u = aux;
        do{
            if(aux->dato > u->dato){
                x = aux->dato;
                aux->dato = u->dato;
                u->dato = x;
            }
            u = u->prox;
        }while(u != primero);

        aux = aux->prox;
    } while(aux != primero);

}

int main(){
    int x, op = -1;

    while(op != 0){
        printf("---- LISTAS CIRCULARES----\n\n");
        printf("1. insertar un dato\n");
        printf("2. mostrar la lista circular\n");
        printf("3. ordenar lista circular\n");
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
            ordenar();
            system("pause");
            system("cls");
            break;
            
            case 0:

            break;

        }
    }
    return 0;
}