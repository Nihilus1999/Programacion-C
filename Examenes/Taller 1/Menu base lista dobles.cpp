/********** Menu Base de dos listas ****/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct lista{
int valor;
lista *prox;};

void voltear(struct lista **p);

void insertar( lista **Ini, int x){
/* inserta x por el comienzo de la lista p */
lista *t = new lista;
t->valor = x;
t->prox = *Ini;
*Ini = t;
}

int determinar_impar(int numero);

void pregunta1(lista **p){
    lista *aux = *p, *u, *q, *s;
    u = aux;
    if(aux)
    while(u->prox != NULL){
        u = u->prox;
    }
    q = u;
    while(aux->prox != q->prox){
        if(determinar_impar(aux->prox->valor)==1){
            s = aux->prox;
            u->prox = s;
            aux->prox = aux->prox->prox;
            u = u->prox;
            aux = (*p);
            s->prox = NULL;
        } else {
             aux = aux->prox;
        }
    }
}

int determinar_impar(int numero){
    int cifra[10];
    int i = 0, impar = 0, par = 0;

    while(numero > 0){
        cifra[i] = numero%10;
        numero = numero/10;
        i++;
        getch();
    }

    for(int s = i-1; s>=0 ; s--){
       if(cifra[s] %2 == 1){
           impar++;
       } else {
           par++;
       }
    }
    if(impar >= 2){
        return 1;
    } else {
        return 0;
    }
}

void pregunta2(lista **a, lista **b){
	lista *t = *a;
	lista *q = *b;
	lista *aux = new lista;
	int o,s=0;
	while(t!=NULL){
		o = t->valor;
		 if(o/10>0){
		 while(o/10>0){
         o=o/10;
         s+=o/10;}
		 if(s%2==0){
		   insertar(&aux,t->valor);}}
		else{
		 if((t->valor%2)==0){
		 insertar(&aux,t->valor);}}
		 t=t->prox;
		 }

	voltear(&aux);
	int r=0,cont=1,u;
	while((q!=NULL)&&(aux!=NULL)){
	if(cont<2){
		u=q->prox->valor;
		q->prox->valor=aux->valor;
		q->prox->prox->valor=u;
	cont++;}
	else if(cont<5){
	while(r<=2){
		u=q->prox->valor;
		q->prox->valor=aux->valor;
		q->prox->prox->valor=u;
		r++;
	}	
	cont++;
	r=0;}
	else {
	while(r<=3){
		u=q->prox->valor;
		q->prox->valor=aux->valor;
		q->prox->prox->valor=u;
		r++;
	}
	r=0;}
	q=q->prox;
	aux=aux->prox;
	u=0;
	}
	
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
pregunta2(&A,&B);
break;
};
printf("\n\n");
system("pause");
}
}/* FIN de Menu Base de dos Listas */