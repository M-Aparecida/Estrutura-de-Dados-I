
/*renomeia struct no para No*/
typedef struct no No;

/*insere numeros ineiros em uma lista encadeada*/
No * insere_int(No* lista, int numero);

/*imprime a lista encadeada*/
void imprime_int(No* lista);

/*libera a lista da memoria*/
void libera_int(No * lista);

/*faz a busca sequencial*/
No * busca_int(int numero, No* lista);

/*remove um elemento da lista*/
No * remove_int(No * lista, int numero);
