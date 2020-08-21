/********** Menu Base de dos listas ****/
#include <stdio.h>
#include <stdlib.h>

struct lista{
int valor;
lista *prox;
};

void eliminar(lista **p, int x);
int buscarelemento(struct lista **p, int x);

void eliminarcomunes(lista **A, lista **B){
    lista *ax = *A, *bx = *B;
    int numero = 0,entrar;
    while (ax){
        entrar == 1;
        bx = *B;
        while (bx){
            if(bx->valor == ax->valor){
                numero = ax->valor;
                while(buscarelemento(A,numero)){
                    eliminar(A,numero);
                } 
                while(buscarelemento(B,numero)){
                    eliminar(B,numero);
                } 
                entrar == 0;
                ax = *A;
                break;
            } else {
                bx = bx->prox;
            }
        }
        if(entrar == 1){
            ax = ax->prox;
        }
    }

}

int buscarelemento(struct lista **p, int x){
    lista *aux = *p;
    while(aux!=NULL){
        if(aux->valor == x){
            return 1;
        } 
        aux=aux->prox;
    }
    return 0;
}

void eliminar(struct lista **p, int x){
    lista *aux = *p, *q;
    if(aux){
        if(aux->valor==x){
        *p= aux->prox;
        q = aux;
        delete q;
        aux = *p;
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

break;

/*pregunta 2 de una lista doble */
case 5:
eliminarcomunes(&A,&B);
system("cls");
break;

break;
};


printf("\n\n");
system("pause");
}
}/* FIN de Menu Base de dos Listas */