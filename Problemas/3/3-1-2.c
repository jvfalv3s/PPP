/*Escreva um programa que vá somando todos os números inteiros começando pelo
1 e que termine quando a soma ultrapasse um limite indicado pelo utilizador. Por
exemplo, se o utilizador tiver indicado 5 deverá adicionar os números 1, 2 e 3, visto
que a sua soma dá 6 enquanto 1 + 2 dá apenas 3. No final deve indicar o número
em que parou*/

#include<stdio.h>

int main(){
    int limite, soma = 0, i = 1;

    printf("Por favor digite o limite: ");
    scanf("%d", &limite);

    while(soma <= limite){
        soma += i;
        i++;
    }

    printf("A soma de todos os numeros desde 1 ate %d e: %d", i-1, soma);

    return 0;
}

//corrigido e compilado sem erros.