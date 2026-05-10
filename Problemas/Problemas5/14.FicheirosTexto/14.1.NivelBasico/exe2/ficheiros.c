#include "ficheiros.h"

#include <stdio.h>
#include <string.h>

static void remover_nova_linha(char *s)
{
    s[strcspn(s, "\n")] = '\0';
}

static int comparar_nome(const Contacto *a, const Contacto *b)
{
    return strcmp(a->nome, b->nome);
}

int ler_contactos(Contacto *lista, int max)
{
    int total = 0;

    if (lista == NULL || max <= 0) {
        return 0;
    }

    printf("Quantos contactos pretende inserir? ");
    if (scanf("%d", &total) != 1 || total <= 0 || total > max) {
        return 0;
    }
    getchar();

    for (int i = 0; i < total; i++) {
        printf("Nome do contacto %d: ", i + 1);
        if (fgets(lista[i].nome, sizeof(lista[i].nome), stdin) == NULL) {
            return 0;
        }
        remover_nova_linha(lista[i].nome);

        printf("Telefone do contacto %d: ", i + 1);
        if (fgets(lista[i].telefone, sizeof(lista[i].telefone), stdin) == NULL) {
            return 0;
        }
        remover_nova_linha(lista[i].telefone);
    }

    return total;
}

void ordenar_contactos_por_nome(Contacto *lista, int total)
{
    for (int i = 0; i < total - 1; i++) {
        for (int j = i + 1; j < total; j++) {
            if (comparar_nome(&lista[i], &lista[j]) > 0) {
                Contacto tmp = lista[i];
                lista[i] = lista[j];
                lista[j] = tmp;
            }
        }
    }
}

int guardar_contactos(const char *nome_ficheiro, const Contacto *lista, int total)
{
    FILE *f = fopen(nome_ficheiro, "w");

    if (f == NULL || lista == NULL || total <= 0) {
        return 0;
    }

    for (int i = 0; i < total; i++) {
        fprintf(f, "%s %s\n", lista[i].telefone, lista[i].nome);
    }

    fclose(f);
    return 1;
}
