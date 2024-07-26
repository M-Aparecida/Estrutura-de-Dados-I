#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int M, N;
    scanf("%d %d", &M, &N);

    int** matriz = (int**)malloc(M * sizeof(int*));
    for (int i = 0; i < M; i++) {
        matriz[i] = (int*)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    int costa = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (matriz[i][j] == 1) {
                if (i == 0 || i == M - 1 || j == 0 || j == N - 1 ||
                    matriz[i - 1][j] == 0 || matriz[i + 1][j] == 0 ||
                    matriz[i][j - 1] == 0 || matriz[i][j + 1] == 0) {
                    costa++;
                }
            }
        }
    }

    printf("%d\n", costa);

    for (int i = 0; i < M; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}