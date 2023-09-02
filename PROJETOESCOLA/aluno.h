#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define TAM 5
#define CADASTRO_CHEIO -2
#define MAT_INVALIDA -3
#define SEXO_INVALIDO -4
#define CADASTRO_REALIZADO -5
#define SUCESSO_ATUALIZACAO -6
#define LISTA_VAZIA -7
#define EXCLUIDO -8
#define erro -9

typedef struct data2 {
  int dia;
  int mes;
  int ano;
} dt2;

/*Criando a struct aluno*/
typedef struct aluno {
  int matricula;
  char cpf[15];
  char nome[50];
  char sexo; // M - Masculino, F - Feminino
  dt2 Dt;
} Al;

Al alun;      /*Criando a variável aluno que será do tipo struct*/
Al Alu[TAM];  // vetor para armazenar a lista de alunos
int qtdA = 0; // variavel para controlar a quantidade de alunos

int inserirAluno(Al Alu[], int qtdA);
void listarAluno(Al Alu[], int qtdA);
void listarAlunoNom(Al Alu[], int qtdA);
void listarAlunoSexo(Al Alu[], int qtdA);
int alterarAluno(Al Alu[], int qtdA);
int excluirAluno(Al Alu[], int qtdA);
void listarAlunoDat(Al Alu[], int qtdA);
void ordenarPorDataAl(Al Alu[], int qtdA);

int inserirAluno(Al Alu[], int qtdA) {
  printf("\n CADASTRO DE ALUNO \n");
  if (qtdA == TAM) {
    printf("\n CADASTRO CHEIO\n");
    return CADASTRO_CHEIO;
  } else {
    printf("\n INFORME O NUMERO DE MATRICULA:");
    scanf("%d", &Alu[qtdA].matricula);
    getchar();
    if (Alu[qtdA].matricula <= 0) {
      return MAT_INVALIDA;
    }
    printf("\n INFORME O NOME:");
    fgets(Alu[qtdA].nome, 50, stdin);
    size_t ln = strlen(Alu[qtdA].nome) - 1; // size_t = unsigned integer type
    if (Alu[qtdA].nome[ln] == '\n')
      Alu[qtdA].nome[ln] = '\0';

    printf("\n INFORME O SEXO:");
    scanf("%c", &Alu[qtdA].sexo);
    Alu[qtdA].sexo = toupper(Alu[qtdA].sexo);
    if (Alu[qtdA].sexo != 'M' && Alu[qtdA].sexo != 'F') {
      return SEXO_INVALIDO;
    }

    printf("\n INFORME A Dia: ");
    scanf("%d", &Alu[qtdA].Dt.dia);

    printf("\n INFORME A MES:");
    scanf("%d", &Alu[qtdA].Dt.mes);

    printf("\n INFORME A ANO:");
    scanf("%d", &Alu[qtdA].Dt.ano);
    getchar();

    printf("\n INFORME O CPF DO ALUNO COM '.' E '-' :");
    fgets(Alu[qtdA].cpf, 15, stdin);
    ln = strlen(Alu[qtdA].cpf) - 1;
    if (Alu[qtdA].cpf[ln] == '\n')
      Alu[qtdA].cpf[ln] = '\0';

    printf("\n");

    return qtdA;
  }
}
void listarAluno(Al Alu[], int qtdA) {
  printf("\n Listar de Aluno \n");
  int i;
  for (i = 0; i < qtdA; i++) {
    if (Alu[i].matricula > 0) {

      printf("\n MATRICULA: %d", Alu[i].matricula);
      printf("\n ALUNO: %s ", Alu[i].nome);
      printf("\n CPF: %s", Alu[i].cpf);
      printf("\n SEXO: %c", Alu[i].sexo);
      printf("\n DATA DE NASCIMENTO: %d/%d/%d", Alu[i].Dt.dia, Alu[i].Dt.mes,
             Alu[i].Dt.ano);
      printf("-------------------------------------------------");

    } else {
      printf("\nLISTA VAZIA\n");
    }
  }
}
void listarAlunoSexo(Al Alu[], int qtdA) {
  printf("\n LISTA DE ALUNOS POR SEXO \n");
  int i;
  if (qtdA > 0) {
    for (i = 0; i < qtdA; i++) {
      printf("\n LISTA POR SEXO FEMININO \n ");
      if (Alu[i].sexo == 'F' || Alu[i].sexo == 'f') {
        printf("\n MATRICULA: %d", Alu[i].matricula);
        printf("\n NOME: %s ", Alu[i].nome);
        printf("\n-----------------------------------\n");
      } else {
        printf("\n LISTA POR SEXO MASCULINO \n ");
        if (Alu[i].sexo == 'M' || Alu[i].sexo == 'm') {
          printf("\n MATRICULA: %d\n", Alu[i].matricula);
          printf("\n ALUNO: %s \n", Alu[i].nome);
          printf("\n-----------------------------------\n");
        } else {
          printf("\n LISTA VAZIA \n");
        }
      }
    }
  }
}
int alterarAluno(Al Alu[], int qtdA) {
  printf("\n ALTERAR ALUNO \n");
  int i, mat;
  for (i = 0; i < qtdA; i++) {
    printf("\n MATRICULA: ");
    scanf("%d", &mat);
    getchar();
    if (mat != Alu[i].matricula) {
      printf("MATRICULA NÃO EXISTE");
    } else {
      printf("\n MATRICULA");
      scanf("%d", &Alu[i].matricula);
      getchar();

      printf("NOME: ");
      fgets(Alu[i].nome, 50, stdin);

      printf("SEXO: ");
      scanf("%c", &Alu[i].sexo);
      getchar();
      Alu[i].sexo = toupper(Alu[i].sexo);
      if (Alu[i].sexo != 'M' && Alu[i].sexo != 'F') {
        printf("ERRO: SEXO DEVE SER 'M' OU 'F' \n ");
        return SEXO_INVALIDO;
      }
      printf("DIA: ");
      scanf("%d", &Alu[i].Dt.dia);

      printf("MÊS: ");
      scanf("%d", &Alu[i].Dt.mes);

      printf("ANO: ");
      scanf("%d", &Alu[i].Dt.ano);
      getchar();

      printf("CPF: ");
      fgets(Alu[i].cpf, 15, stdin);
      size_t ln = strlen(Alu[i].cpf) - 1;
      if (Alu[i].cpf[ln] == '\n')
        Alu[i].cpf[ln] = '\0';

      printf("\n");
      printf("\n ATUALIZADO COM SUCESSO \n");
      return SUCESSO_ATUALIZACAO;
    }
  }
  printf("LISTA VAZIA \n");
  return LISTA_VAZIA;
}
int excluirAluno(Al Alu[], int qtdA) {
  printf("\n EXCLUIR ALUNO \n");
  int i, mat;
  for (i = 0; i < qtdA; i++) {
    printf("\n MATRICULA:");
    scanf("%d", &mat);
    getchar();
    if (mat != Alu[i].matricula) {
      printf("MATRICULA NÃO EXISTE");
    } else {
      for (i = 0; i < qtdA; i++) {
        if (mat == Alu[i].matricula) {
          for (int j = i; j < qtdA - 1; j++) {
            Alu[j] = Alu[j + 1];
          }
          printf("ALUNO EXCLUIDO COM SUCESSO \n");
          return EXCLUIDO;
        }
      }
    }
    return erro;
  }
}

