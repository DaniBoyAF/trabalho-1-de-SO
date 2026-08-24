#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "processflow.h"

int main(void){

    ProcessInfo processo;
    char nome[3000];

    while(1)
    {
        printf("processflow> ");

        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = 0;
        if(strlen(nome) == 0){
            continue;
        }
        char *token;
        token = strtok(nome, " ");
        printf("Você digitou: %s\n", token);
        token = strtok(NULL, " ");

        if(token != NULL){
            printf("Você digitou: %s\n", token);
        }
        token = strtok(NULL, " ");
        if(token != NULL){
            printf("Você digitou: %s\n", token);
        }
        if(token != NULL && strcmp(token, "input") == 0)
        {
            printf("Comando input encontrado !\n");
            continue;
        }
        if(token != NULL && strcmp(token, "run") == 0)
        {
            printf("Comando run encontrado !\n");
            continue;
        }
        if(strcmp(nome, "help") == 0){
            printf("Comandos disponíveis:\n");
            printf("help - Mostra os comandos disponíveis\n");
            printf("exit - Sai do programa\n");
            printf("Qualquer outro comando será apenas impresso na tela\n");

            continue;
        }
        if(strcmp(nome, "task") == 0)
        {
            printf("Comando task encontrado !\n");
            continue;
        }
        processo.arg[0] = '\0';
        processo.quantidade_args = 0;
        token = strtok(NULL, " ");
        if(token == NULL){
            printf("erro: informe o nome da tarefa\n");
            continue;
        }
        while(token != NULL){

            printf("Argumento: %s\n", token);

            strcat(processo.arg, token);
            strcat(processo.arg, " ");

            processo.quantidade_args++;

            token = strtok(NULL, " ");
        }

        printf("Nome: %s\n", processo.nome);
        printf("Programa: %s\n", processo.programa);
        printf("Quantidade de Argumentos: %d\n",
               processo.quantidade_args);

        if(token != NULL && strcmp(token, "workdir") == 0)
        {
            token = strtok(NULL, " ");
        }
        if(strcmp(nome, "exit") == 0){
            return 0;
        }


        printf("Você escreveu isso aqui: %s\n", nome);
    }

    return 0;
}