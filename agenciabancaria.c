#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "AgenciaBancaria.h"



struct agenciabancaria{

    char nome[60];
    int codigo;
    char localizacao[60];
    int conta;
    int numero_do_cliente;
    char hora_de_funcionamento[50]; 
    
};


struct lista{

AgenciaBancaria info;

struct lista *prox;

}Lista;
 

AgenciaBancaria* adc_conta(AgenciaBancaria* dados){
    

AgenciaBancaria* agencia = (AgenciaBancaria*) malloc(sizeof(AgenciaBancaria));
    
    if (agencia == NULL){
        printf("Erro ao alocar memoria");

        exit(1);
    }

    printf("Por favor, insira o nome do cliente: ");
    scanf("%s", agencia->nome);
    printf("Por favor, insira o codigo do cliente: ");
    scanf("%d", agencia->codigo);
    printf("Por favor, insira a localizacao da agencia: ");
    scanf("%s", agencia->localizacao);
    printf("Por favor, insira a conta do cliente: ");
    scanf("%d", agencia->conta);
    printf("Por favor, insira o numero do cliente: ");
    scanf("%d", agencia->numero_do_cliente);
    printf("Por favor, insira o hoarario de funcionamento da agencia: ");
    scanf("%s", agencia->hora_de_funcionamento);

     FILE *arq;

    arq = fopen("agenciabancaria.txt", "a"); //
    if(arq == NULL){ //
        printf("Erro ao abrir o arquivo"); //
        exit(1);
    }
    fprintf(arq, "Nome: %s\n Codigo: %d\n Localizacao: %s\n Conta: %d\n Numero_do_cliente: %d\n Hora_de_funcionamento: %s", agencia->nome, agencia->codigo, agencia->localizacao, agencia->numero_do_cliente, agencia->hora_de_funcionamento);
    //para ler e imprimir 
    fclose(arq); //fechar o arquivo

    return agencia;

   
}


