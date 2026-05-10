#include "ficheiros.h"

#include <ctype.h>
#include <stdio.h>

int criar_ficheiro_com_indice(const char *origem, const char *destino)
{
    FILE *fi = fopen(origem, "rb");
    FILE *fo;
    Indice idx;
    Pessoa p;
    long pos;

    if (fi == NULL) {
        return 0;
    }

    for (int i = 0; i < 26; i++) {
        idx.offsets[i] = 0;
    }

    fo = fopen(destino, "wb");
    if (fo == NULL) {
        fclose(fi);
        return 0;
    }

    fwrite(&idx, sizeof(Indice), 1, fo);

    while (fread(&p, sizeof(Pessoa), 1, fi) == 1) {
        pos = ftell(fo);
        fwrite(&p, sizeof(Pessoa), 1, fo);

        if (p.nome[0] != '\0') {
            int letra = toupper((unsigned char)p.nome[0]) - 'A';
            if (letra >= 0 && letra < 26 && idx.offsets[letra] == 0) {
                idx.offsets[letra] = pos;
            }
        }
    }

    rewind(fo);
    fwrite(&idx, sizeof(Indice), 1, fo);

    fclose(fi);
    fclose(fo);
    return 1;
}
