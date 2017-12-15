#include "Hash.h"
#include "ExtraiPalavra.h"
#include "lista.h"
#include <string.h>

char documentos[50][256] = { "documentos/m01.txt", "documentos/m02.txt",
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

int main(int argc, char *argv[]) {
	arq = NULL;
	int i;
	Inicializa(Tabela);
	GeraPesos(p);
	/*Está faltando iterar os 50 arquivos*/
	for (int j = 0; j < 50; j++) {
		i = 0;
		Lista_de_Palavras *lista = ler_arquivo(documentos[j], argv[1]);

		//LerPalavra(lista->palavras[0], N);
		Elemento.Chave[0] = '\0';
		strcpy(Elemento.Chave, lista->palavras[0]);

		while (strcmp(Elemento.Chave, "aaaaaaaaaa") != 0 && i < lista->tamanho) {

			Insere(Elemento, p, Tabela, documentos[j]);

			strcpy(Elemento.Chave, lista->palavras[i]);
			i++;
		}
	}

	//printf("Tabela apos insercao:\n");
    qsort((TipoItem*)Tabela,M,sizeof(TipoItem),compara);
	Imprime(Tabela);

	if (arq != NULL)
		fclose(arq);
	return 0;
}

