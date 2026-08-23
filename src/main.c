#include <stdio.h>
#include <stdlib.h>
#include "processflow.h"
#include "task.c"

int main(void){

    char nome[3000];
     printf("processflow> ")
     fgets(nome, sizeof(nome), stdin);
     printf("Você escreveu isso aqui: %s",nome);
}