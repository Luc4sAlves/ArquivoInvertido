
#include "invertido.c"

int main(){
    srand(time(0));
    FILE* arq = fopen("tabela.dat", "w+b");

    adiciona_cliente(cria_cliente(rand()), arq);
    adiciona_cliente(cria_cliente(rand()), arq);
    adiciona_cliente(cria_cliente(rand()), arq);
    adiciona_cliente(cria_cliente(rand()), arq);
    adiciona_cliente(cria_cliente(rand()), arq);
    rewind(arq);
    //ler_clientes(arq);
    FILE* arq2 = index_invertido(arq,1,4);

    fclose(arq);
    fclose(arq2);

}
