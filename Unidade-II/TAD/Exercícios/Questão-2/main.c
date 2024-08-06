#include <stdio.h>
#include "disciplina.h"
#include "aluno.h"

int main(void) {
    Disciplina* d1 = cria_disciplina("Matemática", 101);
    Disciplina* d2 = cria_disciplina("Física", 102);

    Aluno* a1 = cria_aluno("João", 12345);
    matricula_disciplina(a1, d1);
    matricula_disciplina(a1, d2);

    exibe_aluno(a1);

    exclui_disciplina(d1);
    exclui_disciplina(d2);
    exclui_aluno(a1);

    return 0;
}