#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

struct produto {
    int codigo;
    char descricao[50];
    int quantidade;
};

Produto* criarProduto(int codigo, char descricao[], int quantidade) {
    Produto *produto = (Produto*) malloc(sizeof(Produto));
    produto->codigo = codigo;
    strcpy(produto->descricao, descricao);
    produto->quantidade = quantidade;
    return produto;
}

void adicionarProdutoAoEstoque(char nome_do_arquivo[], Produto *produto) {
    FILE *arq = fopen(nome_do_arquivo, "ab");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    fwrite(produto, sizeof(Produto), 1, arq);
    fclose(arq);
}

void removerProdutoDoEstoque(char nome_do_arquivo[], int codigo) {
    FILE *arq = fopen(nome_do_arquivo, "rb");
    FILE *temp = fopen("temp.bin", "wb");
    Produto produto;

    if (arq == NULL || temp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    while (fread(&produto, sizeof(Produto), 1, arq)) {
        if (produto.codigo != codigo) {
            fwrite(&produto, sizeof(Produto), 1, temp);
        }
    }

    fclose(arq);
    fclose(temp);
    remove(nome_do_arquivo);
    rename("temp.bin", nome_do_arquivo);
}

void atualizarQuantidadeNoEstoque(char nome_do_arquivo[], int codigo, int nova_quantidade) {
    FILE *arq = fopen(nome_do_arquivo, "rb+");
    Produto produto;

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    while (fread(&produto, sizeof(Produto), 1, arq)) {
        if (produto.codigo == codigo) {
            produto.quantidade = nova_quantidade;
            fseek(arq, -sizeof(Produto), SEEK_CUR);
            fwrite(&produto, sizeof(Produto), 1, arq);
            break;
        }
    }

    fclose(arq);
}

void exibirEstoque(char nome_do_arquivo[]) {
    FILE *arq = fopen(nome_do_arquivo, "rb");
    Produto produto;

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    while (fread(&produto, sizeof(Produto), 1, arq)) {
        printf("Codigo: %d\nDescricao: %s\nQuantidade: %d\n\n", produto.codigo, produto.descricao, produto.quantidade);
    }

    fclose(arq);
}