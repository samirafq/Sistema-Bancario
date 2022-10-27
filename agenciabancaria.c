#include<stdio.h>
#include<stdlib.h>
#include "AgenciaBancaria.h"



struct agenciabancaria{

    char nome[60];
    int codigo;
    char localizacao[60];
    int conta;
    int numero_do_cliente;
    char hora_de_funcionamento[50];
    struct agenciabancaria*prox;
    
};
 

AgenciaBancaria* adc_conta(AgenciaBancaria* dados){

AgenciaBancaria* agencia = (AgenciaBancaria*) malloc(sizeof(AgenciaBancaria));

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

    /*TESTE DE NOVO*/
   
}


