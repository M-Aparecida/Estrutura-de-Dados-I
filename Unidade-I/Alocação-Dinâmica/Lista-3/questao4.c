#include <stdio.h>
#include <stdlib.h>
/*Voce foi contratado para desenvolver um programa em C que permita armazenar nomes completos
 e idades de varias pessoas. O programa deve solicitar ao usuario o numero de pessoas e, em seguida,
 permitir que ele digite o nome completo e a idade de cada pessoa.
 Seu programa deve alocar memoria dinamicamente para armazenar os nomes em uma matriz de
 strings, e as idades devem ser armazenadas em um vetor. Apos a entrada de todos os nomes e idades,
 o programa deve exibir os nomes armazenados.
 Aqui estao as especi cacoes do programa:
 O programa deve comecar solicitando ao usuario o numero de pessoas que deseja armazenar.
 Em seguida, o programa deve pedir ao usuario que digite o nome completo de cada pessoa.
 Os nomes devem ser armazenados em uma matriz alocada dinamicamente.
 Apos o nome, o programa deve solicitar a idade da pessoa.
 As idades devem ser armazenadas em um vetor alocado dinamicamente.
 Apos a entrada de todos os nomes e idades, o programa deve exibir os nomes armazenados.
 Certi que-se de tratar adequadamente a alocacao dinamica de memoria e liberar a memoria
 alocada corretamente apos o uso.
 Observacao: O programa deve ser capaz de armazenar ate 100 nomes completos*/
// Estrutura para armazenar os dados de uma pessoa
struct Pessoa {
    char nome[100];
    int idade;
};

int main(void) {
    int numPessoas;

    printf("Informe o numero de pessoas que deseja armazenar (maximo 100): ");
    scanf("%d", &numPessoas);

    struct Pessoa* pessoas = (struct Pessoa*)malloc(numPessoas * sizeof(struct Pessoa));
    if (pessoas == NULL) {
        printf("Erro na alocacao de memoria.\n");
        exit(1);
    }

    for (int i = 0; i < numPessoas; i++) {
        printf("Digite o nome completo da pessoa %d: ", i + 1);
        scanf(" %[^\n]", pessoas[i].nome); 
        printf("Digite a idade da pessoa %d: ", i + 1);
        scanf("%d", &pessoas[i].idade);
    }

    printf("\nNomes armazenados:\n");
    for (int i = 0; i < numPessoas; i++) {
        printf("%s\n", pessoas[i].nome);
    }

    free(pessoas);

    return 0;
}