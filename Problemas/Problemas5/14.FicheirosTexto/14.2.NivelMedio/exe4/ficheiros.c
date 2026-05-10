#include "ficheiros.h"

#include <stdio.h>

int ler_numeros_ficheiro(const char *nome, Estatisticas *dados)
{
    FILE *f = fopen(nome, "r");
    int n;

    if (f == NULL || dados == NULL) {
        return 0;
    }

    dados->total = 0;

    while (fscanf(f, "%d", &n) == 1) {
        if (dados->total >= MAX_NUMEROS) {
            break;
        }

        dados->numeros[dados->total] = n;
        if (dados->total == 0) {
            dados->maior = n;
            dados->menor = n;
        } else {
            if (n > dados->maior) {
                dados->maior = n;
            }
            if (n < dados->menor) {
                dados->menor = n;
            }
        }
        dados->total++;
    }

    fclose(f);
    return dados->total > 0;
}

int criar_relatorio(const char *nome, const Estatisticas *dados)
{
    FILE *f = fopen(nome, "w");

    if (f == NULL || dados == NULL || dados->total <= 0) {
        return 0;
    }

    fprintf(f, "quantidade=%d\n", dados->total);
    fprintf(f, "maior=%d\n", dados->maior);
    fprintf(f, "menor=%d\n", dados->menor);
    fprintf(f, "numeros=");
    for (int i = 0; i < dados->total; i++) {
        fprintf(f, "%d", dados->numeros[i]);
        if (i < dados->total - 1) {
            fprintf(f, " ");
        }
    }
    fprintf(f, "\n");

    fclose(f);
    return 1;
}

int diferenca_maior_menor(const Estatisticas *dados)
{
    if (dados == NULL || dados->total <= 0) {
        return 0;
    }
    return dados->maior - dados->menor;
}

double media_numeros(const Estatisticas *dados)
{
    long soma = 0;

    if (dados == NULL || dados->total <= 0) {
        return 0.0;
    }

    for (int i = 0; i < dados->total; i++) {
        soma += dados->numeros[i];
    }

    return (double)soma / (double)dados->total;
}

int criar_ficheiro_acima_media(const char *nome, const Estatisticas *dados, double media)
{
    FILE *f = fopen(nome, "w");
    int primeiro = 1;
    int total = 0;
    int maior = 0;
    int menor = 0;

    if (f == NULL || dados == NULL || dados->total <= 0) {
        return 0;
    }

    for (int i = 0; i < dados->total; i++) {
        if ((double)dados->numeros[i] > media) {
            int n = dados->numeros[i];
            if (primeiro) {
                maior = menor = n;
                primeiro = 0;
            } else {
                if (n > maior) {
                    maior = n;
                }
                if (n < menor) {
                    menor = n;
                }
            }
            total++;
        }
    }

    fprintf(f, "quantidade=%d\n", total);
    if (total > 0) {
        fprintf(f, "maior=%d\n", maior);
        fprintf(f, "menor=%d\n", menor);
    } else {
        fprintf(f, "maior=NA\n");
        fprintf(f, "menor=NA\n");
    }

    fprintf(f, "numeros=");
    for (int i = 0; i < dados->total; i++) {
        if ((double)dados->numeros[i] > media) {
            fprintf(f, "%d ", dados->numeros[i]);
        }
    }
    fprintf(f, "\n");

    fclose(f);
    return 1;
}
