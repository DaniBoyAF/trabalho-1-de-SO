#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "processflow.h"
typedef struct{
    int id;
    pid_t pid;
    int ativo;
}Job;

Job jobs[500];
int quantidade_jobs = 0;

void adicionar_job(pid_t pid){
    if(quantidade_jobs < 500){
        jobs[quantidade_jobs].id = quantidade_jobs + 1;
        jobs[quantidade_jobs].pid = pid;
        jobs[quantidade_jobs].ativo = 1;
        quantidade_jobs++;
    }

}
void listar_jobs(void){
   
    for(int i = 0; i < quantidade_jobs; i++){
        printf("ID: %d, PID: %d, Status: %s\n", jobs[i].id, jobs[i].pid, jobs[i].ativo ? "Ativo" : "Inativo");
    }
}
void *buscar_job(int id){
    for(int i=0; i < quantidade_jobs; i++){
        if(jobs[i].id == id){
            return &jobs[i];
        }
    }
    return NULL;
}
void atualizar_status_job(int id, int status){
    Job *job = (Job *)buscar_job(id);
    if(job != NULL){
        job->ativo = status;
    }
}
int esperar_job(int id){
    Job *job = (Job *)buscar_job(id);
    if(job == NULL){
       return 0 ;
    }
    waitpid(job->pid, NULL, 0);
    jo
    return 1;
}