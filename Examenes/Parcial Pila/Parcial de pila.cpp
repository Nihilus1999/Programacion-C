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

void eliminar(struct pila **p, int x){
    int n;
    if(!(vacio(*p))){
        n = tope(*p);
        desapilar(p);
        eliminar(p,x);
        apilar(p,n);
        if(x == n){
            desapilar(p);
        }
    }
}

int comunes(struct pila **b, int x){
    int n, total = 0;
    if(!(vacio(*b))){
        n = tope(*b);
        desapilar(b);
        total = comunes(b,x);
        if(x==n){
            eliminar(b,n);
            apilar(b,n);
            return total + 1;
        }
        apilar(b,n);
        return total;
    }
}

int pregunta_2(struct pila **a, struct pila **b){
    int x, total = 0, aux;
    if(!(vacio(*a))){
        x = tope(*a);
        desapilar(a);
        aux = comunes(b,x);
        total = pregunta_2(a,b);
        if(aux > 0){
            eliminar(a,x);
            printf("%i, ",x);
            apilar(a,x);
            return total + 1;
        }
        apilar(a,x);
        return total;
    }
}

void swap(int *i,int *y){
    int temp;
    temp = *i;
    *i = *y;
    *y = temp;
}

int primo(int *n){
    int i, cont = 0;
    for(i = 1; i<=*n;i++){
        if(*n % i == 0){
            cont++;
        }
    }
    if(cont == 2){
        return 1;
    } else {
        return 0;
    }
}

void impares(struct pila **p, int *x){
    int n;
    if(!(vacio(*p))){
        n = tope(*p);
        desapilar(p);
        impares(p,x);
        if( *x % 2 == 1){
            swap(x,&n);
        }
        apilar(p,n);
        if(primo(&n) == 1){
            desapilar(p);
        }
    }
}

void pregunta_1(struct pila **p){
    int x;
    if(!(vacio(*p))){
        x = tope(*p);
        desapilar(p);
        pregunta_1(p);
        if(x % 2 == 0 && x != 2){
            apilar(p,x);
        } else {
            impares(p,&x);
            if(x != 2)
            apilar(p,x);
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
        pregunta_1(&A);
        break;

        case 5: /* pregunta 2 */
        printf( "\n\t 5. Pregunta 2\n\n");
        printf("los elementos comunes son: %i\n\n",pregunta_2(&A,&B));
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