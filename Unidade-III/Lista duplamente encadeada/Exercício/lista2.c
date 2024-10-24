//todos os nos tem um ponteiro para o proximo, que tem um ponteiro para o proximo e para o anterior
#include "lista2.h"
#include <stdio.h>
#include <stdlib.h>
struct lista2{
    int info; 
    struct lista2* ant;
    struct lista2* prox;
};

Lista2* lst2_insere(Lista2* l, int v){
    Lista2* novo = (Lista2*)malloc(sizeof(Lista2));
    novo->info = v;
    novo->prox = l;
    novo->ant = NULL;
    //verifica se a lista nao esta vazia
    if(l != NULL)
        l->ant = novo;
        return novo;
    
}

//busca um elemento na lista
Lista2* lst2_busca(Lista2* l, int v){
    Lista2* p;
    for(p=l; p!=NULL; p=p->prox)
        if(p->info == v)
            return p;
    return NULL; //nao achou o elemento
}

//funcao que retira um elemento da lista
Lista2* lst2_retira(Lista2* l, int v){
    Lista2* p = lst2_busca(l,v);
    if(p == NULL)
        return l;

    if(l == p) //testa se Ã© o primeiro elemento
        l = p->prox;
    else
        p->ant->prox = p->prox; //se esta no final da lista

    if(p->prox !=NULL) //testa se esta no meio
        p->prox->ant = p->ant;

    free(p);
    return l;
}

