#include "aluno.h"

int main(void){
    No *lista = NULL;
    lista = adiciona_aluno_ordenado(lista, 100, "Pedro", 7.3);
    lista = adiciona_aluno_ordenado(lista, 103, "Lucas", 7.4);
    lista = adiciona_aluno_ordenado(lista, 102, "Matheus", 7.5);
    lista = adiciona_aluno_ordenado(lista, 101, "Anabel", 7.6);
    lista = adiciona_aluno_ordenado(lista, 104, "Maria", 7.7);
    imprime_alunos(lista);
    lista = remove_aluno(lista, 5);
    imprime_alunos(lista);
    libera_lista(lista);
    return 0;
}
