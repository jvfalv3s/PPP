/*Retire strings de uma lista de strings até ela estar vazia, e mostre no ecrã quantas strings
leu, e qual a string com mais carateres*/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

# include "13-1-3-headers.h"

#define TAM 40

#define nSTR 3

int main(){
    char tabela[nSTR][TAM] = {"ola", "adeus", "bom dia"};
    pLista Lista = cria();
    for(int i = 0; i < nSTR; i++){
        insere(Lista, tabela[i]);
    }
    imprime(Lista);

    char maisLonga[TAM] = "", *aux;
    int n = 0;
    while(!vazia(Lista)){
        aux = Lista->prox->nome;
        if(strlen(maisLonga) < strlen(aux))
            strcpy(maisLonga, aux);
        elimina(Lista, aux);
        n++;
    }
    printf("%d strings, mais longa = \"%s\" de comprimento %ld\n", n, maisLonga, strlen(maisLonga));

    destroi(Lista);
    return 0;
}