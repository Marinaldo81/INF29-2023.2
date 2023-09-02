#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM 3
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
typedef struct aluno{
        int matricula;
        char cpf[15];
        char nome[50];
        char sexo; //M - Masculino, F - Feminino
        dt Dt;
}Al;
 
Al alun; /*Criando a variável aluno que será do tipo struct*/
Al Alu[TAM]; // vetor para armazenar a lista de alunos
int qtd=0; // variavel para controlar a quantidade de alunos



int MENU();
int inserirAluno(Al Alu[], int qtd);
void listarAluno(Al Alu[], int qtd);
void listarAlunoNom(Al Alu[], int qtd);
void listarAlunoSexo(Al Alu[], int qtd);
int alterarAluno(Al Alu[], int qtd);
int excluirAluno(Al Alu[], int qtd);
void listarAlunoDat(Al Alu[], int qtd);
void ordenarPorData(Al Alu[], int qtd);

int main()
{
  
    int op, retorno;
    int exit = 0;
    
    
    while (!exit){
        
        
        op = MENU();
        
        switch(op){ 
            case 0:{
            printf("Finalizando Programa");
            exit = 1;
            break;
            }
            case 1:{
            retorno= inserirAluno(Alu,qtd);
            printf("Cadastro realizado com sucesso \n");
            qtd++;
            break;
            }
            case 2: {
                listarAluno(Alu,qtd);
                break;
            }    
            case 3:{
                listarAlunoSexo(Alu,qtd);
                break;
            }
            case 4:{
                listarAlunoNom(Alu,qtd);
                break;
            }
            case 5:{
                ordenarPorData(Alu,qtd);
                break;
            }
            case 6:{
                retorno= excluirAluno(Alu,qtd);
                qtd--;
                break;
            }
            case 7:{
               retorno= alterarAluno(Alu,qtd);
                break;
            }
          
            
        
        } 
        
    }       
}   
int MENU(){
        int op;
        printf("\nCADASTRO DE ALUNO \n");
        printf("\n 1- CADASTRO DE ALUNO \n"); 
        printf("\n 2- LISTAR ALUNO \n "); 
        printf("\n 3- LISTAR ALUNO POR SEXO (1- MASC. OU 2- FEM )\n");
        printf("\n 4- LISTAR ALUNOS ORDENADOS POR NOME \n"); 
        printf("\n 5- LISTAR ALUNO ORDENADO POR DATA DE NASCIMENTO \n");
        printf("\n 6- EXCLUIR \n");
        printf("\n 7- ATUALIZAR \n");
        printf("\n 0- SAIR \n");
        printf("\n INFORME UM NUMERO \n");
        scanf("%d", &op);
        
        return op;
}


