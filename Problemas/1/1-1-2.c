//Altere o programa anterior de modo aque o programa pergunte sua idade e peso, utilizando scanf() antes de mostrar no ecrã.

#include<stdio.h>

int main(){
    int idade, peso;

    printf("Por favor digite sua idade e peso:");
    scanf("%d, %d", &idade, &peso);
    printf("Eu me chamo João Vitor Alves, eu tenho %d anos e peso %d kilos", idade, peso);

    return 0;
}

//exercicio correto e corrigido.