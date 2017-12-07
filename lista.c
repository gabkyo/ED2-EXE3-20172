#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipoelemento{
  char *nomeArquivo;
  int ocorrencias;
}TipoElemento;

typedef struct Celula{
  TipoElemento item;
  struct Celula *prox;
}celula;

typedef struct tipolista{
  celula *primeiro, *ultimo;
}TipoLista;

TipoLista* 
InicializaLista(){
  TipoLista *lista = (TipoLista*)malloc(sizeof(TipoLista));
  lista->primeiro = NULL;
  lista->ultimo = NULL;
  return lista;
}
/////////////////////////////////////////////////////////////
void 
InsereLista(TipoElemento* aluno, TipoLista* lista){
  celula* novo = (celula*)malloc(sizeof(celula));

  if(lista->ultimo == NULL && lista->primeiro == NULL)
  {
    lista->primeiro = lista->ultimo = novo;
  }
  else
  {
    novo->prox = lista->primeiro;
    lista->primeiro = novo;
  }
}
/////////////////////////////////////////////////////////////
TipoElemento* 
RetiraLista (TipoLista* lista, int mat){
  celula* ant;
  celula* p = lista->primeiro;

  while(p!= NULL && p->item.matricula != mat){
    ant = p;
    p = p->prox;
  }
  if(p == NULL)
    return 0;
  if(p == lista->primeiro && p == lista->ultimo){
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    free(p);
    return 0;
  }
  if(p == lista->ultimo){
    lista->ultimo->prox = NULL;
    lista->ultimo = NULL;
    free(p);
    return 0;
  }
  if(p == lista->primeiro){
    lista->primeiro = lista->primeiro->prox;
    free(p);
    return 0;
  }
  else{
    ant->prox = p->prox;
  }
  free(p);
  return 0;
}
/////////////////////////////////////////////////////////
void 
ImprimeLista (TipoLista* lista){
  celula* p = lista->primeiro;

  while(p != NULL){
    printf("NOME:%s\nMATRICULA:%d\nENDERECO:%s\n",p->item.nome
      ,p->item.matricula,p->item.endereco);
    p = p->prox;
  }
}
//////////////////////////////////////////////////////////
TipoLista* 
LiberaLista (TipoLista* lista){
  celula* p = lista->primeiro;
  celula* proximo = p->prox;

  while(p != NULL){
    free(p);
    p = proximo;
    proximo = p->prox;
  }
    free(lista);
}
//////////////////////////////////////////////////////////////////////////////
TipoElemento* 
InicializaTipoElemento(char* nome, int ocorrencias){
  TipoElemento* item = (TipoElemento*)malloc(sizeof(TipoElemento));

  item->nomeArquivo = malloc(sizeof(char)*strlen(nome));
  strcpy(item->nomeArquivo, nome);
  
  item->ocorrencias = ocorrencias;

  return item;
}