#ifndef FUNC_VENDAS_H
#define FUNC_VENDAS_H

#include "../headers/struct_date.h"

typedef struct 
{
    char cpf_cliente[12], codigo_produto[20];
    Date data_venda;
    Hora hora_venda;
    float valor_venda;
} Venda;

void submenu_vendas();

#endif
