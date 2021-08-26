#include <stdio.h>
#include "./include/pesquisa.h"
#define SIZE 4

int main() {
  int v[SIZE];
  int i, valor;

  printf("Preencha o vetor: \n");
  for (i = 0; i < SIZE; i++) {
    scanf("%d", &v[i]);
  }

  bubble(v, SIZE);

  i = 0;

  printf("Novo array: \n");
  for (i = 0; i < SIZE; i++) {
    printf("%d ", v[i]);
  }

  printf("\n");

  return 0;
}
