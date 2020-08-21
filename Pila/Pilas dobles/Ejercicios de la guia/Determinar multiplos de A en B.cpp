/* INICIO MENU BASE PARA MANEJO DE DOS PILAS */
#include <stdio.h>
#include <stdlib.h>


/* PRIMITIVAS DE PILAS */

struct pila{ 
    int valor; 
    struct pila *prox;
};

int vacio ( struct pila *p) {
     return ( p == NULL ) ; 
};

int tope( struct pila *p){
    if (!( vacio ( p ) )) 
    return ( p->valor ); 
    return 0; 
};

void apilar ( struct pila**p, int x) {
    struct pila*t = new struct pila ; /*malloc( sizeof ( struct pila)) ;*/
    t->valor = x; 
    t->prox = (*p); 
    (*p) = t; 
};

void desapilar ( struct pila **p){
if (!(vacio(*p))){ 
    struct pila *t= *p;*p= (*p)->prox;
    delete(t);/*free (t);*/}; 
};


/* RUTINAS BASADAS EN PRIMITIVAS DE PILAS */
void imprime( pila **p){
int x; 
if (!( vacio ( *p ))) {
    x = tope( *p); 
    desapilar ( p ); 
    printf( "| %i ", x);
    imprime( p);
    apilar( p, x); 
    } 
}

void mostrar ( struct pila **p, char letra ) {
    printf( "\n\n\t Pila %c\n\n\t(Tope) ",letra); 
    imprime( p);
    printf( "| (fondo)\n\n"); 
};
/* ESPACIO PARA COLOCAR OTRAS RUTINAS */

int multiplo(struct pila **B, int x){
    int n, contador = 0;
    if(!(vacio(*B))){
        n = tope(*B);
        desapilar(B);
        contador = multiplo(B,x);
        if(n % x == 0){
            apilar(B,n);
            printf("%i ",n);
            return contador + 1;
        }
        apilar(B,n);
        return contador;
    }
    printf("los multiplos de %i son: ", x);
    return contador;
}

void determinar_A(struct pila **A, struct pila **B){
    int x, aux;
    if(!(vacio(*A))){
        x = tope(*A);
        desapilar(A);
        determinar_A(A,B);
        aux = multiplo(B,x);
        if(aux == 0){
            apilar(A,x);
            printf("\n\nno hay multiplos de %i\n\n",x);
        } else {
            apilar(A,x);
            printf("\n\nel total de multiplos de %i son: %i\n\n",x, aux);
        }

    }
}

/* PROGRAMA PRINCIPAL DE MENU PARA MANEJO DE DOS PILAS */
int main() {
int op= -1, n = 0; struct pila*A = NULL,*B = NULL;
while ( op != 0 ) {
system( "cls" );
printf( "\n\n\t\t Menu Manejo de PILAS \n");
printf( "\n\t 1. Apilar un elemento en A");
printf( "\n\t 2. Apilar un elemento en B");
printf( "\n\t 3. Mostrar pilas A y B");
printf( "\n\t 4. Pregunta 1");
printf( "\n\t 5. Pregunta 2");
printf( "\n\n\t 0. Salir \n\n");
printf( "\n\n\t\tIndique opcion (1-5) : ");
scanf("%i", &op);
system( "cls");
printf( "\n\n");

        switch (op){

        case 1: printf( "\n\n\t1. Apilar en A\n\n");
        printf( "\t\tNuevo tope = ");
        scanf( "%i", &n); 
        apilar ( &A , n); 
        break;

        case 2: printf( "\n\n\t2. Apilar en B\n\n");
        printf( "\t\tNuevo tope = ");
        scanf( "%i", &n); 
        apilar ( &B , n); 
        break;

        case 3: printf( "\n\t 3. Mostrar pilas A y B\n\n");
        mostrar( &A,'A' ); 
        mostrar ( &B,'B' );
        break;

        case 4: /* pregunta 1 */
        printf( "\n\t 4. Pregunta 1\n\n");

        break;

        case 5: /* pregunta 2 */
        printf( "\n\t 5. Pregunta 2\n\n");
        determinar_A(&A,&B);
        break;

        }

    if (op) { 
        printf("\n\n"); 
        if (op<6) { 
        printf("\t");
        system("pause");
        }
        system("cls");
        }
    }

return 0;

}/* FIN MENU BASE PARA MANEJO DE DOS PILAS */