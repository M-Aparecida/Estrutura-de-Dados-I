#include <stdio.h>
#include <stdlib.h>

typedef union documentos {
    long int RG;
    char CPF[12];
    long int Passaporte;
    long int Num_SUS;
}Documentos;

typedef struct pessoa {
    char nome[20];
    int idade;
    char genero[20];
    Documentos documento;
    int opcao;
}Pessoa;

void preenche_pessoa(Pessoa *pessoa){
    printf("Informe o nome:\t");
    scanf(" %[^\n]", pessoa->nome);
    printf("Informe a idade:\t");
    scanf(" %d", &pessoa->idade);
    printf("Informe o genero: \t");
    scanf(" %[^\n]", pessoa->genero);
}

void imprime_pessoa(Pessoa *pessoa){
    printf("Nome: %s\nIdade: %d\nGenero: %s\n", pessoa->nome, pessoa->idade, pessoa->genero);
}

void preenche_documentos(Pessoa * pessoa){
printf("Informe a opcao de documento: 1-RG, 2-CPF, 3-Passaporte, 4-Cartao do SUS: \t");
scanf("%d", &pessoa->opcao);
    switch (pessoa->opcao){
        case 1: 
            printf("Informe o RG: \n");
            scanf("%ld", &pessoa->documento.RG); 
            break;
        case 2:
            printf("Informe o CPF: \n");
            scanf(" %s", pessoa->documento.CPF);
            break;
        case 3:
            printf("Informe o Passaporte: \n");
            scanf("%ld", &pessoa->documento.Passaporte);
            break;
        case 4:
            printf("Informe o Numero do cartao do SUS: \n");
            scanf("%ld", &pessoa->documento.Num_SUS);
            break;
        default:
            printf("Essa opcao nao foi cadastrada.\n");
            break;

    }
}

void imprime_documentos(Pessoa * pessoa){
     switch (pessoa->opcao) {
        case 1:
            printf("RG: %ld\n", pessoa->documento.RG);
            break;
        case 2:
            printf("CPF: %s\n", pessoa->documento.CPF);
            break;
        case 3:
            printf("Passaporte: %ld\n", pessoa->documento.Passaporte);
            break;
        case 4:
            printf("Cartao do SUS: %ld\n", pessoa->documento.Num_SUS);
            break;
        default:
            printf("Opcao nao cadastrada.\n");
            break;
    
    }
}

void altera_idade(Pessoa *pessoa){
    int nova_idade;
    printf("Digite a nova idade: \n");
    scanf("%d", &nova_idade);
    pessoa->idade = nova_idade;
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
        imprime_pessoa(&pessoa[maior_idade_index]);
        printf("A pessoa com menor idade: \n");
        imprime_pessoa(&pessoa[menor_idade_index]);
}

int main(void){
    Pessoa pessoas[3];
    int index;

    for (index = 0; index < 3; index++) {
        printf("\nDados da pessoa %d:\n", index + 1);
        preenche_pessoa(&pessoas[index]);
        preenche_documentos(&pessoas[index]);
    }

    maior_menor_idade(pessoas, 3);

    return 0;
}

