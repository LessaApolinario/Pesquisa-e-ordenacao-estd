struct funcionario {
  char nome[50];
  char CPF[14];
  int idade;
  float salario;
};
typedef struct funcionario Func;

int bubble(char vetNome[][100], int tam);

void menu();

void cadastrarFuncionario(char vetNome[][100], char vetCPF[][50], int vetIdade[], float vetSalario[]);

void consultarFuncionarios(char vetNome[][100], char vetCPF[][50], int vetIdade[], float vetSalario[]);

void consultarFuncionariosPorNome(char vetNome[][100]);

int consultarFuncionariosPorCPFSequencial(char vetCPF[][50], int tam, char CPF[]);

int consultarFuncionariosPorCPFBinaria(char vetCPF[][50], int tam, char CPF[]);

void atualizarFuncionario(char vetNome[][100], char vetCPF[][50], int vetIdade[], float vetSalario[]);

int pesquisaSalario(float vet[], int tam, float x);

int pesquisaIdade(int vet[], int tam, int x);
