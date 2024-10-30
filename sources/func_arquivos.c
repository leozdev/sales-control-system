#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../headers/func_clientes.h"
#include "../headers/func_produtos.h"
#include "../headers/func_vendas.h"
#include "../headers/defines.h"

void salvar_clientes(Cliente *clientes, int qtd_clientes)
{
    FILE *arq = fopen(NOME_ARQ_CLIENTES, "wb");

    fwrite(&qtd_clientes, sizeof(int), 1, arq);

    int i, j, tamanho_email, tamanho_telefone;

    for (i = 0; i < qtd_clientes; i++) {
        
        Cliente *cliente = (clientes + i);

        fwrite(cliente->cpf, sizeof(cliente->cpf), 1, arq);
        fwrite(cliente->nome, sizeof(cliente->nome), 1, arq);
        fwrite(&cliente->data_nasc, sizeof(Date), 1, arq);
        fwrite(cliente->sexo, sizeof(cliente->sexo), 1, arq);
        fwrite(&cliente->salario, sizeof(float), 1, arq);
        fwrite(&cliente->qtd_emails, sizeof(int), 1, arq);

        for (j = 0; j < cliente->qtd_emails; j++) {
            tamanho_email = strlen(*(cliente->emails + j)) + 1;
            fwrite(&tamanho_email, sizeof(int), 1, arq);
            fwrite(*(cliente->emails + j), sizeof(char), tamanho_email, arq);
        }

        fwrite(&cliente->qtd_telefones, sizeof(int), 1, arq);

        for (j = 0; j < cliente->qtd_telefones; j++) {
            tamanho_telefone = strlen(*(cliente->telefones + j)) + 1;
            fwrite(&tamanho_telefone, sizeof(int), 1, arq);
            fwrite(*(cliente->telefones + j), sizeof(char), tamanho_telefone, arq);
        }
    }
    fclose(arq);
}

void carregar_clientes(Cliente *clientes, int *qtd_clientes)
{
    FILE *arq = fopen(NOME_ARQ_CLIENTES, "rb");

    if (arq == NULL) 
        return;

    fread(qtd_clientes, sizeof(int), 1, arq);
    
    int i, j, tamanho_email, tamanho_telefone;
    for (i = 0; i < *qtd_clientes; i++) {
        
        Cliente *cliente = (clientes + i);

        fread(cliente->cpf, sizeof(cliente->cpf), 1, arq);
        fread(cliente->nome, sizeof(cliente->nome), 1, arq);
        fread(&cliente->data_nasc, sizeof(Date), 1, arq);
        fread(cliente->sexo, sizeof(cliente->sexo), 1, arq);
        fread(&cliente->salario, sizeof(float), 1, arq);
        fread(&cliente->qtd_emails, sizeof(int), 1, arq);

        cliente->emails = malloc(cliente->qtd_emails * sizeof(char *));

        for (j = 0; j < cliente->qtd_emails; j++) {
            fread(&tamanho_email, sizeof(int), 1, arq);

            *(cliente->emails + j) = malloc(tamanho_email * sizeof(char));
            fread(*(cliente->emails + j), sizeof(char), tamanho_email, arq);
        }

        fread(&cliente->qtd_telefones, sizeof(int), 1, arq);
        cliente->telefones = malloc(cliente->qtd_telefones * sizeof(char *));

        for (j = 0; j < cliente->qtd_telefones; j++) {
            fread(&tamanho_telefone, sizeof(int), 1, arq);

            *(cliente->telefones + j) = malloc(tamanho_telefone * sizeof(char));
            fread(*(cliente->telefones + j), sizeof(char), tamanho_telefone, arq);
        }
    }
    fclose(arq);
}

void salvar_produtos(Produto *produtos, int qtd_produtos)
{
    FILE *arq = fopen(NOME_ARQ_PRODUTOS, "wb");

    fwrite(&qtd_produtos, sizeof(int), 1, arq);
    fwrite(produtos, sizeof(Produto), qtd_produtos, arq);
    fclose(arq);
}

void carregar_produtos(Produto *produtos, int *qtd_produtos)
{
    FILE *arq = fopen(NOME_ARQ_PRODUTOS, "rb");

    if (arq == NULL) 
        return;

    fread(qtd_produtos, sizeof(int), 1, arq);
    fread(produtos, sizeof(Produto), *qtd_produtos, arq);
    fclose(arq);
}

void salvar_vendas(Venda *vendas, int qtd_vendas)
{
    FILE *arq = fopen(NOME_ARQ_VENDAS, "wb");

    fwrite(&qtd_vendas, sizeof(int), 1, arq);
    fwrite(vendas, sizeof(Venda), qtd_vendas, arq);
    fclose(arq);
}

void carregar_vendas(Venda *vendas, int *qtd_vendas)
{
    FILE *arq = fopen(NOME_ARQ_VENDAS, "rb");

    fread(qtd_vendas, sizeof(int), 1, arq);
    fread(vendas, sizeof(Venda), *qtd_vendas, arq);
    fclose(arq);
}