#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "../headers/func_vendas.h"
#include "../headers/func_clientes.h"
#include "../headers/func_produtos.h"

int buscar_venda(Venda *vendas, char cpf_cliente[], char codigo_produto[], Date data, Hora hora, int qtd_vendas) 
{
    for (int i = 0; i < qtd_vendas; i++) {
        if (strcmp((vendas + i)->cpf_cliente, cpf_cliente) == 0 && 
            strcmp((vendas + i)->codigo_produto, codigo_produto) == 0) {

            if ((vendas + i)->data_venda.dia == data.dia && 
                (vendas + i)->data_venda.mes == data.mes && 
                (vendas + i)->data_venda.ano == data.ano &&
                (vendas + i)->hora_venda.horas == hora.horas &&
                (vendas + i)->hora_venda.minutos == hora.minutos) {
                return i;
            }
        }
    }
    return -1;
}


void ler_dados_venda(char cpf_cliente[], char codigo_produto[], Date *data_venda, Hora *hora_venda)
{
    printf("\nDigite o CPF do cliente: ");
    gets(cpf_cliente);

    printf("Digite o código do produto: ");
    gets(codigo_produto);

    printf("Digite a data da venda (DD/MM/AAAA): ");
    scanf("%d/%d/%d",
        &data_venda->dia,
        &data_venda->mes,
        &data_venda->ano);
    fflush(stdin);

    printf("Digite a hora da venda (Horas:Minutos): ");
    scanf("%d:%d",
        &hora_venda->horas,
        &hora_venda->minutos);
    fflush(stdin);
}


int incluir_venda(Venda *vendas, int *qtd_vendas, Cliente *clientes, int *qtd_clientes, Produto *produtos, int *qtd_produtos)
{   
    char cpf_cliente[TAM_CPF], codigo_produto[TAM_CODIGO]; 
    Date data_venda;
    Hora hora_venda;

    ler_dados_venda(cpf_cliente, codigo_produto, &data_venda, &hora_venda);

    // Verifica se o cliente existe
    if (buscar_cliente(clientes, cpf_cliente, *qtd_clientes) == -1)
        return -1;

    // Verifica se o produto existe
    if (buscar_produto(produtos, codigo_produto, *qtd_produtos) == -1)
        return -2;

    // Verifica se a venda já está cadastrada
    if (buscar_venda(vendas, cpf_cliente, codigo_produto, data_venda, hora_venda, *qtd_vendas) != -1)
        return -3;
    
    Venda *venda = (vendas + *qtd_vendas);

    strcpy(venda->cpf_cliente, cpf_cliente);
    strcpy(venda->codigo_produto, codigo_produto);
    venda->data_venda = data_venda;
    venda->hora_venda = hora_venda;

    printf("Digite o valor da venda: R$");
    scanf("%f", &venda->valor_venda);
    fflush(stdin);

    (*qtd_vendas)++;
    return 1;
}


int menu_alteracao_venda()
{   
    int opt;
    printf("\n--- Opções de Alteração de Vendas ---");
    printf("\n1. Valor da venda");
    printf("\n2. Cancelar alteração");
    printf("\n\nSelecione uma opção: ");
    scanf("%d", &opt);
    fflush(stdin);
    return opt;
}

int alterar_venda(Venda *vendas, char cpf_cliente[], char codigo_produto[], Date data, Hora hora, int qtd_vendas)
{   
    int idx = buscar_venda(vendas, cpf_cliente, codigo_produto, data, hora, qtd_vendas);

    if (idx == -1)
        return 0;

    Venda *venda = (vendas + idx);

    int opt = menu_alteracao_venda();
    switch (opt)
    {
        case 1:
            printf("Digite o valor da venda: R$");
            scanf("%f", &venda->valor_venda);
            fflush(stdin);
            break;
        case 2:
            printf("\nAlteração cancelada.");
            break;
        default:
            printf("\nOpção inválida.");
            break;
    }
    return 1;
}


int excluir_venda(Venda *vendas, char cpf_cliente[], char codigo_produto[], Date data, Hora hora, int *qtd_vendas)
{   
    int idx = buscar_venda(vendas, cpf_cliente, codigo_produto, data, hora, *qtd_vendas);

    if (idx == -1)
        return 0;
    
    int i;
    for (i = idx; i < *qtd_vendas; i++) {
        *(vendas + i) = *(vendas + i + 1);
    }

    (*qtd_vendas)--;
    return 1;
}


