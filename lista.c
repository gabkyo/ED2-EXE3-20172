#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipoelemento {
	char *nomeArquivo;
	int ocorrencias;
} TipoElemento;

typedef struct Celula {
	TipoElemento *item;
	struct Celula *prox;
} celula;

typedef struct tipolista {
	celula *primeiro, *ultimo;
} TipoLista;

TipoLista*
InicializaLista() {
	TipoLista *lista = (TipoLista*) malloc(sizeof(TipoLista));
	lista->primeiro = NULL;
	lista->ultimo = NULL;
	return lista;
}
/////////////////////////////////////////////////////////////
void InsereLista(TipoElemento* elemento, TipoLista* lista) {
	celula *novo = (celula*) malloc(sizeof(celula));
	novo->prox = NULL;
	novo->item = elemento;

	if (lista->ultimo == NULL && lista->primeiro == NULL) {
		lista->primeiro = lista->ultimo = novo;
	} else {
		novo->prox = lista->primeiro;
		lista->primeiro = novo;
	}
}
/////////////////////////////////////////////////////////////
TipoElemento*
RetiraLista(TipoLista* lista, char *arquivo) {
	celula* ant;
	celula* p = lista->primeiro;

	while (p != NULL && strcmp(p->item->nomeArquivo, arquivo) != 0) {
		ant = p;
		p = p->prox;
	}
	if (p == NULL)
		return 0;
	if (p == lista->primeiro && p == lista->ultimo) {
		lista->primeiro = NULL;
		lista->ultimo = NULL;
		free(p);
		return 0;
	}
	if (p == lista->ultimo) {
		lista->ultimo->prox = NULL;
		lista->ultimo = NULL;
		free(p);
		return 0;
	}
	if (p == lista->primeiro) {
		lista->primeiro = lista->primeiro->prox;
		free(p);
		return 0;
	} else {
		ant->prox = p->prox;
	}
	free(p);
	return 0;
}
/////////////////////////////////////////////////////////
int
ImprimeLista(TipoLista* lista) {
	celula* p = lista->primeiro;
	int qtd = 0;
	while (p != NULL) {
		printf("  [ %s | %i ] ", p->item->nomeArquivo,
				p->item->ocorrencias);
		qtd++;
		p = p->prox;
	}
	printf("\n");
	return qtd;
}
//////////////////////////////////////////////////////////
TipoLista*
LiberaLista(TipoLista* lista) {
	celula* p = lista->primeiro;
	celula* proximo = p->prox;

	while (p != NULL) {
		free(p->item->nomeArquivo);
		free(p);
		p = proximo;
		proximo = p->prox;
	}
	free(lista);
}
//////////////////////////////////////////////////////////////////////////////
TipoElemento*
InicializaTipoElemento(char* nome, int ocorrencias) {
	TipoElemento* item = (TipoElemento*) malloc(sizeof(TipoElemento));

	item->nomeArquivo = malloc(sizeof(char) * strlen(nome));
	strcpy(item->nomeArquivo, nome);

	item->ocorrencias = ocorrencias;

	return item;
}



void ProcuraEsomaNaLista(TipoLista *lista, char *documento) {
	if (lista == NULL) {
		printf("Lista Vazia\n");
		return;
	}
	celula* p = lista->primeiro;

	while (p != NULL) {
		if (strcmp(p->item->nomeArquivo, documento) == 0) {
			p->item->ocorrencias++;
			return;
		}
		if(p->prox==NULL){
			p->prox=(celula*) malloc(sizeof(celula));
			p->prox->prox=NULL;
			p->prox->item=InicializaTipoElemento(documento,1);
			return;
		}
		p = p->prox;
	}
	printf("Celula não encontrada.\n");
}
