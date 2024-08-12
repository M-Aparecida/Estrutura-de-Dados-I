#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*renomeia struct aluno Aluno */
typedef struct aluno Aluno;

/*função para retornar dados dos alunos*/
Aluno criarAluno(int matricula, char nome[], float media);

void salvarAlunoEmArquivo(char nome_do_arquivo[], Aluno *aluno);

void exibirAlunos(char nome_do_arquivo[]);