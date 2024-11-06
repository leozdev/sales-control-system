#include "../headers/func_relatorio.h"

void gerar_relatorio_cliente_x_telefones(Relatorio_telefones *relatorio, Cliente *clientes, int qtd_clientes, int x_telefones)
{   
    int i, count = 0;

    relatorio->x_telefones = x_telefones;
    for (i = 0; i < qtd_clientes; i++) {
        if ((clientes + i)->qtd_telefones > x_telefones) {
            *(relatorio->clientes + count) = *(clientes + i);
            count++;
        }
    }   
    relatorio->qtd_clientes_relatorio = count;
}

void gerar_relatorio_produtos_vencidos(Relatorio_validade *relatorio, Produto *produtos, int qtd_produtos)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    int i, count = 0;
    for (i = 0; i < qtd_produtos; i++) {
        Produto *produto = produtos + i;

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

void gerar_relatorio_vendas_periodo(Relatorio_periodo *relatorio, Cliente *clientes, Produto *produtos, Venda *vendas, 
                                    int qtd_clientes, int qtd_produtos, int qtd_vendas, Date data_inicio, Date data_fim)
{   
    struct tm tm_inicio = {0}, tm_fim = {0};

    tm_inicio.tm_mday = data_inicio.dia;
    tm_inicio.tm_mon = data_inicio.mes - 1;
    tm_inicio.tm_year = data_inicio.ano - 1900;

    tm_fim.tm_mday = data_fim.dia;
    tm_fim.tm_mon = data_fim.mes - 1;
    tm_fim.tm_year = data_fim.ano - 1900;

    time_t inicio = mktime(&tm_inicio);
    time_t fim = mktime(&tm_fim);

    int i, count = 0;
    int idx_cliente, idx_produto;
    for (i = 0; i < qtd_vendas; i++) {
        Venda *venda = vendas + i;

        struct tm tm_venda = {0};
        tm_venda.tm_mday = venda->data_venda.dia;
        tm_venda.tm_mon = venda->data_venda.mes - 1;
        tm_venda.tm_year = venda->data_venda.ano - 1900;

        time_t data_venda = mktime(&tm_venda);

        if (data_venda >= inicio && data_venda <= fim) {
            idx_cliente = buscar_cliente(clientes, venda->cpf_cliente, qtd_clientes);
            idx_produto = buscar_produto(produtos, venda->codigo_produto, qtd_produtos);

            if (idx_cliente != -1 && idx_produto != -1) {
                *(relatorio->vendas + count) = *venda;
                *(relatorio->clientes + count) = *(clientes + idx_cliente);
                *(relatorio->produtos + count) = *(produtos + idx_produto);
                count++;
            }
        }
    }
    relatorio->data_incio = data_inicio;
    relatorio->data_fim =  data_fim;
    relatorio->qtd_vendas_relatorio = count;
}

void submenu_relatorios(Relatorio_telefones *relatorio_cliente_x_telefones, 
                        Relatorio_validade *relatorio_produtos_vencidos, 
                        Relatorio_periodo *relatorio_vendas_periodo, 
                        Cliente *clientes, Produto *produtos, Venda *vendas, 
                        int qtd_clientes, int qtd_produtos, int qtd_vendas)
{   
    int opt, x_telefones;
    Date data_inicio, data_fim;
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
            case 1:
                printf("\nGerando relatório de clientes com mais de X telefones...\n");

                printf("\nDigite a quantidade de telefones para o relatório de clientes: ");
                scanf("%d", &x_telefones);
                fflush(stdin);

                gerar_relatorio_cliente_x_telefones(relatorio_cliente_x_telefones, clientes, qtd_clientes, x_telefones);
                printf("\nRelatório gerado com sucesso!\n");
                break;

            case 2:
                printf("\nGerando relatório de produtos com data de validade expirada...\n");
                gerar_relatorio_produtos_vencidos(relatorio_produtos_vencidos, produtos, qtd_produtos);
                printf("\nRelatório gerado com sucesso!\n");
                break;

            case 3:
                printf("\nGerando relatório de vendas entre períodos...\n");
                printf("\nDigite a data de início (DD/MM/AAAA): ");
                scanf("%d/%d/%d", &data_inicio.dia, &data_inicio.mes, &data_inicio.ano);
                fflush(stdin);

                printf("\nDigite a data de fim (DD/MM/AAAA): ");
                scanf("%d/%d/%d", &data_fim.dia, &data_fim.mes, &data_fim.ano);
                fflush(stdin);

                gerar_relatorio_vendas_periodo(relatorio_vendas_periodo, clientes, produtos, vendas, qtd_clientes, qtd_produtos, qtd_vendas, data_inicio, data_fim);
                printf("\nRelatório gerado com sucesso!\n");
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
