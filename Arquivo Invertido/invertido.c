#include "invertido.h"

#define oi printf("oi\n");
#define p(int, string) printf("%d, %s\n", int, string);
#define tam_a2 sizeof(int)*3

FILE* index_invertido(FILE* tabela){
    FILE* index = passo_1(tabela);
    index = passo_3(index);
    return index;
}

FILE* passo_1(FILE* tabela){
    FILE* arq2 = fopen("arquivo2.dat", "w+b");
    int i = 1;
    while(!feof(tabela)){
        A2* temp = (A2*)malloc(sizeof(A2));
        cliente* client = le_cliente(tabela);
        if(client == NULL)
            break;
        temp->codCliente = client->codCliente;
        temp->idade = client->idade;
        temp->ed = i;
        imprime_cliente(client);
        escreve_a2(arq2, temp);
        free(client);
        free(temp);
        i++;
    }
    rewind(arq2);

    while(!feof(arq2)){
        //printf("ED: %d\n", *ed);
        A2* aux = le_a2(arq2);
        if(aux == NULL)
            break;
        imprime_A2(aux);
        free(aux);
    }
    rewind(arq2);
    return arq2;

}

FILE* passo_2(FILE* arq2){
    return arq2;
}

FILE* passo_3(FILE* arq2){

    printf("Começando passo 3\n");
    int num_reg = num_registros(arq2);
    A2** vect = (A2**) malloc(sizeof(A2*)*num_reg);
    for(int i = 0; i < num_reg;i++){
        A2* temp = le_a2(arq2);
        if(temp == NULL)
            break;
        vect[i] = temp;
    }
    qsort(vect, num_reg, sizeof(A2*), comp_A2);
    for(int i = 0; i < num_reg; i++){
        imprime_A2(vect[i]);
    }
    rewind(arq2);
    fclose(arq2);
    arq2 = passo_4(vect,&num_reg);
    return arq2;
}

FILE* passo_4(A2** vect, int* num_reg){
    printf("Começando passo 4 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");

    int n = *num_reg;
    int* prox = (int*) malloc(sizeof(int)* n);

    FILE* arq5 = cria_arquivo5(vect, num_reg);
    fclose(arq5);
    FILE* arq6 = fopen("arquivo6.dat", "w+b");


    for(int i = 0; i < n; i++){
        prox[i] = -1;
        /*regs[i]->reg = NULL;
        oi
        regs[i]->prox = -1;*/
    }
    for(int i = 0; i < n-1; i++){
        if(vect[i]->idade == vect[i+1]->idade)
            prox[i] = vect[i+1]->ed;

    }
    A6** regs = ordena_reg(vect,prox,num_reg);
    printf("----------------------------------------\n");
    for(int i = 0; i < n; i++){
        imprime_A6(regs[i]);
    }
    printf("----------------------------------------\n");
    //oi
    for(int i = 0; i < n; i++){
        //imprime_A2(vect[i]);
        A6* regs = (A6*) malloc(sizeof(A6));
        //p(prox[i], "prox")
        regs->reg = vect[i];
        regs->prox = prox[i];
        //imprime_A2(regs->reg);
        //oi
        escreve_a6(arq6, regs);
        free(regs);
    }
    rewind(arq6);
    for(int i =0; i <n; i++){
        imprime_A6(le_a6(arq6));
    }
    p(5, "fim passo 4")
    //arq6 = passo_5(arq6, num_reg);
    return arq6;
}

A6** ordena_reg(A2** vect, int* prox, int* num_reg){
    oi
    //int n = *num_reg;
    p(*num_reg,"n")
    A6** regs = (A6**) malloc(sizeof(A6*)*(*num_reg));
    if(regs == NULL)
        perror("error");
    oi
    for(int i =0;i < (*num_reg);i++){
        oi
        imprime_A2(vect[i]);
        p(prox[i], "prox")
        regs[i]->reg= vect[i];
        regs[i]->prox = prox[i];
        imprime_A2(regs[i]->reg);
    }
    return regs;

}

FILE* passo_5(FILE* arq6, int* num_reg){
    A6** registros = (A6**) malloc(sizeof(A6*) * (*num_reg));
    for(int i = 0; i < *num_reg; i++){
        registros[i] = le_a6(arq6);
    }
    qsort(registros, *num_reg, sizeof(A6*), comp_A6);
}

static int comp_A6(const void *p1, const void* p2){
    A6** a1 = (A6**)p1;
    A6** a2 = (A6**)p2;

    if((*a1)->reg->codCliente > (*a2)->reg->codCliente)
        return 1;
    else if((*a1)->reg->codCliente < (*a2)->reg->codCliente)
        return -1;
    else
        return 0;
}

