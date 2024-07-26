#include <stdio.h>
#include <stdlib.h>

/* Escreva um programa para corrigir provas de multipla escolha. Cada prova tem N
 questoes e cada questao vale 10/N pontos. Os primeiros dados a serem lidos sao o numero de
 questoes e o gabarito da prova. Em seguida, serao lidas as respectivas respostas de um total de
 10 alunos matriculados. Calcule e mostre:
 a) a nota obtida para cada aluno;
 b) a porcentagem de aprovacao, sabendo-se que a nota minima para ser aprovado e 6*/

int main(void) {
    int N;
    printf("Informe o numero de questoes: ");
    scanf("%d", &N);

    char gabarito[N];
    printf("Informe o gabarito: ");
    scanf("%s", gabarito);

    int total_alunos = 10;
    int aprovados = 0;

    for (int i = 0; i < total_alunos; i++) {
        char respostas[N];
        printf("\nAluno %d:\n", i + 1);
        printf("Informe as respostas do aluno (A, B, C, D): ");
        scanf("%s", respostas);

        int nota = 0;
        for (int j = 0; j < N; j++) {
            if (respostas[j] == gabarito[j]) {
                nota += 10 / N;
            }
        }

        if (nota >= 6) {
            aprovados++;
        }
        printf("Nota do aluno %d: %d\n", i + 1, nota);
    }

    printf("\nPorcentagem de aprovacao: %d\n", (aprovados * 100) / total_alunos);

    return 0;
}