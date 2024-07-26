#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario {
    char nome[20];
    float salario;
    int identificador;
    char cargo[20];
} Funcionario;

void preenche(Funcionario * funcionario){
    printf("Digite o nome: \n");
    scanf(" %[^\n]", funcionario->nome);
    printf("Digite o salario: \n");
    scanf("%f", &funcionario->salario);
    printf("Digite o identificador: \n");
    scanf("%d", &funcionario->identificador);
    printf("Digite o cargo: \n");
    scanf(" %[^\n]", funcionario->cargo);  
}

void altera_salario(Funcionario * funcionario){
    float novo_salario;
    printf("Digite o novo salario: \n");
    scanf("%f", &novo_salario);
    funcionario->salario = novo_salario;
    printf("O salario foi alterado.\n");
}

void imprime(Funcionario * funcionario){
    printf("Nome: %s\nSalario: %.2f\nIdentificador: %d\nCargo: %s", funcionario->nome, funcionario->salario, funcionario->identificador, funcionario->cargo);
    }

    void maior_menor_salario(Funcionario * funcionario, int tamanho_vetor){
        float maior_salario = -1.0, menor_salario = 50.000;
        int maior_salario_index = 0, menor_salario_index = 0;
        int index; 
        for(index = 0; index<tamanho_vetor; index++){
            if(funcionario[index].salario > maior_salario){
                maior_salario = funcionario[index].salario;
                maior_salario_index = index;
            }
            if(funcionario[index].salario < menor_salario){
                menor_salario = funcionario[index].salario;
                menor_salario_index = index;
            }
        }
        printf("O funcionario com maior salario:\n");
        imprime(&funcionario[maior_salario_index]);
        printf("\nO funcionario com menor salario:\n");
        imprime(&funcionario[menor_salario_index]);
    
}
    int main(void){
    Funcionario funcionario[3];
    int index;
    for(index=0; index <3; index++){
        preenche(&funcionario[index]);
    }
    maior_menor_salario(funcionario, 3);
    return 0;
    }
