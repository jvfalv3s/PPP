//Escreva um programa que converta uma quatia de euros para dolares.

#include<stdio.h>
#include<math.h>


int main(){

    float euros;
    printf("Por favor forneça a quantidade de euros");
    scanf("%f", &euros);
    float dolares = 1.1 * euros;
    printf("a quantidade de dolares convertidos são: %f", dolares);

    return 0;
}

//Correto e compilado