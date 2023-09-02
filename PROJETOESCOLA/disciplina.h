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
    

/*Criando a struct aluno*/
typedef struct disciplina{
        int codigo;
        int semestre;
        char nome[50];
}Disc;
 
Disc disc; /*Criando a variável professor que será do tipo struct*/
Disc Disciplina[TAM]; // vetor para armazenar a lista de professor
/**int qtd=0; // variavel para controlar a quantidade de professor**/



int inserirDisciplina(Disc Disciplina[], Pro Prof[], int qtdd);
void listarDisciplina(Disc Disciplina[], Pro Prof[], int qtdd);


          
  



int inserirDisciplina(Disc Disciplina[],Pro Prof[], int qtdd){
    printf("\n CADASTRO DE DISCIPLINA \n");
    if (qtdd == TAM){
        printf("\n CADASTRO CHEIO\n");
        return cad_cheio;
    }else{
    printf("\n INFORME O CODIGO DE MATRICULA:");
    scanf("%d", &Disciplina[qtdd].codigo);
    getchar();    
        if (Disciplina[qtdd].codigo <= 0) {
        return erro_matricula;
        }
    printf("\n INFORME O NOME DA DISCIPLINA:");
    scanf("%s", &Disciplina[qtdd].nome); 
    getchar(); 
    printf("\n INFORME O NUMERO DE MATRICULA DO PROFESSOR:");
    scanf("%d", &Prof[qtdd].matricula);
    getchar();    
        if (Prof[qtdd].matricula <= 0) {
        return erro_matricula;
        }
        printf("\n INFORME O SEMESTRE: ");
        scanf("%d", &Disciplina[qtdd].semestre);
        if (Disciplina[qtdd].semestre == Disciplina[qtdd].semestre){
          printf("Disciplina já existe");
          return Disciplina[qtdd].semestre;
        }
        printf("\n"); 
    
        return CADASTRO_REALIZADO;
  }
    
}
void listarDisciplina(Disc Disciplina[],Pro Prof[], int qtdd){
    printf("\n  LISTA DE DISCIPLINA \n");
    int i;
        for (i=0; i<qtdd; i++){
        if (Disciplina[qtdd].codigo > 0){
        
        printf("\n DISCIPLINA: %s", Disciplina[i].nome);
        printf("\n-------------------------------------------------\n");
            
        }else {
            printf("\nLISTA VAZIA\n");
        } 
        }

}
