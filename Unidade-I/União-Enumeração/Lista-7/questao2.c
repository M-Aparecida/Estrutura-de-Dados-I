#include <stdio.h>
#include <stdlib.h>

/* Escreva um programa que implementa uma struct Produto com os campos nome, preco e tipo. O
 tipo deve ser armazenado como uma union que armazena um dos tipos: ALIMENTO, BEBIDA ou
 ELETRONICO. O programa deve ler os dados de um produto e imprimir os dados do produto*/

typedef enum tipo {
    ALIMENTO,
    BEBIDA,
    ELETRONICO
} Tipo;

typedef union tipo_produto {
    char alimento[20];
    char bebida[20];
    char eletronico[20];
} Tipo_Produto;

typedef struct {
    char nome[30];
    float preco;
    Tipo_Produto tipo;
} Produto;

int main(void) {
    Produto produto;

    printf("Informe o nome do produto: ");
    scanf(" %[^\n]", produto.nome);

    printf("Informe o preco do produto: ");
    scanf("%f", &produto.preco);

    int escolha_produto;
    printf("Escolha o tipo do produto (0-ALIMENTO, 1-BEBIDA, 2-ELETRONICO): ");
    scanf("%d", &escolha_produto);

    switch (escolha_produto) {
        case 0:
            printf("Informe o tipo de alimento: ");
            scanf(" %[^\n]", produto.tipo.alimento);
            break;
        case 1:
            printf("Informe o tipo de bebida: ");
            scanf(" %[^\n]", produto.tipo.bebida);
            break;
        case 2:
            printf("Informe o tipo de eletronico: ");
            scanf(" %[^\n]", produto.tipo.eletronico);
            break;
        default:
            printf("Opcao invalida.\n");
            exit(1);
    }


    printf("\nDados do produto:\n");
    printf("Nome: %s\n", produto.nome);
    printf("PreÃ§o: %.2f\n", produto.preco);
    switch (escolha_produto) {
        case 0:
            printf("Tipo: Alimento (%s)\n", produto.tipo.alimento);
            break;
        case 1:
            printf("Tipo: Bebida (%s)\n", produto.tipo.bebida);
            break;
        case 2:
            printf("Tipo: Eletronico (%s)\n", produto.tipo.eletronico);
            break;
    }

    return 0;
}

