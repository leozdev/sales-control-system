#ifndef FUNC_PRODUTOS_H
#define FUNC_PRODUTOS_H

#include "../headers/struct_date.h"

typedef struct 
{
    char codigo[20], descricao[100];
    float tamanho, peso, altura, largura, preco, desconto;
    Date data_validade;
} Produto;

void submenu_produtos();
int buscar_produto();

#endif
