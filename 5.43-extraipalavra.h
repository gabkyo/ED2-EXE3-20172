/* Informar nomes dos arquivos teste.txt e alfabeto.txt na linha de comando */
/* Exemplo: a.out teste.txt alfabeto.txt                                    */

#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define MAXALFABETO 255
#define TRUE  1
#define FALSE 0

typedef short TipoAlfabeto[MAXALFABETO + 1];
FILE *ArqTxt, *ArqAlf;
TipoAlfabeto Alfabeto;
char Palavra[256];
char Linha[256];
int i;
short aux;

typedef struct Lista_de_Palavras {
	int tamanho;
	char **palavras;
} Lista_de_Palavras;

void DefineAlfabeto(short *Alfabeto) {
	char Simbolos[MAXALFABETO + 1];
	int i, CompSimbolos;
	char *TEMP;
	for (i = 0; i <= MAXALFABETO; i++)
		Alfabeto[i] = FALSE;
	fgets(Simbolos, MAXALFABETO + 1, ArqAlf);
	TEMP = strchr(Simbolos, '\n');
	if (TEMP != NULL)
		*TEMP = 0;
	CompSimbolos = strlen(Simbolos);
	for (i = 0; i < CompSimbolos; i++)
		Alfabeto[Simbolos[i] + 127] = TRUE;
	Alfabeto[0] = FALSE; /* caractere de codigo zero: separador */
}

Lista_de_Palavras *ler_arquivo(char *texto, char *alfabeto) {
	ArqTxt = fopen(texto, "r");
	ArqAlf = fopen(alfabeto, "r");
	Lista_de_Palavras *lista;
	lista = malloc(sizeof(Lista_de_Palavras));
	lista->tamanho = 0;
	DefineAlfabeto(Alfabeto); /* Le alfabeto definido em arquivo */
	aux = FALSE;
	while (fgets(Linha, 256, ArqTxt) != NULL) {
		for (i = 1; i <= strlen(Linha); i++) {
			if (Alfabeto[Linha[i - 1] + 127]) {
				sprintf(Palavra + strlen(Palavra), "%c", Linha[i - 1]);
				aux = TRUE;
			} else if (aux) {
				lista->palavras =realloc(lista->palavras,sizeof(char) * 256 * (lista->tamanho + 1));
				strcpy(lista->palavras[lista->tamanho], Palavra);
				++(lista->tamanho);
				puts(Palavra); //palavra lida
				*Palavra = '\0';
				aux = FALSE;
			}
		}
	}
	if (aux) {
		lista->palavras = realloc(lista->palavras,sizeof(char) * 256 * (lista->tamanho + 1));
		strcpy(lista->palavras[lista->tamanho], Palavra);
		++(lista->tamanho);
		puts(Palavra); //palavra lida
		*Palavra = '\0';
	}
	for (int i = 0; i < lista->tamanho; ++i) {
		for (int j = 0; j < strlen(lista->palavras[i]); ++j) {
			lista->palavras[i][j] = tolower(lista->palavras[i][j]); //tudo em lowercase
		}
	}
	fclose(ArqTxt);
	fclose(ArqAlf);
	return lista;
}

/* End. */
