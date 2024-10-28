#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/func_clientes.h"

int buscar_cliente(Cliente *clientes, char cpf[], int qtd_clientes)
{
    int i;
    for (i = 0; i < qtd_clientes; i++) {
        if (strcmp((clientes + i)->cpf, cpf) == 0)
            return i;
    }
    return -1;
}

void cadastrar_email(Cliente *cliente)
{
    char confirma;
    char email[100];

    do
    {
        printf("Digite o e-mail: ");
        gets(email);
    
        cliente->emails = (char **)realloc(cliente->emails, (cliente->qtd_emails + 1) * sizeof(char *));

        *(cliente->emails + cliente->qtd_emails) = (char *)malloc(strlen(email) + 1);
        
        if ((cliente->emails + cliente->qtd_emails) != NULL) {
            strcpy(*(cliente->emails + cliente->qtd_emails), email);
            cliente->qtd_emails++;
        }

        printf("> Deseja cadastrar mais um e-mail para este cliente (S/N): ");
        scanf("%c", &confirma);
        fflush(stdin);

    } while (confirma != 'N' && confirma != 'n');
}

void cadastrar_telefone(Cliente *cliente)
{
    char confirma;
    char telefone[20];

    do
    {
        printf("Digite o telefone: ");
        gets(telefone);

        cliente->telefones = (char **)realloc(cliente->telefones, (cliente->qtd_telefones + 1) * sizeof(char *));

        *(cliente->telefones + cliente->qtd_telefones) = (char *)malloc(strlen(telefone) + 1);
        
        if ((cliente->telefones + cliente->qtd_telefones) != NULL) {
            strcpy(*(cliente->telefones + cliente->qtd_telefones), telefone);
            cliente->qtd_telefones++;
        }

        printf("> Deseja cadastrar mais um telefone para este cliente (S/N): ");
        scanf("%c", &confirma);
        fflush(stdin);

    } while (confirma != 'N' && confirma != 'n');
}


int incluir_cliente(Cliente *clientes, int *qtd_clientes)
{   
    char cpf[12];

    Cliente *cliente = (clientes + *qtd_clientes);

    printf("\nDigite o CPF: ");
    gets(cpf);

    if (buscar_cliente(clientes, cpf, *qtd_clientes) != -1)
        return 0;

    strcpy(cliente->cpf, cpf);

    printf("Digite o nome: ");
    gets(cliente->nome);

    printf("Digite a data de nascimento (DD/MM/AAAA): ");
    scanf("%d/%d/%d", 
      &cliente->data_nasc.dia, 
      &cliente->data_nasc.mes, 
      &cliente->data_nasc.ano);
    fflush(stdin);

    printf("Digite o sexo: ");
    gets(cliente->sexo);

    printf("Digite o salário: ");
    scanf("%f", &cliente->salario);
    fflush(stdin);

    cliente->emails = NULL;
    cliente->telefones = NULL;
    cliente->qtd_emails = 0;
    cliente->qtd_telefones = 0;

    cadastrar_email(cliente);
    cadastrar_telefone(cliente);

    (*qtd_clientes)++;
    return 1;
}


void listar_emails(Cliente *cliente)
{
    printf("\n\tEmails cadastrados:");
    for (int i = 0; i < cliente->qtd_emails; i++)
    {
        printf("\n\t%d. %s", i + 1, *(cliente->emails + i));
    }
}

void listar_telefones(Cliente *cliente)
{
    printf("\n\tTelefones cadastrados:");
    for (int i = 0; i < cliente->qtd_telefones; i++)
    {
        printf("\n\t%d. %s", i + 1,  *(cliente->telefones + i));
    }
}


int menu_alteracao_cliente()
{
    int opt;
    printf("\n--- Opções de Alteração de Clientes ---");
    printf("\n1. Alterar nome");
    printf("\n2. Alterar data de nascimento");
    printf("\n3. Alterar o sexo");
    printf("\n4. Alterar o salário");
    printf("\n5. Alterar emails cadastrados");
    printf("\n6. Alterar telefones cadastrados");
    printf("\n7. Cancelar alteração");
    printf("\n\nSelecione uma opção: ");
    scanf("%d", &opt);
    fflush(stdin);
    return opt;
}

void alterar_email(Cliente *cliente)
{
    listar_emails(cliente);

    if (cliente->qtd_emails == 0)
    {
        printf("\nNenhum email cadastrado.");
        return;
    }

    int idx;
    printf("\nEscolha o email para alterar (1 a %d): ", cliente->qtd_emails);
    scanf("%d", &idx);
    fflush(stdin);
    
    if (idx < 1 || idx > cliente->qtd_emails)
    {
        printf("\nOpção inválida.");
        return;
    }

    char novo_email[50];
    printf("\nDigite o email: ");
    gets(novo_email);

    free(*(cliente->emails + idx - 1));

    *(cliente->emails + idx - 1) = (char *)malloc(strlen(novo_email) + 1);

    strcpy(*(cliente->emails + idx - 1), novo_email);
}

void alterar_telefone(Cliente *cliente)
{
    listar_telefones(cliente);

    if (cliente->qtd_telefones == 0)
    {
        printf("\nNenhum telefone cadastrado.");
        return;
    }

    int idx;
    printf("Escolha o telefone para alterar (1 a %d): ", cliente->qtd_telefones);
    scanf("%d", &idx);
    fflush(stdin);
    
    if (idx < 1 || idx > cliente->qtd_telefones)
    {
        printf("\nOpção inválida.");
        return;
    }

    char novo_telefone[15];
    printf("\nDigite o telefone: ");
    gets(novo_telefone);

    free(*(cliente->telefones + idx - 1));

    *(cliente->telefones + idx - 1) = (char *)malloc(strlen(novo_telefone) + 1);

    strcpy(*(cliente->telefones + idx - 1), novo_telefone);
}

