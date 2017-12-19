#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct elemento
{
  char value;
  struct elemento *prox;
}tipo_elemento;

typedef struct
{
  tipo_elemento *inicio;
  tipo_elemento *fim;
}FILA;

FILA* construtor()
{
  FILA *x= (FILA*)malloc(sizeof(FILA));
  if ( !x )
  {
    printf("ERRO\n");
    exit(1);
  }
  else
  {
    x->inicio=NULL;
    x->fim=NULL;
    return x;
  }
}

int vazia(FILA *x)
{
  if(x->inicio == NULL)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void desconstrutor(FILA *x)
{
  if(!vazia(x))
  {
    tipo_elemento *x1,*x2;
    x1=x->inicio;
    while(x1 != NULL)
    {
      x2=x1;
      x1=x1->prox;
      free(x2);
    }
  }
}

int insere(FILA *x,char value_here)
{
  tipo_elemento *x3=(tipo_elemento*)malloc(sizeof(tipo_elemento));
  if( x3 == NULL)
  {
    printf("Erro na alocação de memoria\n");
    return 0;
  }
  else
  {
    x3->value=value_here;
    x3->prox=NULL; //ultima posição
    if( vazia(x))
    {
      x->inicio=x3;
    }
    else
    {
      x->fim->prox=x3; //novo fim aponta na memoria alocada
    }
    x->fim=x3;
    return 1;
  }
}

int retira(FILA *x,char *word)
{
  tipo_elemento *aux;
  if( vazia(x))
  {
    return 0;
  }
  else
  {
    (*word)=x->inicio->value;
    aux=x->inicio;
    x->inicio=x->inicio->prox;
    free(aux);
    return 1;
  }
}

void print_fila(FILA *x)
{
  tipo_elemento *aux;
  if(vazia(x))
  {
    printf("Fila Vazia\n");
  }
  else
  {
    aux = x->inicio;
    do {
      printf("[%c]",aux->value);
      aux = aux->prox;
    } while(aux != NULL);
    printf("\n");
  }
}

char see_first(FILA *x) //mostra o primeiro valor a sair da fila
{
  char word;
  word = x->inicio->value;
  return word;
}

int tam_fila(FILA *x)
{
  tipo_elemento *aux;
  int cont=0;
  if(vazia(x))
  {
    return cont;
  }
  else
  {
    aux = x->inicio;
    do {
      cont++;
      aux = aux->prox;
    } while(aux != NULL);
    return cont;
  }
}
