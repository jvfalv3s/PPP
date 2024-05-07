#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "13-2-3-funcoes.h"




int main (){

    int n;
    double element;
    pLista Lista1 = cria();
    pLista Lista2 = cria();
    pLista Lista3 = cria();

    printf("Insira o número de elementos da lista 1: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("Insira o elemento %d da lista 1: ", i+1);
        scanf("%lf", &element);
        insere(Lista1, element);
    }

    printf("Insira o número de elementos da lista 2: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("Insira o elemento %d da lista 2: ", i+1);
        scanf("%lf", &element);
        insere(Lista2, element);
    }

    printf("Lista 1:\n");
    imprime(Lista1);
    printf("Lista 2:\n");
    imprime(Lista2);

    junta_x(Lista1, Lista2, Lista3);
    printf("Lista 3:\n");
    imprime(Lista3);

    destroi(Lista1);
    destroi(Lista2);
    destroi(Lista3);

    return 0;
}