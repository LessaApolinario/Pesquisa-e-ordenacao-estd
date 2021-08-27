#include <stdio.h>
#include "./include/pesquisa.h"
#define SIZE 2

int main() {
  char nome[50], CPF[14];
  int idade[SIZE];
  float salario[SIZE];
  int i, valor;

  cadastrarFuncionario(nome, CPF, idade, salario);

  printf("\n\n");

  consultarFuncionarios(nome, CPF, idade, salario);

  return 0;
}
