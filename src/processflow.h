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





#endif // PROCESSFLOW_H
