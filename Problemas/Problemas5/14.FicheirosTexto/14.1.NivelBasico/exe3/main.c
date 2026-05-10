#include <stdio.h>

#include "ficheiros.h"

int main(void)
{
    if (!mostrar_ficheiro("contactos.txt")) {
        printf("Nao foi possivel abrir o ficheiro contactos.txt.\n");
        return 1;
    }

    return 0;
}
