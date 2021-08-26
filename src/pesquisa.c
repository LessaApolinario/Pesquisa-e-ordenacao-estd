#include <stdio.h>
#include "../include/pesquisa.h"

struct funcionario {
  char cpf[14];
  int idade;
  float salario;
};

int bubble(int vet[], int size) {
  int i;
  int j;
  int aux;

  for (j = 1; j < size; j++) {
    for (i = 0; i < size; i++) {
      if (vet[i] > vet[i + 1]) {
        aux = vet[i];
        vet[i] = vet[i + 1];
        vet[i + 1] = aux;
      }
    }
  }

  return 0;
}

int busca(int vet[], int tam, int x) {
  int inicio, fim, meio;

  inicio = 0;
  fim = tam - 1;

  do {
    meio = (inicio + fim) / 2;

    if (x == vet[meio])
      return meio;
    else if (x > vet[meio])
      inicio = meio + 1;
    else
      fim = meio - 1;
  } while (inicio <= fim);

  return -1;
}

void quick(int v[], int tam) {
  int a = 1, b = tam - 1, pivo;
  pivo = v[0];

  if (tam <= 1)
    return;

  while (a <= b) {
    printf("\n A: %d, B: %d", a, b);
    while (v[a] < pivo && a < tam) {
      a++;
    }
    while (v[b] > pivo && b > 0) {
      b--;
    }
    if (a < b) {
      int aux = v[b];
      v[b] = v[a];
      v[a] = aux;
      a++;
      b--;
    }
  }

  v[0] = v[b];
  v[b] = pivo;

  quick(v, b);
  quick(&v[a], tam - a);
}
