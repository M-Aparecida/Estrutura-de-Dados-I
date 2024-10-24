#include <stdio.h>
#include <stdlib.h>
typedef struct aluno{
    char nome[20];
    int idade;
    long int matricula;
}Aluno;

void preenche(Aluno * aluno){
    printf("Informe o nome:\t");
    scanf(" %[^\n]", aluno->nome);
    printf("Informe a idade e matricula: \t");
    scanf("%d %ld", &aluno->idade, &aluno->matricula);
}

void imprime(Aluno * aluno){
    printf("Nome:%s \t Idade:%d \t Matricula: %ld", aluno->nome, aluno->idade, aluno->matricula);
}
