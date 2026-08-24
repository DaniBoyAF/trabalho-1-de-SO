#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "processflow.h"

int main(void)
{
    ProcessInfo processo;
    char nome[3000];

    while(1)
    {
        printf("processflow> ");

        fgets(nome, sizeof(nome), stdin);

        nome[strcspn(nome, "\n")] = 0;

        if(strlen(nome) == 0)
        {
            continue;
        }

        char *token;

        token = strtok(nome, " ");

        if(token == NULL)
        {
            continue;
        }

        printf("Você digitou: %s\n", token);

        if(strcmp(token, "help") == 0)
        {
            printf("Comandos disponíveis:\n");
            printf("help - Mostra os comandos disponíveis\n");
            printf("task - Cria uma tarefa\n");
            printf("run - Executa uma tarefa\n");
            printf("jobs - Mostra os jobs\n");
            printf("wait - Espera um job terminar\n");
            printf("exit - Sai do programa\n");

            continue;
        }

        if(strcmp(token, "exit") == 0)
        {
            return 0;
        }

        if(strcmp(token, "task") == 0)
        {
            printf("Comando task encontrado!\n");

            token = strtok(NULL, " ");

            if(token == NULL)
            {
                printf("Erro: informe o nome da tarefa\n");
                continue;
            }

            strcpy(processo.nome, token);

            token = strtok(NULL, " ");

            if(token == NULL)
            {
                printf("Erro: informe o programa\n");
                continue;
            }

            strcpy(processo.programa, token);

            processo.arg[0] = '\0';
            processo.quantidade_args = 0;

            token = strtok(NULL, " ");

            while(token != NULL)
            {
                printf("Argumento: %s\n", token);

                strcat(processo.arg, token);
                strcat(processo.arg, " ");

                processo.quantidade_args++;

                token = strtok(NULL, " ");
            }

            printf("Nome: %s\n", processo.nome);
            printf("Programa: %s\n", processo.programa);
            printf("Argumentos: %s\n", processo.arg);
            printf("Quantidade de Argumentos: %d\n",
                   processo.quantidade_args);

            int resultado = adicionar_tarefa(&processo);

            if(resultado == 1)
            {
                printf("Tarefa adicionada com sucesso!\n");
            }
            else
            {
                printf("Erro ao adicionar tarefa!\n");
            }

            continue;
        }

        if(strcmp(token, "run") == 0)
        {
            printf("Comando run encontrado!\n");

            token = strtok(NULL, " ");

            if(token == NULL)
            {
                printf("Erro: informe o nome da tarefa\n");
                continue;
            }

            ProcessInfo *tarefa = buscar_tarefa(token);

            if(tarefa == NULL)
            {
                printf("Erro: tarefa não encontrada\n");
                continue;
            }

            int resultado = executar_tarefa(tarefa);

            if(resultado == 1)
            {
                printf("Tarefa executada com sucesso!\n");
            }
            else
            {
                printf("Erro ao executar tarefa!\n");
            }

            continue;
        }

        if(strcmp(token, "jobs") == 0)
        {
            printf("Jobs encontrados:\n");

            listar_jobs();

            continue;
        }

        if(strcmp(token, "wait") == 0)
        {
            token = strtok(NULL, " ");

            if(token == NULL)
            {
                printf("Erro: informe o ID do job\n");
                continue;
            }

            int id = atoi(token);

            int resultado = esperar_job(id);

            if(resultado == 1)
            {
                printf("Job %d finalizado!\n", id);
            }
            else
            {
                printf("Erro: job não encontrado\n");
            }

            continue;
        }

        printf("Você escreveu um comando desconhecido: %s\n", token);
    }

    return 0;
}