int alterar_cliente(Cliente *clientes, char cpf[], int qtd_clientes)
{   
    int idx = buscar_cliente(clientes, cpf, qtd_clientes);
    if (idx == -1)
        return 0;

    Cliente *cliente = (clientes + idx);

    int opt = menu_alteracao_cliente();
    switch (opt)
    {
        case 1:
            printf("\nDigite o nome: %s", (clientes + idx)->nome);
            gets(cliente->nome);
            printf("\nNome atualizado com sucesso!");
            break;
        case 2:
            printf("\nDigite a data de nascimento (DD/MM/AAAA): ");
            scanf("%d/%d/%d", 
                &cliente->data_nasc.dia, 
                &cliente->data_nasc.mes, 
                &cliente->data_nasc.ano);
            fflush(stdin);
            printf("\nData de nascimento atualizado com sucesso!");
            break;
        case 3:
            printf("\nDigite o sexo (M/F): ");
            gets(cliente->sexo);
            printf("\nSexo atualizado com sucesso!");
            break;
        case 4:
            printf("\nDigite o salário: ");
            scanf("%f", &cliente->salario);
            printf("\nSalário atualizado com sucesso!");
            break;
        case 5:
            alterar_email(cliente);
            printf("\nEmail atualizado com sucesso!");
            break;
        case 6:
            alterar_telefone(cliente);
            printf("\nTelefone atualizado com sucesso!");
            break;
        case 7:
            printf("\nAlteração cancelada.");
            break;
        default:
            printf("\nOpção inválida.");
            break;
    }
    return 1;
}


int excluir_cliente(Cliente *clientes, char cpf[], int *qtd_clientes) 
{
    int idx = buscar_cliente(clientes, cpf, *qtd_clientes);
    if (idx == -1)
        return 0;

    Cliente *cliente = (clientes + idx);

    int i;
    for (i = 0; i < cliente->qtd_emails; i++) {
        free(*(cliente->emails + i));
    }

    for (i = 0; i <cliente->qtd_telefones; i++) {
        free(*(cliente->telefones + i));
    }

    free(cliente->emails);
    free(cliente->telefones);

    for (i = idx; i < *qtd_clientes - 1; i++) {
        *(clientes + i) = *(clientes + i + 1);
    }

    (*qtd_clientes)--;
    return 1;
}


void exibir_cliente(Cliente *cliente)
{
    printf("\n\tCPF: %s", cliente->cpf);
    printf("\n\tNome: %s", cliente->nome);
    printf("\n\tData de nascimento: %02d/%02d/%02d", cliente->data_nasc.dia, cliente->data_nasc.mes, cliente->data_nasc.ano);
    printf("\n\tSexo: %s", cliente->sexo);
    listar_emails(cliente);
    listar_telefones(cliente);
    printf("\n\t---------------------------------\n");
}

int listar_todos_clientes(Cliente *clientes, int qtd_clientes)
{   
    if (qtd_clientes < 1)
        return 0;

    int i;
    for (i = 0; i < qtd_clientes; i++) {
        exibir_cliente(clientes+i);
    }
    return 1;
}

int listar_cliente_especifico(Cliente *clientes, char cpf[], int qtd_clientes) 
{
    int idx = buscar_cliente(clientes, cpf, qtd_clientes);

    if (idx == -1)
        return 0;

    exibir_cliente(clientes+idx);
    return 1;
}


void submenu_clientes(Cliente *clientes, int *qtd_clientes)
{   
    int opt;
    char cpf[12];
    do
    {
        printf("\n---------- Submenu de Clientes ----------");
        printf("\n1. Listar Todos");
        printf("\n2. Listar um Cliente Específico");
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
                printf("\nListando todos os clientes cadastrados...\n");
                if (!(listar_todos_clientes(clientes, *qtd_clientes)))
                    printf("\nNenhum cliente cadastrado!\n");
                break;

            case 2:
                printf("\nListando um cliente específico...\n");
                printf("\nInsira o CPF do cliente: ");
                gets(cpf);

                if (!(listar_cliente_especifico(clientes, cpf, *qtd_clientes)))
                    printf("\nCPF não encontrado.\n");
                break;

            case 3:
                printf("\nIncluindo um novo cliente...\n");

                if (incluir_cliente(clientes, qtd_clientes))
                    printf("\nCliente cadastrado com sucesso!\n");
                else
                    printf("\nCPF já cadastrado.\n");
                break;

            case 4:
                printf("\nAlterando dados de um cliente...\n");
                printf("\nInsira o CPF do cliente: ");
                gets(cpf);

                if (!(alterar_cliente(clientes, cpf, *qtd_clientes)))
                    printf("\nCPF não encontrado.\n");
                break;

            case 5:
                printf("\nExcluindo cliente...\n");
                printf("\nInsira o CPF do cliente: ");
                gets(cpf);

                if ((excluir_cliente(clientes, cpf, qtd_clientes)))
                    printf("\nCliente excluído com sucesso.\n", cpf);
                else
                    printf("\nCPF não encontrado.\n");
                break;

            case 6:
                printf("\nVoltando ao menu principal...\n");
                break;

            default:
                printf("\nOpção inválida. Por favor, escolha uma opção de 1 a 6.\n");
                break;
        }
    } while (opt != 6);
}