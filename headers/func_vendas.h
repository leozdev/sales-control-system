#ifndef FUNC_VENDAS_H
#define FUNC_VENDAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/func_clientes.h"
#include "../headers/func_produtos.h"
#include "../headers/struct_date.h"
#include "../headers/defines.h"

typedef struct 
{
    char cpf_cliente[TAM_CPF], codigo_produto[TAM_CODIGO];
    Date data_venda;
    Hora hora_venda;
    float valor_venda;
} Venda;

void submenu_vendas();

#endif
