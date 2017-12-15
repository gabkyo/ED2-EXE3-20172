#include "lista.h"

char posicoes[50][256] = { "documentos/m01.txt", "documentos/m02.txt",
		"documentos/m03.txt", "documentos/m04.txt", "documentos/m05.txt",
		"documentos/m06.txt", "documentos/m07.txt", "documentos/m08.txt",
		"documentos/m09.txt", "documentos/m10.txt", "documentos/m11.txt",
		"documentos/m12.txt", "documentos/m13.txt", "documentos/m14.txt",
		"documentos/m15.txt", "documentos/m16.txt", "documentos/m17.txt",
		"documentos/m18.txt", "documentos/m19.txt", "documentos/m20.txt",
		"documentos/m21.txt", "documentos/m22.txt", "documentos/m23.txt",
		"documentos/m24.txt", "documentos/m25.txt", "documentos/m26.txt",
		"documentos/m27.txt", "documentos/m28.txt", "documentos/m29.txt",
		"documentos/m30.txt", "documentos/m31.txt", "documentos/m32.txt",
		"documentos/m33.txt", "documentos/m34.txt", "documentos/m35.txt",
		"documentos/m36.txt", "documentos/m37.txt", "documentos/m38.txt",
		"documentos/m39.txt", "documentos/m40.txt", "documentos/m41.txt",
		"documentos/m42.txt", "documentos/m43.txt", "documentos/m44.txt",
		"documentos/m45.txt", "documentos/m46.txt", "documentos/m47.txt",
		"documentos/m48.txt", "documentos/m49.txt", "documentos/m50.txt" };

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
int procuraPosicao(char *arquivo){
    int posicao;
    
    for(int i = 0;i < 50;i++){
        if(!strcmp(arquivo, posicoes[i])){
            posicao = i;
            return posicao + 1;
        }
    } 
    return -1;
}
/////////////////////////////////////////////////////////
int
ImprimeLista(TipoLista* lista) {
	celula* p = lista->primeiro;
	int qtd = 0;
	while (p != NULL) {
	    int posicao = procuraPosicao(p->item->nomeArquivo);
	    //printf("%s\n",p->item->nomeArquivo);
		printf("[%d,%i]", posicao,
				p->item->ocorrencias);
		if(p->prox != NULL){
		    printf(",");
		}
		qtd++;
		p = p->prox;
	}
	//printf("\n");
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