void exibir_venda(const Venda *venda) 
{
    printf("\n\tCPF do cliente: %s", venda->cpf_cliente);
    printf("\n\tCódigo do produto: %s", venda->codigo_produto);
    printf("\n\tData da venda: %02d/%02d/%04d", venda->data_venda.dia, venda->data_venda.mes, venda->data_venda.ano);
    printf("\n\tHora da venda: %02d:%02d", venda->hora_venda.horas, venda->hora_venda.minutos);
    printf("\n\tValor da venda: R$%.2f", venda->valor_venda);
    printf("\n\t---------------------------------\n");
}

int listar_todas_vendas(Venda *vendas, int qtd_vendas)
{   
    if (qtd_vendas < 1)
        return 0;
    
    int i;
    for (i = 0; i < qtd_vendas; i++) {
        exibir_venda(vendas+i);
    }
    return 1;
}   

int listar_venda_especifica(Venda *vendas, char cpf_cliente[], char codigo_produto[], Date data, Hora hora, int qtd_vendas)
{   
    int idx = buscar_venda(vendas, cpf_cliente, codigo_produto, data, hora, qtd_vendas);
    
    if (idx == -1)
        return 0;

    exibir_venda(vendas+idx);

    return 1;
}


void submenu_vendas(Venda *vendas, int *qtd_vendas, Cliente *clientes, int *qtd_clientes, Produto *produtos, int *qtd_produtos)
{   
    int opt;
    char cpf_cliente[TAM_CPF], codigo_produto[TAM_CODIGO]; 
    Date data_venda;
    Hora hora_venda;

    do
    {   
        system("cls");
        printf("\n---------- Submenu de Vendas ----------\n");
        printf("\n1. Listar Todas");
        printf("\n2. Listar uma Venda Específica");
        printf("\n3. Incluir");
        printf("\n4. Alterar");
        printf("\n5. Excluir");
        printf("\n6. Voltar ao Menu Principal");
        printf("\n\nSelecione uma opção: ");
        scanf("%d", &opt);
        fflush(stdin);

       switch (opt)
        {
            case 1:
                printf("\nListando todos as vendas cadastradas...\n");
                if (!(listar_todas_vendas(vendas, *qtd_vendas)))
                    printf("\nNenhuma venda cadastrada!\n");
                break;

            case 2:
                printf("\nListando uma venda específica...\n");
                
                ler_dados_venda(cpf_cliente, codigo_produto, &data_venda, &hora_venda);

                if (!(listar_venda_especifica(vendas, cpf_cliente, codigo_produto, data_venda, hora_venda, *qtd_vendas)))
                    printf("\nVenda não encontrada.\n");
                break;

            case 3:
                printf("\nIncluindo uma nova venda...\n");

                switch (incluir_venda(vendas, qtd_vendas, clientes, qtd_clientes, produtos, qtd_produtos))
                {
                    case 1:
                        printf("\nVenda cadastrada com sucesso!");
                        break;
                    
                    case -1:
                        printf("\nCliente não encontrado.\n");
                        break;
                    
                    case -2:
                        printf("\nProduto não encontrado.\n");
                        break;
                    
                    case -3:
                        printf("\nVenda já cadastrada.\n");
                        break;
                }
                break;

            case 4:
                printf("\nAlterando dados de uma venda...\n");

                ler_dados_venda(cpf_cliente, codigo_produto, &data_venda, &hora_venda);

                alterar_venda(vendas, cpf_cliente, codigo_produto, data_venda, hora_venda, *qtd_vendas);
                break;

            case 5:
                printf("\nExcluindo venda...\n");

                ler_dados_venda(cpf_cliente, codigo_produto, &data_venda, &hora_venda);

                if (excluir_venda(vendas, cpf_cliente, codigo_produto, data_venda, hora_venda, qtd_vendas))
                    printf("\nVenda excluída com sucesso!");
                else
                    printf("\nVenda não encontrada.");
                break;

            case 6:
                printf("\nVoltando ao menu principal...\n");
                break;
                
            default:
                printf("\nOpção inválida. Por favor, escolha uma opção de 1 a 6.\n");
                break;
        }

        printf("\nPressione Enter para continuar...");
        getchar();
    } while (opt != 6);
}