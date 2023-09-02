#include <stdio.h>
#include <string.h>
#include <ctype.h>


//#define TAM 3
#define cad_cheio -2
#define erro_matricula -3
#define ERRO_CADASTRO_SEXO -4
#define CADASTRO_REALIZADO -5
#define SUCESSO_ATUALIZACAO -6
#define LISTA_VAZIA -7
#define EXCLUIDO -8
#define erro -9

typedef struct data{
        int dia;
        int mes;
        int ano;
} dt;
    

/*Criando a struct aluno*/
typedef struct professor{
        int matricula;
        char cpf[15];
        char nome[50];
        char sexo; //M - Masculino, F - Feminino
        dt Dt;
}Pro;
 
Pro pro; /*Criando a variável professor que será do tipo struct*/
Pro Prof[TAM]; // vetor para armazenar a lista de professor
int qtd=0; // variavel para controlar a quantidade de professor




int inserirProfessor(Pro Prof[], int qtdP);
void listarProfessor(Pro Prof[], int qtdP);
void listarProfessorNom(Pro Prof[], int qtdP);
void listarProfessorSexo(Pro Prof[], int qtdP);
int alterarProfessor(Pro Prof[], int qtdP);
int excluirProfessor(Pro Prof[], int qtdP);
void listarProfessorDat(Pro Prof[], int qtdP);
void ordenarPorData(Pro Prof[], int qtdP);



int inserirProfessor(Pro Prof[], int qtdP){
    printf("\n CADASTRO DE PROFESSOR \n");
    if (qtdP == TAM){
        printf("\n CADASTRO CHEIO\n");
        return cad_cheio;
    }else{
    printf("\n INFORME O NUMERO DE MATRICULA:");
    scanf("%d", &Prof[qtdP].matricula);
    getchar();    
        if (Prof[qtdP].matricula <= 0) {
        return erro_matricula;
        }
        printf("\n INFORME O NOME:");
        fgets(Prof[qtdP].nome, 50 , stdin);
        size_t ln = strlen(Prof[qtdP].nome) - 1; //size_t = unsigned integer type
        if (Prof[qtdP].nome[ln] == '\n')
        Prof[qtdP].nome[ln] = '\0';
    
        printf("\n INFORME O SEXO:");
        scanf("%c", &Prof[qtdP].sexo);
        Prof[qtdP].sexo = toupper (Prof[qtdP].sexo);        
            if (Prof[qtdP].sexo != 'M' &&  Prof[qtdP].sexo != 'F'){
            return ERRO_CADASTRO_SEXO;
            }
        printf("\n DIGITE O DIA: ");
        scanf("%d", &Prof[qtdP].Dt.dia);
                
        printf("\n DIGITE O MES: ");
        scanf("%d", &Prof[qtdP].Dt.mes);
                
        printf("\n DIGITE O ANO: ");
        scanf("%d", &Prof[qtdP].Dt.ano);
        getchar();
       
        printf("\n INFORME O CPF: ");
        fgets(Prof[qtdP].cpf, 15, stdin);
        ln = strlen(Prof[qtdP].cpf)-1;
        if (Prof[qtdP].cpf[ln] == '\n')
        Prof[qtdP].cpf[ln] = '\0';
    
        printf("\n"); 
    
        return CADASTRO_REALIZADO;
  }
    
}
void listarProfessor(Pro Prof[], int qtdP){
    printf("\n  LISTA DE PROFESSORES \n");
    int i;
        for (i=0; i<qtdP; i++){
        if (Prof[i].matricula > 0){
        printf("\n MATRICULA: %d", Prof[i].matricula);
        printf("\n ALUNO: %s ", Prof[i].nome);
        printf("\n CPF: %s", Prof[i].cpf);
        printf("\n SEXO: %c", Prof[i].sexo);
        printf("\n DATA DE NASCIMENTO %d/%d/%d\n", Prof[i].Dt.dia, Prof[i].Dt.mes, Prof[i].Dt.ano);
        printf("\n-------------------------------------------------\n");
            
        }else {
            printf("\nLISTA VAZIA\n");
        } 
        }

}
void listarProfessorSexo(Pro Prof[], int qtdP){
   printf("\n LISTA DE PROFESSOR POR SEXO \n");
   int i;
    if (qtdP > 0){
        for (i=0; i<qtdP; i++){
            printf("\n LISTA POR SEXO FEMININO \n ");
            if(Prof[i].sexo == 'F' || Prof[i].sexo == 'f'){
            printf("\n MATRICULA: %d", Prof[i].matricula);
            printf("\n PROFESSOR:  %s", Prof[i].nome);
            printf("\n-----------------------------------\n");
            } else{
                          printf("\n LISTA VAZIA \n");
                  } 
            printf("\n LISTA POR SEXO MASCULINO \n "); 
            if(Prof[i].sexo == 'M' || Prof[i].sexo == 'm'){
            printf("\n MATRICULA: %d", Prof[i].matricula);
            printf("\n PROFESSOR: %s", Prof[i].nome);
            printf("\n-----------------------------------\n");
            } else{
                          printf("\n LISTA VAZIA \n");
                  }
               
            }
        }  
    }       
    
    
    
    

