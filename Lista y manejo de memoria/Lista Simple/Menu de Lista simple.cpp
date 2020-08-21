#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct lista{
    int valor;
    lista *prox;
};

void insertarcola(struct lista **p,int x);
void insertarcabeza(struct lista **p, int x);
void eliminar(struct lista **p, int x);
int buscar(struct lista **p, int x);
void voltear(struct lista **p);
void ordenar(struct lista **p);
void eliminar_repetidos(struct lista **p);
void eliminar_pares(struct lista **p, int x);
void eliminar_impares(struct lista **p, int x);
void eliminar_primo(struct lista **p, int x);
int primo(int x);
void mostrarlista(struct lista **p, int x);
void swap(struct infraccion *i,struct infraccion *y);

int main(){
    int op=-1,x=0;
    struct lista *p=NULL;

    while(op!=0){
    system("cls");
    printf("-----MANEJO DINAMICO DE MEMORIA----\n\n\n");
    printf("1. Insertar dato en cola\n");
    printf("2. Insertar dato en cabeza\n");
    printf("3. Eliminar dato de la lista\n");
    printf("4. Buscar elementos en la lista\n");
    printf("5. Voltear lista\n");
    printf("6. Ordenar lista\n");
    printf("7. Eliminar elementos repetidos\n");
    printf("8. Eliminar pares\n");
    printf("9. Eliminar Impares\n");
    printf("10. Eliminar numeros primos\n");
    printf("11. Mostrar lista\n");
    printf("0. salir\n\n");

    printf("introduzca una opcion: ");
    scanf("%i",&op);

    switch(op){
        case 1:
        system("cls");
        printf("introduzca el elemento de la lista: ");
        scanf("%i",&x);
        insertarcola(&p,x);
        printf("\n\n");
        break;

        case 2:
        system("cls");
        printf("introduzca el elemento de la lista: ");
        scanf("%i",&x);
        insertarcabeza(&p,x);
        printf("\n\n");
        break;

        case 3:
        system("cls");
        mostrarlista(&p,x);
        printf("\n\nintroduzca el elemento a eliminar: ");
        scanf("%i",&x);
        eliminar(&p,x);
        printf("\n\n");
        system("pause");
        break;

        case 4:
        system("cls");
        printf(" introduzca el elemento que desea buscar: ");
        scanf("%i", &x);
        printf("\nel elemento es: %i, y se ha repetido %i en la lista\n\n", x,buscar(&p,x));
        system("pause");
        system("cls");
        break;
        
        case 5:
        voltear(&p);
        system("cls");
        break;

        case 6:
        ordenar(&p);
        system("cls");
        break;

        case 7:
        eliminar_repetidos(&p);
        system("cls");
        break;

        case 8:
        eliminar_pares(&p,x);
        system("cls");
        break;

        case 9:
        eliminar_impares(&p,x);
        system("cls");
        break;

        case 10:
        eliminar_primo(&p,x);
        system("cls");
        break;

        case 11:
        system("cls");
        mostrarlista(&p,x);
        printf("\n\n");
        system("pause");
        break;
    }

    }
    return 0;

}

void insertarcola(struct lista **p,int x){
    lista *aux = *p;
    if(aux==NULL){
        aux = new struct lista;
        aux ->valor = x;
        aux ->prox = NULL;
        *p = aux;
    }else{
        while(aux->prox){
            aux = aux->prox;
        }
        lista *t = new struct lista;
        t->valor = x;
        t->prox = NULL;
        aux->prox = t;
    }
}

void insertarcabeza(struct lista **p, int x){
    lista *aux = *p;
    if(aux==NULL){
        aux = new struct lista;
        aux->valor=x;
        aux->prox=NULL;
        *p=aux;
    }else{
        lista *t = new struct lista;
        t->valor = x;
        t->prox = aux;
        *p = t;
    }
}

void eliminar(struct lista **p, int x){
    lista *aux = *p;
    if(aux)
    if(aux->valor==x){
       *p= aux->prox;
       delete aux;
    } else {
        while(aux->prox!= NULL && aux->prox->valor!=x){
            aux = aux->prox;
        }
        if(aux->prox){
            lista *temp = aux->prox;
            aux->prox = temp->prox;
            delete temp;
        }
    }
}

int buscar(struct lista **p, int x){
    int valor=0;
    lista *aux = *p;
    while(aux!=NULL){
        if(aux->valor == x){
            valor++;
        }
        aux = aux->prox;
    }
    return valor;
}

void voltear(struct lista **p){
    lista *u = *p;
    while(u != NULL && u->prox != NULL){
        lista *aux;
        aux = u->prox;
        u->prox = aux->prox;
        aux->prox = (*p);
        (*p) = aux;
    }
}

void swap(struct lista **i,struct lista **y){
    struct lista *temp;
    temp = *i;
    *i = *y;
    *y = temp;
}

void ordenar(struct lista **p){
    int y = 0;
    if((*p)==NULL){
        return;
    } else {
        lista *aux = *p;
            while(aux){
                lista *u;
                u = aux->prox;
                while(u){
                    if(aux->valor > u->valor){
                       swap(&aux,&u);
                       u = aux;
                    }
                    u = u->prox;
                }
                aux = aux->prox;
            }
        }
    }

void eliminar_repetidos(struct lista **p){
    lista *aux = *p, *u, *q;
    while(aux){
        u = aux;
        while(u && u->prox){
            if(u->prox->valor == aux->valor){
                q = u->prox;
                u->prox = u->prox->prox;
                delete q;
            }
            else{
                u = u->prox;
            }
        }
        aux = aux->prox;
    }
}

void eliminar_pares(struct lista **p, int x){
    lista *aux = *p;
    while(aux){
        if(aux->valor % 2 == 0){
            eliminar(p,aux->valor);
            aux = *p;
        }
        else{
            aux = aux->prox;
        }
    }
}

void eliminar_impares(struct lista **p, int x){
    lista *aux = *p;
    while(aux){
        if(aux->valor %2 == 1){
            eliminar(p,aux->valor);
            aux = *p;
        } else {
            aux = aux->prox;
        }
    }
}

void eliminar_primo(struct lista **p, int x){
    lista *aux = *p;
    while(aux){
        if(primo(aux->valor) == 1){
            eliminar(p,aux->valor);
            aux = *p;
        } else {
            aux = aux->prox;
        }
    }
}

int primo(int x){
    int i, cont=0;
    for(i = 1; i <= x; i++){
        if(x %i == 0){
            cont++;
        }
    }
    if(cont==2){
        return 1;
    } else{
        return 0;
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