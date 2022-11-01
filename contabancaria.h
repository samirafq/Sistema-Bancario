typedef struct contabancaria ContaBancaria;
ContaBancaria* adc_conta(char agencia, char cliente, char data_de_abertura, float saldo, char status, int numero);
void remover_conta(ContaBancaria *conta);
void listar_contas_cadastradas(char* contabancaria);
void buscar_conta(char agencia, char cliente, char data_de_abertura, float saldo, char status, int numero);
void consultar_conta_ativa(char agencia, char cliente, char data_de_abertura, float saldo, char status, int numeroa);
void consultar_quantitativo_de_agencias(char agencia, char cliente, char data_de_abertura, float saldo, char status, int numeroa);
void sair_conta(char agencia, char cliente, char data_de_abertura, float saldo, char status, int numero);
void salvarArquivo(char **agencia, char *cliente, char** data_de_abertura, float *saldo, char **status, unsigned int* numero, int cont);
