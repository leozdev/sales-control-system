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
    Cliente *cliente;
    int x_telefones;
} Relatorio_telefones;

typedef struct
{
    Produto *produto;
    Date data_atual;
} Relatorio_validade;

typedef struct
{
    Cliente *cliente;
    Produto *produto;
    Venda *venda;
    Date data_incio;
    Date data_fim;
} Relatorio_periodo;

void submenu_relatorios();

#endif
