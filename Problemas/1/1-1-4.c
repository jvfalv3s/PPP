//Desenvolva um programa que determine a hipotenusa de um triângulo retângulo dado os valores dos seus catetos.

#include<stdio.h>
#include<math.h>

int main(){

    int cateto1, cateto2;
    printf("Por favor forneça o tamanho dos catetos");
    scanf("%d %d", &cateto1, &cateto2);
    double hipotenusa = sqrt(cateto1 * cateto1 + cateto2 * cateto2);
    printf("O valor da hipotenusa é: %f", hipotenusa);

    return 0;
}

//algum erro quanto a library math.h
//compilação com erro.z 