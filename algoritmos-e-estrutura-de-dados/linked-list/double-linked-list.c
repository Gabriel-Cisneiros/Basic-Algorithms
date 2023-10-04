#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista
struct Node {
    int data;
    struct Node* prox;
    struct Node* ant;
};

// Função para criar um novo nó
struct Node* criarNo(int data) {
    struct Node* novoNo = (struct Node*)malloc(sizeof(struct Node));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória para o novo nó.\n");
        exit(1);
    }
    novoNo->data = data;
    novoNo->prox = NULL;
    novoNo->ant = NULL;
    return novoNo;
}

// Função para inserir um nó no início da lista
void inserirInicio(struct Node** cabeca, int data) {
    struct Node* novoNo = criarNo(data);
    if (*cabeca != NULL) {
        novoNo->prox = *cabeca;
        (*cabeca)->ant = novoNo;
    }
    *cabeca = novoNo;
}

// Função para imprimir a lista da esquerda para a direita
void imprimirParaFrente(struct Node* cabeca) {
    struct Node* atual = cabeca;
    while (atual != NULL) {
        printf("%d ", atual->data);
        atual = atual->prox;
    }
    printf("\n");
}

// Função para imprimir a lista da direita para a esquerda
void imprimirParaTras(struct Node* cauda) {
    struct Node* atual = cauda;
    while (atual != NULL) {
        printf("%d ", atual->data);
        atual = atual->ant;
    }
    printf("\n");
}

// Função principal para teste
int main() {
    struct Node* cabeca = NULL;
    inserirInicio(&cabeca, 3);
    inserirInicio(&cabeca, 2);
    inserirInicio(&cabeca, 1);

    printf("Lista encadeada (da esquerda para a direita): ");
    imprimirParaFrente(cabeca);

    // Vamos obter a cauda da lista para imprimir da direita para a esquerda
    struct Node* cauda = cabeca;
    while (cauda->prox != NULL) {
        cauda = cauda->prox;
    }

    printf("Lista encadeada (da direita para a esquerda): ");
    imprimirParaTras(cauda);

    // Libera a memória alocada para os nós da lista
    while (cabeca != NULL) {
        struct Node* temp = cabeca;
        cabeca = cabeca->prox;
        free(temp);
    }

    return 0;
}
