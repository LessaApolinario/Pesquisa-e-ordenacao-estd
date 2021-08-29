#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/pesquisa.h"
#define SIZE 1

int bubble(char vetNome[][100], int tam) {
  int i;
  int j;
  char aux[100];

  for (j = 0; j < tam - 1; j++) {
    for (i = j + 1; i < tam; i++) {
      if (strcmp(vetNome[j], vetNome[i]) > 0) {
        strcpy(aux, vetNome[j]);
        strcpy(vetNome[j], vetNome[i]);
        strcpy(vetNome[i], aux);
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

void quick(char vetNome[][100], int tam) {
  int a = 1, b = tam - 1;
  char pivo[100];

  strcpy(pivo, vetNome[0]);

  if (tam <= 1)
    return;

  while (a <= b) {
    while (strcmp(pivo, vetNome[a]) == -1 && a < tam) {
      a++;
    }
    while (strcmp(vetNome[b], pivo) == 1 && b > 0) {
      b--;
    }
    if (a < b) {
      char aux[100];

      strcpy(aux, vetNome[b]);
      strcpy(vetNome[b], vetNome[a]);
      strcpy(vetNome[a], aux);

      a++;
      b--;
    }
  }

  strcpy(vetNome[0], vetNome[b]);
  strcpy(vetNome[b], pivo);

  quick(vetNome, b);
  quick(&vetNome[a], tam - a);
}

int pesquisa(int vet[], int tam, int x) {
  int i;
  int achou = 0; // false

  for (i = 0; i < tam; i++) {
    if (vet[i] == x) {
      achou = 1;

      break;
    }
  }

  if (achou == 1) {
    printf("%d achado na posição %d\n", x, i);

    return 0;
  } else {
    printf("%d não encontrado\n", x);

    return 1;
  }
}

void menu() {
  printf("\n==========Empresa X==========\n");
  printf("| 1 - Cadastrar funcionário\n");
  printf("| 2 - Exibir funcionários por nome\n");
  printf("| 3 - Consultar funcionário por CPF\n");
  printf("| 4 - Atualizar dados de um funcionário\n");
  printf("| 5 - Consultar funcionários\n");
  printf("| 6 - Sair\n");
}

void cadastrarFuncionario(char vetNome[][100], char vetCPF[][50], int vetIdade[], float vetSalario[]) {
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

void consultarFuncionariosPorNome(char vetNome[][100]) {
  int i;

  for (i = 0; i < SIZE; i++) {
    printf("\nNome: %s\n", vetNome[i]);
  }
}

void consultarFuncionarios(char vetNome[][100], char vetCPF[][50], int vetIdade[], float vetSalario[]) {
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

int consultarFuncionariosPorCPFSequencial(char vetCPF[][50], int tam, char CPF[14]) {
  int i;

  for (i = 0; i < tam; i++) {
    if (strcmp(vetCPF[i], CPF) == 0) {
      printf("\nO funcionário existe com o CPF %s existe na posição %d.\n", vetCPF[i], i);
      break;
    }
  }

  return -1;
}

int consultarFuncionariosPorCPFBinaria(char vetCPF[][50], int tam, char CPF[]) {
  int inicio, fim, meio;

  inicio = 0;
  fim = tam - 1;

  do {
    meio = (inicio + fim) / 2;

    if (strcmp(CPF, vetCPF[meio]) == 0) {
      // Se a string CPF for igual a string vetCPF[i]
      printf("\nO funcionário existe com o CPF %s na posição %d.\n", vetCPF[meio], meio);
      return meio;
    } else if (strcmp(CPF, vetCPF[meio]) > 0) {
      // se a string CPF for maior
      inicio = meio + 1;
    } else {
      // se a string CPF for menor, ou seja, o retorno de strcmp é -1
      fim = meio - 1;
    }
  } while (inicio <= fim);

  return -1;
}

void atualizarFuncionario(char vetNome[][100], char vetCPF[][50], int vetIdade[], float vetSalario[]) {
  char nome[100], CPF[14];
  int idade;
  float salario;
  int i;

  for (i = 0; i < SIZE; i++) {
    printf("Informe o nome do funcionário a atualizar: ");
    scanf(" %[^\t\n]s", nome);
    setbuf(stdin, NULL);

    printf("Informe o CPF do funcionário: ");
    scanf(" %[^\t\n]s", CPF);
    setbuf(stdin, NULL);

    if (strcmp(vetNome[i], nome) == 0 && strcmp(vetCPF[i], CPF) == 0) {
      if (pesquisaIdade(vetIdade, SIZE, vetIdade[i]) == 1) {
        printf("Informe a nova idade do funcionário: ");
        scanf("%d", &idade);

        vetIdade[i] = idade;
      }

      if (pesquisaSalario(vetSalario, SIZE, vetSalario[i]) == 1) {
        printf("Informe o novo salário do funcionário: ");
        scanf("%f", &salario);

        vetSalario[i] = salario;

        printf("\nFuncionário atualizado com sucesso!\n");
      }
    } else {
      printf("\nDados inválidos para o funcionário informado!\n");
    }
  }
}

int pesquisaSalario(float vet[], int tam, float x) {
  int i, achou = 0;

  for (i = 0; i < tam; i++) {
    if (vet[i] == x) {
      achou = 1;

      break;
    }
  }

  if (achou == 1) {
    return 1;
  } else {
    return 0;
  }
}

int pesquisaIdade(int vet[], int tam, int x) {
  int i, achou = 0;

  for (i = 0; i < tam; i++) {
    if (vet[i] == x) {
      achou = 1;

      break;
    }
  }

  if (achou == 1) {
    return 1;
  } else {
    return 0;
  }
}
