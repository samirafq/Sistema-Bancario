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

 struct lista{

    AgenciaBancaria* conta;
    struct lista* prox;
};

void cadastro(AgenciaBancaria *dados, Lista* l){

    Lista* conta = (Lista*) malloc(sizeof(Lista));

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
   
   FILE *arq = fopen("agenciabancariaEntrada.txt", "a");
    if(arq == NULL){
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
    fprintf(arq, "Nome: %s\n Codigo: %d\n Localizacao: %s\n Conta: %d\n Numero do cliente: %d\n Hora de funcionamento: %s", dados->nome, dados->codigo, dados->localizacao, dados->conta, dados->numero_do_cliente, dados->hora_de_funcionamento);

    fclose(arq);


}

/*void remover_conta(AgenciaBancaria *conta, Lista* l){

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

}*/

Lista* buscar_conta(int elemento, Lista* l){

Lista * contador;

	for(contador=l; contador!=NULL; contador=contador->prox){
		if(contador->conta->numero_do_cliente == elemento)
			return contador;
	}

	return NULL;

}
    void imprime_agenciaconta(AgenciaBancaria* conta, Lista* l){

    Lista*contador;
   
    for(contador=l; contador!=NULL; contador=contador->prox){
        printf(" Conta = %i \n", contador->conta);
    }

    printf("\nNome %s \n", conta->nome);
    printf("\nCodigo %d \n", conta->codigo);
    printf("\nLocalizacao %s \n", conta->localizacao);
    printf("\nConta %d \n", conta->conta);
    printf("\nNumero do cliente %d \n", conta->numero_do_cliente);
    printf("\nHora de funcionamento %s \n", conta->hora_de_funcionamento);

}

/*void editar_conta(){
}

void consultar_conta_ativa(){


}

void consultar_quantitativo_de_agencias(){

}

void sair_conta(){


}*/





