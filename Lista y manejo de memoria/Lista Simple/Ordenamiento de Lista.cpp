#include<stdio.h>
#include<stdlib.h>

struct lista{
	int valor;
	struct lista* sig;
};

int pedirNumero()
{
	int n;
	printf("\n\t Introduce el numero: ");
	scanf("%i", &n); getchar();
	return n;
}

void agregarElemento(struct lista **l, int n)
{
	struct lista *temp = (struct lista*) malloc(sizeof(struct lista));
	temp->valor = n;
	temp->sig = *l;
	*l = temp;
}

void quitarElemento(struct lista **l, int n)
{
	if(*l)
	{
		if((*l)->valor == n)
		{
			struct lista *aux = *l;
			*l = (*l)->sig;
			free(aux);
		}
		else
		{
			struct lista *aux = *l;
			for( ; (aux->sig); aux = aux->sig)
				if(aux->sig->valor == n)
					break;
			if(aux->sig)
			{
				struct lista *temp = aux->sig;
				aux->sig = aux->sig->sig;
				free(temp);
			}
			else
				printf("\n\n\t El elemento %i no se encuentra en la lista!!!\n\n", n);
		}
	}
	else
		printf("\n\n\t La lista esta vacia!!!\n\n");
}

void borrarLista(struct lista **l)
{
	if(l && *l)
	{
		borrarLista(&((*l)->sig));
		struct lista *aux = *l;
		*l = NULL;
		free(aux);
	}
}

void mostrarLista(struct lista *l)
{
	printf("\n\n\tCAB->");
	for(; l; l = l->sig)
	{
		printf("[%i]->", l->valor);
	}
	printf("NULL\n\n");
}

void intercambiar(int *n1, int *n2)
{
	int aux = *n1;
	*n1 = *n2;
	*n2 = aux;
}

void ordIntercambio(struct lista *l)
{
	struct lista *aux;
	if(l)
	{
		for( ; l->sig; l = l->sig)
			for(aux = l->sig; aux; aux = aux->sig)
				if(l->valor > aux->valor)
					intercambiar(&(l->valor), &(aux->valor));
	}
}

void ordSeleccion(struct lista *l)
{
	struct lista *minPos = NULL;
	if(l)
	{
		for( ; l->sig; l = l->sig)
		{
			minPos = l;
			for(struct lista *aux = l->sig; aux; aux = aux->sig)
				if(minPos->valor > aux->valor)
					minPos = aux;
			if(minPos != l)
				intercambiar(&(l->valor), &(minPos->valor));
		}
	}
}

void ordBurbuja(struct lista *l)
{
	if(l)
	{
		struct lista *fin = NULL;
		struct lista *aux;
		int cambios;
		while(1)
		{
			cambios = 0;
			for(aux = l; aux->sig != fin; aux = aux->sig)
			{
				if(aux->valor > aux->sig->valor)
				{
					intercambiar(&(aux->valor), &(aux->sig->valor));
					cambios++;
				}
			}
			fin = aux;
			if(fin == l->sig || !cambios)
				break;
		}
	}
}

void ordInsercion(struct lista *l)
{
	if(l)
	{
		if(!(l->sig))
			return;
		struct lista *fin = l->sig;
		do
		{
			fin = fin->sig;
			struct lista *aux, *auxFin = fin;
			while(auxFin != l->sig)
			{
				for(aux = l; aux->sig->sig != auxFin; aux = aux->sig);
				auxFin = aux->sig;
				if(aux->valor > aux->sig->valor)
					intercambiar(&(aux->valor), &(aux->sig->valor));
			}
		}while(fin);
	}
}

struct lista *devolverPos(struct lista *l, int pos)
{
	for(int n = 0;((l) && (n < pos)); n++, l = l->sig);
	return (struct lista*) l;
}

