/*
 ============================================================================
 Name        : Prompt.c
 Author      : 
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_entry(char *entry) {
	//printf("You entered: %s\n", entry);
}

typedef struct No No;

struct No
{
	int valor;
	No* prox;

};

typedef struct
{
	No* first;
	No* last;
	int tam;
} ListaNo;

int get(ListaNo* n, int indice)
{
	indice--;
	No* proximo = n->first;
	for(int i=0; i<indice; i++)
	{
		proximo = proximo->prox;
	}
	printf("%d ", proximo->valor);
}

void put(ListaNo* n, int v)
{
	No* novoNo = (No*)malloc(sizeof(No));
	novoNo->valor = v;
	novoNo->prox = NULL;
	if(n->first == NULL)
	{
		n->first = novoNo;
		n->tam =1;

	} else{
		
		n->last->prox = novoNo;
		n->tam++;
	}
	n->last = novoNo;
}
void list(ListaNo* n)
{
	No* proximo = n->first;
	for(int i=0; i<n->tam; i++)
	{
		printf("%d ", proximo->valor);
		proximo = proximo->prox;

	}
	printf("\n");
}
void rm(ListaNo* n, int v)
{
	No* proximo = n->first;
	No* auxProx = NULL;
	while(proximo!=NULL)
	{
		if(proximo->valor == v)
		{
			break;
		} else
		{
			auxProx = proximo;
			proximo = proximo->prox;

		}
		
	}
	if(proximo->valor == v)
	{
		auxProx = proximo->prox;
		n->tam --;
		free(proximo);
	}
	else
	{	
		printf("Valor não encontrado na lista");
	}

}
void clear(ListaNo* n)
{
	No* proximo = n->first;
	No* auxProximo;
	for(int i=0; i<n->tam; i++)
	{
		auxProximo = proximo->prox;
		if(proximo!=NULL)
			free(proximo);
		proximo = auxProximo;
	}

}
void first(ListaNo* n)
{
	printf("%d \n", n->first->valor);
}
void last(ListaNo* n)
{
	printf("%d \n", n->last->valor);
}

void quicksort()
{
}

int main(int argc, char *argv[]) {
	char input[201];
	int valor;
	ListaNo* minhaLista = (ListaNo*)malloc(sizeof(ListaNo));
	while(1) {
		printf("prompt> ");
		if (fgets(input, 200, stdin) == NULL) {
			printf("An error ocurred.\n");
			break;
		}

		if (strncmp(input, "exit\n", 5) == 0) {
			printf("Leaving. Good bye.\n");
			break;
		}
		if (strncmp(input, "put ", 4) == 0)
		{
			sscanf(input, "put %d", &valor);
			put(minhaLista, valor);
			list(minhaLista);

		}
		if (strncmp(input, "get ", 4) == 0)
		{
			sscanf(input,"get %d", &valor);
			get(minhaLista, valor);

		}
		if (strncmp(input, "list", 4) == 0)
			list(minhaLista);
		if (strncmp(input, "remove ", 7) == 0)
		{
			sscanf(input,"remove %d", &valor);
			rm(minhaLista, valor);
			list(minhaLista);
		}
		if (strncmp(input, "clear", 5) == 0)
			clear(minhaLista);
		if (strncmp(input, "first", 5) == 0)
			first(minhaLista);
		if (strncmp(input, "last", 4) == 0)
			last(minhaLista);
		if (strncmp(input, "sort", 4) == 0)
			quicksort(minhaLista);

		print_entry(input);
	}

	return EXIT_SUCCESS;
}
