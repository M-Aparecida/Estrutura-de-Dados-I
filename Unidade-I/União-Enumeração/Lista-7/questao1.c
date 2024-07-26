#include <stdio.h>
#include <stdlib.h>

/*Escreva um programa que implementa uma struct Pessoa com os campos nome, idade e genero. O
 genero deve ser armazenado como um enum com os valores MASCULINO e FEMININO. O programa
 deve ler os dados de uma pessoa e imprimir os dados da pessoa*/

 typedef enum genero{
    MASCULINO,
    FEMININO,
    NEUTRO
 }Genero;

 typedef struct pessoa{
    char nome[20];
    int idade;
    Genero genero;
 }Pessoa;

 void preenche_pessoa(Pessoa *pessoa){
    printf("Informe o nome: \n");
    scanf(" %[^\n]", pessoa->nome);
    printf("Informe a idade: \n");
    scanf(" %d", &pessoa->idade);
    
    int genero;
    printf("Informe o genero: 0-MASCULINO, 1-FEMININO, 2-NEUTRO\n");
    scanf(" %d", &genero);
    if (genero == 0) {
        pessoa->genero = MASCULINO;
    } else if (genero == 1) {
        pessoa->genero = FEMININO;
    } else if (genero == 2) {
        pessoa->genero = NEUTRO;
    } else {
        printf("Opcao Invalida!\n");
    }

}

void imprime_pessoa(Pessoa *pessoa){
    printf("Nome: %s\nIdade: %d\nGenero: ", pessoa->nome, pessoa->idade);
    switch (pessoa->genero){
    case MASCULINO:
        printf("Masculino\n");
        break;
    case FEMININO:
        printf("Feminino\n");
        break;
    case NEUTRO:
        printf("Neutro\n");
        break;
    default:
    printf("Opcao nao cadastrada.\n");
    break;

}
}
int main(void){
    Pessoa pessoa;
    preenche_pessoa(&pessoa);
    imprime_pessoa(&pessoa);
    return 0;
}
