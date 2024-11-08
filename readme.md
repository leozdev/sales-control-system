# Projeto Final - Controle de Vendas

Este é o projeto final desenvolvido para a disciplina de **Algoritmos e Programação 2**, ministrada pela **Professora Eloize Seno**. O objetivo do projeto é desenvolver uma aplicação para o controle de vendas de produtos em um supermercado, utilizando conceitos de vetores, strings, registros e funções em linguagem C.

## Objetivo do Projeto

A aplicação permite:

- Armazenar e gerenciar informações de clientes, produtos e vendas realizadas.
- Realizar operações de listagem, inclusão, alteração e exclusão para cada entidade (clientes, produtos, vendas).
- Gerar relatórios específicos sobre clientes, produtos e vendas, de acordo com critérios determinados pelo usuário.

## Funcionalidades Principais

### Entidades e Atributos

1. **Cliente**
   - CPF (Chave)
   - Nome
   - Data de Nascimento
   - Sexo
   - Salário
   - E-mails
   - Telefones

2. **Produto**
   - Código (Chave)
   - Descrição
   - Tamanho
   - Peso
   - Altura
   - Largura
   - Preço
   - Desconto
   - Data de Validade

3. **Venda**
   - CPF do Cliente (Chave)
   - Código do Produto (Chave)
   - Data (Chave)
   - Hora (Chave)
   - Valor

### Menu de Opções

1. **Submenu de Clientes**: Listar, incluir, alterar e excluir clientes.
2. **Submenu de Produtos**: Listar, incluir, alterar e excluir produtos.
3. **Submenu de Vendas**: Listar, incluir, alterar e excluir vendas.
4. **Submenu de Relatórios**:
   - Clientes com mais de X telefones.
   - Produtos com data de validade expirada.
   - Vendas realizadas entre datas específicas fornecidas pelo usuário.
5. **Sair**

### Regras e Restrições

- **Chaves únicas**: Não é permitido cadastrar mais de um registro com valores repetidos nos atributos-chave.
- **Persistência de Dados**: O sistema deve utilizar arquivos para armazenamento permanente dos dados.

---
