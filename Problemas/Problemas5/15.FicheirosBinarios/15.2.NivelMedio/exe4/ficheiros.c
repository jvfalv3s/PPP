#include "ficheiros.h"

#include <ctype.h>
#include <stdio.h>

int mostrar_nomes_por_letra(const char *ficheiro, char letra)
{
    FILE *f = fopen(ficheiro, "rb");
    Indice idx;
    Pessoa p;
    int alvo;
    long inicio;

    if (f == NULL) {
        return 0;
    }

    if (fread(&idx, sizeof(Indice), 1, f) != 1) {
        fclose(f);
        return 0;
    }

    alvo = toupper((unsigned char)letra) - 'A';
    if (alvo < 0 || alvo > 25 || idx.offsets[alvo] == 0) {
        fclose(f);
        return 1;
    }

    inicio = idx.offsets[alvo];
    fseek(f, inicio, SEEK_SET);

    while (fread(&p, sizeof(Pessoa), 1, f) == 1) {
        if (toupper((unsigned char)p.nome[0]) != toupper((unsigned char)letra)) {
            break;
        }
        printf("%s - %d\n", p.nome, p.ano);
    }

    fclose(f);
    return 1;
}
