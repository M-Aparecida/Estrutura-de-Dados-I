#include <stdio.h>
#include "aluno.h"
#include <stdlib.h>

struct aluno{
    int matricula;
    char nome[50];
    float media; 
};

Aluno* criarAluno(int matricula, char nome[], float media){
    Aluno *aluno = (Aluno*) malloc(sizeof(Aluno));
    aluno->matricula = matricula;
    aluno->media = media;
    strcpy(aluno->nome, nome);
    return aluno;

}

void salvarAlunoEmArquivo(char nome_do_arquivo[], Aluno *aluno){
    FILE *arq = fopen(nome_do_arquivo, "a"); 
    if(arq==NULL){
        printf("sem memoria\n");
        return;
    }
    fprintf(arq, "%d\t%s\t%f\n", aluno->matricula, aluno->nome, aluno->media);
    fclose(arq);
}

void exibirAlunos(char nome_do_arquivo[]){
    Aluno aluno;
    int cont = 1;
    FILE *arq = fopen(nome_do_arquivo, "r");
    if(arq==NULL){
        printf("Erro ao abrir\n");
        return;
    }
    while(fscanf(arq, "%d\t%[^\t]%f\n", &aluno.matricula, aluno.nome, &aluno.media) != EOF){
        printf("Aluno: %d: %d\t%s\t%.2f\n", cont, aluno.matricula, aluno.nome, aluno.media);
        cont ++;
    }
    fclose(arq);
}