void ordQuicksort(struct lista *l, int izq, int der)
{
	if(l)
	{
		if(izq >= der) return;
		struct lista *pIzq = devolverPos(l, izq), *pDer = devolverPos(l, der);
		int pivote = pIzq->valor; //Guardando el pivote
		int m = izq, n = der + 1;
		while(1)
		{
			do{m++; pIzq = pIzq->sig;}while((pIzq->valor <= pivote) && (m < der));
			do{n--; pDer = devolverPos(l, n);}while((pDer->valor >= pivote) && (n > izq));
			if(m >= n) break;
			intercambiar(&(pDer->valor),&(pIzq->valor));
		}
		//Anulando la posicion de pIzq y buscando el limite por la izquierda
		pIzq = devolverPos(l, izq);
		pIzq->valor = pDer->valor;
		pDer->valor = pivote;
		ordQuicksort(l, izq, n-1);
		ordQuicksort(l, n+1, der);
	}
}

void ordQuicksortVector(int *v, int izq, int der)
{
	if(izq >= der) return;
	int pivote = v[izq], m = izq, n = der + 1;
	while(1)
	{
		do{
			m++;
		}while((v[m] <= pivote) && (m < der));
		do{
			n--;
		}while((v[n] >= pivote) && (n > izq));
		if(m >= n) break;
		intercambiar(&(v[m]), &(v[n]));
	}
	v[izq] = v[n];
	v[n] = pivote;
	ordQuicksortVector(v, izq, n - 1);
	ordQuicksortVector(v, n + 1, der);
}

int copiarListaVector(struct lista *l, int **v)
{
	int cantidadElementos = 0;
	for(struct lista *aux = l; aux; cantidadElementos++, aux = aux->sig);
	int *a = NULL;
	if(cantidadElementos)
	{
		a = (int *) malloc(sizeof(int)*cantidadElementos);
		for(int i = 0; i < cantidadElementos; i++, l = l->sig)
			a[i] = l->valor;
	}
	*v = a;
	return cantidadElementos;
}

int main(){
	int op;
	struct lista *lista = NULL;
	struct lista *aux = NULL;
	int *v = NULL;
	do{
		system("cls");
		printf("\n\n\t ###    Menu    ###\n");
		printf("\n\t 1.-> Agregar elemento");
		printf("\n\t 2.-> Eliminar elemento");
		printf("\n\t 3.-> Borrar toda la lista!!!");
		printf("\n\t 4.-> Mostrar lista");
		printf("\n\n\t ###    Metodos de Ordenamiento    ###\n");
		printf("\n\t 5.-> Ordenar por intercambio");
		printf("\n\t 6.-> Ordenar por seleccion");
		printf("\n\t 7.-> Ordenar por burbuja");
		printf("\n\t 8.-> Ordenar por insercion");
		printf("\n\t 9.-> Ordenar por quicksort");
		printf("\n\t 10.-> Copiar lista vector ordenar y a lista");
		printf("\n\t 0.-> Salir\n\n");
		printf("\t ->: "); scanf("%i", &op); getchar();
		switch(op)
		{
		case 1:
			{
				int n = pedirNumero();
				agregarElemento(&lista, n);
			}
			break;
		case 2:
			{
				int n = pedirNumero();
				quitarElemento(&lista, n);
			}
			break;
		case 3:
				borrarLista(&lista);
		case 4:
				mostrarLista(lista);
			break;
		case 5:
				ordIntercambio(lista);
			break;
		case 6:
				ordSeleccion(lista);
			break;
		case 7:
				ordBurbuja(lista);
			break;
		case 8:
				ordInsercion(lista);
			break;
		case 9:
				{
					int elem = 0;
					for(struct lista *aux = lista; aux; elem++, aux = aux->sig);
					ordQuicksort(lista, 0, elem - 1);
				}
			break;
		case 10:
			{
				int elem = copiarListaVector(lista, &v);
				ordQuicksortVector(v, 0, elem - 1);
				for(int i = 0; i < elem; i++)
				{
					agregarElemento(&aux, v[i]);
				}
				mostrarLista(aux);
			}
			break;
		case 0:
			exit(1);
			break;
		default:
			printf("\n\t Opcion invalida !!!\n");
			break;
		};
		system("pause");
	}while(op);
	return 0;
}
