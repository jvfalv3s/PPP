//escreva um programa que receba tres numeros e indique o maior

#include<stdio.h>

int main(){
    int a, b, c;

    printf("Por favor indique o primeiro numero: ");
    scanf("%d", &a);
    printf("Por favor indique o segundo numero: ");
    scanf("%d", &b);
    printf("Por favor indique o terceiro numero: ");
    scanf("%d", &c);

    if (a > c && a > b){
        printf("o maior numero e : %d", a);
    }
    else if(b > c && b > a){
        printf("o maior numero e %d", b);

    }else{
        printf("o maior numero e %d", c);
    }


    return 0;
}

//corrigido e compilado sem erros.