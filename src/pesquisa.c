#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/pesquisa.h"
#define SIZE 1

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

int pesquisa(int vet[], int tam, int x) {
  int i;
  int achou = 0; // false

  printf("Digite o valor a procurar: ");
  scanf("%d", &x);

  for (i = 0; i < tam; i++) {
    if (vet[i] == x) {
      achou = 1;

      break;
    }
  }

  if (achou == 1) {
    printf("%d achado na posição %d\n", x, i);
  } else {
    printf("%d não encontrado\n", x);
  }
}

void menu() {
  printf("\n==========Empresa X==========\n");
  printf("| 1 - Cadastrar funcionário\n");
  printf("| 2 - Exibir funcionários por nome\n");
  printf("| 3 - Consultar funcionário por CPF\n");
  printf("| 4 - Atualizar dados de um funcionário\n");
  printf("| 5 - Sair\n");
}

void cadastrarFuncionario(char vetNome[][100], char vetCPF[][14], int vetIdade[], float vetSalario[]) {
  int i;
  Func *f = (Func *)malloc(sizeof(Func));

  for (i = 0; i < SIZE; i++) {
    printf("Informe o nome do funcionário: ");
    scanf(" %[^\t\n]s", f->nome);
    strcpy(vetNome[i], f->nome);
    setbuf(stdin, NULL);

    printf("Informe o CPF do funcionário: ");
    scanf(" %[^\t\n]s", f->CPF);
    strcpy(vetCPF[i], f->CPF);
    setbuf(stdin, NULL);

    printf("Informe a idade do funcionário: ");
    scanf("%d", &f->idade);

    vetIdade[i] = f->idade;

    printf("Informe o salário do funcionário: ");
    scanf("%f", &f->salario);

    vetSalario[i] = f->salario;
  }
}

void consultarFuncionarios(char vetNome[][100], char vetCPF[][14], int vetIdade[], float vetSalario[]) {
  int i;

  for (i = 0; i < SIZE; i++) {
    printf("--------------------\n");
    printf("Nome: %s\n", vetNome[i]);
    printf("CPF: %s\n", vetCPF[i]);
    printf("Idade = %d\n", vetIdade[i]);
    printf("Salário = %.2f\n", vetSalario[i]);
    printf("--------------------\n");
  }
}

void consultarFuncionariosPorCPFSequencial(char vetCPF[][14], int tam, char CPF[14]) {
  int i;

  for (i = 0; i < tam; i++) {
    if (strcmp(vetCPF[i], CPF) == 0) {
      printf("O funcionário existe com o CPF %s existe.\n", vetCPF[i]);
      break;
    }
  }
}
