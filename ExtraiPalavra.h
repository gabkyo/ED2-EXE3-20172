
/* Header Files to include*/
#ifndef EXTRAIPALAVRA_H_
#define EXTRAIPALAVRA_H_

/* Informar nomes dos arquivos teste.txt e alfabeto.txt na linha de comando */
/* Exemplo: a.out teste.txt alfabeto.txt                                    */

#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Hash.h"

#define MAXALFABETO 255
#define PALAVRA 256
#define TRUE  1
#define FALSE 0

typedef short TipoAlfabeto[MAXALFABETO + 1];
FILE *ArqTxt, *ArqAlf;
TipoAlfabeto Alfabeto;
char Palavra[256];
char Linha[256];
int i;
short aux;

typedef struct Lista {
	int tamanho;
	char **palavras;
} Lista_de_Palavras;

void DefineAlfabeto(short *Alfabeto);

Lista_de_Palavras *ler_arquivo(char *texto, char *alfabeto);

#endif
