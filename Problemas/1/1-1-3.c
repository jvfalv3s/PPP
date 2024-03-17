//Construa um programa que dado o raio da base e a altura de um cilindro lhe permita calcular o volume.

#include<stdio.h>
#include<math.h>

int main(){

    int raio, altura;
    


    printf("Porfavor forneça o raio e a altura: ");
    scanf("%d, %d", &raio, &altura);
    int volume = (3.14 * (raio * raio) * altura);
    printf("o volume do cilindro é %d", volume);

    return 0;
}

//corrigido e completo.