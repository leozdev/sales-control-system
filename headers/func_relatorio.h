#ifndef FUNC_RELATORIO_H
#define FUNC_RELATORIO_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../headers/func_clientes.h"
#include "../headers/func_produtos.h"
#include "../headers/func_vendas.h"
#include "../headers/struct_date.h"

typedef struct
{
    int x_telefones;
    Cliente clientes[TOTAL_CLIENTES];
    int qtd_clientes_relatorio;
} Relatorio_telefones;

typedef struct
{
    Produto produtos[TOTAL_PRODUTOS];
    Date data_atual;
    int qtd_produtos_relatorio;
} Relatorio_validade;

typedef struct
{
    Cliente clientes[TOTAL_CLIENTES];
    Produto produtos[TOTAL_PRODUTOS];
    Venda vendas[TOTAL_VENDAS];
    Date data_incio;
    Date data_fim;
    int qtd_vendas_relatorio;
} Relatorio_periodo;

void submenu_relatorios();

#endif
