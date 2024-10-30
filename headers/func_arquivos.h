#ifndef FUNC_ARQUIVOS_H
#define FUNC_ARQUIVOS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../headers/func_clientes.h"
#include "../headers/func_produtos.h"
#include "../headers/func_vendas.h"
#include "../headers/func_relatorio.h"
#include "../headers/defines.h"

void salvar_clientes();
void carregar_clientes();
void salvar_produtos();
void carregar_produtos();
void salvar_vendas();
void carregar_vendas();
void salvar_relatorio_x_telefones();
void salvar_relatorio_prod_vencido();
void salvar_relatorio_vendas_periodo();

#endif