#ifndef DEFINES_H
#define DEFINES_H

// Tamanho dos vetores de registro:
#define TOTAL_CLIENTES 10
#define TOTAL_PRODUTOS 10
#define TOTAL_VENDAS 10

// Nome dos arquivos de persistência:
#define NOME_ARQ_CLIENTES "../dados_binario/dados_clientes.dat"
#define NOME_ARQ_PRODUTOS "../dados_binario/dados_produtos.dat"
#define NOME_ARQ_VENDAS "../dados_binario/dados_vendas.dat"
#define NOME_ARQ_RELATORIO_X_TELEFONES "../relatorios/relatorio_x_telefones.txt"
#define NOME_ARQ_RELATORIO_PROD_VENCIDO "../relatorios/relatorio_prod_vencido.txt"
#define NOME_ARQ_RELATORIO_VENDAS_PERIODO "../relatorios/relatorio_vendas_periodo.txt"

// Tamanho máximo dos vetores que armazenam tais dados:
#define TAM_NOME 50
#define TAM_CPF 12
#define TAM_EMAIL 50
#define TAM_TELEFONE 16
#define TAM_SEXO 10
#define TAM_CODIGO 11
#define TAM_DESCRICAO 50
#define QTD_MAX_EMAILS 5
#define QTD_MAX_TELEFONES 5

#endif