#include <stdio.h>

#include "ficheiros.h"

int main(void)
{
    if (!criar_paljuntas("pal1.txt", "pal2.txt", "paljuntas.txt")) {
        printf("Erro ao criar paljuntas.txt.\n");
        return 1;
    }

    printf("Ficheiro paljuntas.txt criado com sucesso.\n");
    return 0;
}
