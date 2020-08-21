/********** Menu Base de dos listas ****/

/*
Dada dos lista A y B, cree una rutina que:
intercale de A los numeros formados solo por los digitos pares (moviendo la casilla) y coloquelos en B
(partiendo del primer elemento) del siguiente modo:

    Un elemento de A y un elemento de B
    Dos elementos de A y dos elementos de B
    tres elementos de A y tres elementos de B

Y asi sucesivamente hasta que no haya elementos pares de A ( o hasta que se acabe A), los elementos de A quedan
en orden inverso en la lista resultante.
*/


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct lista{
int valor;
lista *prox;};

void mostrar ( lista *Ini);
void insertar( struct lista **Ini, int x);

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


int determinar_par(int x){
    int y, par = 0, impar = 0;

    while(x){
        y = x % 10;
        x = x/10;

        if( y % 2 == 1){
            impar++;
        }
    }
    if(impar == 0) {
        return 1;
    } else {
        return 0;
    }

}

void intercalarmoveespecial(lista **a, lista **b){
	lista *p=*a; lista *h=*b; int salir=0;
	if (!(*a)) return;
	
	if (!(*b)) {
		*b=*a;
		return;
	}
	int rep=1; int i;
	while ((p)&&(salir==0)){
		if ( h->prox!=NULL ) {
			for (i=0;i<rep;i++){
			if(p!=NULL){
			(*a)=(*a)->prox;
			p->prox=h->prox;
			h->prox=p;
			h=h->prox;
			p=*a;
		        }
			}  
            i=0;
			while (i<rep+1){
				if (h->prox!=NULL) h=h->prox;
				i++;
			}
			rep++;
		}else{ 
			h->prox=(*a);
			while(*a) (*a)=(*a)->prox;
			salir=1;
		}
		
	}
	
}

void pregunta6(struct lista **A, struct lista **B){
    lista *ax = *A, *bx = *B,*u, *aux = NULL;
    u = ax;
    if(!(ax)) return;
    while(u != NULL){
        u = u->prox;
    }
    while(ax != u){
        if(determinar_par(ax->valor) == 1){
            insertar(&aux,ax->valor);
            eliminar(A,ax->valor);
            ax = *A;
        } else {
            ax = ax->prox;
        }
    }
    mostrar(aux);
    getch();
   intercalarmoveespecial(&aux,B);
   bx = *B;

}

void insertar( struct lista **Ini, int x){
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
pregunta6(&A,&B);
break;
};
printf("\n\n");
system("pause");
}
}/* FIN de Menu Base de dos Listas */