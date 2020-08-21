/********** Menu Base de dos listas ****/

/* Dada una lista A de enteros A:
ordene ascedentemente en funcion de la cantidad de digitos impares que contiene. aquellos numeros que
contienen al menos 2 digitos pares usando el metodo de seleccion. los numero que no se afecten quedan en
su posicion inicial */


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct lista{
int valor;
lista *prox;
};

void insertar( lista **Ini, int x){
/* inserta x por el comienzo de la lista p */
lista *t = new lista;
t->valor = x;
t->prox = *Ini;
*Ini = t;
}

int condicion(int x, int residuo){
    int cont = 0;
    if(x == 0){
        return (x % 2) == residuo;
    }

    while(x>0){
        if((x % 10) % 2 == residuo){
            cont++;
        }
        x = x/10;
    }
    return cont;

}

void swap(int *i,int *y){
    int temp;
    temp = *i;
    *i = *y;
    *y = temp;
}

void pregunta1(struct lista **p){
    int y = 0;
    lista *menor = NULL;
    for(lista *plista = *p; plista; plista = plista->prox)
        if(condicion(plista->valor, 0)>= 2){
            printf("%i\n\n",plista->valor);
            system("pause");
            menor = plista;
            for(lista *aux = plista->prox; aux; aux = aux->prox) {
                if(condicion(aux->valor,0)>=2 && (condicion(aux->valor,1) < condicion(menor->valor,1)))
                menor = aux;
            }
            swap(&plista->valor,&menor->valor);
        }
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
pregunta1(&A);
break;

/*pregunta 2 de una lista doble */
case 5:

break;
};
printf("\n\n");
system("pause");
}
}/* FIN de Menu Base de dos Listas */