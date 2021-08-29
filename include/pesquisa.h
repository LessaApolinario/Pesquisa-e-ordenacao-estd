struct funcionario {
  char nome[50];
  char CPF[14];
  int idade;
  float salario;
};
typedef struct funcionario Func;

int bubble(char vetNome[][100], int tam);

int busca(int vet[], int tam, int x);

void quick(char vetNome[][100], int tam);

int pesquisa(int vet[], int tam, int x);

void menu();

void cadastrarFuncionario(char vetNome[][100], char vetCPF[][14], int vetIdade[], float vetSalario[]);

void consultarFuncionarios(char vetNome[][100], char vetCPF[][14], int vetIdade[], float vetSalario[]);

void consultarFuncionariosPorNome(char vetNome[][100]);

int consultarFuncionariosPorCPFSequencial(char vetCPF[][14], int tam, char CPF[]);

int consultarFuncionariosPorCPFBinaria(char vetCPF[][14], int tam, char CPF[]);

void atualizarFuncionario(char vetNome[][100], char vetCPF[][14], int vetIdade[], float vetSalario[]);

int pesquisaSalario(float vet[], int tam, float x);

int pesquisaIdade(int vet[], int tam, int x);
