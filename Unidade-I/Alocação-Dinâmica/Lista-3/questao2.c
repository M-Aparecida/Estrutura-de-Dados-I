#include <stdio.h>
#include <stdlib.h>

/* Implemente um programa em C que solicite ao usuario o numero de linhas e colunas de uma matriz e,
 em seguida, aloque dinamicamente memoria para armazenar essa matriz. Peca ao usuario que insira
 os elementos da matriz e, por m, imprima a matriz na forma original e transposta*/

void preenche_matriz(int linhas, int colunas, int matriz[linhas][colunas]) {
    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
}

void imprime_matriz(int linhas, int colunas, int matriz[linhas][colunas]) {
    printf("Matriz original:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

void imprime_transposta(int linhas, int colunas, int matriz[linhas][colunas]) {
    printf("Matriz transposta:\n");
    for (int j = 0; j < colunas; j++) {
        for (int i = 0; i < linhas; i++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int linhas, colunas;

    printf("Informe o numero de linhas da matriz: ");
    scanf("%d", &linhas);
    printf("Informe o numero de colunas da matriz: ");
    scanf("%d", &colunas);

    int** matriz = (int**)malloc(linhas * sizeof(int*));
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int*)malloc(colunas * sizeof(int));
    }

    preenche_matriz(linhas, colunas, matriz);
    imprime_matriz(linhas, colunas, matriz);
    imprime_transposta(linhas, colunas, matriz);

    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}