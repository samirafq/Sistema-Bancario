typedef struct contabancaria ContaBancaria;
ContaBancaria* adc_conta(char* contabancaria);
void remover_conta(ContaBancaria *conta);
void listar_contas_cadastradas(char* ContaBancaria);
void buscar_conta(ContaBancaria *conta);
void editar_conta(ContaBancaria *conta);
void consultar_conta_ativa(ContaBancaria *conta);
void consultar_quantitativo_de_agencias(ContaBancaria *conta);
void sair_conta(ContaBancaria *conta);