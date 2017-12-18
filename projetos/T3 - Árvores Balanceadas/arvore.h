#define red 0 // cores da arvore rubro negra
#define black 1

typedef struct _no{	// cada nó possui
	int item;		// um item
	struct _no* pai;	// ponteiros para o pai, e seus filhos
	struct _no* esq;
	struct _no* dir;
	int cor; // cor
}no;


typedef struct _arvore{ 
	no* raiz;
}arvore;

void inicia(arvore** tree); // malloc struct arvore
void cria_no(no **raiz, int item, no* pai); // cria o nó com os atributos padrões
void insere(arvore* tree, int item); //insere na posição correta seguindo o conceito de arvores binárias e chama o balanceamento
void pre_ordem(no* raiz); // impressão pré ordem
void em_ordem(no * raiz); // impressão em ordem
void pos_ordem(no * raiz); // impressão pós ordem
void visita(no *raiz); // imprime o item do nó
void arruma_rb(arvore* tree, no* novo); // efetua o balanceamento seguindo as regras de arvores rubro negra
void rotacao_esq(arvore* tree, no* atual); // rotação de um nó para esquerda
void rotacao_dir(arvore* tree, no* atual);	// rotação de um nó para direita
void max(arvore *tree); // acha o nó de maior número
void min(arvore *tree);	// acha o nó de menor número
no* busca(no* raiz, int item); // busca um nó que contém o item
void sucessor(arvore *tree, int k); // acha um numero maior que k, menor possível
void predecessor(arvore *tree, int k); // acha um numero menor que k, maior possível
void free_tree(arvore* tree); // libera a memória da struct arvore
void pos_ordem_free(no * raiz); // libera a memória dos nós