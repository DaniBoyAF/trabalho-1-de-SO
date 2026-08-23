#include <stdio.h>
#include <stdlib.h>
#include "processflow.h"
#include "task.c"

int main(void){

    ProcessInfo processo;
    char nome[3000];
    int resultado = adicionar_tarefa(&processo);
    if(resultado == 1){
        printf("Tarefa adicionada com sucesso!\n");
    }else{
        printf("Erro ao adicionar tarefa!\n");
    }
    while(1)
    {
     printf("processflow> ");
     fgets(nome, sizeof(nome), stdin);

     nome[strcspn(nome, "\n")] = 0;
     if(strlen(nome)== 0){
        continue;
     }
     char *token;
     token = strtok(nome, " ");
      printf("Você digitou: %s\n", token);
     token = strtok(NULL, " ");
      printf("Você digitou: %s\n", token);
     token = strtok(NULL, " ");
      printf("Você digitou: %s\n", token);

     if(strcmp(nome,"help")==0){
        printf("Comandos disponíveis:\n");
        printf("help - Mostra os comandos disponíveis\n");
        printf("exit - Sai do programa\n");
        printf("Qualquer outro comando será apenas impresso na tela\n");
     }


     if(strcmp(nome,"task")== 0)
     {
        printf("Comando task encontrado !\n");
        continue;
     }
      
      token = strtok(NULL, " ");
      if(token == NULL){
        printf("erro: informe o nome da tarefa\n");
        continue;
      }
    processo.arg[0] = '\0';
      token = strtok(NULL, " ");
      while(token != NULL){
        printf("Argumento: %s\n", token);
        strcat(processo.arg, token);
        strcat(processo.arg, " ");
        process.num_args++;
        token = strtok(NULL, " ");
      }
      ProcessInfo processo ;
      strcpy(processo.name, token);
      printf("Nome: %s\n", processo.name);
      printf("Programa: %s\n", processo.programa);
      printf("Quantidade de Argumentos: %d\n", processo.num_args);
      continue;

    }
 
     if(strcmp(nome,"exit")==0){
        return 0;
     }
    
     printf("Você escreveu isso aqui: %s",nome);
    }
}