#include <stdio.h>

#include "ficheiros.h"

int main(void)
{
    if (!mostrar_inverso("pessoas.dat")) {
        printf("Erro ao abrir pessoas.dat.\n");
        return 1;
    }

    return 0;
}
