#include "ficheiros.h"

#include <stdio.h>

int validar_inventario(const char *ficheiro_binario, int *tem_duplicados)
{
    FILE *f = fopen(ficheiro_binario, "rb");
    Item itens[MAX_ITENS];
    int total = 0;

    if (f == NULL || tem_duplicados == NULL) {
        return 0;
    }

    *tem_duplicados = 0;

    while (total < MAX_ITENS && fread(&itens[total], sizeof(Item), 1, f) == 1) {
        total++;
    }
    fclose(f);

    for (int i = 0; i < total; i++) {
        for (int j = i + 1; j < total; j++) {
            if (itens[i].referencia == itens[j].referencia) {
                *tem_duplicados = 1;
            }
        }
    }

    return 1;
}

int gerar_lista_reposicao(const char *ficheiro_binario, const char *ficheiro_texto)
{
    FILE *fb = fopen(ficheiro_binario, "rb");
    FILE *ft = fopen(ficheiro_texto, "w");
    Item item;

    if (fb == NULL || ft == NULL) {
        if (fb != NULL) fclose(fb);
        if (ft != NULL) fclose(ft);
        return 0;
    }

    while (fread(&item, sizeof(Item), 1, fb) == 1) {
        if (item.quantidade < 10) {
            fprintf(ft, "Ref:%d | Desc:%s | Qtd:%d\n", item.referencia, item.descricao, item.quantidade);
        }
    }

    fclose(fb);
    fclose(ft);
    return 1;
}
