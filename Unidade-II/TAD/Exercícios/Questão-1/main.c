#include <stdio.h>
#include "ContaBancaria.h"

int main(void){
    ContaBancaria * conta = cria_conta("Maria", 1000.00, 23455);
    Deposita(conta, 2500.00);
    Sacar(conta, 3000.00);
    Transferir(conta, 200.00);
    printf("Saldo atual: %.2f\n", Saldo(conta));

    free(conta);


    return 0;
}