#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 1000000

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int busca_sequencial(int *entrada, int tamanho) {
    // Função que busca o maior elemento dentro de um vetor
    int maior = entrada[0];
    for (int index = 1; index < tamanho; index++) {
        if (maior < entrada[index]) { // Busca do maior elemento 
            maior = entrada[index];
        }
    }
    return maior;
}

int busca_binaria(int vet[], int maior, int tamanho) {
    int inicio = 0, final = tamanho - 1;
    while (inicio <= final) {
        int meio = inicio + (final - inicio) / 2;
        if (vet[meio] == maior) {
            return vet[meio];
        } else if (vet[meio] < maior) {
            inicio = meio + 1;
        } else {
            final = meio - 1;
        }
    }
    return -1;
}

int main(void) {
    int entrada[TAMANHO];
    srand(time(NULL)); 
    for (int index = 0; index < TAMANHO; index++) {
        entrada[index] = rand();
    }

    clock_t tempo_inicial = clock();
    // Função de busca
    int maior = busca_sequencial(entrada, TAMANHO); // Complexidade O(n)
    double tempo_final = (double)(clock() - tempo_inicial) / CLOCKS_PER_SEC * 1000;
    printf("Maior Elemento: %d\nTempo de execucao: %.4f ms\n", maior, tempo_final);

    qsort(entrada, TAMANHO, sizeof(int), compare);
    tempo_inicial = clock();
    // Função de busca
    int maior2 = busca_binaria(entrada, maior, TAMANHO); // Complexidade O(log n)
    tempo_final = (double)(clock() - tempo_inicial) / CLOCKS_PER_SEC * 1000;
    printf("Maior Elemento (Busca Binaria): %d\nTempo de execucao: %.4f ms\n", maior2, tempo_final);

    return 0;
}