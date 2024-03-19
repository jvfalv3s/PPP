//escreva um programa que apresentados 2 numeros, indique a soma se ambos forem pares, a multiplicacao caso ambos forem impares e o impar se forem alternados.

#include<stdio.h>

int main(){

    int a, b;

    printf("apresente o primeiro numero: ");
    scanf("%d", &a);
    printf("apresente o segundo numero: ");
    scanf("%d", &b);

    if(a && b %2 == 0){
        printf("ambos sao pares logo, a + b e igual a: %d", a + b);
    }else if (a && b % 2 != 0){
        printf("ambos os numeros sao impares logo a x b e igual a: %d", a * b);
    }else{
        printf("o numero impar e: %d", b);
    }

    return 0;
}

//incorreto, pedir pro prof corrigir.