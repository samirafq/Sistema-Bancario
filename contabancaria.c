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

struct lista
{

    ContaBancaria *conta;
    struct lista *prox;
};

ContaBancaria* adiciona_conta(void){

ContaBancaria *conta;
    conta = (ContaBancaria *) malloc(sizeof(ContaBancaria));
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

    printf("\n Agencia: %s\n", conta->agencia);
    printf("\n Cliente: %s\n", conta->cliente);
    printf("\n Data de abertura: %s \n", conta->data_de_abertura);
    printf("\n Status: %s\n", conta->status);
    printf("\n Saldo: %f\n", conta->saldo);
    printf("\n Numero: %i\n", conta->numero);


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

void imprime_lista_de_contas(Lista *contas_lista)
{

    Lista *contador;
    for (contador = contas_lista; contador != NULL; contador = contador->prox)
    {
        imprime_conta(contas_lista->conta);
    }
}





/*void editar_conta(){
    
}*/

/*Lista* consultar_conta_ativa(int elemento, Lista* l){

Lista * contador;

	for(contador=l; contador!=NULL; contador=contador->prox){
		if(contador->conta->numero == elemento)
			return contador;
	}

	return NULL;

}*/


/*void consultar_quantitativo_de_agencias(){

}

void remover_conta(ContaBancaria *conta){

    free(conta);

}

void sair_conta(Lista* l){




}*/
