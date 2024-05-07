/*Crie uma lista ligada para conter contactos (nome e número de telefone). Mantenha a lista
ordenada por ordem alfabética crescente do nome (apenas uma diferença entre
maiúsculas e minúsculas não faz um nome ser diferente). Crie funções para colocar,
retirar e consultar a lista.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "13-2-2-headers.h"

#define NP 3

int main(){
    Contato tabela[NP] = {{"Ana", "123"}, {"Rui", "456"}, {"Pedro", "789"}};
    pLista lista = cria();
    for (int i = 0; i < NP; i++){
        insere(lista, tabela+1);
    }
    imprime(lista);

    destroi(lista);
}