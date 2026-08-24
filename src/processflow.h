#ifndef PROCESSFLOW_H
#define PROCESSFLOW_H

#include <sys/types.h>

typedef struct{

    char nome[3000];
    char programa[3000];
    char arg[3000];
    int quantidade_args;

} ProcessInfo;


typedef struct{

    int id;
    pid_t pid;
    int estado;

} Job;


extern ProcessInfo tarefas[50];

extern int quantidade_tarefas;


int adicionar_tarefa(ProcessInfo *processo);

ProcessInfo *buscar_tarefa(char *nome);


void adicionar_job(pid_t pid);

void listar_jobs(void);

Job *buscar_job(int id);

void atualizar_estado_job(int id, int estado);

int esperar_job(int id);


int executar_tarefa(ProcessInfo *processo);

#endif