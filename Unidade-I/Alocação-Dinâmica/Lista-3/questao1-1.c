#include <stdio.h>
#include <stdlib.h>

 /*Escreva um programa em C que solicite ao usuario o tamanho de um vetor e, em seguida, aloque
 dinamicamente memoria para armazenar esse vetor. Depois disso, peca ao usuario que insira os
 elementos do vetor e, por fim, imprima os elementos na ordem inversa.
Entrada:
 -Tamanho do vetor
 -Variavel para guardar o vetor
Processamento:
 -Preencher o vetor
Saida:
 -Imprima os elementos na ordem inversa*/

 void preenche_vetor(int tamanho, int* vetor){
    printf("Digite os elementos do vetor:\n");
    for(int count = 0; count < tamanho; count++){
        scanf("%d", &vetor[count]);
    }
 }

 void imprime_inverso(int tamanho, int* vetor){
    printf("Vetor inverso:\n");
    for(int count = tamanho - 1; count >= 0; count--){
        printf("%d\n", vetor[count]);
    }
 }

 int* aloca_vetor(int tamanho){
    int* vetor = (int*)malloc(tamanho * sizeof(int));
    if(vetor == NULL){
        printf("Sem memoria.");
        exit(1);
    }
    else{
        printf("Vetor alocado com sucesso!\n");
    }

    return vetor;

 }

 int main(void){
    int tamanho;
    printf("Informe o tamanho do vetor:\t");
    scanf("%d", &tamanho);

    //Aloca vetor
    int* vetor = aloca_vetor(tamanho);
    //Elementos do vetor
    preenche_vetor(tamanho, vetor);
    //Imprime vetor inverso
    imprime_inverso(tamanho, vetor);
    free(vetor);
    return 0;
 }