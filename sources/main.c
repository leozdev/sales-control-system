#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "../headers/func_clientes.h"
#include "../headers/func_produtos.h"
#include "../headers/func_vendas.h"
#include "../headers/func_relatorio.h"
#include "../headers/func_arquivos.h"
#include "../headers/defines.h"

int menu() 
{
    int opt;
    printf("\n|| Sistema de Controle de Vendas ||\n");
    printf("\n---------- MENU ----------\n");
    printf("\n1. Submenu de Clientes");
    printf("\n2. Submenu de Produtos");
    printf("\n3. Submenu de Vendas");
    printf("\n4. Submenu Relatórios");
    printf("\n5. Sair");
    printf("\n\nSelecione uma opção: ");
    scanf("%d", &opt);
    fflush(stdin);
    return opt;
}

int main() 
{
    setlocale(LC_ALL, "pt_BR.UTF-8");

    Cliente *clientes = (Cliente *) calloc(TOTAL_CLIENTES, sizeof(Cliente));
    Produto *produtos = (Produto *) calloc(TOTAL_PRODUTOS, sizeof(Produto));
    Venda *vendas = (Venda *) calloc(TOTAL_VENDAS, sizeof(Venda));

    Relatorio_telefones *relatorio_telefones = (Relatorio_telefones *) calloc(1, sizeof(Relatorio_telefones));
    Relatorio_validade *relatorio_validade = (Relatorio_validade *) calloc(1, sizeof(Relatorio_validade));
    Relatorio_periodo *relatorio_periodo = (Relatorio_periodo *) calloc(1, sizeof(Relatorio_periodo));

    if (clientes == NULL || produtos == NULL || vendas == NULL || 
        relatorio_telefones == NULL || relatorio_validade == NULL || relatorio_periodo == NULL) {
        printf("\nErro na alocação de memória.\n");
        exit(1);
    }

    int qtd_clientes = 0, qtd_vendas = 0, qtd_produtos = 0;

    // Carregar os dados para os registros
    carregar_clientes(clientes, &qtd_clientes);
    carregar_produtos(produtos, &qtd_produtos);
    carregar_vendas(vendas, &qtd_vendas);

    int opt;
    do 
    {   
        system("cls");
        opt = menu();
        switch (opt) 
        {
            case 1:
                submenu_clientes(clientes, &qtd_clientes);
                break;

            case 2:
                submenu_produtos(produtos, &qtd_produtos);
                break;

            case 3:
                submenu_vendas(vendas, &qtd_vendas, clientes, &qtd_clientes, produtos, &qtd_produtos);
                break;
                
            case 4:
                submenu_relatorios(relatorio_telefones, relatorio_validade, relatorio_periodo, 
                                clientes, produtos, vendas, qtd_clientes, qtd_produtos, qtd_vendas);
                break;

            case 5:
                printf("\nSaindo do programa...");
                break;

            default:
                printf("\nOpção inválida. Por favor, escolha uma opção de 1 a 5.\n");
                printf("\nPressione Enter para continuar...");
                getchar();
                break;
        }

    } while (opt != 5);

    // Salvar em arquivo binário os dados dos registros (Clientes, Produtos, Vendas, e Relatórios)
    salvar_clientes(clientes, qtd_clientes);
    salvar_produtos(produtos, qtd_produtos);
    salvar_vendas(vendas, qtd_vendas);

    // Gerando os relatórios ao final da execução do programa
    if (relatorio_telefones->qtd_clientes_relatorio > 0)
        salvar_relatorio_x_telefones(relatorio_telefones);
    if (relatorio_validade->qtd_produtos_relatorio > 0)
        salvar_relatorio_prod_vencido(relatorio_validade);
    if (relatorio_periodo->qtd_vendas_relatorio > 0)
        salvar_relatorio_vendas_periodo(relatorio_periodo);

    free(clientes);
    free(vendas);
    free(produtos);
    free(relatorio_telefones);
    free(relatorio_validade);
    free(relatorio_periodo);
}

//  gcc -o controle_de_vendas main.c func_clientes.c func_produtos.c func_vendas.c func_relatorio.c func_arquivos.c
