#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//estructuras primivitas
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

//funciones adicionales a partir de las primitivas

int nroConMenosDigitos(int x, int y){
    int a = 0; int b = 0; int mayor = 0;
    int auxA = x; int auxB = y;
    while(x>0){
        a++;
        x = x/10;
    }
    while(y>0){
        b++;
        y = y/10;
    }
    if(a>=b){
        return b;
    }else{
        return a;
    }
}

int checkDigitosInternosIguales(int x, int y){
    int count = 0; int nroMenosDigitos = nroConMenosDigitos(x,y);
    int aux = 0; int aux2 = 0; int auxX = x; int auxY = y;
    while(x>0){
        aux = x%10;
        y = auxY;
        while(y>0){
            aux2 = y%10;
            if(aux == aux2){
                count++;
                break;
            }
            y = y/10;
        }
        x = x/10;
    }
    if(count == nroMenosDigitos){
        return 1;
    }else{
        return 0;
    }
}

int digitos_iguales(struct pila **p, int x){
    int n, aux=0, total = 0;
    if(!(vacio(*p))){
        n = tope(*p);
        desapilar(p);
        total = digitos_iguales(p,x);
        apilar(p,n);
        if(checkDigitosInternosIguales(x,n)==1){
            desapilar(p);
            return total + 1;
        }
        return total;
    }
    return total;
}

void eliminar_iguales(struct pila **p){
    int x, aux;
    if(!(vacio(*p))){
        x = tope(*p);
        desapilar(p);
        aux = digitos_iguales(p,x);
        eliminar_iguales(p);
        apilar(p,x);
        if(aux!=0){
            desapilar(p);
        }
    }
}

int main(){
    int op = -1, x;
    pila *p = NULL;

    while(op!=0){
        printf("-------- ESTRUCTURA DE PILA --------\n\n");
        printf("1. apilar un elemento\n");
        printf("2. desapilar\n");
        printf("3. mostrar tope\n");
        printf("4. mostrar los elementos de la pila\n");
        printf("5. eliminar digitos iguales\n");
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
            eliminar_iguales(&p);
            break;
        }
    }
}