void listarAlunoDat(Al Alu[], int qtdA) {
  int i, mes;
  printf("\n LISTAR POR DATA DE NASCIMENTO\n");
  for (i = 0; i < qtdA; i++) {
    if (mes = Alu[qtdA].Dt.mes) {
      printf("\n Nome: %s\n ", Alu[qtdA].nome);
      printf("\n Mes: %d\n ", Alu[qtdA].Dt.mes);
    }
  }
}

void ordenarPorDataAl(Al Alu[], int qtdA) {
  for (int i = 0; i < qtdA - 1; i++) {
    for (int j = 0; j < qtdA - i - 1; j++) {
      if (Alu[j].Dt.ano > Alu[j + 1].Dt.ano ||
          (Alu[j].Dt.ano == Alu[j + 1].Dt.ano &&
           Alu[j].Dt.mes > Alu[j + 1].Dt.mes) ||
          (Alu[j].Dt.ano == Alu[j + 1].Dt.ano &&
           Alu[j].Dt.mes == Alu[j + 1].Dt.mes &&
           Alu[j].Dt.dia > Alu[j + 1].Dt.dia)) {
        // Trocar os elementos Alu[j] e Alu[j + 1]
        Al temp = Alu[j];
        Alu[j] = Alu[j + 1];
        Alu[j + 1] = temp;
      }
    }
  }
  return listarAluno(Alu, qtdA);
}

void listarAlunoNom(Al Alu[], int qtdA) {
  printf("\n     LISTA DE ALUNOS  por nome  \n");
  int i, x;
  char aux[80];
  if (qtdA > 0) {
    for (i = 0; i < qtdA - 1; i++) {
      for (x = i + 1; x < qtdA; x++) {
        if (strcmp(Alu[i].nome, Alu[x].nome) > 0) {
          strcpy(aux, Alu[i].nome);
          strcpy(Alu[i].nome, Alu[x].nome);
          strcpy(Alu[x].nome, aux);
        }
      }
    }
    for (i = 0; i < qtdA; i++) {
      printf("%s\n", Alu[i].nome);
    }
  } else {
    printf("LISTA VAZIA");
  }
}
