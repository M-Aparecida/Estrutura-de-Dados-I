#include <stdio.h>
#include <stdlib.h>

FILE * open_file(char * nome, char * modo){
    FILE * arquivo = fopen(nome, modo);
    if(arquivo == NULL){
        printf("Can't open the file\n");
        exit(1);
    } else {
        printf("File open\n");
    }
    return arquivo;
}

int main(void){
    FILE * arquivo_de_entrada, * arquivo_de_saida;
    int vetor[10];
    int i, menor, maior, soma = 0;
    float media;

    arquivo_de_entrada = open_file("entrada_q2.txt", "r");
    arquivo_de_saida = open_file("saida_q2.txt", "w");

    for(i = 0; i < 10; i++){
        fscanf(arquivo_de_entrada, "%d", &vetor[i]);
        soma += vetor[i];
        if(i == 0){
            menor = maior = vetor[i];
        } else {
            if(vetor[i] < menor) menor = vetor[i];
            if(vetor[i] > maior) maior = vetor[i];
        }
    }

    media = soma / 10.0;

    fprintf(arquivo_de_saida, "Menor elemento: %d\n", menor);
    fprintf(arquivo_de_saida, "Maior elemento: %d\n", maior);
    fprintf(arquivo_de_saida, "Média dos elementos: %.2f\n", media);

    fclose(arquivo_de_entrada);
    fclose(arquivo_de_saida);

    return 0;
}