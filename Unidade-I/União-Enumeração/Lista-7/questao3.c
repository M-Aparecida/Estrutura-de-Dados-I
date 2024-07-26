#include <stdio.h>
#include <stdlib.h>

/*Escreva um programa que implementa uma struct Data com os campos dia, mes e ano. O mes deve
 ser armazenado como um enum com os valores JANEIRO, FEVEREIRO, MARCO, ABRIL, MAIO,
 JUNHO, JULHO, AGOSTO, SETEMBRO, OUTUBRO, NOVEMBRO e DEZEMBRO. O programa
 deve ler a data e imprimir a data no formato dd/mm/aaaa*/

typedef enum mes{
    JANEIRO,
    FEVEREIRO,
    MARCO,
    ABRIL,
    MAIO,
    JUNHO,
    JULHO,
    AGOSTO,
    SETEMBRO,
    OUTUBRO,
    NOVEMBRO,
    DEZEMBRO
} Mes;

typedef struct data{
    int dia;
    Mes mes;
    int ano;
} Data;

int main(void) {
    Data data;

    printf("Informe a data (dd mm aaaa): ");
    scanf("%d %d %d", &data.dia, &data.mes, &data.ano);

    if (data.dia < 1 || data.dia > 31 || data.mes < JANEIRO || data.mes > DEZEMBRO || data.ano < 1900 || data.ano > 3000) {
        printf("Data invÃ¡lida.\n");
        return 1;
    }

    printf("Data formatada: %02d/%02d/%04d\n", data.dia, data.mes + 1, data.ano);

    return 0;
}