#include <stdio.h>

void quickSort(int vect[], int tam, int inicio, int fim){
  if ( fim <= inicio) return;

  int pivot = partition(vect, tam, inicio, fim);
  quickSort(vect, tam, inicio, pivot - 1);
  quickSort(vect, tam, pivot + 1, fim);
}

int partition(int vect[], int tam, int inicio, int fim){

  int pivot = vect[fim];
  int i = inicio - 1;

  for (int j = inicio; j <= fim - 1; j++){
    if (vect[j] < pivot){
      i++;
      int temp = vect[i];
      vect[i] = vect[j];
      vect[j] = temp;
    }
  }
  i++;
  int temp = vect[i];
  vect[i] = vect[fim];
  vect[fim] = temp;

  return i;
}

int main(void){
  int vect[] = {37, 12, 68, 53, 25, 41, 76, 9};
  int tam = sizeof(vect) / 4;
  int inicio = 0;
  int fim = tam - 1;
  quickSort(vect, tam, inicio, fim);
  for (int i = 0; i < tam; i++){
    printf("%d ", vect[i]);
  }
  return 0;
}