int alterarProfessor(Pro Prof[], int qtdP){
  printf("\n ALTERAR PROFESSOR \n");
    int i, mat;
        for (i=0; i<qtdP; i++){
        printf("\n Informe o numero de matricula \n");
        scanf("%d", &mat);
        getchar();
        if (mat != Prof[i].matricula){
        printf("MATRICULA NÃO EXISTE");
        }else {
        printf("\n Informe o numero de matricula \n");
        scanf("%d", &Prof[i].matricula);
        getchar();
        
        printf("Digite o nome: ");
        fgets(Prof[i].nome, 50, stdin);
        
        printf("Digite o sexo: ");
        scanf("%c", &Prof[i].sexo);
        getchar();
        Prof[i].sexo = toupper (Prof[i].sexo);
            if (Prof[i].sexo != 'M' && Prof[i].sexo != 'F'){
                printf("ERRO: SEXO DEVE SER 'M' OU 'F' \n " );
                return ERRO_CADASTRO_SEXO;
            }else{
                printf("Digite o dia de nascimento: ");
                scanf("%d", &Prof[i].Dt.dia);
                
                printf("Digite o dia de nascimento: ");
                scanf("%d", &Prof[i].Dt.mes);
                
                printf("Digite o dia de nascimento: ");
                scanf("%d", &Prof[i].Dt.ano);
                getchar();
                
                printf("Digite o CPF: ");
                fgets(Prof[i].cpf, 15, stdin);
                size_t ln= strlen(Prof[i].cpf) -1;
                    if(Prof[i].cpf[ln]== '\n')
                        Prof[i].cpf[ln]= '\0';
                        
                        printf("\n");
                        printf("Atualização com sucesso\n");
                        return SUCESSO_ATUALIZACAO;
                
                
            }
        }
        }
    printf("LISTA VAZIA \n");
    return LISTA_VAZIA;
      
} 
int excluirProfessor(Pro Prof[], int qtdP){
 printf("\n EXCLUIR PROFESSOR \n");
 int i, mat;
 for (i=0; i<qtdP; i++){
        printf("\n Informe o numero de matricula \n");
        scanf("%d", &mat);
        getchar();
        if (mat != Prof[i].matricula){
        printf("MATRICULA NÃO EXISTE");
        }else {
            for(i=0; i<qtdP; i++){
                if(mat==Prof[i].matricula){
                    for(int j=i; j<qtdP-1; j++){
                        Prof[j] = Prof[j+1];
                    }
                    printf("PROFESSORES EXCLUIDO COM SUCESSO \n");
                    return EXCLUIDO;
                }
            }
             
        } 
        return erro;
    }

}


void listarProfessorDat(Pro Prof[], int qtdP){
    int i, mes;
    printf("\nListar Por Data de Nascimento\n");
    for (i=0; i<qtdP; i++){
    if (mes = Prof[qtdP].Dt.mes){
        printf("\n Nome: %s\n ", Prof[qtdP].nome);
        printf("\n Mes: %d\n ", Prof[qtdP].Dt.mes);
    }
    }
    
}

void ordenarPorData(Pro Prof[], int qtdP) {
    for (int i = 0; i < qtdP - 1; i++) {
        for (int j = 0; j < qtdP - i - 1; j++) {
            if (Prof[j].Dt.ano > Prof[j + 1].Dt.ano ||
                (Prof[j].Dt.ano == Prof[j + 1].Dt.ano && Prof[j].Dt.mes > Prof[j + 1].Dt.mes) ||
                (Prof[j].Dt.ano == Prof[j + 1].Dt.ano && Prof[j].Dt.mes == Prof[j + 1].Dt.mes && Prof[j].Dt.dia > Prof[j + 1].Dt.dia)) {
                // Trocar os elementos Prof[j] e Prof[j + 1]
                Pro temp = Prof[j];
                Prof[j] = Prof[j + 1];
                Prof[j + 1] = temp;
            }
        }
    }
 return listarProfessor(Prof,qtdP);
  
}


void listarProfessorNom(Pro Prof[], int qtd) {
    printf("\n     LISTA DE PROFESSOR  por nome  \n");
    int i, x;
    char aux[80]; 
    if (qtd > 0) {
        for (i = 0; i < qtd - 1; i++) {
            for (x = i + 1; x < qtd; x++) {
                if (strcmp(Prof[i].nome, Prof[x].nome) > 0) {
                    strcpy(aux, Prof[i].nome);
                    strcpy(Prof[i].nome, Prof[x].nome);
                    strcpy(Prof[x].nome, aux);
                }
            }
        }
        for (i = 0; i < qtd; i++) {
            printf("%s\n", Prof[i].nome);
        }
    } else {
        printf("Lista Vazia");
    }
}