int inserirAluno(Al Alu[], int qtd){
    printf("\n CADASTRO DE ALUNO \n");
    if (qtd == TAM){
        printf("\n CADASTRO CHEIO\n");
        return cad_cheio;
    }else{
    printf("\n INFORME O NUMERO DE MATRICULA:");
    scanf("%d", &Alu[qtd].matricula);
    getchar();    
        if (Alu[qtd].matricula <= 0) {
        return erro_matricula;
        }
        printf("\n INFORME O NOME:");
        fgets(Alu[qtd].nome, 50 , stdin);
        size_t ln = strlen(Alu[qtd].nome) - 1; //size_t = unsigned integer type
        if (Alu[qtd].nome[ln] == '\n')
        Alu[qtd].nome[ln] = '\0';
    
        printf("\n INFORME O SEXO:");
        scanf("%c", &Alu[qtd].sexo);
        Alu[qtd].sexo = toupper (Alu[qtd].sexo);        
            if (Alu[qtd].sexo != 'M' &&  Alu[qtd].sexo != 'F'){
            return ERRO_CADASTRO_SEXO;
            } 
    
        printf("\n INFORME A Dia: ");
        scanf("%d", &Alu[qtd].Dt.dia);
            
        printf("\n INFORME A MES:");
        scanf("%d", &Alu[qtd].Dt.mes);
            
        printf("\n INFORME A ANO:");
        scanf("%d", &Alu[qtd].Dt.ano);
        getchar();
    
        printf("\n INFORME O CPF:");
        fgets(Alu[qtd].cpf, 15, stdin);
        ln = strlen(Alu[qtd].cpf)-1;
        if (Alu[qtd].cpf[ln] == '\n')
        Alu[qtd].cpf[ln] = '\0';
    
        printf("\n"); 
    
        return CADASTRO_REALIZADO;
    }
    
}
void listarAluno(Al Alu[], int qtd){
    printf("\n Listar de Aluno \n");
    int i;
        if (qtd > 0){
        for (i=0; i<qtd; i++){
        printf("\n MATRICULA: %d", Alu[i].matricula);
        printf("\n ALUNO: %s ", Alu[i].nome);
        printf("\n CPF: %s", Alu[i].cpf);
        printf("\n SEXO: %c", Alu[i].sexo);
        printf("\n DATA DE NASCIMENTO: %d/%d/%d", Alu[i].Dt.dia, Alu[i].Dt.mes, Alu[i].Dt.ano);
        printf("-------------------------------------------------");
            
        }
        } else {
            printf("\nLISTA VAZIA\n");
        }

}
void listarAlunoSexo(Al Alu[], int qtd){
   printf("\n LISTA DE ALUNOS POR SEXO \n");
   int i;
    if (qtd > 0){
        for (i=0; i<qtd; i++){
            printf("\n LISTA POR SEXO FEMININO \n ");
            if(Alu[i].sexo == 'F' || Alu[i].sexo == 'f'){
            printf("\n MATRICULA: %d", Alu[i].matricula);
            printf("\n NOME: %s ", Alu[i].nome);
            printf("\n-----------------------------------\n");
            } else { printf("\n LISTA POR SEXO MASCULINO \n "); 
                    if(Alu[i].sexo == 'M' || Alu[i].sexo == 'm'){
                    printf("\n MATRICULA: %d\n", Alu[i].matricula);
                    printf("\n ALUNO: %s \n", Alu[i].nome);
                     printf("\n-----------------------------------\n");
                  } else{
                          printf("\n LISTA VAZIA \n");
                        }
               
            }
        }  
    }       
    
    
    
    
}
int alterarAluno(Al Alu[], int qtd){
  printf("\n ALTERAR ALUNO \n");
    int i, mat;
        for (i=0; i<qtd; i++){
        printf("\n MATRICULA: ");
        scanf("%d", &mat);
        getchar();
        if (mat != Alu[i].matricula){
        printf("MATRICULA NÃO EXISTE");
        }else {
        printf("\n MATRICULA");
        scanf("%d", &Alu[i].matricula);
        getchar();
        
        printf("NOME: ");
        fgets(Alu[i].nome, 50, stdin);
        
        printf("SEXO: ");
        scanf("%c", &Alu[i].sexo);
        getchar();
        Alu[i].sexo = toupper (Alu[i].sexo);
            if (Alu[i].sexo != 'M' && Alu[i].sexo != 'F'){
                printf("ERRO: SEXO DEVE SER 'M' OU 'F' \n " );
                return ERRO_CADASTRO_SEXO;
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
                size_t ln= strlen(Alu[i].cpf) -1;
                    if(Alu[i].cpf[ln]== '\n')
                        Alu[i].cpf[ln]= '\0';
                        
                        printf("\n");
                        printf("\n ATUALIZADO COM SUCESSO \n");
                        return SUCESSO_ATUALIZACAO;
                
                
            
        }
        }
    printf("LISTA VAZIA \n");
    return LISTA_VAZIA;
      
} 
int excluirAluno(Al Alu[], int qtd){
 printf("\n EXCLUIR ALUNO \n");
 int i, mat;
 for (i=0; i<qtd; i++){
        printf("\n MATRICULA:");
        scanf("%d", &mat);
        getchar();
        if (mat != Alu[i].matricula){
        printf("MATRICULA NÃO EXISTE");
        }else {
            for(i=0; i<qtd; i++){
                if(mat==Alu[i].matricula){
                    for(int j=i; j<qtd-1; j++){
                        Alu[j] = Alu[j+1];
                    }
                    printf("ALUNO EXCLUIDO COM SUCESSO \n");
                    return EXCLUIDO;
                }
            }
             
        } 
        return erro;
    }

}


void listarAlunoDat(Al Alu[], int qtd){
    int i, mes;
    printf("\n LISTAR POR DATA DE NASCIMENTO\n");
    for (i=0; i<=qtd; i++){
    if (mes = Alu[qtd].Dt.mes){
        printf("\n Nome: %s\n ", Alu[qtd].nome);
        printf("\n Mes: %d\n ", Alu[qtd].Dt.mes);
    }
    }
    
}

void ordenarPorData(Al Alu[], int qtd) {
    for (int i = 0; i < qtd - 1; i++) {
        for (int j = 0; j < qtd - i - 1; j++) {
            if (Alu[j].Dt.ano > Alu[j + 1].Dt.ano ||
                (Alu[j].Dt.ano == Alu[j + 1].Dt.ano && Alu[j].Dt.mes > Alu[j + 1].Dt.mes) ||
                (Alu[j].Dt.ano == Alu[j + 1].Dt.ano && Alu[j].Dt.mes == Alu[j + 1].Dt.mes && Alu[j].Dt.dia > Alu[j + 1].Dt.dia)) {
                // Trocar os elementos Alu[j] e Alu[j + 1]
                Al temp = Alu[j];
                Alu[j] = Alu[j + 1];
                Alu[j + 1] = temp;
            }
        }
    }
 return listarAluno(Alu,qtd);
  
}


void listarAlunoNom(Al Alu[], int qtd) {
    printf("\n     LISTA DE ALUNOS  por nome  \n");
    int i, x;
    char aux[80]; 
    if (qtd > 0) {
        for (i = 0; i < qtd - 1; i++) {
            for (x = i + 1; x < qtd; x++) {
                if (strcmp(Alu[i].nome, Alu[x].nome) > 0) {
                    strcpy(aux, Alu[i].nome);
                    strcpy(Alu[i].nome, Alu[x].nome);
                    strcpy(Alu[x].nome, aux);
                }
            }
        }
        for (i = 0; i < qtd; i++) {
            printf("%s\n", Alu[i].nome);
        }
    } else {
        printf("LISTA VAZIA");
    }
}

