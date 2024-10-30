#ifndef FUNC_CLIENTES_H
#define FUNC_CLIENTES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/struct_date.h"
#include "../headers/defines.h"

typedef struct 
{
    char cpf[TAM_CPF];
    char nome[TAM_EMAIL];
    Date data_nasc;
    char sexo[TAM_SEXO];
    float salario;
    char emails[QTD_MAX_EMAILS][TAM_EMAIL];
    char telefones[QTD_MAX_TELEFONES][TAM_TELEFONE];
    int qtd_emails;
    int qtd_telefones;
} Cliente;

void submenu_clientes();
int buscar_cliente();

#endif
