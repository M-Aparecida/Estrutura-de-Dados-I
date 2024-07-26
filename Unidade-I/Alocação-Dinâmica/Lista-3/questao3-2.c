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
 Saida:
 -Matriz
*/

int main(void){
    unsigned int tamanho;
    printf("Informe o tamanho: ");
    scanf("%d", &tamanho);
    int ** matriz = (int**)malloc(tamanho * sizeof(int*));
    if(matriz == NULL){
        printf("sem memoria");
        exit(1);
    }
    
    int count;
    for(count = 0; count < tamanho; count++){
        matriz[count] = (int*)malloc(tamanho * sizeof(int));
        if(matriz[count] == NULL){
        printf("Sem memoria");
        exit(1);
        }
    }
    //Preenchendo a matriz
    int linha, coluna;
    for(linha = 0; linha < tamanho; linha++){
        for(coluna = 0; coluna <tamanho; coluna++){
            matriz[linha][coluna] = rand()%100;
        }
    }
    //Imprimindo a matriz
    for(linha = 0; linha < tamanho; linha++){
        for(coluna = 0; coluna < tamanho; coluna++){
            printf("%d ", matriz[linha][coluna]);
        }
        printf("\n");
    }

    //Liberar memoria
    for(count = 0; count < tamanho; count++){
        free(matriz[count]);
    }
    free(matriz);

    return 0;



}