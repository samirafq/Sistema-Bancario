#include<stdio.h>
#include<stdlib.h>
#include "Agencia Bancaria.h"



struct agenciabancaria{

    char nome[60];
    char codigo;
    char conta;
    char nummero_do_cliente;
    char hora_de_funcionamento;
    struct agenciabancaria*prox;
    
};


AgenciaBancaria* adc_conta(AgenciaBancaria* dados){

AgenciaBancaria* novo = (AgenciaBancaria*) malloc(sizeof(AgenciaBancaria));

    printf("Digite o nome do cliente: ");
    scanf("%s", dados->nome);
    printf("Digite o codigo do cliente: ");
    scanf("%s", dados->codigo);
    printf("Digite a conta do cliente: ");
    scanf("%s", dados->conta);
    printf("Digite o numero do cliente: ");
    scanf("%s", dados->numero_do_cliente);
    printf("Digite o hoarario de funcionamento: ");
    scanf("%s", dados->hora_de_funcionamento);

}
