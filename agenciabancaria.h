typedef struct agenciabancaria AgenciaBancaria;
typedef struct lista Lista;
Lista *adicionar_conta_lista(ContaBancaria *conta_adicionar, Lista * lista_de_conta);
void imprime_agenciaconta(Lista* contas_lista);
Lista* buscar_conta(int elemento, Lista* l);
/*void imprime_agenciaconta(AgenciaBancaria* conta);
void remover_conta(AgenciaBancaria *conta, Lista* l);
void editar_conta(AgenciaBancaria *dados);
void consultar_conta_ativa(char ativa, Lista* l);
void consultar_quantitativo_de_agencias(AgenciaBancaria *dados);
void sair_conta(AgenciaBancaria dados);*/