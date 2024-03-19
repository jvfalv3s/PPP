//escreva um programa para determinar cada tipo de bilhete baseado na tabela.

#include<stdio.h>

int main(){
    int idade;
    printf("por favor me indique sua idade: ");
    scanf("%d", &idade);

    if( idade < 12  && idade > 61){
        printf("O bilhete e insento de pagamento");
    }
    if(idade > 12 && idade < 24){
        printf("o bilhete paga pela tarifa radical");

    } else if(idade > 37 && idade < 48){
        printf("o bilhete paga a tarifa normal");
    } else{
        printf("o bilhete paga a tarifa light");
    }


    return 0;
}

//corrigido e compilado corretamente