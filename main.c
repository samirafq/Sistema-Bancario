#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <windows.h>
//#include "agenciabancaria.c"
#include "contabancaria.c"

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
                
                ContaBancaria* conta = adicionar_conta();
                       
                break;

            case OPCAO2:

                Beep(1000,500);

                printf("Remover conta\n");
                
                break;

            case OPCAO3:

                Beep(1000,500);

                imprime_conta(conta);
                imprime_agenciaconta(conta);
               
                break;

            case OPCAO4:

                Beep(1000,500);
               
                //ContaBancaria* conta = buscar_conta(conta);
                //AgenciaBancaria* conta = buscar_conta(conta);

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

                printf("Sair\n");

            default:

                printf("Opcao invalida!");

                return 1;
        }

    } while(!saida);

    return 0;

}