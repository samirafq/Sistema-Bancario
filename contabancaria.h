typedef struct contabancaria ContaBancaria;
typedef struct lista Lista;

/*funcao que adiciona uma conta*/
ContaBancaria* adiciona_conta(void);

/*funcao que adiciona uma conta de lista*/
Lista *adicionar_conta_lista(ContaBancaria *conta_adicionar, Lista *lista_de_conta);

/*funcao que remove a conta*/
//void remover_conta(ContaBancaria *conta);

/*funcao que imprime uma conta*/
void imprime_conta(ContaBancaria* conta);

/*funcao que imprime uma lista de contas*/
void imprime_lista_de_contas(Lista *contas_lista);

/*funcao que busca a conta*/
Lista* buscar_conta(int numero_da_conta, Lista* l);

/*Lista* consultar_conta_ativa(int elemento, Lista* l);
void consultar_quantitativo_de_agencias(char agencia, char cliente, char data_de_abertura, float saldo, char status, int numeroa);
void sair_conta(char agencia, char cliente, char data_de_abertura, float saldo, char status, int numero);
void salvarArquivo(char **agencia, char *cliente, char** data_de_abertura, float *saldo, char **status, unsigned int* numero, int cont);*/
