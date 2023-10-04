#include <stdio.h>

void bubbleSort(int vect[], int tam){
  for(int i = 0; i < tam; i++){
    for(int j = 0; j < tam - i - 1; j++){
      if(vect[j] > vect[j + 1]){
        int temp = vect[j];
        vect[j] = vect[j + 1];
        vect[j + 1] = temp;
      }
    }
  }
}

int main (void){
  int vect[] = {37, 12, 68, 53, 25, 41, 76, 9};
  int tam = sizeof(vect) / 4;
  bubbleSort(vect, tam);
  for (int i = 0; i < tam; i++){
    printf("%d, ", vect[i]);
  }
  return 0;
}
