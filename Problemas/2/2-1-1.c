//escreva um programa que receba um numero e indique se e par ou impar

#include <stdio.h>

int main(){
    printf("Por favor, digite um numero: ");
    int num;
    scanf("%d", &num);
    if( num %2 == 0){
        printf("O numero e par");
    }
    else{
        printf("O numero e impar");
    }

    return 0;
}

//corrigido e compilado sem erros.