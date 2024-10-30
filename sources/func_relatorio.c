#include "../headers/func_relatorio.h"

int relatorio_cliente_x_telefones(Cliente *clientes, int qtd_clientes, int x_telefones)
{   
    int i;
    for (i = 0; i < qtd_clientes; i++) {
        if ((clientes + i)->qtd_telefones > x_telefones){
            printf(""); //TODO: TERMINAR
        }
    }
    return 1;
}


int relatorio_produtos_vencidos(Produto *produtos, int qtd_produtos)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    int dia = tm.tm_mday;
    int mes = tm.tm_mon + 1;
    int ano = tm.tm_year + 1900;

    int i, count;
    for (i = 0; i < qtd_produtos; i++) {
        struct tm data_valid_produto = {0};
        data_valid_produto.tm_mday = (*(produtos + i)).data_validade.dia;
        data_valid_produto.tm_mon = (*(produtos + i)).data_validade.mes - 1;
        data_valid_produto.tm_year = (*(produtos + i)).data_validade.ano - 1900;

        time_t time_validade = mktime(&data_valid_produto);
        time_t time_atual = mktime(&tm);

        if (time_validade < time_atual) {
                printf("O %s está vencido!\n", (*(produtos + i)).codigo);
                count++;
            }
        
    }
    return 1;
}

int relatorio_vendas_periodo(Venda *vendas, int qtd_vendas)
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
    return 1;
}

void submenu_relatorios()
{   
    int opt;
    do
    {   
        system("cls");
        printf("\n---------- Submenu de Relatórios ----------");
        printf("\n1. Relatório de Clientes com Mais de X Contatos Telefônicos");
        printf("\n2. Relatório de Produtos Vencidos");
        printf("\n3. Relatório de Vendas por Período");
        printf("\n4. Voltar ao Menu Principal");

        printf("\nSelecione uma opção: ");
        scanf("%d", &opt);
        fflush(stdin);
        
        switch (opt)
        {
        // TODO: TERMINAR
        case 1:
            // relatorio_cliente_x_telefones();
            break;
        case 2:
            // relatorio_produtos_vencidos();
            break;
        case 3:
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