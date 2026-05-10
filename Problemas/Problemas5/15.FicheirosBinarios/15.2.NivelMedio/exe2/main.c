#include <stdio.h>
#include <string.h>

#include "ficheiros.h"

int main(void)
{
    char palavra[MAX_PALAVRA];
    int linha;

    if (!ordenar_ficheiro_palavras("palavras.txt")) {
        printf("Erro ao ordenar palavras.txt.\n");
        return 1;
    }

    printf("Palavra a inserir: ");
    if (fgets(palavra, sizeof(palavra), stdin) == NULL) {
        return 1;
    }
    palavra[strcspn(palavra, "\n")] = '\0';

    printf("Linha de insercao (1..N): ");
    if (scanf("%d", &linha) != 1) {
        return 1;
    }

    if (!inserir_palavra_linha("palavras.txt", palavra, linha)) {
        printf("Erro ao inserir palavra na linha indicada.\n");
        return 1;
    }

    printf("Operacoes concluidas em palavras.txt.\n");
    return 0;
}
