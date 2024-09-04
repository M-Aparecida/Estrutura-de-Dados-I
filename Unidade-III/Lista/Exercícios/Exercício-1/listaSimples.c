#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
} No;

//implementação bsica -Questão 1

No* inserir_no_inicio(No * lista, int valor) {
    No * novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Sem memoria\n");
        exit(1);
    }
    novo_no->valor = valor;
    novo_no->proximo = lista;
    return novo_no;
}

No* inserir_no_fim(No * lista, int valor) {
    No * novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Sem memoria.\n");
        exit(1);
    }
    novo_no->valor = valor;
    novo_no->proximo = NULL;

    if (lista == NULL) {
        return novo_no;
    } else {
        No * temp = lista;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novo_no;
        return lista;
    }
}

void exibir_lista(No * lista) {
    No * temp = lista;
    while (temp != NULL) {
        printf("%d ", temp->valor);
        temp = temp->proximo;
    }
}

No* remover_primeiro(No * lista) {
    if (lista == NULL) {
        printf("Lista vazia\n");
        return NULL;
    }
    No * temp = lista;
    lista = lista->proximo;
    free(temp);
    return lista;
}

//buscar e remover - Questão 2

int buscar(No * lista, int valor) {
    No * temp = lista;
    int posicao = 0;
    while (temp != NULL) {
        if (temp->valor == valor) {
            return posicao;
        }
        temp = temp->proximo;
        posicao++;
    }
    return -1; 
}

No* remover_valor(No * lista, int valor) {
    if (lista == NULL) {
        printf("Lista vazia\n");
        return NULL;
    }

    No *  temp = lista;
    No *anterior = NULL;

    while (temp != NULL && temp->valor != valor) {
        anterior = temp;
        temp = temp->proximo;
    }

    if (temp == NULL) {
        printf("Valor nao encontrado\n");
        return lista;
    }

    if (anterior == NULL) {
        lista = temp->proximo;
    } else {
        anterior->proximo = temp->proximo;
    }

    free(temp);
    return lista;
}

No* inserir_apos(No * lista, int valor, int novo_valor) {
    No * temp = lista;
    while (temp != NULL && temp->valor != valor) {
        temp = temp->proximo;
    }

    if (temp == NULL) {
        printf("Valor nao encontrado\n");
        return lista;
    }

    No* novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Sem memoria\n");
        exit(1);
    }
    novo_no->valor = novo_valor;
    novo_no->proximo = temp->proximo;
    temp->proximo = novo_no;

    return lista;
}

int main(void) {
    No * lista = NULL;

    lista = inserir_no_inicio(lista, 10);
    lista = inserir_no_inicio(lista, 20);
    lista = inserir_no_fim(lista, 30);
    lista = inserir_no_fim(lista, 40);

    printf("Lista Simples:");
    exibir_lista(lista);

    int posicao = buscar(lista, 30);
    if (posicao != -1) {
        printf("\nValor 30 encontrado na posicao: %d\n", posicao);
    } else {
        printf("Valor 30 nao encontrado na lista.\n");
    }

    lista = remover_valor(lista, 20);
    printf("Lista depois de remover o valor 20: ");
    exibir_lista(lista);

    lista = inserir_apos(lista, 10, 25);
    printf("\nLista depois de inserir 25 depois do valor 10: ");
    exibir_lista(lista);

    return 0;
}