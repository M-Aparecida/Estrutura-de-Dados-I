#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/*lista para manipular numeros inteiros*/

struct no{
    int info;
    No * prox; //endereco para o proximo elemento
};

No * insere_int(No* lista, int numero){
    No * novo_elemento=(No*)malloc(sizeof(No));
    if(novo_elemento==NULL){
        printf("Sem memoria");
        exit(1);
    }
    novo_elemento->info = numero;
    novo_elemento->prox = lista;
    return novo_elemento;
}

void imprime_int(No* lista){
    No * count;
    for(count = lista; count != NULL; count=count->prox){
        printf(" %d ", count->info);
    }
}

void libera_int(No * lista){
    No* count = lista;
    No * aux;
    while(count!=NULL){
        aux = count->prox;
        free(count);
        count = aux;
    }
}

No * busca_int(int numero, No* lista){
    No * count;
    for(count=lista;count!=NULL;count=count->prox){
        if(count->info == numero){
            printf("Valor encontrado: %d", count->info);
            return count;
        }
    }
    printf("Valor nao encontrado.");
    return NULL;
}

No * remove_int(No * lista, int numero){
    No * ant = NULL; //guardar o elemento anterior
    No * count=lista; //contador para percorrer a lista;
    //buscando o elemento a ser removido
    While(count->info!=numero){
        if(count==NULL){
            return lista;
        }
        ant = count;
        count=count->prox;
    }
    //o elemento e o primeiro da lista
    if(ant ==NULL){
        lista = lista->prox;
        //o elemento esta no meio ou no final da lista
    } else{
        ant->prox = count->prox;
    }
    free(count);
    return lista;
}