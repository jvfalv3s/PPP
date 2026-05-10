#include <stdio.h>

#include "ficheiros.h"

int main(void)
{
    Contacto lista[MAX_CONTACTOS];
    int total = ler_contactos(lista, MAX_CONTACTOS);

    if (total <= 0) {
        printf("Dados invalidos para contactos.\n");
        return 1;
    }

    ordenar_contactos_por_nome(lista, total);

    if (!guardar_contactos("contactos.txt", lista, total)) {
        printf("Nao foi possivel guardar o ficheiro contactos.txt.\n");
        return 1;
    }

    printf("Ficheiro contactos.txt criado com sucesso.\n");
    return 0;
}
