//implementar um algoritmo que modifica o formato de horas de 24h para 12.

#include<stdio.h>

int main(){
    int hora, minutos;
    printf("por favor me indique a hora: ");
    scanf("%d", &hora);

    //preciso que conte os minutos tambem:
    printf("por favor me indique os minutos: ");
    scanf("%d", &minutos);

    if(hora > 12){
        printf("A hora e: %d:%d PM", hora-12, minutos);
    } else{
        printf("A hora e: %d:%d AM", hora, minutos);
    }

    return 0;
}

//corrigido e compilado corretamente