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

    if (arq == NULL) 
        return;
        
    fread(qtd_vendas, sizeof(int), 1, arq);
    fread(vendas, sizeof(Venda), *qtd_vendas, arq);
    fclose(arq);
}

void salvar_relatorio_x_telefones(Relatorio_telefones *relatorio)
{
    FILE *arq = fopen(NOME_ARQ_RELATORIO_X_TELEFONES, "w");

    char buffer[100];

    sprintf(buffer, "------ Relatório de clientes que possuem mais de '%d' telefones ------\n", relatorio->x_telefones);
    fputs(buffer, arq);

    if (relatorio->qtd_clientes_relatorio < 1)
        fputs("\nNenhum cliente...", arq);
        

    int i, j;
    for (i = 0; i < relatorio->qtd_clientes_relatorio; i++) {
        Cliente *cliente = relatorio->clientes + i;

        sprintf(buffer, "\n\tCPF: %s\n", cliente->cpf);
        fputs(buffer, arq);

        sprintf(buffer, "\tNome: %s\n", cliente->nome);
        fputs(buffer, arq);

        sprintf(buffer, "\tData de nascimento: %02d/%02d/%02d\n", cliente->data_nasc.dia, cliente->data_nasc.mes, cliente->data_nasc.ano);
        fputs(buffer, arq);

        sprintf(buffer, "\tSexo: %s\n", cliente->sexo);
        fputs(buffer, arq);

        sprintf(buffer, "\tSalário: %2.f\n", cliente->salario);
        fputs(buffer, arq);

        sprintf(buffer, "\tEmails:\n");
        fputs(buffer, arq);
        for (j = 0; j < cliente->qtd_emails; j++) {
            sprintf(buffer, "\t\t%d. %s\n", j + 1, *(cliente->emails + j));
            fputs(buffer, arq);
        }

        sprintf(buffer, "\tTelefones:\n");
        fputs(buffer, arq);
        for (j = 0; j < cliente->qtd_telefones; j++) {
            sprintf(buffer, "\t\t%d. %s\n", j + 1, *(cliente->telefones + j));
            fputs(buffer, arq);
        }

        fputs("\n-------------------------\n", arq);
    }
    fclose(arq);
}

void salvar_relatorio_prod_vencido(Relatorio_validade *relatorio)
{
    FILE *arq = fopen(NOME_ARQ_RELATORIO_PROD_VENCIDO, "w");

    char buffer[100];

    fputs("------ Relatório de produtos com a validade expirada ------\n", arq);

    if (relatorio->qtd_produtos_relatorio < 1)
        fputs("\nNenhum produto...\n", arq);

    int i;
    for (i = 0; i < relatorio->qtd_produtos_relatorio; i++) {
        Produto *produto = relatorio->produtos + i;

        sprintf(buffer, "\nCódigo: %s", produto->codigo);
        fputs(buffer, arq);

        sprintf(buffer, "\nDescrição: %s", produto->descricao);
        fputs(buffer, arq);

        sprintf(buffer, "\nTamanho: %d", produto->tamanho);
        fputs(buffer, arq);

        sprintf(buffer, "\nPeso: %d", produto->peso);
        fputs(buffer, arq);

        sprintf(buffer, "\nAltura: %d", produto->altura);
        fputs(buffer, arq);

        sprintf(buffer, "\nLargura: %d", produto->largura);
        fputs(buffer, arq);

        sprintf(buffer, "\nPreço: R$%.2f", produto->preco);
        fputs(buffer, arq);

        sprintf(buffer, "\nDesconto: R$%.2f", produto->desconto);
        fputs(buffer, arq);

        sprintf(buffer, "\nData de validade: %02d/%02d/%02d", produto->data_validade.dia, produto->data_validade.mes, produto->data_validade.ano);
        fputs(buffer, arq);

        fputs("\n-------------------------\n", arq);
    }
    fclose(arq);
}

void salvar_relatorio_vendas_periodo(Relatorio_periodo *relatorio)
{
    //TODO: TERMINAR
}
