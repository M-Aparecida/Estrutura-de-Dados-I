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

 int main(void){
    int tamanho;
    printf("Informe o tamanho do vetor: \t");
    scanf("%d", &tamanho);
    int* vetor = (int*) malloc(tamanho * sizeof(int));
    if(vetor == NULL){
        printf("Sem memoria");
        exit(1);     //deixa o codigo mais limpo
    }
    else{
        printf("Vetor alocado com sucesso! \n");
    }
    //Elementos do vetor
    printf("Digite os elementos do vetor:\n");
    for(int count = 0; count < tamanho; count++){
        scanf("%d", &vetor[count]);
    }
    //Imprime vetor inverso
    printf("Vetor inverso: \n");
    for(int count = tamanho - 1; count >= 0; count--){
        printf("%d \t", vetor[count]);
    }
    free(vetor);
    return 0;
 }
