#include "aluno.h"

struct aluno{
    int matricula;
    char nome[100];
    float media;
};

struct no{
    Aluno *aluno;
    No* prox;
};

No* adiciona_aluno(No * lista, int matricula, char* nome, float media){
    Aluno *aluno = (Aluno*)malloc(sizeof(Aluno));
    if(aluno==NULL){
        printf("ERRO");
        exit(1);
    }
    aluno->matricula = matricula;
    strcpy(aluno->nome, nome);
    aluno->media = media;

    No *novo = (No *)malloc(sizeof(No));
    if(novo==NULL){
        printf("ERRO");
        exit(1);
    }
    novo->aluno = aluno;
    novo->prox = lista;
    return novo;
 }

void imprime_alunos(No* lista){
    No* aux;
    for(aux = lista; aux!= NULL; aux = aux->prox){
        printf("\nNome: %s\tMatricula: %d\tMedia: %.1f", aux->aluno->nome, aux->aluno->matricula, aux->aluno->media);
    }
}

No* remove_aluno(No* lista, int matricula){
    No* aux = lista;
    No* ant = NULL;
    if(lista->aluno->matricula == matricula){
        aux = lista->prox;
        free(lista->aluno);
        free(lista);
        return aux;
    }
    while(aux!=NULL && aux->aluno->matricula != matricula){
        ant = aux;
        aux = aux->prox;
    }
    if(aux == NULL){
        printf("\nAluno nao encontrado");
        return lista;
    }
    ant->prox = aux->prox;
    free(aux->aluno);
    free(aux);
    return lista;
}

void libera_lista(No* lista){
    No* aux = lista;
    No* ant;
    while(aux != NULL){
        ant = aux;
        aux = aux->prox;
        free(ant->aluno);
        free(ant);
    }
}

No* adiciona_aluno_ordenado(No* lista, int matricula, char* nome, float media){
    Aluno *aluno = (Aluno*)malloc(sizeof(Aluno));
    if(aluno==NULL){
        printf("ERRO");
        exit(1);
    }
    aluno->matricula = matricula;
    strcpy(aluno->nome, nome);
    aluno->media = media;

    No *novo = (No *)malloc(sizeof(No));
    if(aluno==NULL){
        printf("ERRO");
        exit(1);
    }
    novo->aluno = aluno;
    if(lista == NULL){
        novo->prox = NULL;
        return novo;
    }
    if(matricula < lista->aluno->matricula){
        novo->prox = lista;
        return novo;
    }

    No *aux = lista;
    No *ant;
    while(aux != NULL && aux->aluno->matricula < matricula){
        ant = aux;
        aux = aux->prox;
    }
    ant->prox = novo;
    novo->prox = aux;
}