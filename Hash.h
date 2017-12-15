
/* Header Files to include*/
#ifndef HASH_H_
#define HASH_H_

#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"

#define VAZIO  "!!!!!!!!!!"
#define RETIRADO  "**********"

#define N  256  /* Tamanho da Chave */
#define M  7151 //mudar para uma variavel M=N/0.7

typedef unsigned int TipoApontador;
typedef char TipoChave[N];
typedef unsigned TipoPesos[N];

typedef struct TipoItem {
	//char Palavra[256];
	TipoLista *listaOcorrencia; // incidencias em tipo 50 arquivos
	/* outros componentes */
	TipoChave Chave;
} TipoItem;

typedef unsigned int TipoIndice;
typedef TipoItem TipoDicionario[M];

char listaParaOrdenar[M][256];
TipoDicionario Tabela;
TipoPesos p;
TipoItem Elemento;
FILE *arq;
int j, i;

void GeraPesos(TipoPesos p);

TipoIndice h(TipoChave Chave, TipoPesos p);

void Inicializa(TipoDicionario T);

TipoApontador Pesquisa(TipoChave Ch, TipoPesos p, TipoDicionario T);

void Insere(TipoItem x, TipoPesos p, TipoDicionario T, char *documento);

void Retira(TipoChave Ch, TipoPesos p, TipoDicionario T);

//void Imprime(TipoDicionario tabela);

void LerPalavra(char *p, int Tam);

int compara(const void *a, const void *b);

void Imprime(TipoDicionario tabela);

#endif
