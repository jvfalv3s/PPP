#include <stdio.h>

#include "ficheiros.h"

int main(void)
{
    int duplicados = 0;

    if (!validar_inventario("inventario.dat", &duplicados)) {
        printf("Erro a validar inventario.dat.\n");
        return 1;
    }

    if (duplicados) {
        printf("Aviso: existem referencias duplicadas no inventario.\n");
    } else {
        printf("Inventario validado sem referencias duplicadas.\n");
    }

    if (!gerar_lista_reposicao("inventario.dat", "reposicao.txt")) {
        printf("Erro a criar reposicao.txt.\n");
        return 1;
    }

    printf("Ficheiro reposicao.txt criado com sucesso.\n");
    return 0;
}
