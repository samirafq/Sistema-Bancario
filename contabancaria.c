#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    printf("\nPor favor, insira o numero agencia do cliente:\n ");
    scanf(" %[^\n]", conta->agencia);
    printf("\nPor favor, insira o nome do cliente:\n ");
    scanf(" %[^\n]", conta->cliente);
    printf("\nPor favor, insira a data da abertura da conta:\n ");
    scanf(" %[^\n]", conta->data_de_abertura);
    printf("\nPor favor, insira o saldo da conta:\n ");
    scanf("%f", &conta->saldo);
    printf("\nPor favor, insira o status da sua conta:\n ");
    scanf(" %[^\n]", conta->status);
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
 Lista* cria_lista(void){

    return NULL; 
 }

Lista *adicionar_conta_lista(ContaBancaria *conta_adicionar, Lista *lista_de_conta)
{

    Lista *nova_conta = (Lista *)malloc(sizeof(Lista));
    nova_conta->conta = conta_adicionar;
    nova_conta->prox = lista_de_conta;
    return nova_conta;
}

int conta_vazia(Lista* l){
    return(l==NULL);
}

Lista* remover_conta(Lista* l, int elemento){

    Lista* anterior = NULL;
    Lista* ponteiro = l;

    while(ponteiro->conta->numero != elemento){
        if(ponteiro==NULL)
                return l;

                anterior = ponteiro;
                ponteiro = ponteiro->prox;
    }

    if(anterior==NULL)

        l = ponteiro->prox;

    else

        anterior->prox = ponteiro->prox;
        

      free(ponteiro);

    return l;

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
        if (contador_lista->conta->numero == numero_da_conta){
             return contador_lista;
        }
       
    }
    return NULL;
}

void editar_conta(Lista *l){

    int elemento = 0;
    
    printf("Insira o numero da conta anterior: ");
	scanf("%d", &elemento);

    Lista *ponteiro;
    for(ponteiro=l; ponteiro!=NULL; ponteiro=ponteiro->prox){
		if(ponteiro->conta->numero == elemento){

    printf("conta encontrada!\n");

    printf("Insira a nova agencia do cliente: ");
    scanf(" %[^\n]", ponteiro->conta->agencia);
    printf("Insira o novo nome do cliente: ");
    scanf(" %[^\n]", ponteiro->conta->cliente);
    printf("Insira a nova data de abertura do cliente: ");
    scanf(" %[^\n]", ponteiro->conta->data_de_abertura);
    printf("Insira o novo saldo do cliente: ");
    scanf("%f", &ponteiro->conta->saldo);
    printf("Insira o novo status do cliente: ");
    scanf(" %[^\n]", ponteiro->conta->status);
    printf("Insira o novo numero do cliente: ");
    scanf("%d", &ponteiro->conta->numero);

        }
   
    }
  
}

/*void consultar_conta_ativa(Lista* l){

	Lista* ponteiro;

	char agencia [60];
    char strucagencia[60];
    char cliente [60];
    char struccliente[60];
	

    int retorno_conta_1;
    int retorno_conta2;

    printf("Por gentileza, insira a conta que procura: ");
	scanf(" %[^\n]", agencia);
	printf("Por gentileza, insira o nome do cliente: ");
	scanf(" %[^\n]", cliente);

	for(ponteiro=l; ponteiro!=NULL; ponteiro=ponteiro->prox){

		strcpy(strucagencia, ponteiro->conta->agencia);
		retorno_conta_1 = strcmp(agencia, strucagencia);
		strcpy(struccliente, ponteiro->conta->cliente);
		retorno_conta2 = strcmp(cliente, struccliente);

		if(retorno_conta_1 == 0 && retorno_conta2 == 0){

			printf("Total de contas ativas: %d\n", ponteiro->conta->numero);

		}
	}
	

}*/

void consultar_quantitativo_de_agencias(Lista* l){

Lista* ponteiro;
int contador_de_lista = 0;

	for(ponteiro=l; ponteiro!=NULL; ponteiro=ponteiro->prox){
		contador_de_lista++;
			
	}

    printf("Quantidade de agencias disponiveis eh: %d\n", contador_de_lista);
	

}


