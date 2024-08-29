#include <stdio.h>
#include <stdlib.h>

    FILE * open_file(char * nome, char * modo){
        FILE * arquivo = fopen(nome, modo);
        if(arquivo==NULL){
            printf("Can't open the file\n");
            exit(1);
        }
        else{
            printf("File open\n");
        }
        return arquivo;
    }
    
int main(void){
    FILE * arquivo_de_entrada, * arquivo_de_saida;
    arquivo_de_entrada = open_file("entrada_q3.txt", "r");
    arquivo_de_saida = open_file("saida_q3.txt", "w");
    float nota1, nota2, nota3, media;
    char nome[20];
    
    while(!feof(arquivo_de_entrada)){
        fscanf(arquivo_de_entrada, "%20[^\t]\t%f\t%f\t%f\n", nome, &nota1, &nota2, &nota3);
        printf("%20[^\t]\t%f\t%f\t%f\n", nome, &nota1, &nota2, &nota3);
        media = (nota1 + nota2 + nota3)/3.0;
        if(media>=7.0){
        fprintf(arquivo_de_saida, "%s\t%.1f\nAprovado\n", nome, media);
        }
        else{
            fprintf(arquivo_de_saida, "%s\t%.1f\nReprovado\n", nome, media);
        }
    }
    fclose(arquivo_de_entrada);
    fclose(arquivo_de_saida);

    return 0;

}