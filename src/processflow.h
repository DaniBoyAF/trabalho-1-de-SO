#ifndef PROCESSFLOW_H
#define PROCESSFLOW_H

#include <sys/types.h>
typedef struct{
    char nome[3000];
    char programa[3000];
    char arg [3000];
    int quantdade_args;
} ProcessInfo;
extern tarefas 
extern int quantidade_tarefas;
int adicionar_tarefa(ProcessInfo *processo);
ProcessInfo *buscar_tarefa(char *nome);
void adicionar_job(pid_t pid);  
void listar_jobs(void);
void *buscar_job(int id);
void atualizar_status_job(int id, int status);
int esperar_job(int id);




#endif // PROCESSFLOW_H
