#include "ficheiros.h"

#include <stdio.h>
#include <string.h>

int linha_mais_longa(const char *nome_ficheiro, char *linha_saida, int capacidade, int *tamanho_maximo)
{
    FILE *f = fopen(nome_ficheiro, "r");
    char linha[MAX_LINHA];
    int max = -1;

    if (f == NULL || linha_saida == NULL || capacidade <= 0 || tamanho_maximo == NULL) {
        return 0;
    }

    linha_saida[0] = '\0';

    while (fgets(linha, sizeof(linha), f) != NULL) {
        int len = (int)strcspn(linha, "\n");
        if (len > max) {
            max = len;
            strncpy(linha_saida, linha, (size_t)capacidade - 1);
            linha_saida[capacidade - 1] = '\0';
            linha_saida[strcspn(linha_saida, "\n")] = '\0';
        }
    }

    fclose(f);

    if (max < 0) {
        return 0;
    }

    *tamanho_maximo = max;
    return 1;
}
