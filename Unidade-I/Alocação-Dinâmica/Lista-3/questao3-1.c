#include <stdio.h>
#include <stdlib.h>
#include <math.h> //usar a rand() para numeros aleatorios

/*Crie um programa em C que leia um numero inteiro positivo n do usuario e aloque dinamicamente
memoria para armazenar uma matriz quadrada de ordem n. Preencha essa matriz com numeros
aleatorios entre 1 e 100, e em seguida, exiba a matriz resultante.
Entrada:
 -Um inteiro para o tamanho da matriz
 -Uma matriz quadrada
Processamento:
 -Preencher a matriz com valores 1-100
 Sai­da:
 -Matriz
*/
int ** aloca_matriz(int tamanho);
void preenche_matriz(int **matriz, int tamanho);
void imprime(int ** matriz, int tamanho);
void libera(int ** matriz, int tamanho);

int main(void){


    unsigned int tamanho;
    printf("Informe o tamanho:");
    scanf("%d", &tamanho);
    //Alocacao da matriz
    int ** matriz = aloca_matriz(tamanho);
   
    //Preenchendo a matriz
    preenche_matriz(matriz, tamanho);
    //Imprime a matriz
    imprime(matriz, tamanho);
    //Libera a memoria
    libera(matriz, tamanho);
    return 0;
}

    void libera(int ** matriz, int tamanho){
        int count;
        for(count = 0; count < tamanho; count++){
            free(matriz[count]);
        }
        free(matriz);
    }

    int ** aloca_matriz(int tamanho){
        int ** matriz = (int**) malloc(tamanho * sizeof(int*));
        if(matriz == NULL){
            printf("Sem memoria!");
            exit(1);
        }
        int count;
        for(count = 0; count < tamanho; count++){
            matriz[count] = (int*) malloc(tamanho * sizeof(int));
            if(matriz[count] == NULL){
                exit(1);
            }
        }
        return matriz;
    }

    void preenche_matriz(int ** matriz, int tamanho){
        printf("\nPreenchendo matriz\n");
        int linha, coluna;
        for(linha = 0; linha < tamanho; linha ++){
            for(coluna = 0; coluna < tamanho; coluna++){
                matriz[linha][coluna] = rand()%100;
            }
        }
    }

    void imprime(int ** matriz, int tamanho){
        printf("\nImprimindo matriz\n");
        int linha, coluna;
        for(linha = 0; linha < tamanho; linha++){
            for(coluna = 0; coluna < tamanho; coluna++){
                printf("%d\t", matriz[linha][coluna]);
            }
            printf("\n");
        }
    }

    