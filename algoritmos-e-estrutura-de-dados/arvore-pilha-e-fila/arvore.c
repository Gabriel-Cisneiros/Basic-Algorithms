#include <stdio.h>
#include <stdlib.h>

typedef struct arvore {
  int info;
  struct arvore *esq;
  struct arvore *dir;
} Arvore;

Arvore *criarNo(int valor, Arvore *esq, Arvore *dir) {
  Arvore *no = (Arvore *)malloc(sizeof(Arvore));
  no->info = valor;
  no->esq = esq;
  no->dir = dir;
  return no;
}

int busca(int target, Arvore *raiz){
  if (raiz == NULL){
    return -1;
  }
  else if (raiz->info == target){
    return target;
  }
  else if(raiz->info < target){
     return busca(target, raiz->esq);
  }
  else{
    return busca(target, raiz->dir);
  }
  return target;
}

int buscaMaiorQueCinquenta(Arvore *raiz){
  if (raiz == NULL){
    return 0;
  }

  int contador = 0;

  if (raiz->info > 50){
    contador++;
  }

  contador += buscaMaiorQueCinquenta(raiz->esq);
  contador += buscaMaiorQueCinquenta(raiz->dir);

  return contador;
}


Arvore *insere(Arvore *raiz, Arvore *no) {
  if (raiz == NULL) {
    raiz = no;
  } else {
    if (no->info < raiz->info) {
      raiz->esq = insere(raiz->esq, no);
    } else {
      raiz->dir = insere(raiz->dir, no);
    }
  }
  return raiz;
}

void red(Arvore *raiz) {
  if (raiz != NULL) {
    printf("%d", raiz->info);
    red(raiz->esq);
    red(raiz->dir);
  }
}

void erd(Arvore *raiz) {
  if (raiz != NULL) {
    erd(raiz->esq);
    printf("%d", raiz->info);
    erd(raiz->dir);
  }
}

void edr(Arvore *raiz) {
  if (raiz != NULL) {
    edr(raiz->esq);
    edr(raiz->dir);
    printf("%d", raiz->info);
  }
}

Arvore *removerRaiz(Arvore *raiz) {
  Arvore *p, *q;

  if (raiz == NULL) {
    return NULL;
  } else if (raiz->esq == NULL) {
    q = raiz->dir;
    free(raiz);
    return q;
  } else {
    p = raiz;
    q = raiz->esq;
  }
  while (q->dir != NULL) {
    p = q;
    q = q->dir;
  }
  if (p != raiz) {
    p->dir = q->esq;
    q->esq = raiz->esq;
  }
  q->dir = raiz->dir;
  free(raiz);
  return q;
}

int main(void) {
  Arvore *raiz = NULL;
  Arvore *a, *b, *c, *d, *e, *f;
  int target = 6;

  raiz = criarNo(51, a, b);
  a = criarNo(16, NULL, c);
  b = criarNo(20, d, e);
  c = criarNo(50, NULL, NULL);
  d = criarNo(10, NULL, NULL);
  e = criarNo(60, NULL, NULL);

  printf("Antes do removerRaiz:\n");
  red(raiz);
  printf("\n");
  edr(raiz);
  printf("\n");
  erd(raiz);

  printf("\n");
  printf("\n");

  printf("busca do valor %d:", target);

  int resultado = busca(target, raiz);

  if (resultado == -1){
    printf("\nNúmero não encontrado");
  } else {
    printf("\nO numero foi %d encontrado", target);
  }

  printf("\n");

  raiz = removerRaiz(raiz);
  printf("\nApos o removerRaiz:\n");
  red(raiz);
  printf("\n");
  edr(raiz);
  printf("\n");
  erd(raiz);

  return 0;
}
