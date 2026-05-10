#include "ficheiros.h"

#include <stdio.h>
#include <string.h>

static void remover_nova_linha(char *s)
{
    s[strcspn(s, "\n")] = '\0';
}

static int ler_palavras(const char *nome_ficheiro, char palavras[][MAX_PALAVRA], int max)
{
    FILE *f = fopen(nome_ficheiro, "r");
    int total = 0;

    if (f == NULL) {
        return -1;
    }

    while (total < max && fgets(palavras[total], MAX_PALAVRA, f) != NULL) {
        remover_nova_linha(palavras[total]);
        if (palavras[total][0] != '\0') {
            total++;
        }
    }

    fclose(f);
    return total;
}

static int guardar_palavras(const char *nome_ficheiro, char palavras[][MAX_PALAVRA], int total)
{
    FILE *f = fopen(nome_ficheiro, "w");

    if (f == NULL) {
        return 0;
    }

    for (int i = 0; i < total; i++) {
        fprintf(f, "%s\n", palavras[i]);
    }

    fclose(f);
    return 1;
}

int ordenar_ficheiro_palavras(const char *nome_ficheiro)
{
    char palavras[MAX_PALAVRAS][MAX_PALAVRA];
    int total = ler_palavras(nome_ficheiro, palavras, MAX_PALAVRAS);

    if (total < 0) {
        return 0;
    }

    for (int i = 0; i < total - 1; i++) {
        for (int j = i + 1; j < total; j++) {
            if (strcmp(palavras[i], palavras[j]) > 0) {
                char tmp[MAX_PALAVRA];
                strcpy(tmp, palavras[i]);
                strcpy(palavras[i], palavras[j]);
                strcpy(palavras[j], tmp);
            }
        }
    }

    return guardar_palavras(nome_ficheiro, palavras, total);
}

int inserir_palavra_linha(const char *nome_ficheiro, const char *palavra, int linha)
{
    char palavras[MAX_PALAVRAS][MAX_PALAVRA];
    int total = ler_palavras(nome_ficheiro, palavras, MAX_PALAVRAS - 1);

    if (total < 0 || palavra == NULL || linha <= 0 || linha > total + 1) {
        return 0;
    }

    for (int i = total; i >= linha; i--) {
        strcpy(palavras[i], palavras[i - 1]);
    }

    strncpy(palavras[linha - 1], palavra, MAX_PALAVRA - 1);
    palavras[linha - 1][MAX_PALAVRA - 1] = '\0';
    total++;

    return guardar_palavras(nome_ficheiro, palavras, total);
}
