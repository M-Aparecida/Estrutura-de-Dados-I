#include <stdio.h>
#include <stdlib.h>
/*TAD chamado "Disciplina" com os seguintes campos e operações:
char nome[100]: armazena o nome da disciplina.
int codigo: armazena o código identificador único da disciplina*/

/*Criação de struct para armazenar dados da disciplina: 
struct ContaBancaria renomeada para ContaBancari*/
typedef struct Disciplina {
    char nome[100];
    int codigo;
} Disciplina;

Disciplina* cria_disciplina(char nome[], int codigo);
void exclui_disciplina(Disciplina* disciplina);