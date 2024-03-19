//implemente um programa em c que leia a nota de um aluno de 0 a 20 e converta na classificacao igual a da tebala.

#include<stdio.h>

int main(){
    int nota;

    printf("Por favor digite a nota: ");
    scanf("%d", &nota);

    if(nota < 10){
        printf("Nota insuficiente");
    } else if ( nota < 14){
        printf("Nota suficiente");
    }else if ( nota < 17){
        printf( "Nota Boa");
    } else {
        printf("Nota excelente");
    }


    return 0;
}

//corrigido e compilado corretamente.