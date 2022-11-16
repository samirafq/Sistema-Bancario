#include <stdio.h>
#include <stdlib.h>
#include "contabancaria.h"
#include "agenciabancaria.h"

struct contabancaria{

    char agencia [60];
    char cliente [60];
    char data_de_abertura [60];
    float saldo;
    char status [60];
    int numero;
};

struct lista{

    ContaBancaria *conta;
    struct lista *prox;

};

ContaBancaria* adiciona_conta(void){
    
    ContaBancaria *conta = (ContaBancaria *) malloc(sizeof(ContaBancaria));
     
    if (conta == NULL){
        printf("Erro ao alocar memoria");
        exit(1);
    }
    printf("\nPor favor, insira a agencia do cliente:\n ");
    scanf("%s", conta->agencia);
    printf("\nPor favor, insira o nome do cliente:\n ");
    scanf("%s", conta->cliente);
    printf("\nPor favor, insira a data da abertura da conta:\n ");
    scanf("%s", conta->data_de_abertura);
    printf("\nPor favor, insira o saldo da conta:\n ");
    scanf("%f", &conta->saldo);
    printf("\nPor favor, insira o status da sua conta:\n ");
    scanf("%s", conta->status);
    printf("\nPor favor, insira o numero da conta:\n ");
    scanf("%d", &conta->numero);

   FILE *arq = fopen("contabancariaEntrada.txt", "a");
    if(arq == NULL){
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
    fprintf(arq, "Agencia: %s\n Cliente: %s\n Data de Abertura: %s\n Saldo: %f\n Status: %s\n Numero: %d", conta->agencia, conta->cliente, conta->data_de_abertura, conta->saldo, conta->status, conta->numero);

    fclose(arq);
    
    return conta;
}


Lista *adicionar_conta_lista(ContaBancaria *conta_adicionar, Lista *lista_de_conta)
{

    Lista *nova_conta = (Lista *)malloc(sizeof(Lista));
    nova_conta->conta = conta_adicionar;
    nova_conta->prox = lista_de_conta;
    return nova_conta;
}


void imprime_conta(ContaBancaria* conta){

    printf("Agencia: %s\n", conta->agencia);
    printf("Cliente: %s\n", conta->cliente);
    printf("Data de abertura: %s \n", conta->data_de_abertura);
    printf("Status: %s\n", conta->status);
    printf("Saldo: %f\n", conta->saldo);
    printf("Numero: %i\n", conta->numero);


}

void imprime_lista_de_contas(Lista *contas_lista)
{

    Lista *contador;
    for (contador = contas_lista; contador != NULL; contador = contador->prox)
    {
        imprime_conta(contas_lista->conta);
    }
}

Lista *buscar_conta(int numero_da_conta, Lista *l)
{

    Lista *contador_lista;

    for (contador_lista = l; contador_lista != NULL; contador_lista = contador_lista->prox)
    {
        if (contador_lista->conta->numero == numero_da_conta);
        return contador_lista;
    }

    return NULL;
}

void editar_conta(Lista* list_de_cont, int numero_de_conta){
    
    char nova_agencia [60];
    char novo_cliente [60];
    char nova_data_de_abertura [60];
    float novo_saldo;
    char novo_status [60];
    int novo_numero;

    Lista* cont = buscar_conta(list_de_cont, numero_de_conta);
    printf("Insira a nova agencia do cliente: ");
    scanf("%s", nova_agencia);
    cont->conta->agencia=nova_agencia;
    printf("Insira o novo nome do cliente: ");
    scanf("%s", novo_cliente);
    cont->conta->cliente=novo_cliente;
    printf("Insira a nova data de abertura do cliente: ");
    scanf("%s", nova_data_de_abertura);
    cont->conta->data_de_abertura=nova_data_de_abertura;
    printf("Insira o novo saldo do cliente: ");
    scanf("%f", novo_saldo);
    cont->conta->saldo=novo_saldo;
    printf("Insira o novo status do cliente: ");
    scanf("%s", novo_status);
    cont->conta->status=novo_status;
    printf("Insira o novo numero do cliente: ");
    scanf("%d", novo_numero);
    cont->conta->numero=novo_numero;
    
}
    

/*Lista* consultar_conta_ativa(int elemento, Lista* l){

Lista * contador;

	for(contador=l; contador!=NULL; contador=contador->prox){
		if(contador->conta->numero == elemento)
			return contador;
	}

	return NULL;

}*/


/*void consultar_quantitativo_de_agencias(){

}*/

Lista* remover_conta(Lista* lista_das_contas, int l){

    Lista* anterior = NULL;
    Lista* ponteiro = lista_das_contas;

    while(ponteiro->conta->numero!=l){
        if(ponteiro==NULL)
                return lista_das_contas;
    }

    if(anterior==NULL)

        lista_das_contas = ponteiro->prox;

    else

        anterior->prox = ponteiro->prox;
        
            free(ponteiro);

    return lista_das_contas;

}

