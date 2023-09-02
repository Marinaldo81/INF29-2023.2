#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 5
#include "aluno.h"
#include "professor.h"
#include "disciplina.h"


int CADALUNO();
int CADPROFESSOR();
int CADDISCIPLINA();
int inserirAluno(Al Alu[], int qtdA);
void listarAluno(Al Alu[], int qtdA);
void listarAlunoNom(Al Alu[], int qtdA);
void listarAlunoSexo(Al Alu[], int qtdA);
int alterarAluno(Al Alu[], int qtdA);
int excluirAluno(Al Alu[], int qtdA);
void listarAlunoDat(Al Alu[], int qtdA);


int inserirProfessor(Pro Prof[], int qtdP);
void listarProfessor(Pro Prof[], int qtdP);
void listarProfessorNom(Pro Prof[], int qtdP);
void listarProfessorSexo(Pro Prof[], int qtdP);
int alterarProfessor(Pro Prof[], int qtdP);
int excluirProfessor(Pro Prof[], int qtdP);
void listarProfessorDat(Pro Prof[], int qtdP);
void ordenarPorData(Pro Prof[], int qtdP);


inserirDisciplina(Disc Disciplina[], Pro Prof[], int qtdd);
void listarDisciplina(Disc Disciplina[], Pro Prof[], int qtdd);


int main(){    
 
int qtdA = 0; // variável para controlar a quantidade de alunos cadastrados
int qtdP = 0; // variável para controlar a quantidade de professores cadastrados 
int qtdd = 0; // variável para controlar a quantidade de disciplinas  cadastrados
Al alun; /*Criando a variável aluno que será do tipo struct*/
Al Alu[TAM]; // vetor para armazenar a lista de alunos
//Pro pro; /*Criando a variável professor que será do tipo struct*/
//Pro Prof[TAM]; // vetor para armazenar a lista de professor 
//Disc disc; /*Criando a variável professor que será do tipo struct*/
//Disc Disciplina[TAM]; // vetor para armazenar a lista de professor  
  
  
  int op, opa, opp, opd, retorno;
  int  exit = 0;
    
  while (!exit){
    op = MENU();
      
    switch(op){
  	  case 0:{
        exit = 1;
        break;
      }
      case 1:{
        CADALUNO();
        int exitA=0;
        while (!exitA){  
          opa = CADALUNO();
          switch(opa){
           case 0:{
           exitA = 1;
            break;
            }
            case 1:{
            retorno= inserirAluno(Alu,qtdA);
            printf("CADASTRO REALIZADO COM SUCESSO \n");
            qtdA++;
            break;
            }
            case 2: {
                listarAluno(Alu,qtdA);
                break;
            }    
            case 3:{
                listarAlunoSexo(Alu,qtdA);
                break;
            }
            case 4:{
                listarAlunoNom(Alu,qtdA);
                break;
            }
            case 5:{
                ordenarPorDataAl(Alu,qtdA);
                break;
            }
            case 6:{
                retorno= excluirAluno(Alu,qtdA);
                qtdA--;
                break;
            }
            case 7:{
               retorno= alterarAluno(Alu,qtdA);
                break;
            }
          
            
        
          }  
        }      
       break; 
      }
      case 2:{
      CADPROFESSOR();
        int exitp=0;
        while (!exitp){  
        opp = CADPROFESSOR();  
        switch(opp){ 
            case 0:{
            exitp = 1;
            break;
            }
            case 1:{
            retorno= inserirProfessor(Prof,qtdP);
            printf("CADASTRO REALIZADO COM SUCESSO \n");
            qtdP++;
            break;
            }
            case 2: {
                listarProfessor(Prof,qtdP);
                break;
            }    
            case 3:{
                listarProfessorSexo(Prof,qtdP);
                break;
            }
            case 4:{
                listarProfessorNom(Prof,qtdP);
                break;
            }
            case 5:{
                ordenarPorData(Prof,qtdP);
                break;
            }
            case 6:{
                retorno= excluirProfessor(Prof,qtdP);
                qtdP--;
                break;
            }
            case 7:{
               retorno= alterarProfessor(Prof,qtdP);
                break;
            }
          
            
        
        } 
        
        } 
      break;
      }
      case 3:{
        CADDISCIPLINA();
        int exitD=0;
        while (!exitD){
            opd = CADDISCIPLINA();
            switch(opd){ 
            case 0:{
            printf("FINALIZANDO PROGRAMA");
            exitD = 1;
            break;
            }
            case 1:{
            retorno= inserirDisciplina(Disciplina, Prof, qtdd);
            printf("CADASTRO REALIZADO COM SUCESSO \n");
            qtdd++;
            break;
            }
            case 2: {
                listarDisciplina(Disciplina, Prof,  qtdd);
                break;
            }    
                          
            
        
          } 
        
        } 
        break;
      }  
    } 
  }
}

int MENU(){
  int op;
  printf("-----PROGRAMA ESCOLA -----\n");
  printf("1 -  CADASTRO ALUNO \n");
  printf("2 -  CADASTRO PROFESSOR \n");
  printf("3 -  CADASTRO DISCIPLINA \n");
  printf("0 -  SAIR \n");
  scanf("%d",&op);
  return op;
}


int CADALUNO(){
  int opa;
  printf("-----CADASTRO DE ALUNO---- \n");
  printf("1- CADASTRO DE ALUNO \n"); 
  printf("2- LISTAR ALUNO \n "); 
  printf("3- LISTAR ALUNO POR SEXO (1- MASC. OU 2- FEM )\n");
  printf("4- LISTAR ALUNOS ORDENADOS POR NOME \n"); 
  printf("5- LISTAR ALUNO ORDENADO POR DATA DE NASCIMENTO \n");
  printf("6- EXCLUIR \n");
  printf("7- ATUALIZAR \n");
  printf("0- SAIR \n");
  printf("INFORME UM NUMERO \n");
  scanf("%d", &opa);      
  return opa;
}



int CADPROFESSOR(){
  int opp;
  printf("----- PAINEL PROFESSOR -----\n");
  printf("1- INCLUIR DE PROFESSOR \n"); 
  printf("2- LISTAR PROFESSOR \n "); 
  printf("3- LISTAR PROFESSOR POR SEXO (1- MASC. OU 2- FEM )\n");
  printf("4- LISTAR PROFESSOR ORDENADOS POR NOME \n"); 
  printf("5- LISTAR PROFESSOR ORDENADO POR DATA DE NASCIMENTO \n");
  printf("6- EXCLUIR PROFESSOR\n");
  printf("7- ATUALIZAR PROFESSOR\n");
  printf("0- SAIR \n");
  printf("INFORME UMA OPCAO ? \n ");
  scanf("%d",&opp);
  return opp;
}


int CADDISCIPLINA(){
  int opd;
  printf("----CADASTRO DE DISCIPLINA---- \n");
  printf("1- CADASTRO DE DISCIPLINA \n"); 
  printf("2- LISTAR DISCIPLINA \n "); 
  printf("0 - VOLTAR\n");
  printf("INFORME UMA OPCAO ? \n ");     
  scanf("%d", &opd);
        
  return opd;
}


int RELATORIOS(){
  int op;
  printf("----- PAINEL RELATORIOS -----\n");
  printf("1 -  ANIVERSARIANTES DO MES\n");
  printf("2 -  LISTA DE PESSOAS (PROFESSORR / ALUNO) \n");
  printf("4 -  LISTA DE ALUNOS MATRICULADOS EM MENOS DE 3 DISCIPLINAS  \n");
  printf("\n INFORME UMA OPCAO ? ");
  scanf("%d",&op);
  return op;
}




