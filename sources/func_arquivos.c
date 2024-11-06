#include "../headers/func_arquivos.h"

void salvar_clientes(Cliente *clientes, int qtd_clientes)
{
    FILE *arq = fopen(NOME_ARQ_CLIENTES, "wb");
    if (arq == NULL)
        printf("Erro ao abrir o arquivo.\n");

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

    char buffer[200];

    sprintf(buffer, "------ Relatório de clientes com mais de %d telefones ------\n", relatorio->x_telefones);
    fputs(buffer, arq);

    if (relatorio->qtd_clientes_relatorio < 1) {
        sprintf(buffer, "\nNenhum cliente com mais de %d telefones cadastrado.\n", relatorio->x_telefones);
        fputs(buffer, arq);
        return;
    }

    int i, j;
    for (i = 0; i < relatorio->qtd_clientes_relatorio; i++) {
        Cliente *cliente = (relatorio->clientes + i);

        sprintf(buffer, "\n\tCPF: %s\n", cliente->cpf);
        fputs(buffer, arq);

        sprintf(buffer, "\tNome: %s\n", cliente->nome);
        fputs(buffer, arq);

        sprintf(buffer, "\tData de nascimento: %02d/%02d/%04d\n", cliente->data_nasc.dia, cliente->data_nasc.mes, cliente->data_nasc.ano);
        fputs(buffer, arq);

        sprintf(buffer, "\tSexo: %s\n", cliente->sexo);
        fputs(buffer, arq);

        sprintf(buffer, "\tSalário: R$ %.2f\n", cliente->salario);
        fputs(buffer, arq);

        fputs("\tEmails:\n", arq);
        for (j = 0; j < cliente->qtd_emails; j++) {
            sprintf(buffer, "\t%d. %s\n", j + 1, *(cliente->emails + j));
            fputs(buffer, arq);
        }

        fputs("\tTelefones:\n", arq);
        for (j = 0; j < cliente->qtd_telefones; j++) {
            sprintf(buffer, "\t%d. %s\n", j + 1, *(cliente->telefones + j));
            fputs(buffer, arq);
        }

        fputs("\n-------------------------\n", arq);
    }
    fclose(arq);
}

void salvar_relatorio_prod_vencido(Relatorio_validade *relatorio)
{
    FILE *arq = fopen(NOME_ARQ_RELATORIO_PROD_VENCIDO, "w");

    char buffer[200];

    fputs("------ Relatório de produtos com validade expirada ------\n", arq);

    if (relatorio->qtd_produtos_relatorio < 1) {
        fputs("\nNenhum produto com validade expirada.\n", arq);
        return;
    }

    int i;
    for (i = 0; i < relatorio->qtd_produtos_relatorio; i++) {
        Produto *produto = (relatorio->produtos + i);

        sprintf(buffer, "\n\tCódigo: %s\n", produto->codigo);
        fputs(buffer, arq);

        sprintf(buffer, "\tDescrição: %s\n", produto->descricao);
        fputs(buffer, arq);

        sprintf(buffer, "\tTamanho: %d cm\n", produto->tamanho);
        fputs(buffer, arq);

        sprintf(buffer, "\tPeso: %d g\n", produto->peso);
        fputs(buffer, arq);

        sprintf(buffer, "\tAltura: %d cm\n", produto->altura);
        fputs(buffer, arq);

        sprintf(buffer, "\tLargura: %d cm\n", produto->largura);
        fputs(buffer, arq);

        sprintf(buffer, "\tPreço: R$ %.2f\n", produto->preco);
        fputs(buffer, arq);

        sprintf(buffer, "\tDesconto: R$ %.2f\n", produto->desconto);
        fputs(buffer, arq);

        sprintf(buffer, "\tData de validade: %02d/%02d/%04d\n", produto->data_validade.dia, produto->data_validade.mes, produto->data_validade.ano);
        fputs(buffer, arq);

        fputs("\n-------------------------\n", arq);
    }
    fclose(arq);
}

void salvar_relatorio_vendas_periodo(Relatorio_periodo *relatorio)
{
    FILE *arq = fopen(NOME_ARQ_RELATORIO_VENDAS_PERIODO, "w");
   
    char buffer[200];

    sprintf(buffer, "------ Relatório de vendas no período de %02d/%02d/%04d a %02d/%02d/%04d ------\n",
            relatorio->data_incio.dia, relatorio->data_incio.mes, relatorio->data_incio.ano,
            relatorio->data_fim.dia, relatorio->data_fim.mes, relatorio->data_fim.ano);
    fputs(buffer, arq);

    if (relatorio->qtd_vendas_relatorio < 1) {
        fputs("\nNenhuma venda registrada no período.\n", arq);
        return;
    }

    int i;
    for (i = 0; i < relatorio->qtd_vendas_relatorio; i++) {
        Cliente *cliente = (relatorio->clientes + i);
        Produto *produto = (relatorio->produtos + i);
        Venda *venda = (relatorio->vendas + i);

        sprintf(buffer, "\n\tCliente: %s\n", cliente->nome);
        fputs(buffer, arq);

        sprintf(buffer, "\tCPF: %s\n", cliente->cpf);
        fputs(buffer, arq);

        sprintf(buffer, "\tCódigo: %s\n", produto->codigo);
        fputs(buffer, arq);

        sprintf(buffer, "\tDescrição: %s\n", produto->descricao);
        fputs(buffer, arq);

        sprintf(buffer, "\tData da Venda: %02d/%02d/%04d\n", venda->data_venda.dia, venda->data_venda.mes, venda->data_venda.ano);
        fputs(buffer, arq);

        sprintf(buffer, "\tHora da Venda: %d:%d\n", venda->hora_venda.horas, venda->hora_venda.minutos);
        fputs(buffer, arq);

        sprintf(buffer, "\tTotal da Venda: R$ %2.f\n", venda->valor_venda);
        fputs(buffer, arq);

        fputs("\n\t-------------------------\n", arq);
    }
    fclose(arq);
}
