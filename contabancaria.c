#include <stdio.h>
#include <stdlib.h>
#include "contabancaria.h"

struct contabancaria{

    char agencia [60];
    char cliente [60];
    char data_de_abertura [60];
    float saldo;
    char status [60];
   unsigned int numero;
};
struct lista{

    ContaBancaria* conta;
    struct lista*prox;
};

ContaBancaria* adicionar_conta(void){

ContaBancaria *conta;
    conta = (ContaBancaria *) malloc(sizeof(ContaBancaria));
    if (conta == NULL){
        printf("Erro ao alocar memoria");
        exit(1);
    }
    printf("Por favor, insira a agencia do cliente:\n ");
    scanf("%s", conta->agencia);
    printf("Por favor, insira o nome do cliente:\n ");
    scanf("%s", conta->cliente);
    printf("Por favor, insira a data da abertura da conta:\n ");
    scanf("%s", conta->data_de_abertura);
    printf("Por favor, insira o saldo da conta:\n ");
    scanf("%f", &conta->saldo);
    printf("Por favor, insira o status da sua conta:\n ");
    scanf("%s", conta->status);
    printf("Por favor, insira o numero da conta:\n ");
    scanf("%d", &conta->numero);

    FILE *arq = fopen("contabancariaEntrada.txt", "w");
    if(arq == NULL){
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
    fprintf(arq, "Agencia: %s\n Cliente: %s\n Data de Abertura: %s\n Saldo: %f\n Status: %s\n Numero: %d", conta->agencia, conta->cliente, conta->data_de_abertura, conta->saldo, conta->status, conta->numero);

    fclose(arq);
    
return conta;

}

void imprime_conta(ContaBancaria* conta){

    printf("Agencia %s \n", conta->agencia);
    printf("Cliente %s \n", conta->cliente);
    printf("Data de abertura %s \n", conta->data_de_abertura);
    printf("Status %s \n", conta->status);
    printf("Saldo %f \n", conta-> saldo);
    printf("Numero %i \n", conta-> numero);


}

   Lista* buscar_conta(int elemento, Lista* l){

Lista * contador;

	for(contador=l; contador!=NULL; contador=contador->prox){
		if(contador->conta->numero == elemento)
			return contador;
	}

	return NULL;

} 

/*void editar_conta(){
}

Lista* consultar_conta_ativa(int elemento, Lista* l){

Lista * contador;

	for(contador=l; contador!=NULL; contador=contador->prox){
		if(contador->conta->numero ==elemento)
			return contador;
	}

	return NULL;

}


void consultar_quantitativo_de_agencias(char agencia, char cliente, char data_de_abertura, float saldo, char status, int numero){

}

void remover_conta(ContaBancaria *conta){

    free(conta);

}

void sair_conta(char agencia, char cliente, char data_de_abertura, float saldo, char status, int numero){


}*/
