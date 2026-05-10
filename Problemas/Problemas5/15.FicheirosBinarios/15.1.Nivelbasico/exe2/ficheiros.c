#include "ficheiros.h"

#include <stdio.h>

int mostrar_inverso(const char *nome_ficheiro)
{
    FILE *f = fopen(nome_ficheiro, "rb");
    Pessoa p;
    long total;

    if (f == NULL) {
        return 0;
    }

    fseek(f, 0, SEEK_END);
    total = ftell(f) / (long)sizeof(Pessoa);

    for (long i = total - 1; i >= 0; i--) {
        fseek(f, i * (long)sizeof(Pessoa), SEEK_SET);
        if (fread(&p, sizeof(Pessoa), 1, f) == 1) {
            printf("%s - %d\n", p.nome, p.ano);
        }
    }

    fclose(f);
    return 1;
}
