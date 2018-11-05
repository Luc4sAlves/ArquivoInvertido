
#include "invertido.c"

//Vitor Pinheiro David
//Douglas Custodio de Araujo
//Jose Lucas Alves gomes

int main(){
    srand(time(0));
    printf("------------------ Arquivo Invertido ------------------\n");
    printf("UFRRJ - Ciencia da Computacao, Estrutura de Dados II\n");
    printf("Alunos: Douglas Custodio de Araujo\nJose Lucas Alves Gomes\nVitor Pinheiro David\n");
    printf("-------------------------------------------------------\n");
    FILE* arq = fopen("tabela.dat", "w+b");
    cria_tabela(arq);
    int option;
    int *num_reg;
    int* num_idades;
    FILE* index = index_invertido(arq, num_reg);
    if(index != NULL)
        printf("\nIndexacao realizada com sucesso!\n");

    while(option){
        printf("\nSelecione a Opcao:\n");
        printf("1 - Imprimir arquivo de saida\n2 - Imprimir arquivo de Indices\n3 - Buscar registros com idade x\n4 - Mostrar Tabela de Registros\n0 - Sair\n");
        scanf("%d", &option);
        printf("\n");
        switch(option){
        case 1:
            imprime_saida(num_reg);
            break;
        case 2:
            imprime_index(num_reg);
            break;
        case 3:
            busca_idade(num_reg);
            break;
        case 4:
            ler_clientes(arq);
            break;
        case 0:
            break;
        default:
            printf("Opcao incorreta D:\n");
            break;
        }
    }
    //adiciona_cliente(cria_cliente(5), arq);
    rewind(arq);
    //ler_clientes(arq);
    fclose(arq);
    fclose(index);

}
