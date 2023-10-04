#include <stdio.h>

void selectionSort(int vect[], int tam){
  for (int i = 0; i < tam; i++){
    int min = i;
    for (int j = i + 1; j < tam; j++){
      if(vect[min] > vect[j]){
        min = j;
      }
    }
    int temp = vect[i];
    vect[i] = vect[min];
    vect[min] = temp;
  }
}

int main (void) {
  int vect[] = {37, 12, 68, 53, 25, 41, 76, 9};
  int tam = sizeof(vect)/4;
  selectionSort(vect, tam);
  for (int i = 0; i < tam; i++){
    printf("%d ", vect[i]);
  }
  return 0;
}
