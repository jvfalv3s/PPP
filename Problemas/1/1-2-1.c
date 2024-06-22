//Construa um programa que determine o menor numero de notas e de moedas a devolver de troco para uma compra inferior a 100 euros.

#include<stdio.h>
#include<math.h>

int main(){

    int notas[] = {100, 50, 20, 10, 5};
    float moedas[] = {2, 1, 0.5, 0.2, 0.1, 0.05, 0.01};

    float valor;

    printf("Introduza o valor da compra: ");
    scanf("%f", &valor);

    if(valor >= 100){
        printf("Valor invalido\n");
        return 1;
    }

    printf("Notas:\n");
    for(int i = 0; i < 5; i++){
        int n = valor / notas[i];
        if(n > 0){
            printf("%d nota(s) de %d euros\n", n, notas[i]);
            valor -= n * notas[i];
        }
    }

    printf("Moedas:\n");

    //o menor numeros de moedas
    for(int i = 0; i < 7; i++) { // Adjusted for the length of the updated moedas array
        int n = valor / moedas[i];
        if(n > 0) {
            printf("%d moeda(s) de %.2f euros\n", n, moedas[i] / 100.0); // Convert cents back to euros for display
            valor -= n * moedas[i];
        }
    }
    return 0;
}