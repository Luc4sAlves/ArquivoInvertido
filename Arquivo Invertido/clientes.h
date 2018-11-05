#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Vitor Pinheiro David
//Douglas Custodio de Araujo
//Jose Lucas Alves gomes

typedef struct Cliente
{
	int codCliente;
	char nome[100];
	int idade;
}cliente;

//funções para inserção na tabela:
	cliente* cria_cliente(int idade, int cod);

	void adiciona_cliente(cliente*,FILE*);

//funções para remoção da tabela:
	void remove_cliente(FILE*);

//pesquisar:
	cliente* pesquisa_cliente();

//funções impressao:
	void ler_clientes(FILE*);

	cliente* le_cliente(FILE*);

	void imprime_cliente(cliente*);

//auxiliares:
	int tamanho_cliente();
	int le_idade(FILE*);
	int le_codigo(FILE*);

//Funcoes keep mantem o ponteiro do arquivo para o mesmo registro de antes da chamada
	int le_codigo_keep(FILE*);

	int le_idade_keep(FILE*);
//Sobrescrever campos no registro, mantem o ponteiro igual as funcoes keep

void sobrescreve_cod(FILE*, int);
void sobrescreve_status(FILE*, int);
