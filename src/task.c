#include <stdio.h>
#include <stdlib.h>
#include "processflow.h"
#include "task.h"
#include <string.h>

processInfo tarefas[50];
int quantidade_tarefas = 0;

int adicionar_tarefa(ProcessInfo *processo){
    if(quantidade_tarefas < 50){
        tarefas[quantidade_tarefas] = *processo;
        quantidade_tarefas++;
        return 1;
    }
    return 0;
}
ProcessInfo *buscar_tarefa(char *nome){
    for(int i = 0; i < quantidade_tarefas; i++){
        if(strcmp(tarefas[i].nome, nome) == 0){
            return &tarefas[i];
        }
    }
    return NULL;

}