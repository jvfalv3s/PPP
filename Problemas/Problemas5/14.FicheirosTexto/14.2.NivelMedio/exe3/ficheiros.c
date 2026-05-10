#include "ficheiros.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

static void remover_nova_linha(char *s)
{
    s[strcspn(s, "\n")] = '\0';
}

static void minusculas(const char *origem, char *destino, int capacidade)
{
    int i;
    for (i = 0; origem[i] != '\0' && i < capacidade - 1; i++) {
        destino[i] = (char)tolower((unsigned char)origem[i]);
    }
    destino[i] = '\0';
}

static int cmp_ci(const char *a, const char *b)
{
    char aa[MAX_PALAVRA];
    char bb[MAX_PALAVRA];
    minusculas(a, aa, MAX_PALAVRA);
    minusculas(b, bb, MAX_PALAVRA);
    return strcmp(aa, bb);
}

static int existe(const char palavras[][MAX_PALAVRA], int total, const char *cand)
{
    for (int i = 0; i < total; i++) {
        if (cmp_ci(palavras[i], cand) == 0) {
            return 1;
        }
    }
    return 0;
}

static int ler_para_lista(const char *nome, char palavras[][MAX_PALAVRA], int total)
{
    FILE *f = fopen(nome, "r");
    char linha[MAX_PALAVRA];

    if (f == NULL) {
        return -1;
    }

    while (fgets(linha, sizeof(linha), f) != NULL) {
        remover_nova_linha(linha);
        if (linha[0] == '\0') {
            continue;
        }
        if (!existe(palavras, total, linha) && total < MAX_PALAVRAS) {
            strncpy(palavras[total], linha, MAX_PALAVRA - 1);
            palavras[total][MAX_PALAVRA - 1] = '\0';
            total++;
        }
    }

    fclose(f);
    return total;
}

static void ordenar_palavras(char palavras[][MAX_PALAVRA], int total)
{
    for (int i = 0; i < total - 1; i++) {
        for (int j = i + 1; j < total; j++) {
            if (cmp_ci(palavras[i], palavras[j]) > 0) {
                char tmp[MAX_PALAVRA];
                strcpy(tmp, palavras[i]);
                strcpy(palavras[i], palavras[j]);
                strcpy(palavras[j], tmp);
            }
        }
    }
}

int criar_paljuntas(const char *ficheiro1, const char *ficheiro2, const char *saida)
{
    char palavras[MAX_PALAVRAS][MAX_PALAVRA];
    int total = 0;
    FILE *out;

    total = ler_para_lista(ficheiro1, palavras, total);
    if (total < 0) {
        return 0;
    }

    total = ler_para_lista(ficheiro2, palavras, total);
    if (total < 0) {
        return 0;
    }

    ordenar_palavras(palavras, total);

    out = fopen(saida, "w");
    if (out == NULL) {
        return 0;
    }

    for (int i = 0; i < total; i++) {
        fprintf(out, "%s\n", palavras[i]);
    }

    fclose(out);
    return 1;
}
