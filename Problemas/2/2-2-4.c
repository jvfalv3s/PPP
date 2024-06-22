//escreva um programa que determine  a que estacao do ano pertence uma data ( dia e mes ) fornecida pelo utilizador.

#include<stdio.h>
#include<stdlib.h>

int main(){
    int dia, mes;
    printf("Introduza o dia e o mes: ");
    scanf("%d %d", &dia, &mes);

    if(mes == 1 || mes == 2 || mes == 3){
        printf("Primavera\n");
    }

    if(mes == 4 || mes == 5 || mes == 6){
        printf("Verao\n");
    }

    if(mes == 7 || mes == 8 || mes == 9){
        printf("Outono\n");
    }

    if(mes == 10 || mes == 11 || mes == 12){
        printf("Inverno\n");
    }

    return 0;
}
//corrigido e correto.