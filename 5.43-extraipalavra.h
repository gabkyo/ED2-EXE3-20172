#ifndef EXTRAI_H_
#define EXTRAI_H
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

void DefineAlfabeto(short *Alfabeto);

Lista_de_Palavras *ler_arquivo(char *texto, char *alfabeto);
#endif
