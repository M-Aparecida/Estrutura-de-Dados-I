#include <stdio.h>
#include <stdlib.h>

/*Uma empresa fez uma pesquisa para saber se as pessoas gostaram ou nÃ£o de um
 novo produto. Um numero N de pessoas de ambos os sexos foi entrevistado, e o questionario
 consistia em apenas duas perguntas: (i) o sexo do entrevistado (M/F) e (ii) sua opiniao sobre o
 produto (gostou/nao gostou). Escreva um programa em C que:
 a) leia as respostas contidas no questionario e armazene-as em dois arrays vinculados,
 um deles contendo a resposta para a primeira pergunta e o outro contendo a resposta
 para a segunda pergunta.
 b) determine a porcentagem de pessoas do sexo feminino que responderam que
 gostaram do produto.
 c) determine a porcentagem de pessoas do sexo masculino que responderam que nao
 gostaram do produto*/

int main(void) {
    int N;
    printf("Informe o numero de entrevistados: ");
    scanf("%d", &N);

    int total = 0; 
    int gostaram_feminino = 0; 
    int nao_gostaram_masculino = 0; 

    char sexo, opiniao;
    for (int i = 0; i < N; i++) {
        printf("Entrevistado %d:\n", i + 1);
        printf("Sexo (Masculino/Feminino): ");
        scanf(" %c", &sexo);
        printf("Opiniao (gostou ou nao gostou): ");
        scanf(" %c", &opiniao);

        total++;
        if (sexo == 'F' && opiniao == 'g') {
            gostaram_feminino++;
        } else if (sexo == 'M' && opiniao == 'n') {
            nao_gostaram_masculino++;
        }
    }

    int porcentagem_feminino = (gostaram_feminino * 100) / total;
    int porcentagem_masculino = (nao_gostaram_masculino * 100) / total;

    printf("\nResultados:\n");
    printf("Porcentagem de mulheres que gostaram: %d\n", porcentagem_feminino);
    printf("Porcentagem de homens que nao gostaram: %d\n", porcentagem_masculino);

    return 0;
}