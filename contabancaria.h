typedef struct contabancaria ContaBancaria;
ContaBancaria* adc_conta(char* contabancaria);
ContaBancaria* remover_conta(ContaBancaria *conta);
ContaBancaria* listar_contas_cadastradas(ContaBancaria *conta);
ContaBancaria* buscar_conta(ContaBancaria *conta);
ContaBancaria* editar_conta(ContaBancaria *conta);
ContaBancaria* consultar_conta_ativa(ContaBancaria *conta);
ContaBancaria* consultar_quantitativo_de_agencias(ContaBancaria *conta);
ContaBancaria* sair_conta(ContaBancaria *conta);