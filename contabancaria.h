typedef struct contabancaria ContaBancaria;
typedef struct lista Lista;

/*funcao que adiciona uma conta*/
ContaBancaria* adiciona_conta(void);

/*funcao de cria lista*/
Lista* cria_lista(void);

/*funcao que adiciona uma conta de lista*/
Lista *adicionar_conta_lista(ContaBancaria *conta_adicionar, Lista *lista_de_conta);

/*funcao da lista vazia*/
int conta_vazia(Lista* l);

/*funcao que remove a conta*/
Lista* remover_conta(Lista* l, int e);

/*funcao que imprime uma conta*/
void imprime_conta(ContaBancaria* conta);

/*funcao que imprime uma lista de contas*/
void imprime_lista_de_contas(Lista *contas_lista);

/*funcao que busca a conta*/
Lista* buscar_conta(int numero_da_conta, Lista* l);

/*funcao que edita a conta*/
void editar_conta(Lista *l);

/*funcao de consultar contas ativas*/
//void consultar_conta_ativa(Lista* l);

/*funcao de consultar a quantidade de agencias*/
void consultar_quantitativo_de_agencias(Lista* l);




