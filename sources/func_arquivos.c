#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../headers/func_clientes.h"
#include "../headers/func_produtos.h"
#include "../headers/func_vendas.h"

void salvar_clientes(Cliente *clientes, int qtd_clientes, char *nome_arq)
{
    FILE *arq = fopen(nome_arq, "wb");

    fwrite(&qtd_clientes, sizeof(int), 1, arq);

    for (int i = 0; i < qtd_clientes; i++) {
        
        Cliente *cliente = (clientes + i);

        // Escreve os dados do cliente
        fwrite(cliente->cpf, sizeof(clientes->cpf), 1, arq);
        fwrite(clientes->nome, sizeof(clientes->nome), 1, arq);
        fwrite(clientes->sexo, sizeof(clientes->sexo), 1, arq);
        fwrite(&clientes->salario, sizeof(float), 1, arq);
        fwrite(&clientes->qtd_emails, sizeof(int), 1, arq);

        // Escreve cada email
        for (int j = 0; j < clientes->qtd_emails; j++) {
            int tamanho_email = strlen(*(clientes->emails + j)) + 1;
            fwrite(&tamanho_email, sizeof(int), 1, arq);
            fwrite(*(clientes->emails + j), sizeof(char), tamanho_email, arq);
        }

        fwrite(&clientes->qtd_telefones, sizeof(int), 1, arq);

        // Escreve cada telefone
        for (int j = 0; j < clientes->qtd_telefones; j++) {
            int tamanho_telefone = strlen(*(clientes->telefones + j)) + 1;
            fwrite(&tamanho_telefone, sizeof(int), 1, arq);
            fwrite(*(clientes->telefones + j), sizeof(char), tamanho_telefone, arq);
        }
    }
}