#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "processflow.h"

Job jobs[50];

int quantidade_jobs = 0;

void adicionar_job(pid_t pid)
{
    if(quantidade_jobs < 50)
    {
        jobs[quantidade_jobs].id = quantidade_jobs + 1;
        jobs[quantidade_jobs].pid = pid;
        jobs[quantidade_jobs].estado = 1;

        quantidade_jobs++;
    }
}

void listar_jobs(void)
{
    for(int i = 0; i < quantidade_jobs; i++)
    {
        printf("ID: %d, PID: %d, Status: %s\n",
               jobs[i].id,
               jobs[i].pid,
               jobs[i].estado ? "Ativo" : "Inativo");
    }
}

Job *buscar_job(int id)
{
    for(int i = 0; i < quantidade_jobs; i++)
    {
        if(jobs[i].id == id)
        {
            return &jobs[i];
        }
    }

    return NULL;
}

void atualizar_estado_job(int id, int estado)
{
    Job *job = buscar_job(id);

    if(job != NULL)
    {
        job->estado = estado;
    }
}

int esperar_job(int id)
{
    Job *job = buscar_job(id);

    if(job == NULL)
    {
        return 0;
    }

    waitpid(job->pid, NULL, 0);

    job->estado = 0;

    return 1;
}