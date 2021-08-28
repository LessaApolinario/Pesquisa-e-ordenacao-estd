#include <stdio.h>
#include "./include/pesquisa.h"
#define SIZE 2

int main() {
  char nome[SIZE][100], CPF[SIZE][14];
  int idade[SIZE];
  float salario[SIZE];
  int i, op;

  do {
    menu();
    scanf("%d", &op);

    switch (op) {
    case 1:
      cadastrarFuncionario(nome, CPF, idade, salario);
      break;

    case 2:
      // consultarFuncionariosPorNome();
      break;

    case 3:
      // consultarFuncionariosPorCPF();
      break;

    case 4:
      // atualizarFuncionario();
      break;

    case 5:
      printf("Fim das operações\n");
      break;

    default:
      printf("Opção inválida\n");
      break;
    }
  } while (op != 5);
  // cadastrarFuncionario(nome, CPF, idade, salario);

  // printf("\n\n");

  // consultarFuncionarios(nome, CPF, idade, salario);

  return 0;
}
