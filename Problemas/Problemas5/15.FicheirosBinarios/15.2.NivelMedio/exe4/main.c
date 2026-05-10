#include <stdio.h>

#include "ficheiros.h"

int main(void)
{
    char letra;

    printf("Que letra deseja consultar? ");
    if (scanf(" %c", &letra) != 1) {
        return 1;
    }

    if (!mostrar_nomes_por_letra("pessoas_index.dat", letra)) {
        printf("Erro ao abrir/ler pessoas_index.dat.\n");
        return 1;
    }

    return 0;
}
