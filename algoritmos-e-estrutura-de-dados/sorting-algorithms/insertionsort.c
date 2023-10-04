#include <stdio.h>

void insertionSort(int vect[], int tam){
  for(int i = 1; i < tam; i++){
    int temp = vect[i];
    int j = i - 1;

    while(j >=0 && vect[j] > temp){
      vect[j + 1] = vect[j];
      j--;
    }
    vect[j + 1] = temp;
  }
}

int main (void){

  int vetor[] = {4, 6, 2, 4, 1, 5, 9, 6, 3};
  int tam = sizeof(vetor) / 4;
  insertionSort(vetor, tam);
  for(int i = 0; i < tam; i++){
    printf("%d ", vetor[i]);
  }
  return 0;
}
