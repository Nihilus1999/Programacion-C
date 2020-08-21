/*************** EJEMPLOS DE MANEJO DINAMICO DE LISTAS *************** /
/********** 1 ) Menu Base de listas ****/
#include <stdio.h>
#include <stdlib.h>

struct lista{
int valor;
lista *prox;};

void insertar( lista **cab, int x){
/* inserta x por el comienzo de la lista p */
lista *t = new lista;
t->valor = x;
t->prox = *cab;
*cab = t;
}

void mostrar ( lista *cab){
/* muestra por pantalla la lista enlazada */
lista *t = cab;
system("cls");
printf( "\n\nMostrar lista\n\n Cab ");
while ( t){
printf("->[%i]", t->valor);
t= t->prox;};
printf("->NULL\n\n");
}

void eliminar ( lista **p, int x){
/* elimina la primera ocurrencia del valor x en la lista p */
lista *t=*p;
if (t)
if (t->valor==x){
*p=(*p)->prox;
delete( t); }
else { while ((t->prox)&&(t->prox->valor != x)) t=t->prox;
if (t->prox){
lista *aux= t->prox;
t->prox = t->prox->prox;
delete( aux );
        }
    }
}


void swap( int *x, int *y){
/* Intercambia los contenidos de las direcciones x , y */
int c= *x;
*x=*y;
*y=c;}

/* busca un elemento de la lista y cuenta la cantidad de veces que se repite */
int buscarelemento(struct lista **p, int x){
    int cont=0;
    lista *aux = *p;
    while(aux!=NULL){
        if(aux->valor == x){
            cont++;
        } 
        aux=aux->prox;
    }
    return cont;
}



int main() {
int op = -1, x=0, n;
lista *p=NULL;

while ( op ){

system("cls");
printf( "\n\n\t\tMENU DE MANEJO DE LISTAS \n\n\t ");
printf( "1.\tInsertar por comienzo de lista\n\t ");
printf( "2.\tEliminar dato\n\t ");
printf( "3.\tMostrar lista\n\t ");
printf( "0.\tSALIR del sistema\n\n\t ");
scanf("%i", &op);

switch (op){
case 1: printf("\n\n\tIndique dato a Insertar ");
scanf( "%i", &x);
insertar (&p, x);
break;
case 2: printf("\n\n\tIndique dato a Eliminar ");
scanf( "%i", &x);
eliminar (&p, x);
break;
case 3: 
mostrar(p);
break;
case 4:
printf("introduzca el numero a buscar: ");
scanf("%i",&x);
printf("\n\nel elemento es el %i y se ha repetido %i en la lista\n\n",x, buscarelemento(&p,x));
break;


}
system("pause");
};
}/* FIN de Menu Base de Listas */