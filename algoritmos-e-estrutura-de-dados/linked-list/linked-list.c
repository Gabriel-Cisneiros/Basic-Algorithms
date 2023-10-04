#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *next;
};

void printLinkedList(struct node *p) {
  while (p != NULL) {
    printf("%d ", p->value);
    p = p->next;
  }
}

struct node* insert(struct node *head, int data) {
  struct node *newNode = malloc(sizeof(struct node));
  newNode->value = data;
  newNode->next = head;
  return newNode;
}

struct node* removeNode(struct node *head, int data) {
  struct node *current = head;
  struct node *prev = NULL;

  while (current != NULL) {
    if (current->value == data) {
      if (prev != NULL) {
        prev->next = current->next;
        free(current);
      } else {
        struct node *temp = head;
        head = head->next;
        free(temp);
      }
      return head;
    }
    prev = current;
    current = current->next;
  }

  return head;
}

struct node* search(struct node *head, int data) {
  struct node *current = head;
  while (current != NULL) {
    if (current->value == data) {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

int main() {
  struct node *head = NULL;
  head = insert(head, 3);
  head = insert(head, 2);
  head = insert(head, 1);

  printf("Lista original: ");
  printLinkedList(head);
  printf("\n");

  int searchValue = 2;
  struct node *searchResult = search(head, searchValue);
  if (searchResult != NULL) {
    printf("%d encontrado na lista.\n", searchValue);
  } else {
    printf("%d não encontrado na lista.\n", searchValue);
  }

  int removeValue = 2;
  head = removeNode(head, removeValue);
  printf("Lista após a remoção de %d: ", removeValue);
  printLinkedList(head);
  printf("\n");

  return 0;
}
