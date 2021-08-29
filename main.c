#include <stdio.h>
#include "./include/pesquisa.h"
#define SIZE 1

int main() {
  char nome[SIZE][100], CPF[SIZE][50]; // matrizes de strings
  int idade[SIZE]; // vetor de idades
  float salario[SIZE]; // vetor de salários
  int i, op;
  int opcao;
  char cpfCliente[50]; // cpf a ser pesquisado

  do {
    menu();
    scanf("%d", &op);

    switch (op) {
    case 1:
      cadastrarFuncionario(nome, CPF, idade, salario);
      break;

    case 2:
      bubble(nome, SIZE);
      consultarFuncionariosPorNome(nome);
      break;

    case 3:
      printf("Pesquisa binária (0) ou sequencial (1)? ");
      scanf("%d", &opcao);

      if (opcao == 0) {
        printf("Informe o CPF do cliente: ");
        scanf("%s", cpfCliente);

        consultarFuncionariosPorCPFBinaria(CPF, SIZE, cpfCliente);
      } else if (opcao == 1) {
        printf("Informe o CPF do cliente: ");
        scanf("%s", cpfCliente);

        consultarFuncionariosPorCPFSequencial(CPF, SIZE, cpfCliente);
      }
      break;

    case 4:
      atualizarFuncionario(nome, CPF, idade, salario);
      break;

    case 5:
      consultarFuncionarios(nome, CPF, idade, salario);
      break;

    case 6:
      printf("Fim das operações\n");
      break;

    default:
      printf("Opção inválida\n");
      break;
    }
  } while (op != 6);

  return 0;
}
