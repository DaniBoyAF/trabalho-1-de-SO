#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include "processflow.h"

int executar_tarefa(ProcessInfo *processo)
{
    pid_t pid;

    pid = fork();

    if(pid < 0)
    {
        perror("Erro ao criar processo filho");
        return -1;
    }

    if(pid == 0)
    {
        printf("processo filho criado\n");

        char *args[50];

        args[0] = processo->programa;

        int i = 1;

        char *token = strtok(processo->arg, " ");

        while(token != NULL && i < 49)
        {
            args[i] = token;
            i++;

            token = strtok(NULL, " ");
        }

        args[i] = NULL;

        execvp(args[0], args);

        perror("Erro ao executar programa filho");
        exit(1);
    }

    if(pid > 0)
    {
        adicionar_job(pid);

        printf("Processo iniciado com PID: %d\n", pid);

        return 1;
    }

    return -1;
}