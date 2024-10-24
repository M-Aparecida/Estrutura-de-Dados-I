#include <stdlib.h>
#include "lista.c"

int main(void){
    No * lista = NULL; //lista vazia
    //inserindo elementoa
    lista = insere_int(lista, 3);
    lista = insere_int(lista, 1);
    lista = insere_int(lista, 2);
    No * numero = busca_int(3, lista);
    //imprimir a lista
    imprime_int(lista);
    libera_int(lista);
}