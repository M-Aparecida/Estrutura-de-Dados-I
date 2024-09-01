/*renomeia struct produto Produto*/
typedef struct produto Produto;

/*função para criar um novo produto*/
Produto* criarProduto(int codigo, char descricao[], int quantidade);

/*função para adicionar um produto ao estoque*/
void adicionarProdutoAoEstoque(char nome_do_arquivo[], Produto *produto);

/*função para remover um produto do estoque com base no código*/
void removerProdutoDoEstoque(char nome_do_arquivo[], int codigo);

/*função para atualizar a quantidade em estoque de um produto*/
void atualizarQuantidadeNoEstoque(char nome_do_arquivo[], int codigo, int nova_quantidade);

/*função para exibir todos os produtos no estoque*/
void exibirEstoque(char nome_do_arquivo[]);