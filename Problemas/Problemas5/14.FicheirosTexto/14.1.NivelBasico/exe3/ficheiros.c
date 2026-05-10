#include "ficheiros.h"

#include <stdio.h>

int mostrar_ficheiro(const char *nome_ficheiro)
{
    FILE *f = fopen(nome_ficheiro, "r");
    int c;

    if (f == NULL) {
        return 0;
    }

    while ((c = fgetc(f)) != EOF) {
        putchar(c);
    }

    fclose(f);
    return 1;
}
