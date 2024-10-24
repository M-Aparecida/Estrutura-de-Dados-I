#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;

typedef struct no No;

No* adiciona_aluno(No * lista, int matricula, char* nome, float media);

void imprime_alunos(No* lista);

No* remove_aluno(No* lista, int matricula);

void libera_lista(No* lista);

No* adiciona_aluno_ordenado(No* lista, int matricula, char* nome, float media);
