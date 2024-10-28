#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "../headers/func_clientes.h"
#include "../headers/func_produtos.h"
#include "../headers/func_vendas.h"
#include "../headers/func_relatorio.h"
#include "../headers/func_arquivos.h"

#define TOTAL_CLIENTES 100
#define TOTAL_PRODUTOS 100
#define TOTAL_VENDAS 100

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

    if (clientes == NULL || produtos == NULL || vendas == NULL) {
        printf("\nErro na alocação de memória.\n");
        exit(1);
    }

    int qtd_clientes = 0, qtd_vendas = 0, qtd_produtos = 0;

    int opt;
    do 
    {
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
                printf("\nOpção inválida. Por favor, escolha uma opção de 1 a 5.");
                break;
        }
    } while (opt != 5);

    // Salvar em arquivo binário os dados dos registros (Clientes, Produtos e Vendas)
    salvar_clientes(clientes, qtd_clientes, "clientes.dat");
    // Libera a memória alocada dinamicamente para os emails e telefones de cada cliente
    int i, j, k;
    for (i = 0; i < qtd_clientes; i++) {

        for (j = 0; j < (clientes + i)->qtd_emails; j++) {
            free(*((clientes + i)->emails + j));
        }
        free((clientes + i)->emails);

        for (k = 0; k < (clientes + i)->qtd_telefones; k++) {
            free(*((clientes + i)->telefones + k));
        }
        free((clientes + i)->telefones);
    }
    // ----------------------------------------------------------------------------------

    free(clientes);
    free(vendas);
    free(produtos);
}

// gcc -o projeto main.c func_clientes.c func_produtos.c func_vendas.c func_relatorio.c
