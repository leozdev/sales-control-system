#include "../headers/func_relatorio.h"

void gerar_relatorio_cliente_x_telefones(Relatorio_telefones *relatorio, Cliente *clientes, int qtd_clientes, int x_telefones)
{   
    int i, count = 0;

    relatorio->x_telefones = x_telefones;
    for (i = 0; i < qtd_clientes; i++) {
        if ((clientes + i)->qtd_telefones > x_telefones)
            *(relatorio->clientes + count) = *(clientes + i);
            count++;
    }   
    relatorio->qtd_clientes_relatorio = count;
}


void gerar_relatorio_produtos_vencidos(Relatorio_validade *relatorio, Produto *produtos, int qtd_produtos)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    int dia = tm.tm_mday;
    int mes = tm.tm_mon + 1;
    int ano = tm.tm_year + 1900;

    int i, count = 0;
    for (i = 0; i < qtd_produtos; i++) {
        Produto *produto = (produtos + i);

        struct tm data_valid_produto = {0};
        data_valid_produto.tm_mday = produto->data_validade.dia;
        data_valid_produto.tm_mon = produto->data_validade.mes - 1;
        data_valid_produto.tm_year = produto->data_validade.ano - 1900;

        time_t data_validade = mktime(&data_valid_produto);
        time_t data_atual = mktime(&tm);

        if (data_validade < data_atual) {
                *(relatorio->produtos + count) = *produto;
                count++;
            }
    }
    relatorio->qtd_produtos_relatorio = count;
}

void gerar_relatorio_vendas_periodo(Venda *vendas, int qtd_vendas)
{   
    struct tm tm_inicio = {0}, tm_fim = {0};

    time_t inicio = mktime(&tm_inicio);
    time_t fim = mktime(&tm_fim);

    // TODO: TERMINAR
    // for (int i = 0; i < qtd_vendas; i++) {
    //     struct tm tm_venda = {0};

    //     tm_venda.tm_year = vendas[i].data.ano - 1900; // Ajusta o ano
    //     tm_venda.tm_mon = vendas[i].data.mes - 1;     // Ajusta o mês
    //     tm_venda.tm_mday = vendas[i].data.dia;         // Dia da venda

    //     time_t data_venda = mktime(&tm_venda);

    //     if (data_venda >= inicio && data_venda <= fim) {
    //         contador++;
    //         printf("Venda em %02d/%02d/%d: R$%.2f\n", vendas[i].data.dia, vendas[i].data.mes, vendas[i].data.ano, vendas[i].valor);
    //     }
    // }
}

void submenu_relatorios(Relatorio_telefones *relatorio_cliente_x_telefones, 
                        Relatorio_validade *relatorio_produtos_vencidos, 
                        Relatorio_periodo *relatorio_vendas_periodo, 
                        Cliente *clientes, Produto *produtos, Venda *vendas, 
                        int qtd_clientes, int qtd_produtos, int qtd_vendas)
{   
    int opt, x_telefones;
    do
    {   
        system("cls");
        printf("\n|| Sistema de Controle de Vendas ||\n");
        printf("\n---------- Submenu de Relatórios ----------\n");
        printf("\n1. Relatório de Clientes com Mais de X Contatos Telefônicos");
        printf("\n2. Relatório de Produtos Vencidos");
        printf("\n3. Relatório de Vendas por Período");
        printf("\n4. Voltar ao Menu Principal");
        printf("\n\nSelecione uma opção: ");
        scanf("%d", &opt);
        fflush(stdin);
        
        switch (opt)
        {
        // TODO: TERMINAR
        case 1:
            printf("\nGerarando relatório de clientes com mais de x telefones...\n");

            printf("\nDigite a quantidade de telefones que deseja buscar para o relatório de clientes: ");
            scanf("%d", &x_telefones);
            fflush(stdin);

            gerar_relatorio_cliente_x_telefones(relatorio_cliente_x_telefones, clientes, qtd_clientes, x_telefones);
            printf("\nRelatório gerado com sucesso!\n");
            break;

        case 2:
            printf("\nGerarando relatório de produtos com data de validade expirada...\n");
            gerar_relatorio_produtos_vencidos(relatorio_produtos_vencidos, produtos, qtd_produtos);
            printf("\nRelatório gerado com sucesso!\n");
            break;

        case 3:
            printf("\nGerarando relatório de vendas entre períodos...\n");
            // relatorio_vendas_periodo();
            break;

        case 4:
            printf("\nVoltando ao menu principal...\n");
            break;
            
        default:
            printf("\nOpção inválida. Por favor, escolha uma opção de 1 a 4.\n");
            break;
        }

        printf("\nPressione Enter para continuar...");
        getchar();
    } while (opt != 4);
}