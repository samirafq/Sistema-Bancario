#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenciabancaria.h"
#include "contabancaria.h"


struct agenciabancaria
{

    char nome[10];
    int codigo;
    char localizacao[10];
    Lista * lista_de_conta_da_agencia;
    char hora_de_funcionamento[10];
    int numero_do_cliente;
};

struct lista{

    ContaBancaria *conta;
    struct lista *prox;
};

Lista *adicionar_conta_lista(ContaBancaria *conta_adicionar, Lista * lista_de_conta){

    Lista* nova_conta =(Lista*) malloc(sizeof(Lista));
    nova_conta->conta = conta_adicionar;
    nova_conta->prox = lista_de_conta;
    return nova_conta;
}


    void imprime_agenciaconta(Lista* contas_lista){

        Lista* contador;
        for(contador=contas_lista;contador!=NULL; contador=contador->prox){
            imprime_conta(contas_lista->conta);
        }
       

    }

    Lista* buscar_conta(int elemento, Lista* l){

    Lista * contador;

	for(contador=l; contador!=NULL; contador=contador->prox){
		if(contador->conta->numero_do_cliente == elemento);
			return contador;
	}

	return NULL;

    }


    /*void editar_conta(){
    }

    void consultar_conta_ativa(){


    }

    void consultar_quantitativo_de_agencias(){

    }

    /*void remover_conta(AgenciaBancaria * conta, Lista * l)
    {

        Lista *anterior = NULL; // ponteiro para elemento anterior
        Lista *p = l;           // ponteiro para percorrer a lista
        while (p->prox != conta)
        {                     // procurar na lista, guardando anterior
            if (p == NULL)    // n entendi pq info n ta sendo compativel
                return conta; // n achou e retorna lista original
            anterior = p;
            p = p->prox;
            // verificar se achou o elemento
        }
        // retira o elemento
        if (anterior == NULL)
            // retira o elemento do inicio
            l = p->prox;

        else
            // retira elemento do meio da lista
            anterior->prox = p->prox;
        free(p);  // liberar memoria de p
        return l; // retorna l
    }*/

    //void sair_conta(){


    //}
