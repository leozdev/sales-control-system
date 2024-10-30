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
    printf("\n---------- MENU ----------");
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
    setlocale(LC_ALL, "pt.BR_UTF-8");

    Cliente *clientes = (Cliente *) malloc(TOTAL_CLIENTES * sizeof(Cliente));
    Produto *produtos = (Produto *) malloc(TOTAL_PRODUTOS * sizeof(Produto));
    Venda *vendas = (Venda *) malloc(TOTAL_VENDAS * sizeof(Venda));
    Relatorio_telefones *relatorios_telefones = (Relatorio_telefones *) malloc(TOTAL_CLIENTES * sizeof(Relatorio_telefones));
    Relatorio_validade *relatorios_validade = (Relatorio_validade *) malloc(TOTAL_PRODUTOS * sizeof(Relatorio_validade));
    Relatorio_periodo *relatorios_periodo = (Relatorio_periodo *) malloc(TOTAL_VENDAS * sizeof(Relatorio_periodo));

    if (clientes == NULL || produtos == NULL || vendas == NULL || 
        relatorios_telefones == NULL || relatorios_validade == NULL || relatorios_periodo == NULL) {
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
                submenu_relatorios();
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

    // Salvar em arquivo binário os dados dos registros (Clientes, Produtos e Vendas)
    salvar_clientes(clientes, qtd_clientes);
    salvar_produtos(produtos, qtd_produtos);
    salvar_vendas(vendas, qtd_vendas);


    free(clientes);
    free(vendas);
    free(produtos);
    free(relatorios_telefones);
    free(relatorios_validade);
    free(relatorios_periodo);
}

// gcc -o projeto main.c func_clientes.c func_produtos.c func_vendas.c func_relatorio.c
