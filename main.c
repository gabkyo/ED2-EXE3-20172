#include "5.28a5.29-hash-endaberto.h"

int main(int argc, char *argv[]) {
	arq = NULL;
	int i = 0;
	Inicializa(Tabela);

	Lista_de_Palavras *lista = ler_arquivo(argv[1], argv[2]);
	GeraPesos(p);
	//LerPalavra(lista->palavras[0], N);
	strcpy(Elemento.Chave, lista->palavras[0]);
	while (strcmp(Elemento.Chave, "aaaaaaaaaa") != 0 && i < lista->tamanho) {
		Insere(Elemento, p, Tabela);
		strcpy(Elemento.Chave, lista->palavras[i]);
		i++;
	}

	printf("Tabela apos insercao:\n");
	Imprime(Tabela);

	if (arq != NULL)
		fclose(arq);
	return 0;
}
