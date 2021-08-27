struct funcionario {
  char nome[50];
  char CPF[14];
  int idade;
  float salario;
};
typedef struct funcionario Func;

int bubble(int vet[], int size);

int busca(int vet[], int tam, int x);

void quick(int v[], int tam);

void cadastrarFuncionario(char vetNome[], char vetCPF[], int vetIdade[], float vetSalario[]);

void consultarFuncionarios(char vetNome[], char vetCPF[], int vetIdade[], float vetSalario[]);

void printStringArray(char vet[]);
