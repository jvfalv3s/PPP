//escreva um programa que determine  a que estacao do ano pertence uma data ( dia e mes ) fornecida pelo utilizador.

#include<stdio.h>

int main(){
    char estacao[4] = {"Inverno", "Primavera", "Verao", "Outono"};
    int dia, mes;

    printf("Por favor digite o dia: ");
    scanf("%d", &dia);
    printf("Por favor digite o mes: ");
    scanf("%d", &mes);

    if(mes < 3 || (mes == 3 && dia < 21) || (mes == 6 && dia > 20)){
        printf("Estamos na estacao do ano: %s", estacao[0]);
    } else if (mes < 6 || (mes == 6 && dia < 21) || (mes == 9 && dia > 20)){
        printf("Estamos na estacao do ano: %s", estacao[1]);
    } else if (mes < 9 || (mes == 9 && dia < 21) || (mes == 12 && dia > 20)){
        printf("Estamos na estacao do ano: %s", estacao[2]);
    } else {
        printf("Estamos na estacao do ano: %s", estacao[3]);
    }

    return 0;
}

//errado e pedir ao proff para corrigir.