#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipoeleento TipoElemento;

typedef struct Celula celula;

typedef struct tipolista TipoLista;

TipoLista* InicializaLista();
/////////////////////////////////////////////////////////////
void InsereLista (TipoElemento* aluno, TipoLista* lista);
/////////////////////////////////////////////////////////////
TipoElemento* RetiraLista(TipoLista* lista, int mat);
/////////////////////////////////////////////////////////
int ImprimeLista (TipoLista* lista);
//////////////////////////////////////////////////////////
TipoLista* LiberaLista (TipoLista* lista);
//////////////////////////////////////////////////////////////////////////////
TipoElemento* InicializaTipoElemento(char* nome, int ocorrencias);

void ProcuraEsomaNaLista(TipoLista *lista, char *documento);
