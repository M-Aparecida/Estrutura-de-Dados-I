/*Arquivo cabeÃ§alho para tipo abstrato de dados (TAD) Aluno*/

/*Tipo exportado*/
typedef struct aluno Aluno;

/*Funcao que aloca dinamicamente uma struct aluno na memoria*/
Aluno * aloca_aluno(void);

/*Funcao para preencher uma struct Aluno. A funcao recebe um endereÃ§o para aluno*/
void preenche(Aluno * aluno);

/*Funcao para imprimir uma struct Aluno. A funcao recebe um endereÃ§o para aluno e imprime os dados*/
void imprime(Aluno * aluno);