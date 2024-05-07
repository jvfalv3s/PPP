/*Crie uma função que inverta a ordem dos elementos de uma lista ligada de datas. A
inversão deve ser realizada de forma a não alterar a localização física dos elementos na
lista.*/
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#include "13-2-6-header.h"
#define TAM 40


int main(){
    char tabela[3][TAM] = {"ola", "adeus", "bom dia"};
    pLista Lista = cria();
    for(int i = 0; i < 3; i++){
        insere(Lista, tabela[i]);
    }
    imprime(Lista);

    inverte(Lista);
    imprime(Lista);


    return 0;
}