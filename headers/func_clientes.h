#ifndef FUNC_CLIENTES_H
#define FUNC_CLIENTES_H

#include "../headers/struct_date.h"

typedef struct 
{
    char cpf[12];
    char nome[100];
    Date data_nasc;
    char sexo[10];
    float salario;
    char **emails;
    char **telefones;
    int qtd_emails;
    int qtd_telefones;
} Cliente;

void submenu_clientes();
int buscar_cliente();

#endif
