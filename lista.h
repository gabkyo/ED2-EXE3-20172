#ifndef LISTA_H_
#define LISTA_H_

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

TipoLista* InicializaLista();
/////////////////////////////////////////////////////////////
void InsereLista (TipoElemento* aluno, TipoLista* lista);
/////////////////////////////////////////////////////////////
TipoElemento* RetiraLista(TipoLista* lista, char *arquivo);
/////////////////////////////////////////////////////////
int ImprimeLista (TipoLista* lista);
//////////////////////////////////////////////////////////
TipoLista* LiberaLista (TipoLista* lista);
//////////////////////////////////////////////////////////////////////////////
TipoElemento* InicializaTipoElemento(char* nome, int ocorrencias);

void ProcuraEsomaNaLista(TipoLista *lista, char *documento);
int procuraPosicao(char *arquivo);

#endif
