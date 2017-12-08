#include "Hash.h"
#include "ExtraiPalavra.h"
#include <string.h>

int main(int argc, char *argv[]) {
	arq = NULL;
	int i = 0;
	Inicializa(Tabela);
		printf("passou1\n");

	/*Está faltando iterar os 50 arquivos*/
	//for(int i = 1; i <= 50; i++){
		Lista_de_Palavras *lista = ler_arquivo(argv[1], argv[2]);
		printf("passou\n");
		GeraPesos(p);
		//LerPalavra(lista->palavras[0], N);
		strcpy(Elemento.Chave, lista->palavras[0]);
		while (strcmp(Elemento.Chave, "aaaaaaaaaa") != 0 && i < lista->tamanho) {

			Insere(Elemento, p, Tabela, argv[1]);

			strcpy(Elemento.Chave, lista->palavras[i]);
			i++;
		}
	//}

	printf("Tabela apos insercao:\n");
	Imprime(Tabela);

	if (arq != NULL)
		fclose(arq);
	return 0;
}
