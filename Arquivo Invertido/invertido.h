#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "clientes.c"

typedef struct A2{
    int ed;
	int codCliente;
	//char nome[100];
	int idade;
}A2;

typedef struct A6{
    A2* reg;
    int prox;
}A6;

typedef struct A5{
    int idade;
    int pointer;
    int qtd;

}A5;

FILE* index_invertido(FILE*, int*);
FILE* passo_1(FILE*);
FILE* passo_2(FILE*);
FILE* passo_3(FILE*, int*);
FILE* passo_4(A2**, int*);
A6** passo_5(A2**, int*, int*);
FILE* passo_6(FILE*, FILE*, int*);
//FILE* passo_5(FILE*, int*);
FILE* cria_arquivo5(A2**, int*);
int num_registros(FILE*);
static int comp_A2(const void*, const void*);
static int comp_A6(const void*, const void*);
int escreve_a2(FILE*, A2*);
A2* le_a2(FILE*);
void imprime_A2(A2*);
A6* le_a6(FILE*);

int escreve_a5(FILE*, A5*);
A5* le_a5(FILE*);
void imprime_A5(A5*);
int escreve_a6(FILE*, A6*);
void imprime_A6(A6*);
void cria_tabela(FILE*);
void imprime_saida(int*);
void imprime_index(int*);
void busca_idade(int*);
cliente** pega_idade(int, int);
