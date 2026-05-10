#include <stdio.h>

#include "ficheiros.h"

int main(void)
{
    if (!ordenar_ficheiro_long("numeros.dat", "numeros_ordenados.dat")) {
        printf("Erro a ordenar ficheiro binario.\n");
        return 1;
    }

    printf("Ficheiro numeros_ordenados.dat criado.\n");
    return 0;
}