FILE* cria_arquivo5(A2** vect, int*num_reg){
    FILE* arq5 = fopen("arquivo5.dat", "w+b");
    int n = *num_reg;
    int* idades = (int*) malloc(sizeof(int)* n);
    int qtd_idades = 0;
    int igual = 0;
    int ultima_idade;
    int i, j;
    for(i = 0; i < n; i++){
        idades[i] = vect[i]->idade;
        for(j = 0; j < i; j++){
            if(idades[i] == idades[j])
                igual = 1;
        }
        if(!igual){
            qtd_idades++;

        }
        igual = 0;
    }

    int* pointers = (int*) malloc(sizeof(int)*qtd_idades);
    int* index_idades = (int*) malloc(sizeof(int)*qtd_idades);
    int* quantidade_reg = (int*) malloc(sizeof(int)*qtd_idades);
    int k = 1;
    index_idades[0] = vect[0]->idade;
    pointers[0] = vect[0]->ed;

    for(i = 1; i < n; i++){
        //oi
        ultima_idade = vect[i]->idade;
        if(ultima_idade == vect[i-1]->idade)
            continue;
        else{
            index_idades[k] = ultima_idade;
            pointers[k] = vect[i]->ed;
            k++;
        }
    }
    for(i = 0;i<qtd_idades;i++){
        quantidade_reg[i] = 0;
        //p(i, "i")
        //p(index_idades[i], "index")
        //p(pointers[i], "pointers")
        for(j = 0; j < n; j++){
            if(index_idades[i] == vect[j]->idade)
                quantidade_reg[i]++;
        }
        //p(quantidade_reg[i], "qtd")
        A5* temp = (A5*) malloc(sizeof(A5));
        temp->idade = index_idades[i];
        temp->pointer = pointers[i];
        temp->qtd = quantidade_reg[i];
        escreve_a5(arq5, temp);
        free(temp);

    }
    rewind(arq5);
    free(pointers);
    free(index_idades);
    free(quantidade_reg);
    free(idades);
    for(i = 0; i < qtd_idades;i++){
        imprime_A5(le_a5(arq5));
    }
    rewind(arq5);
    return arq5;
}

int num_registros(FILE* arq2){
    int i = 0;
    while(!feof(arq2)){
        A2* temp = le_a2(arq2);
        if(temp == NULL)
            break;
        else
            i++;
    }
    //printf("cabei\n");
    rewind(arq2);
    return i;
}

static int comp_A2(const void* p1, const void* p2){
    A2** a1 = (A2**)p1;
    A2** a2 = (A2**)p2;

    if((*a1)->idade > (*a2)->idade)
        return 1;
    else if((*a1)->idade < (*a2)->idade)
        return -1;
    else
        return 0;
}

int escreve_a2(FILE* arq, A2* client){
    if(!client) return 0;//verifica se o cliente é diferente de NULL
    fwrite(&client->ed, sizeof(int), 1,arq);
	fwrite(&client->codCliente, sizeof(int), 1, arq);
    fwrite(&client->idade,sizeof(int),1,arq);
    //oi
    free(client);
    fflush(arq);
    return 1;
}

int escreve_a5(FILE* arq, A5* index){
    if(!index){
        printf("A5 Nulo\n");
        return 0;
    }
    fwrite(&index->idade, sizeof(int), 1, arq);
    fwrite(&index->pointer, sizeof(int), 1, arq);
    fwrite(&index->qtd, sizeof(int), 1, arq);
}

int escreve_a6(FILE* arq, A6* registro){
    //oi
    if(!registro){
        printf("A6 NULL\n");
        return 0;
    }
    A2* client = registro->reg;
    //imprime_A2(client);
    if(!client) return 0;
    escreve_a2(arq, client);
    //oi
    /*fwrite(&client->ed, sizeof(int), 1,arq);
    oi
	fwrite(&client->codCliente, sizeof(int), 1, arq);
    fwrite(&client->idade,sizeof(int),1,arq);*/
    fwrite(&registro->prox, sizeof(int), 1, arq);
    //printf("terminando escrever a6\n");
    return 1;
}

A6* le_a6(FILE* arq){
    A6* temp = (A6*) malloc(sizeof(A6));
    temp->reg = le_a2(arq);
    if(temp->reg == NULL)
        return NULL;
    if(fread(&temp->prox, sizeof(int),1,arq)>0)
        return temp;
    else return NULL;
}

A5* le_a5(FILE* arq){
    A5* index = (A5*) malloc(sizeof(A5));
    if(fread(&index->idade, sizeof(int), 1, arq)>0){
        fread(&index->pointer, sizeof(int), 1, arq);
        fread(&index->qtd, sizeof(int), 1, arq);
        return index;
    }
    else return NULL;
}

A2* le_a2(FILE* arq){
    A2* temp = (A2*)malloc(sizeof(A2));

	if(fread(&temp->ed, sizeof(int), 1, arq) > 0){
        fread(&temp->codCliente, sizeof(int), 1, arq) > 0;
		//fread(temp->nome, sizeof(char), sizeof(temp->nome), clientesDat);
	    fread(&temp->idade,sizeof(int),1,arq);
	}
	else{
		temp = NULL;
		printf("NULL A2\n");
	}

    return temp;
}


void imprime_A5(A5* index){
    printf("**********************************************");
    printf("\nIdade Indexada: ");
    printf("%d", index->idade);
    printf("\nPonteiro para o primeiro: ");
    printf("%d", index->pointer);
    printf("\nQuantidade de registros com essa idade: ");
    printf("%d\n", index->qtd);
    printf("**********************************************\n");
}


void imprime_A6(A6* client){
    printf("**********************************************");
    printf("\nEd do cliente: ");
    printf("%d", client->reg->ed);
    printf("\nCodigo do cliente: ");
    printf("%d", client->reg->codCliente);
    printf("\nIdade do cliente: ");
    printf("%d", client->reg->idade);
    printf("\nProx do cliente: ");
    printf("%d\n", client->prox);
    printf("**********************************************\n");
}

void imprime_A2(A2* client){
    printf("**********************************************");
    printf("\nEd do cliente: ");
    printf("%d", client->ed);
    printf("\nCodigo do cliente: ");
    printf("%d", client->codCliente);
    printf("\nIdade do cliente: ");
    printf("%d\n", client->idade);
    printf("**********************************************\n");
}


