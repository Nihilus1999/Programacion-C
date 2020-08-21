#include <stdio.h>
#include <stdlib.h>


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

void swap(int *i,int *y){
    int temp;
    temp = *i;
    *i = *y;
    *y = temp;
}

void ordenar(struct pila **p, int *x){
    int n;
    if(!(vacio(*p))){
        n = tope(*p);
        desapilar(p);
            if(*x > n){
                swap(x,&n);
            }
        ordenar(p,&n);
        apilar(p,n);
    }
}

void ordenarpila(struct pila **p){
    int x,n;
    if(!(vacio(*p))){
        x = tope(*p);
        desapilar(p);
        ordenar(p,&x);
        ordenarpila(p);
        apilar(p,x);
    }

}

int main(){
    int op, x;
    pila *p = NULL;

    while(op!=0){
        printf("-------- ESTRUCTURA DE PILA --------\n\n");
        printf("1. apilar un elemento\n");
        printf("2. desapilar\n");
        printf("3. mostrar tope\n");
        printf("4. mostrar los elementos de la pila\n");
        printf("0. salir\n\n");
        printf("introduzca una opcion: ");
        scanf("%i",&op);

        switch(op){
            case 1:
            system("cls");
            printf("introduzca un elemento: ");
            scanf("%i",&x);
            apilar(&p,x);
            system("cls");
            break;

            case 2:
            desapilar(&p);
            system("cls");
            break;

            case 3:
            system("cls");
            printf("tope -> %i\n\n", tope(p));
            system("pause");
            system("cls");
            break;

            case 4:
            system("cls");
            mostrar(&p);
            system("pause");
            system("cls");
            break;

            case 5:
            system("cls");
            ordenarpila(&p);
            system("cls");
            break;
        }
    }
}