#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//estructuras primivitas
struct pila{
    int valor;
    struct pila *prox;
};

int vacio (struct pila *p){
    return (p==NULL);
}

int tope(struct pila *p){
    if (!(vacio(p))){
        return(p->valor);
    }
    return 0;
}

void apilar(struct pila **p, int x){
    pila *t;
    t = new struct pila;
    t->valor = x;
    t->prox = (*p);
    (*p) = t;
}

void desapilar(struct pila **p){
    if(!(vacio(*p))){
         pila *t = *p;
        (*p)= (*p)->prox;
        delete t;
    }
   
}

void mostrar(struct pila **p){
    pila *aux = *p;
    printf("tope -> ");
    while(aux != NULL){
        printf("|%i| ",aux->valor);
        aux = aux->prox;
    }
    printf("<-fondo\n\n");
}

//funciones adicionales a partir de las primitivas



int main(){
    int op = -1, x;
    pila *A = NULL;
    pila *B = NULL;

    while(op!=0){
        printf("-------- ESTRUCTURA DE PILA --------\n\n");
        printf("1. apilar un elemento a la pila A\n");
        printf("2. apilar un elemento a la pila B\n");
        printf("3. desapilar A\n");
        printf("4. desapilar B\n");
        printf("5. mostrar tope de A y B\n");
        printf("6. mostrar los elementos de la pila A y B\n");
        printf("0. salir\n\n");
        printf("introduzca una opcion: ");
        scanf("%i",&op);

        switch(op){
            case 1:
            system("cls");
            printf("introduzca un elemento: ");
            scanf("%i",&x);
            apilar(&A,x);
            system("cls");
            break;

            case 2:
            system("cls");
            printf("introduzca un elemento: ");
            scanf("%i",&x);
            apilar(&B,x);
            system("cls");
            break;

            case 3:
            desapilar(&A);
            system("cls");
            break;

            case 4:
            desapilar(&B);
            system("cls");

            case 5:
            system("cls");
            printf("tope de A -> %i\n\n", tope(A));
            printf("tope de B -> %i\n\n",tope(B));
            system("pause");
            system("cls");
            break;

            case 6:
            system("cls");
            printf("Pila A ");
            mostrar(&A);
            printf("Pila B ");
            mostrar(&B);
            system("pause");
            system("cls");
            break;

            case 7:
            
            break;
        }
    }
}