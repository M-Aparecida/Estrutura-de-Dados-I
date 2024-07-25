#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_TURMAS 10
#define MAX_VAGAS 30

typedef struct aluno{
    int mat;
    char nome[81];
    float notas[3];
    float media;
} Aluno;

typedef struct turma{
    char id;
    int vagas;
    Aluno* alunos[MAX_VAGAS];
} Turma;

Turma* turmas[MAX_TURMAS];

int i, j;

Turma* cria_turma(char id){
    Turma* nova_turma = (Turma*) malloc(sizeof(Turma));
    if (nova_turma == NULL){
        printf("Erro ao alocar memoria para a turma.\n");
        exit(1);
    }

    nova_turma->id = tolower(id);

    nova_turma->vagas = MAX_VAGAS;

    for (i = 0; i < MAX_VAGAS; i++){
        nova_turma->alunos[i] = NULL;
    }

    return nova_turma;
}

void matricula_aluno(Turma* turma, int mat, char* nome){
    if (turma->vagas == 0) {
        printf("NÃ£o ha vagas disponiveis na turma %c.\n", turma->id);
        return;
    }

    Aluno* novo_aluno = (Aluno*) malloc(sizeof(Aluno));
    if (novo_aluno == NULL) {
        printf("Erro ao alocar memoria para o aluno.\n");
        exit(1);
    }

    novo_aluno->mat = mat;

    strncpy(novo_aluno->nome, nome, sizeof(novo_aluno->nome) - 1);

    novo_aluno->nome[sizeof(novo_aluno->nome) - 1] = '\0';

    for (i = 0; i < 3; i++) {
        novo_aluno->notas[i] = 0;
    }
    novo_aluno->media = 0;

    for (i = 0; i < MAX_VAGAS; i++){
        if (turma->alunos[i] == NULL){
            turma->alunos[i] = novo_aluno;
            turma->vagas--;
            printf("Aluno matriculado com sucesso na turma %c.\n", turma->id);
            return;
        }
    }
    printf("Nao e possivel matricular o aluno, a turma %c estÃ¡ cheia.\n", turma->id);
}

void lanca_notas(Turma* turma){
    for (i = 0; i < MAX_VAGAS; i++){
        if (turma->alunos[i] != NULL){
            printf("Lancando notas para aluno %s - Matricula: %d\n", turma->alunos[i]->nome, turma->alunos[i]->mat);
            float soma = 0;
            for (j = 0; j < 3; j++) {
                printf("Informe a nota %d: ", j + 1);
                scanf("%f", &turma->alunos[i]->notas[j]);
                soma += turma->alunos[i]->notas[j];
            }
            turma->alunos[i]->media = soma / 3;
        }
    }
}

void imprime_alunos(Turma* turma){
    printf("Alunos da turma %c:\n", turma->id);
    for (i = 0; i < MAX_VAGAS; i++){
        if (turma->alunos[i] != NULL){
            printf("Matricula: %d\n", turma->alunos[i]->mat);
            printf("Nome: %s\n", turma->alunos[i]->nome);
            printf("Notas: %.2f, %.2f, %.2f\n", turma->alunos[i]->notas[0], turma->alunos[i]->notas[1], turma->alunos[i]->notas[2]);
            printf("Media: %.2f\n\n", turma->alunos[i]->media);
        }
    }
}

void imprime_turmas(Turma** turmas, int n){
    for (i = 0; i < n; i++) {
        if (turmas[i] != NULL) {
            printf("Turma %c - %d vagas disponiveis\n", turmas[i]->id, turmas[i]->vagas);
        }
    }
}


Turma* procura_turma(Turma** turmas, int n, char id){
    id = tolower(id);
    for (i = 0; i < n; i++) {
        if (turmas[i] != NULL && turmas[i]->id == id) {
            return turmas[i];
        }
    }
    return NULL;
}

int main(){
    int opcao, mat;
    char id_turma, nome[81];

    printf("Bem-vindo ao Programa de Gerenciamento de Turmas!\n");
    printf("Este programa gerencia as turmas ofertadas, fornecendo as funcionalidades de matricula, lancamento de notas e listagem de alunos.\n");

    printf("Autora: Maria Aparecida.\t Versao: 1.0\n");

    do {
        printf("\nMENU:\n");
        printf("1- Criar turma\n");
        printf("2- Listar turmas\n");
        printf("3- Matricular aluno\n");
        printf("4- Lancar notas\n");
        printf("5- Listar alunos\n");
        printf("6- Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                printf("\nCriando nova turma...\n");
                printf("Digite um id: ");
                scanf(" %c", &id_turma);
                for (i = 0; i < MAX_TURMAS; i++) {
                    if (turmas[i] == NULL) {
                        turmas[i] = cria_turma(id_turma);
                        printf("Turma %c criada com sucesso!\n", id_turma);
                        break;
                    }
                }
                break;

            case 2:
                printf("\nListando turmas...\n");
                imprime_turmas(turmas, MAX_TURMAS);
                break;

            case 3:
                printf("\nMatriculando aluno...\n");
                printf("Digite o id da turma: ");
                scanf(" %c", &id_turma);
                printf("Digite a matricula: ");
                scanf("%d", &mat);
                getchar();
                printf("Digite o nome: ");
                scanf(" %[^\n]", nome);
                Turma* turma = procura_turma(turmas, MAX_TURMAS, id_turma);
                if (turma != NULL) {
                    matricula_aluno(turma, mat, nome);
                } else {
                    printf("\nTurma %c nÃ£o encontrada.\n", id_turma);
                }
                break;

            case 4:
                printf("\nLancando notas...\n");
                printf("Digite o id da turma: ");
                scanf(" %c", &id_turma);
                turma = procura_turma(turmas, MAX_TURMAS, id_turma);
                if (turma != NULL) {
                    lanca_notas(turma);
                } else {
                    printf("\nTurma %c nÃ£o encontrada!\n", id_turma);
                }
                break;

            case 5:
                printf("\nListando alunos...\n");
                printf("Digite o id da turma: ");
                scanf(" %c", &id_turma);
                turma = procura_turma(turmas, MAX_TURMAS, id_turma);
                if (turma != NULL) {
                    imprime_alunos(turma);
                } else {
                    printf("\nTurma %c nÃ£o encontrada!\n", id_turma);
                }
                break;

            case 6:
                printf("\nObrigado por usar este programa!\n");
                break;

            default:
                printf("\nOpcao invalida.\n");
                break;
        }

    } while (opcao != 6);

    for (i = 0; i < MAX_TURMAS; i++) {
        if (turmas[i] != NULL) {
            for (j = 0; j < MAX_VAGAS; j++) {
                if (turmas[i]->alunos[j] != NULL) {
                    free(turmas[i]->alunos[j]);
                }
            }
            free(turmas[i]);
        }
    }

    return 0;
