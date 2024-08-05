#include <stdio.h>
#include <stdlib.h>

/*TAD para criar conta bancaria que cria, deposita, saca, transfere e retorna o saldo */

/*Criação de struct para armazenar dados da conta bancaria: 
struct ContaBancaria renomeada para ContaBancaria*/
typedef struct ContaBancaria ContaBancaria;

/*Função que aloca memória para struct conta e retorna seu endereço parms:
char * titular: nome do titular da conta
float saldo: saldo disponível na conta
int número: número da conta
*/
ContaBancaria * cria_conta(char * titular, float saldo, int numero);

/*Função que simula a operação de deposita
parms:
ContaBancaria * conta: representa conta bancaria
float valor:  cria variavel para receber novo valor
*/
void Deposita(ContaBancaria * conta, float dinheiro);

/*Função que simula a operação de secar valor de uma conta
parms:
ContaBancaria * conta: representa conta bancaria
float valor: valor que sera decrementado da conta
*/
void Sacar(ContaBancaria * conta, float valor);

/**/
void Transferir(ContaBancaria * conta, float novovalor);

/*Retorna o saldo da conta*/
float Saldo(ContaBancaria * conta);