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

int pesquisa(int vet[], int tam, int x);

void menu();

void cadastrarFuncionario(char vetNome[][100], char vetCPF[][14], int vetIdade[], float vetSalario[]);

void consultarFuncionarios(char vetNome[][100], char vetCPF[][14], int vetIdade[], float vetSalario[]);
