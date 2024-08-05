#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ContaBancaria.h"

struct ContaBancaria {
    char titular[20];
    float saldo;
    int numero;
};

ContaBancaria * cria_conta(char * titular, float saldo, int numero){
    ContaBancaria * conta = (ContaBancaria*) malloc(sizeof(ContaBancaria));
    if(conta ==NULL){
        printf("Sem memoria!\n");
        exit(1);
    }
    else{
        printf("Conta alocada!\n");
    }
    conta->numero=numero;
    conta->saldo=saldo;
    strcpy(conta->titular, titular);
    return conta;
}

void Deposita(ContaBancaria * conta, float dinheiro){
    conta->saldo = conta->saldo + dinheiro;
    printf("Valor depositado com sucesso.\nNovo saldo: %f", conta->saldo);
}

void Sacar(ContaBancaria * conta, float valor){
    if(conta->saldo >= valor){
        conta->saldo = conta->saldo - valor;
        printf("\nValor sacado com sucesso!\n");
    }
    else{
        printf("O saldo é insuficiente.\n");
    }
}

void Transferir(ContaBancaria * conta, float novovalor){
    if(conta->saldo >= novovalor){
        conta->saldo = conta->saldo - novovalor;
        printf("Valor transferido.\n");
    } 
    else{
        printf("O saldo é insuficiente.\n");
    }
}

float Saldo(ContaBancaria * conta){
    printf("Saldo restante:%f", conta->saldo);
}