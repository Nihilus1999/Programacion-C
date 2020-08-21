/********** Menu Base de dos listas ****/

/*
Dada una lista A de enteros:
cree una rutina "void pregunta1(struct lista ** p)" que deje al final de la lista
aquellos numeros que tengan mas de 2 dgitos impares ordenados ascedentemente por la cantidad de numeros pares
que contenga
*/


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct lista{
int valor;
lista *prox;
};

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

int determinar_par(int x){
    int i, par = 0;

    while(x){
        i = x % 10;
        x = x/10;

        if(i % 2 == 0){
            par++;
        }
    }
    return par;
}

void swap(int *i,int *y){
    int temp;
    temp = *i;
    *i = *y;
    *y = temp;
}

void ordenar(struct lista **p){
    int y=0;
    lista *aux = *p;
    while(aux != NULL){
        lista *u = aux->prox;
        while(u != NULL){
            if(determinar_par(aux->valor) > determinar_par(u->valor)){
               swap(&aux->valor, &u->valor);
            }
            u = u->prox;
        }
        aux = aux->prox;
    }
}

void insertar_final(struct lista **p, int x){
    lista *aux = *p;
        if(aux== NULL){
            aux = new struct lista;
            aux->valor = x;
            aux->prox = NULL;
            *p = aux;
        } else {
            while(aux->prox != NULL){
                aux = aux->prox;
            }
            lista *t = new struct lista;
            t->valor = x;
            t->prox = NULL;
            aux->prox = t;
            ordenar(p);
        }
}

int determinar_impar(int x){
    int i, impar = 0;

    while(x){
        i = x % 10;
        x = x/10;

        if(i % 2 == 1){
            impar++;
        }
    }
    return impar;
}

void pregunta(struct lista **A,int x){
    lista *aux = *A, *final = *A;
    while(final->prox != NULL){
        final = final->prox;
    }
    while(aux != final){
        if(determinar_impar(aux->valor)>=2){
            insertar_final(&final,aux->valor);
            eliminar(A,aux->valor);
            aux = *A;
        } else {
            aux = aux->prox;
        }
    }
}

void insertar( lista **Ini, int x){
/* inserta x por el comienzo de la lista p */
lista *t = new lista;
t->valor = x;
t->prox = *Ini;
*Ini = t;
}

void mostrar ( lista *Ini){
/* muestra por pantalla la lista enlazada */
lista *t = Ini;
while ( t){
printf("[%i]->", t->valor);
t= t->prox;};
printf("NULL\n\n");
}

void mostrarlst( lista *p, char c){
 /* imprime encabezado y llama a mostrar */
printf( "\n\n\tLista %c ->",c);
mostrar(p);
}

int main() {
int op = -1, x=0, n;
lista *A=NULL,*B=NULL;

while ( op ){
system("cls");
printf( "\n\n\t\tMENU DE MANEJO DE LISTAS \n\n\t ");
printf( "1.\tInsertar en A\n\t ");
printf( "2.\tInsertar en B\n\t ");
printf( "3.\tMostrar listas\n\t ");
printf( "4.\tpregunta 1 (lista A)\n\t ");
printf( "5.\tpregunta 2 (lista A y B)\n\t ");
printf( "0.\tSalir\n\n ");
printf( "\t\tSu opcion (0..3): ");
scanf("%i", &op);

switch (op){
case 1: printf("\n\n\tIndique dato a Insertar en A ");
 scanf( "%i", &x);
 insertar (&A, x);
 break;

case 2: printf("\n\n\tIndique dato a Insertar en B ");
 scanf( "%i", &x);
 insertar (&B, x);
 break;

case 3: mostrarlst(A,'A');
mostrarlst(B,'B');
 break;

/*pregunta 1 de una lista simple */
case 4:
pregunta(&A,x);
break;

/*pregunta 2 de una lista doble */
case 5:

break;
};
printf("\n\n");
system("pause");
}
}/* FIN de Menu Base de dos Listas */