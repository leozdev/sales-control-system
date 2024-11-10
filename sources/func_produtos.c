#include "../headers/func_produtos.h"

int buscar_produto(Produto *produtos, char codigo[], int qtd_produtos)
{   
    int i;
    for (i = 0; i < qtd_produtos; i++) {
        if (strcmp((produtos + i)->codigo, codigo) == 0)
            return i;
    }
    return -1;
}

int incluir_produto(Produto *produtos, int *qtd_produtos)
{
    char codigo[TAM_CODIGO];

    Produto *produto = (produtos + *qtd_produtos);

    printf("\nDigite o código do produto: ");
    gets(codigo);

    if (buscar_produto(produtos, codigo, *qtd_produtos) != -1)
        return 0;
    
    strcpy(produto->codigo, codigo);

    printf("Digite a descrição do produto: ");
    gets(produto->descricao);
    
    printf("Digite o tamanho do produto (cm): ");
    scanf("%f", &produto->tamanho);
    fflush(stdin);

    printf("Digite o peso do produto (g): ");
    scanf("%f", &produto->peso);
    fflush(stdin);

    printf("Digite a altura do produto (cm): ");
    scanf("%f", &produto->altura);
    fflush(stdin);

    printf("Digite a largura do produto (cm): ");
    scanf("%f", &produto->largura);
    fflush(stdin);

    printf("Digite o preço do produto: R$ ");
    scanf("%f", &produto->preco);
    fflush(stdin);

    printf("Digite o desconto do produto: R$ ");
    scanf("%f", &produto->desconto);
    fflush(stdin);

    printf("Digite a data de validade do produto (DD/MM/AAAA): ");
    scanf("%d/%d/%d", 
      &produto->data_validade.dia, 
      &produto->data_validade.mes, 
      &produto->data_validade.ano);
    fflush(stdin);

    (*qtd_produtos)++;
    return 1;
}

int menu_alteracao_produto()
{   
    int opt;
    printf("\n--- Opções de Alteração de Produto ---\n");
    printf("\n1. Alterar a descrição");
    printf("\n2. Alterar o tamanho");
    printf("\n3. Alterar o peso");
    printf("\n4. Alterar a altura");
    printf("\n5. Alterar a largura");
    printf("\n6. Alterar o preço");
    printf("\n7. Alterar o desconto");
    printf("\n8. Alterar a data de validade");
    printf("\n9. Cancelar alteração");
    printf("\n\nSelecione uma opção: ");
    scanf("%d", &opt);
    fflush(stdin);
    return opt;
}

int alterar_produto(Produto *produtos, char codigo[], int qtd_produtos)
{   
    int idx =  buscar_produto(produtos, codigo, qtd_produtos);
    if (idx == -1)
        return 0;
    
    Produto *produto = (produtos + idx);

    int opt = menu_alteracao_produto();
    switch (opt)
    {
        case 1:
            printf("Digite a descrição do produto: ");
            gets(produto->descricao);
            printf("\nDescrição alterada com sucesso!\n");
            break;

        case 2:
            printf("Digite o tamanho do produto: ");
            scanf("%f", &produto->tamanho);
            fflush(stdin);
            printf("\nTamanho alterado com sucesso!\n");
            break;

        case 3:
            printf("Digite o peso do produto: ");
            scanf("%f", &produto->peso);
            fflush(stdin);
            printf("\nPeso alterado com sucesso!\n");
            break;

        case 4:
            printf("Digite a altura do produto: ");
            scanf("%f", &produto->altura);
            fflush(stdin);
            printf("\nAltura alterada com sucesso!\n");
            break;

        case 5:
            printf("Digite a largura do produto: ");
            scanf("%f", &produto->largura);
            fflush(stdin);
            printf("\nLargura alterada com sucesso!\n");
            break;

        case 6:
            printf("Digite o preço do produto: ");
            scanf("%f", &produto->preco);
            fflush(stdin);
            printf("\nPreço alterado com sucesso!\n");
            break;

        case 7:
            printf("Digite o desconto do produto: ");
            scanf("%f", &produto->desconto);
            fflush(stdin);
            printf("\nDesconto alterado com sucesso!\n");
            break;

        case 8:
            printf("Digite a data de validade do produto (DD/MM/AAAA): ");
            scanf("%d/%d/%d", 
                &produto->data_validade.dia, 
                &produto->data_validade.mes, 
                &produto->data_validade.ano);
            fflush(stdin);
            printf("\nData de validade alterada com sucesso!\n");
            break;

        case 9:
            printf("\nAlteração cancelada.\n");
            break;

        default:
            printf("\nOpção inválida.\n");
            break;
    }
    return 1;
}

