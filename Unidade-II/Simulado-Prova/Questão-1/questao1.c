#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANHO 1000000


int compare(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}

int busca_sequencial(int * entrada, int tamanho){
    //funcao que busca do maior elemento dentro de um vetor
    int maior = entrada[0];
    int index;
    //busca linear
    for(index=0; index<tamanho; index++){
        if(maior<entrada[index]){ //busca do maior elemento 
            maior = entrada[index];
        }
    }
    return maior;
}

int busca_binaria(int vet[], int maior, int tamanho){
    int inicio = 0, final = tamanho-1;
    while(inicio <= final){
        int meio = inicio + (final - inicio)/2;
        if(vet[meio] ==maior){
            return vet[meio];
        } else if(vet[meio] < maior){
            inicio = meio + 1;
        } else{
            final = meio -1;
        }
    }
    return -1;
}

int main(void){
    int entrada[TAMANHO];
    for(int index=0; index<TAMANHO; index++){
        entrada[index] = rand();
    }
    clock_t tempo_inicial = clock();
    //fução de busca
    int maior = busca_sequencial(entrada, TAMANHO); //complexidade O(n)

    double tempo_final = (double) (clock() - tempo_inicial)/CLOCKS_PER_SEC;
    tempo_final = tempo_final * 1000;
    printf("Maior Elemento: %d\n Tempo de execucao:%.4f (ms)\n", maior, tempo_final);

    qsort(entrada, TAMANHO, sizeof(int), compare);
    tempo_inicial = clock();

    //função de busca
    int maior2 = busca_binaria(entrada, maior, TAMANHO); //complexidade O(logn)
    tempo_final = (double) (clock() - tempo_inicial)/CLOCKS_PER_SEC;
    tempo_final = tempo_final * 1000;
    printf("Tempo de execucao:%.4f (ms)\n", maior2, tempo_final);
    return 0;
}