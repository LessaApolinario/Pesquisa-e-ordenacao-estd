#include <stdio.h>
#include "./include/pesquisa.h"
#define SIZE 2

int main() {
  char nome[SIZE][100], CPF[SIZE][14];
  int idade[SIZE];
  float salario[SIZE];
  int i, valor;

  cadastrarFuncionario(nome, CPF, idade, salario);

  printf("\n\n");

  consultarFuncionarios(nome, CPF, idade, salario);

  return 0;
}
