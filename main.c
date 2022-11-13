#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <windows.h>
#include <string.h>
#include "contabancaria.c"
#include "agenciabancaria.c"


#define TITULO_OPCAO1 "Adicionar conta"
#define TITULO_OPCAO2 "Remover conta"
#define TITULO_OPCAO3 "Listar contas cadastradas"
#define TITULO_OPCAO4 "Buscar conta"
#define TITULO_OPCAO5 "Editar conta"
#define TITULO_OPCAO6 "Consultar contas ativas em uma agencia"
#define TITULO_OPCAO7 "Consultar quantitativo de agencias"
#define TITULO_OPCAO8 "Sair"


#define N_OPCOES 8
#define OPCAO1 '1'
#define OPCAO2 '2'
#define OPCAO3 '3'
#define OPCAO4 '4'
#define OPCAO5 '5'
#define OPCAO6 '6'
#define OPCAO7 '7'
#define OPCAO8 '8'



/****
* Função: LimpaBuffer()
* Descrição: Lê e descarta caracteres encontrados na entrada
* Parâmetros: Nenhum
* Retorno: Nada
****/
void LimpaBuffer(void) {
    int valorLido; /* valorLido deve ser int! */
    do {
        valorLido = getchar();
    } while ((valorLido != '\n') && (valorLido != EOF));
}
/****
* Função: LeOpcao()
* Descrição: Lê e valida a opção digitada pelo usuário
* Parâmetros:
*   menorValor (entrada): o menor valor válido
*   maiorValor (entrada): o maior valor válido
* Retorno: A opção lida é validada
****/
int LeOpcao(int menorValor, int maiorValor) {
    int op;
    while (1) {
        printf("\nDigite sua opcao: ");
        op = getchar();
        if (op >= menorValor && op <= maiorValor) {
            LimpaBuffer();
            break;
        }
        else {
            printf("\nOpcao invalida. Tente novamente.");
            printf("\nA opcao deve estar entre %c e %c. \n",
                   menorValor, maiorValor);
            LimpaBuffer();
        }
    }
    return op;
}

/****
* Função: ApresentaMenu
* Descrição: Apresenta menu com número indeterminado de opções
* Parâmetros:
*   nItens (entrada): número de itens no menu
*   menorOpcao (entrada): caractere associado ao item I
* Retorno: Nada
****/
void Menu(int nItens, int Opcao, ...) {
    int i;
    va_list argumentos;
    /* Inicia lista de argumentos variáveis */
    va_start(argumentos, Opcao);
    /* Lê cada argumento e imprime na tela. Note que o */
    /* tipo de cada argumento é char *, que é o tipo que */
    /* representa strings em C */
    for(i = 0; i < nItens; ++i) {
        printf("%c-%s\n", Opcao++, va_arg(argumentos, char *));
    }
    va_end(argumentos);/* Encerra processamento de argumentos */
}

int main(void) {
    
   Lista* listas_de_contas_total=NULL;
   int numero_conta_busca;
   Lista* remover_numero=NULL;
   int list;

    //alocacao da agencia

   /* AgenciaBancaria* banco_SAF=(AgenciaBancaria*) malloc(sizeof(AgenciaBancaria));

    strcpy(banco_SAF->nome, "Agencia Samira Aquino França");
    banco_SAF->codigo=1105;
    strcpy(banco_SAF->localizacao, "Avenida Brasil");
    banco_SAF->numero_do_cliente=0;
    strcpy(banco_SAF->hora_de_funcionamento, "Atendimento a partir das 08:00 as 17:00");*/

    unsigned char opcao;
    unsigned int saida = 0;

    do {
        Menu(N_OPCOES, OPCAO1,
                      TITULO_OPCAO1, TITULO_OPCAO2,
                      TITULO_OPCAO3, TITULO_OPCAO4, TITULO_OPCAO5, TITULO_OPCAO6, TITULO_OPCAO7, TITULO_OPCAO8);

        opcao = LeOpcao(OPCAO1, OPCAO1 + N_OPCOES - 1);
        
        switch(opcao){

            case OPCAO1:

                Beep(1000,500);
 
                //printf("testey");
                ContaBancaria* conta = adiciona_conta();
                listas_de_contas_total = adicionar_conta_lista(conta, listas_de_contas_total);
               // banco_SAF->lista_de_conta_da_agencia = listas_de_contas_total; 

                break;
                
            case OPCAO2:

                Beep(1000,500);

                printf("Conta removida com sucesso!\n");
                scanf("%d", &remover_numero);
                listas_de_contas_total = remover_conta(remover_numero, list);
                
                break;

            case OPCAO3:

                Beep(1000,500);

                imprime_conta(conta);
                imprime_lista_de_contas(listas_de_contas_total);
               
                break;

            case OPCAO4:

                Beep(1000,500);

               printf("Digite o numero da conta que deseja buscar: ");
               scanf("%d", &numero_conta_busca);
               listas_de_contas_total = buscar_conta(numero_conta_busca, listas_de_contas_total);
               imprime_conta(listas_de_contas_total->conta);
                
                break;

            case OPCAO5:

                Beep(1000,500);

                printf("Editar conta\n");

            case OPCAO6:

                Beep(1000,500);

                printf("Consultar contas ativas em uma dada agencia\n");

            case OPCAO7:

                Beep(1000,500);

                printf("Consultar quantitativo de agencias\n");

                case OPCAO8:
                
                Beep(1000,500);
                
                saida=1;
                printf("Saida liberada! Obrigada por ultilizar nosso programa! Ateciosamente, banco_SAF!\n");

            default:

                return 1;
        }

    } while(!saida);

    return 0;

}