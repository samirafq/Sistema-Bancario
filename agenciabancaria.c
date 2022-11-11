#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contabancaria.h"
#include "agenciabancaria.h"

struct agenciabancaria
{

    char nome[10];
    int codigo;
    char localizacao[10];
    Lista *lista_de_conta_da_agencia;
    char hora_de_funcionamento[10];
    int numero_do_cliente;
};
