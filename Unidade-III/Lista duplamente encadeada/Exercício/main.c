#include "lista2.h"
#include <stdio.h>
#include <stdlib.h>
int main(void){
    Lista2 * lista; 
    // NULL <- |5| -><- |3| -> NULL
    lista = lst2_insere(lista, 3); //insere 3
    lista = lst2_insere(lista, 5);
    
    Lista2 * elemento = lst2_busca(lista, 3); //buscar elemento 3 na lista
    printf("Elemento: %d", elemento->info);

    return 0;
    
}

