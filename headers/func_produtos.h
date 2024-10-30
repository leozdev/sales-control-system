#ifndef FUNC_PRODUTOS_H
#define FUNC_PRODUTOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/struct_date.h"
#include "../headers/defines.h"

typedef struct 
{
    char codigo[TAM_CODIGO], descricao[TAM_DESCRICAO];
    float tamanho, peso, altura, largura, preco, desconto;
    Date data_validade;
} Produto;

void submenu_produtos();
int buscar_produto();

#endif
