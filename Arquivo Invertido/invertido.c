#include "invertido.h"

#define oi printf("oi\n");
#define p(int, string) printf("%d, %s\n", int, string);

FILE* index_invertido(FILE* tabela, int n, int* tam){
    FILE* arq2 = fopen("arquivo2.dat", "w+b");
    int i = 1;

    while(!feof(tabela)){
        A2* temp = (A2*)malloc(sizeof(A2));
        temp->ed = i;
        temp->cliente = le_cliente(tabela);
        if(temp->cliente == NULL)
            break;
        imprime_cliente(temp->cliente);
        escreve_a2(temp->cliente, arq2,temp->ed);
        free(temp);
        i++;
    }

    int* ed;
    rewind(arq2);
    while(!feof(arq2)){
        fread(ed, sizeof(int), 1, arq2);
        //printf("ED: %d\n", *ed);
        cliente* aux = le_a2(arq2);
        if(aux == NULL)
            break;
        imprime_cliente(aux);
        free(aux);
    }
    return arq2;

}

int escreve_a2(FILE* arq, cliente* client, ind ed){
    if(!client) return; //verifica se o cliente é diferente de NULL
    fwrite(&ed, sizeof(int), 1,arq);
	fwrite(&client->codCliente, sizeof(int), 1, arq);
    fseek(arq, sizeof(client->nome), SEEK_CUR);
    fwrite(&client->idade,sizeof(int),1,arq);
    free(client);
    fflush(out);
}

cliente* le_a2(FILE* arq){
    cliente* temp = (cliente*)malloc(sizeof(cliente));

	if(fread(&temp->codCliente, sizeof(int), 1, arq) > 0){
		//fread(temp->nome, sizeof(char), sizeof(temp->nome), clientesDat);
		fseek(arq, sizeof(client->nome), SEEK_CUR);
	    fread(&temp->idade,sizeof(int),1,arq);
	}
	else{
		temp = NULL;
		printf("NULL\n");
	}

    return temp;

}


