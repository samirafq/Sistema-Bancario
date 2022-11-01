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

ContaBancaria* adc_conta(char agencia, char cliente, char data_de_abertura, float saldo, char status, unsigned int numero){

ContaBancaria *conta;
    conta = (ContaBancaria *) malloc(sizeof(ContaBancaria));
    if (conta == NULL){
        printf("Erro ao alocar memoria");
        exit(1);
    }
    printf("Por favor, insira a agencia do cliente: ");
    scanf("%s", conta->agencia);
    printf("Por favor, insira o nome do cliente: ");
    scanf("%s", conta->cliente);
    printf("Por favor, insira a data da abertura da conta: ");
    scanf("%s", conta->data_de_abertura);
    printf("Por favor, insira o saldo da conta: ");
    scanf("%f", &conta->saldo);
    printf("Por favor, insira o status da sua conta: ");
    scanf("%s", conta->status);
    printf("Por favor, insira o numero da conta: ");
    scanf("%d", &conta->numero);

    FILE *arq;
    arq = fopen("contabancariaEntrada.txt", "w");
    if(arq == NULL){
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
    fprintf(arq, "Agencia: %s\n Cliente: %s\n Data de Abertura: %s\n Saldo: %f\n Status: %s\n Numero: %d", conta->cliente, conta->data_de_abertura, conta->saldo, conta->status, conta->numero);

    fclose(arq);

    return conta;

}
/*void carregaArquivo(char agencia, char cliente, char data_de_abertura, float saldo, char status, int numero){

}*/

void salvarArquivo(char **agencia, char *cliente, char** data_de_abertura, float *saldo, char **status, unsigned int* numero, int cont){

    FILE *arq = fopen("contabancariaEntrada.txt", "r");
    int i;

    for ( i = 0; i < cont; i++)
    {
        fscanf(arq, "%s\n %s\n  %s\n  %f\n %s\n  %d", agencia[i], cliente[i], data_de_abertura[i], saldo[i], numero[i]);
    }
    fclose(arq);

}


void remover_conta(ContaBancaria *conta){

    free(conta);

}

void listar_contas_cadastradas(char* contabancaria){

ContaBancaria* conta;
    FILE *arq = fopen(contabancaria, "r");
    if(arq == NULL){
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    fscanf(arq, "%s %s %s %f %s %d", conta->agencia, conta->cliente, conta->data_de_abertura, conta->saldo, conta->status, conta->numero);
    printf ("Agencia: %s\n Cliente: %s\n Data de Abertura: %s\n Saldo: %f\n Status: %s\n Numero: %d", conta->cliente, conta->data_de_abertura, conta->saldo, conta->status, conta->numero);
    
    fclose(conta);

    }

void buscar_conta(char *agencia, char cliente, char data_de_abertura, float saldo, char status, int numero){
    
    int d, inicio, meio, final;
    inicio = 0;
    final = cliente - 1;

    while(inicio <= final){
        meio = (inicio + final)/2;
        if(data_de_abertura < agencia[meio]);
                final = meio - 1;

        else 

        if(data_de_abertura > agencia[meio])
                inicio = meio + 1;
        else

            return meio;
    }
     return - 1;
}


void editar_conta(char agencia, char cliente, char data_de_abertura, float saldo, char status, int numero){


}

void consultar_conta_ativa(char agencia, char cliente, char data_de_abertura, float saldo, char status, int numero){


}

void consultar_quantitativo_de_agencias(char agencia, char cliente, char data_de_abertura, float saldo, char status, int numero){

}

void sair_conta(char agencia, char cliente, char data_de_abertura, float saldo, char status, int numero){


}


