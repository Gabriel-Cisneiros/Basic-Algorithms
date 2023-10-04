#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  int info;
  struct celula *prox;
} Celula;

typedef struct pilha {
  Celula *topo;
} Pilha;

void inicializa(Pilha *pilha) { pilha->topo = NULL; }

void push(Pilha *pi, int valor) {
  Celula *nova = (Celula *)malloc(sizeof(Celula));
  nova->info = valor;
  nova->prox = pi->topo;
  pi->topo = nova;
}

void pop(Pilha *pi) {
  if (pi->topo == NULL) {
    printf("pilha vazia\n");
  } else {
    Celula *aux = pi->topo;
    pi->topo = (pi->topo)->prox;
    free(aux);
  }
}

void imprime(Pilha *pi) {
  if (pi->topo == NULL) {
    printf("pilha vazia\n");
  } else {
    for (Celula *p = pi->topo; p != NULL; p = p->prox) {
      printf("[%d] ", p->info);
    }
    printf("\n");
  }
}

int main() {
  Pilha pilha;

  inicializa(&pilha);
  push(&pilha, 10);
  push(&pilha, 20);
  push(&pilha, 30);
  push(&pilha, 40);
  push(&pilha, 50);

  printf("Conteúdo da pilha:\n");
  imprime(&pilha);

  printf("\n");

  pop(&pilha);
  pop(&pilha);

  printf("Conteúdo da pilha após pops:\n");
  imprime(&pilha);

  return 0;
}

