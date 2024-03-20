//crie um programa que calcule a soma de todos os numeros desde 1 ate um dado limite pedido ao utilizador

#include<stdio.h>

int main(){
    int limite, soma = 0;

    printf("Por favor digite o limite: ");
    scanf("%d", &limite);

    for(int i = 1; i <= limite; i++){
        soma += i;
    }

    printf("A soma de todos os numeros desde 1 ate %d e: %d", limite, soma);
    
    return 0;
}

//correto e compilado sem erros.