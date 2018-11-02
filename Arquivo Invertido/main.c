
#include "invertido.c"

int main(){
    srand(time(0));
    FILE* arq = fopen("tabela.dat", "w+b");
    //rand()/1000
    adiciona_cliente(cria_cliente(13), arq);
    adiciona_cliente(cria_cliente(13), arq);
    adiciona_cliente(cria_cliente(12), arq);
    adiciona_cliente(cria_cliente(13), arq);
    adiciona_cliente(cria_cliente(5), arq);
    adiciona_cliente(cria_cliente(5), arq);
    adiciona_cliente(cria_cliente(7), arq);
    adiciona_cliente(cria_cliente(5), arq);
    rewind(arq);
    //ler_clientes(arq);
    FILE* arq2 = index_invertido(arq,1,4);

    fclose(arq);
    fclose(arq2);

}
