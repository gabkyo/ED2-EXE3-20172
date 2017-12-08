#include "ExtraiPalavra.h"

char *ltrim(char *s)
{
    while(isspace(*s)) s++;
    return s;
}

char *rtrim(char *s)
{
    char* back = s + strlen(s);
    while(isspace(*--back));
    *(back+1) = '\0';
    return s;
}

char *trim(char *s)
{
    return rtrim(ltrim(s)); 
}

Lista_de_Palavras*
alocaListaPalavras(int tamanhoLista, int tamanhoPalavra){

  Lista_de_Palavras *lista = malloc(sizeof(Lista_de_Palavras));
  lista->tamanho = 0;

  lista->palavras = (char**)malloc(tamanhoLista);
  for(int i = 0; i < tamanhoLista; i++){
    lista->palavras[i] = (char*)malloc(tamanhoPalavra);
    lista->palavras[i] = strdup("-1");
  }

  return lista;
}

void 
DefineAlfabeto(short *Alfabeto) {
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

Lista_de_Palavras* 
ler_arquivo(char *texto, char *alfabeto) {
	ArqTxt = fopen(texto, "r");
	ArqAlf = fopen(alfabeto, "r");

	int k = 0;
	Lista_de_Palavras *lista = alocaListaPalavras(M,PALAVRA);

	DefineAlfabeto(Alfabeto); /* Le alfabeto definido em arquivo */
	aux = FALSE;

	while (fgets(Linha, 256, ArqTxt) != NULL) { 
		for (i = 1; i <= strlen(Linha); i++) 
		{ 
			if (Alfabeto[Linha[i-1]+127]) { 
				sprintf(Palavra + strlen(Palavra), "%c", Linha[i-1]);
			  	aux = TRUE;
			}  
			else if (aux) { 
				if(Palavra != '\0'){
					strcpy(lista->palavras[k],Palavra);
					lista->tamanho++;
					//puts(Palavra); // jogar palavra na lista
					//printf("%s\n",lista->palavras[k] );
					*Palavra = '\0';
					aux = FALSE;
					k++;
				}
			}

		}
  	}

	if (aux) {
		if(Palavra != '\0'){
			strcpy(lista->palavras[k],Palavra);
			lista->tamanho++;
			//puts(Palavra); //palavra lida
			*Palavra = '\0';
		}
	}



	for (int i = 0; i < lista->tamanho;	 ++i) {
		for (int j = 0; j < strlen(lista->palavras[i]); ++j) {
			lista->palavras[i][j] = tolower(lista->palavras[i][j]); //tudo em lowercase
		}
		lista->palavras[i] = trim(lista->palavras[i]);
	}

	fclose(ArqTxt);
	fclose(ArqAlf);


	printf("TAMANHO : %d\n",lista->tamanho );
	for(int i = 0; i < lista->tamanho; i++){
		if(strcmp(lista->palavras[i], "-1"))
			printf("%s\n",lista->palavras[i] );
	}


	return lista;
}

/* End. */
