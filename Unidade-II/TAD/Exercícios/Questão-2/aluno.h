#include <stdio.h>
#include <stdlib.h>
#include "disciplina.h"
/*TAD chamado "Aluno" com os seguintes campos e operações:
char nome[100]: armazena o nome do aluno.
int matricula: armazena o número de matrícula único do aluno.
Disciplina* disciplinas[10]: um array de ponteiros para Disciplinas, que 
armazena as disciplinas em que o aluno está matriculado.
int num_disciplinas: armazena o número atual de disciplinas em que o aluno 
está matriculado */


typedef struct Aluno {
    char nome[100];
    int matricula;
    Disciplina* disciplinas[10];
    int num_disciplinas;
} Aluno;

Aluno* cria_aluno(char nome[], int matricula);
void matricula_disciplina(Aluno* aluno, Disciplina* disciplina);
void exclui_aluno(Aluno* aluno);
void exibe_aluno(Aluno* aluno);