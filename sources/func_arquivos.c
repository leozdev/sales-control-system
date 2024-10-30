#include "../headers/func_arquivos.h"

void salvar_clientes(Cliente *clientes, int qtd_clientes)
{
    FILE *arq = fopen(NOME_ARQ_CLIENTES, "wb");

    fwrite(&qtd_clientes, sizeof(int), 1, arq);
    fwrite(clientes, sizeof(Cliente), qtd_clientes, arq);
    fclose(arq);
}

void carregar_clientes(Cliente *clientes, int *qtd_clientes)
{
    FILE *arq = fopen(NOME_ARQ_CLIENTES, "rb");

    if (arq == NULL) 
        return;

    fread(qtd_clientes, sizeof(int), 1, arq);
    fread(clientes, sizeof(Cliente), *qtd_clientes, arq);
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