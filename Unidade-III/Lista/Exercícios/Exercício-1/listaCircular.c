#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no * proximo;
} No;

//implementação básica Questão 3
No* inserir_no_inicio(No * lista, int valor) {
    No * novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Sem memoria!\n");
        exit(1);
    }
    novo_no->valor = valor;

    if (lista == NULL) {
        novo_no->proximo = novo_no; 
        return novo_no;
    }

    No * temp = lista;
    while (temp->proximo != lista) {
        temp = temp->proximo;
    }
    novo_no->proximo = lista;
    temp->proximo = novo_no;

    return novo_no;
}

No* inserir_no_fim(No * lista, int valor) {
    No * novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Sem memoria!\n");
        exit(1);
    }
    novo_no->valor = valor;

    if (lista == NULL) {
        novo_no->proximo = novo_no; 
        return novo_no;
    }

    No *temp = lista;
    while (temp->proximo != lista) {
        temp = temp->proximo;
    }
    temp->proximo = novo_no;
    novo_no->proximo = lista;

    return lista;
}

void exibir_lista(No * lista) {
    if (lista == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    No * temp = lista;
    do {
        printf("%d ", temp->valor);
        temp = temp->proximo;
    } while (temp != lista);
}

//busca e remoção - Questão 4
int buscar(No * lista, int valor) {
    if (lista == NULL) {
        return -1; 
    }

    No *temp = lista;
    int posicao = 0;
    do {
        if (temp->valor == valor) {
            return posicao;
        }
        temp = temp->proximo;
        posicao++;
    } while (temp != lista);

    return -1; 
}

No* remover_valor(No * lista, int valor) {
    if (lista == NULL) {
        printf("Lista vazia\n");
        return NULL;
    }

    No * temp = lista;
    No * anterior = NULL;

    do {
        if (temp->valor == valor) {
            break;
        }
        anterior = temp;
        temp = temp->proximo;
    } while (temp != lista);

    if (temp->valor != valor) {
        printf("Valor nao encontrado\n");
        return lista;
    }

    if (temp == lista) {
        No * ultimo = lista;
        while (ultimo->proximo != lista) {
            ultimo = ultimo->proximo;
        }
        if (lista->proximo == lista) {
            lista = NULL;
        } else {
            lista = lista->proximo;
            ultimo->proximo = lista;
        }
    } else {
        anterior->proximo = temp->proximo;
    }

    free(temp);
    return lista;
}

No* remover_primeiro(No * lista) {
    if (lista == NULL) {
        printf("Lista vazia\n");
        return NULL;
    }

    No * temp = lista;
    No * ultimo = lista;

    while (ultimo->proximo != lista) {
        ultimo = ultimo->proximo;
    }

    if (lista->proximo == lista) {
        lista = NULL;
    } else {
        lista = lista->proximo;
        ultimo->proximo = lista;
    }

    free(temp);
    return lista;
}

No* remover_ultimo(No * lista) {
    if (lista == NULL) {
        printf("Lista vazia\n");
        return NULL;
    }

    No *  temp = lista;
    No * anterior = NULL;

    while (temp->proximo != lista) {
        anterior = temp;
        temp = temp->proximo;
    }

    if (anterior == NULL) {
        lista = NULL;
    } else {
        anterior->proximo = lista;
    }

    free(temp);
    return lista;
}

int main(void) {
    No * lista = NULL;

    lista = inserir_no_inicio(lista, 10);
    lista = inserir_no_inicio(lista, 20);
    lista = inserir_no_fim(lista, 30);
    lista = inserir_no_fim(lista, 40);

    printf("Lista circular: ");
    exibir_lista(lista);

    int posicao = buscar(lista, 30);
    if (posicao != -1) {
        printf("Valor 30 encontrado na posicao: %d\n", posicao);
    } else {
        printf("Valor 30 nao encontrado na lista.\n");
    }

    lista = remover_valor(lista, 20);
    printf("lista depois de remover o valor 20: ");
    exibir_lista(lista);

    lista = remover_primeiro(lista);
    printf("\nLista depois de remover o primeiro elemento: ");
    exibir_lista(lista);

    lista = remover_ultimo(lista);
    printf("\nLista depois de remover o ultimo elemento: ");
    exibir_lista(lista);

    return 0;
}