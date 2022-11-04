#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "agenciabancaria.h"
#include "contabancaria.h"



struct agenciabancaria{

    char nome[10];
    int codigo;
    char localizacao[10];
    Lista *conta;
    int numero_do_cliente;
    unsigned int hora_de_funcionamento[10]; 
    
};

typedef struct lista{

ContaBancaria *info;

struct lista *prox;

}Lista;
 

void cadastro(AgenciaBancaria *dados, Lista* l){

    Lista* conta = (Lista*) malloc(sizeof(Lista));

    conta -> info = adc_conta();
    conta -> prox = l;
    dados -> conta = conta;

    if (dados == NULL){
        printf("Erro ao alocar memoria");

        exit(1);
    }

    printf("Por favor, insira o nome do cliente: ");
    scanf("%s", dados->nome);
    printf("Por favor, insira o codigo do cliente: ");
    scanf("%d", dados->codigo);
    printf("Por favor, insira a localizacao da agencia: ");
    scanf("%s", dados->localizacao);
    printf("Por favor, insira o numero do cliente: ");
    scanf("%d", dados->numero_do_cliente);
    printf("Por favor, insira o hoarario de funcionamento da agencia: ");
    scanf("%d", dados->hora_de_funcionamento);
   
   FILE *arq = fopen("agenciabancariaEntrada.txt", "w");
    if(arq == NULL){
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
    fprintf(arq, "Nome: %s\n Codigo: %d\n Localizacao: %s\n Conta: %d\n Numero do cliente: %d\n Hora de funcionamento: %s", dados->nome, dados->codigo, dados->localizacao, dados->conta, dados->numero_do_cliente, dados->hora_de_funcionamento);

    fclose(arq);


}
/*void carregaArquivo(char **nome, int *codigo, char** localizacao, int *conta, int **numero_do_cliente,  unsigned int hora_de_funcionamento){

}*/

void salvarArquivo(char **nome, int *codigo, char** localizacao, int *conta, int **numero_do_cliente,  unsigned int *hora_de_funcionamento, int cont){

    FILE *arq = fopen("agenciaabancariaEntrada.txt", "r");

    int i;

    for ( i = 0; i < cont; i++)
    {

        fscanf(arq, "%s\n %s\n  %s\n  %f\n %s\n  %d", nome[i], codigo[i], localizacao[i], conta[i], numero_do_cliente[i], hora_de_funcionamento[i]);

    }

    fclose(arq);

}

void remover_conta(AgenciaBancaria *conta, Lista* l){

    Lista* anterior = NULL; //ponteiro para elemento anterior
    Lista* p = l; //ponteiro para percorrer a lista
    while(p->info!=conta){//procurar na lista, guardando anterior
        if(p==NULL) //n entendi pq info n ta sendo compativel
                return conta;//n achou e retorna lista original
        anterior = p;
        p = p->prox;
        //verificar se achou o elemento
    }
    //retira o elemento
    if(anterior==NULL)
    //retira o elemento do inicio
    l=p->prox;

    else 
    //retira elemento do meio da lista
    anterior->prox = p->prox;
    free(p); //liberar memoria de p
    return l; //retorna l

}

void listar_contas_cadastradas(char* agenciabancaria, Lista* l){

    Lista*anterior;

    for(anterior=l; anterior!=NULL; anterior=anterior->prox){

        printf(" Info = %d\n", anterior->info);
    }

AgenciaBancaria* conta=(AgenciaBancaria*)malloc(sizeof(AgenciaBancaria));
    FILE *arq = fopen(agenciabancaria, "r");
    if(arq == NULL){

        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    while ( fscanf(arq, "%s %s %s %f %s %d", conta->nome, conta->codigo, conta->localizacao, conta->conta, conta->numero_do_cliente,conta->hora_de_funcionamento )!=EOF );
    {

        printf ("Nome: %s\n Codigo: %d\n Localizacao: %s\n Conta: %d\n Numero do cliente: %d\n Hora de funcionamento: %s", conta->nome, conta->codigo, conta->localizacao,conta->conta, conta->numero_do_cliente,conta->hora_de_funcionamento);
    
    }
        
    fclose(arq);

    }

void buscar_conta(float *conta, Lista* l){
    
    Lista* p;
    for(p=l; p!=NULL; p=p->prox){
            if(p->info == conta)
                return p;
    }

    return NULL;

}


/*void editar_conta(char agencia, char cliente, char data_de_abertura, float saldo, char status, int numero){
}

void consultar_conta_ativa(char agencia, char cliente, char data_de_abertura, float saldo, char status, int numero){


}

void consultar_quantitativo_de_agencias(char agencia, char cliente, char data_de_abertura, float saldo, char status, int numero){

}

void sair_conta(char agencia, char cliente, char data_de_abertura, float saldo, char status, int numero){


}*/





