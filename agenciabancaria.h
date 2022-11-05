typedef struct agenciabancaria AgenciaBancaria;
typedef struct lista Lista;
void cadastro(AgenciaBancaria *dados, Lista* l);
Lista* buscar_conta(int elemento, Lista* l);
void imprime_agenciaconta(AgenciaBancaria* conta, Lista* l);
/*void remover_conta(AgenciaBancaria *conta, Lista* l);
void editar_conta(AgenciaBancaria *dados);
void consultar_conta_ativa(AgenciaBancaria *dados);
void consultar_quantitativo_de_agencias(AgenciaBancaria *dados);
void sair_conta(AgenciaBancaria dados);*/