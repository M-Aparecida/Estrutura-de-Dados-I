#include <stdio.h>
#include <stdlib.h>
/*Crie um tipo estruturado para armazenar dados de uma pessoa. Uma estrutura deste tipo possui os
 seguintes campos: nome da pessoa, numero do documento e idade.
 a) Escreva uma funcao que receba como parametro o endereco de uma estrutura do tipo Pessoa e
 preencha seus campos com valores fornecidos pelo usuario via teclado.
 b) Escreva uma funcao que receba como parametro o endereco de uma estrutura do tipo Pessoa e
 imprima os valores dos seus campos.
 c) Implemente uma funcao para realizar uma atualizacao da idade de uma estrutura do tipo Pessoa.
 d) Escreva uma funcao que receba como parametro um vetor de estruturas do tipo Pessoa e imprima
 o nome da Pessoa mais velha e mais nova.*/ 

typedef struct pessoa{
    char nome[20];
    long int numDocumento;
    int idade;
} Pessoa;

void preenche(Pessoa *pessoa){
    printf("Digite o nome: \n");
    scanf(" %[^\n]", pessoa->nome);
    printf("Digite o numero do documento: \n");
    scanf("%ld", &pessoa->numDocumento);
    printf("Digite a idade: \n");
    scanf("%d", &pessoa->idade);
}

void altera_idade(Pessoa *pessoa){
    int nova_idade;
    printf("Digite a nova idade: \n");
    scanf("%d", &nova_idade);
    pessoa->idade = nova_idade;
    printf("A idade foi alterado.\n");
}

void imprime(Pessoa *pessoa){
    printf("Nome: %s\nNumero do documento: %ld\nIdade: \n%d", pessoa->nome, pessoa->numDocumento, pessoa->idade);
    }

     void maior_menor_idade(Pessoa * pessoa, int tamanho_vetor){
        int maior_idade = -1, menor_idade = 101;
        int maior_idade_index, menor_idade_index = 0;
        int index; 
        for(index = 0; index<tamanho_vetor; index++){
            if(pessoa[index].idade > maior_idade){
                maior_idade = pessoa[index].idade;
                maior_idade_index = index;
            }
            if(pessoa[index].idade < menor_idade){
                menor_idade = pessoa[index].idade;
                menor_idade_index = index;
            }
        }
        printf("A pessoa com maior idade: \n");
        imprime(&pessoa[maior_idade_index]);
        printf("A pessoa com menor idade: \n");
        imprime(&pessoa[menor_idade_index]);
}

 int main(void){
    Pessoa pessoa[3];
    int index;
    for(index=0; index <3; index++){
        preenche(&pessoa[index]);
    }
    maior_menor_idade(pessoa, 3);
    return 0;
    }
