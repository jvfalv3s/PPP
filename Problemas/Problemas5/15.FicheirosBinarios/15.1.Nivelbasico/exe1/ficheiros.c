#include "ficheiros.h"

#include <stdio.h>
#include <string.h>

static void remover_nova_linha(char *s)
{
    s[strcspn(s, "\n")] = '\0';
}

int ler_pessoas(Pessoa *pessoas, int max)
{
    int total;

    if (pessoas == NULL || max <= 0) {
        return 0;
    }

    printf("Numero de pessoas: ");
    if (scanf("%d", &total) != 1 || total <= 0 || total > max) {
        return 0;
    }
    getchar();

    for (int i = 0; i < total; i++) {
        printf("Nome da pessoa %d: ", i + 1);
        if (fgets(pessoas[i].nome, sizeof(pessoas[i].nome), stdin) == NULL) {
            return 0;
        }
        remover_nova_linha(pessoas[i].nome);

        printf("Ano de nascimento da pessoa %d: ", i + 1);
        if (scanf("%d", &pessoas[i].ano) != 1) {
            return 0;
        }
        getchar();
    }

    return total;
}

void ordenar_pessoas(Pessoa *pessoas, int total)
{
    for (int i = 0; i < total - 1; i++) {
        for (int j = i + 1; j < total; j++) {
            if (strcmp(pessoas[i].nome, pessoas[j].nome) > 0) {
                Pessoa tmp = pessoas[i];
                pessoas[i] = pessoas[j];
                pessoas[j] = tmp;
            }
        }
    }
}

int guardar_pessoas_binario(const char *nome_ficheiro, const Pessoa *pessoas, int total)
{
    FILE *f = fopen(nome_ficheiro, "wb");

    if (f == NULL || pessoas == NULL || total <= 0) {
        return 0;
    }

    fwrite(pessoas, sizeof(Pessoa), (size_t)total, f);
    fclose(f);
    return 1;
}
