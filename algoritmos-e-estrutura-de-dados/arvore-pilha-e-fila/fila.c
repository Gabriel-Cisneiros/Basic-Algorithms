#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
  int info;
  struct celula *prox;
}Celula;

typedef struct fila{
  Celula*inicio;
  Celula*fim;
}Fila;

void inicializa(Fila*fila){
  fila->inicio = NULL;
  fila->fim = NULL;
}

void insere(Fila*fila, int valor){
  Celula*novaCelula = (Celula*)malloc(sizeof(Celula));
  novaCelula->info = valor;
  novaCelula->prox = NULL;

  if (fila->inicio == NULL){
    fila->inicio = novaCelula;
  } else {
    (fila->fim)->prox = novaCelula;
  }
  fila->fim = novaCelula;
}

void remover (Fila*fila){
  if(fila->inicio == NULL){
    printf("Fila vazia :(");
  } else {
    Celula*temp = fila->inicio;
    fila->inicio = (fila->inicio)->prox;
    free(temp);
  }
}

void imprimir(Fila*fila){
  if(fila->inicio == NULL){
    printf("Fila vazia :(");
  } else {
    for(Celula *p = fila -> inicio; p != NULL; p = p->prox){
      printf("{%d}", p->info);
    }
    printf("\n");
  }
}

int main(void) {
  Fila fila;
  inicializa(&fila);

  insere(&fila, 10);
  insere(&fila, 25);
  insere(&fila, 8);
  insere(&fila, 23);
  insere(&fila, 11);
  printf("Fila antes da remoção\n");
  imprimir(&fila);

  printf("\n");

  remover(&fila);
  printf("Fila depois da remoção\n");
  imprimir(&fila);

  return 0;
}
