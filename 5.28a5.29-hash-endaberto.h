#ifndef HASH_H_
#define HASH_H_
#define VAZIO  "!!!!!!!!!!"
#define RETIRADO  "**********"

#define N  5003   /* Tamanho da Chave */
#define M  7151 //mudar para uma variavel M=N/0.7
typedef unsigned int TipoApontador;
typedef char TipoChave[N];
typedef unsigned TipoPesos[N];
typedef struct Lista_de_arquivo {
	char *nome_do_arquivo;
	int ocorrencias;
} Lista_de_arquivo;
typedef struct TipoItem {
	char Palavra[256];
	Lista_de_arquivo *tabela; // incidencias em tipo 50 arquivos
	/* outros componentes */
	TipoChave Chave;
} TipoItem;
typedef unsigned int TipoIndice;
typedef TipoItem TipoDicionario[M];
TipoDicionario Tabela;
TipoPesos p;
TipoItem Elemento;
FILE *arq;
int j, i;

void GeraPesos(TipoPesos p);

TipoIndice h(TipoChave Chave, TipoPesos p);
void Inicializa(TipoDicionario T);

TipoApontador Pesquisa(TipoChave Ch, TipoPesos p, TipoDicionario T);

void Insere(TipoItem x, TipoPesos p, TipoDicionario T);

void Retira(TipoChave Ch, TipoPesos p, TipoDicionario T);

void Imprime(TipoDicionario tabela);

void LerPalavra(char *p, int Tam);

#endif