int excluir_produto(Produto *produtos, char codigo[], int *qtd_produtos)
{   
    int idx = buscar_produto(produtos, codigo, *qtd_produtos);
    if (idx == -1)
        return 0;
    
    int i; 
    for (i = idx; i < *qtd_produtos; i++) {
        *(produtos + i) = *(produtos + i + 1);
    }

    (*qtd_produtos)--;
    return 1;
}

void exibir_produto(Produto *produto)
{
    printf("\n\tCódigo: %s", produto->codigo);
    printf("\n\tDescrição: %s", produto->descricao);
    printf("\n\tTamanho: %.2f cm", produto->tamanho);
    printf("\n\tPeso: %.2f g", produto->peso);
    printf("\n\tAltura: %.2f cm", produto->altura);
    printf("\n\tLargura: %.2f g", produto->altura);
    printf("\n\tPreço: R$ %.2f", produto->preco);
    printf("\n\tDesconto: R$ %.2f", produto->desconto);
    printf("\n\tData de validade: %02d/%02d/%02d", produto->data_validade.dia, produto->data_validade.mes, produto->data_validade.ano);
    printf("\n\t---------------------------------\n");
}

int listar_todos_produtos(Produto *produtos, int qtd_produtos)
{   
    if (qtd_produtos < 1)
        return 0;
    
    printf("\nProdutos:\n");
    int i;
    for (i = 0; i < qtd_produtos; i++) {
        exibir_produto(produtos+i);
    }
}

int listar_produto_especifico(Produto *produtos, char codigo[], int qtd_produtos)
{   
    int idx = buscar_produto(produtos, codigo, qtd_produtos);
    if (idx == -1)
        return 0;

    printf("\nProduto:\n");
    exibir_produto(produtos+idx);
    return 1;
}

void submenu_produtos(Produto *produtos, int *qtd_produtos)
{
    int opt;
    char codigo[TAM_CODIGO];

    do
    {   
        system("cls");
        printf("\n|| Sistema de Controle de Vendas ||\n");
        printf("\n---------- Submenu de Produtos ----------\n");
        printf("\n1. Listar Todos");
        printf("\n2. Listar um Produto Específico");
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
                printf("\nListando todos os produtos cadastrados...\n");

                if (!(listar_todos_produtos(produtos, *qtd_produtos)))
                    printf("\nNenhum produto cadastrado!\n");
                break;

            case 2:
                printf("\nListando um produto específico...\n");
                
                printf("\nDigite o código do produto: ");
                gets(codigo);

                if (!(listar_produto_especifico(produtos, codigo, *qtd_produtos)))
                    printf("\nCódigo não encontrado.\n");
                break;

            case 3:
                printf("\nIncluindo um novo produto...\n");

                if (incluir_produto(produtos, qtd_produtos))
                    printf("\nProduto cadastrado com sucesso.\n");
                else
                    printf("\nCódigo já cadastrado.\n");
                break;

            case 4:
                printf("\nAlterando dados de um produto...\n");
                printf("\nDigite o código do produto: ");
                gets(codigo);
                
                if (alterar_produto(produtos, codigo, *qtd_produtos))
                    printf("\nProduto alterado com sucesso.\n");
                else
                    printf("\nCódigo não encontrado.\n");
                break;

            case 5:
                printf("\nExcluindo um produto...\n");
                printf("\nDigite o código do produto: ");
                gets(codigo);

                if (excluir_produto(produtos, codigo, qtd_produtos))
                    printf("\nProduto excluído com sucesso.\n");
                else
                    printf("\nCódigo não encontrado\n");
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