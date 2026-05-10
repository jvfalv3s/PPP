#include <stdio.h>

#include "ficheiros.h"

int main(void)
{
    Estatisticas dados;
    double media;

    if (!ler_numeros_ficheiro("numeros.txt", &dados)) {
        printf("Erro ao ler numeros.txt.\n");
        return 1;
    }

    if (!criar_relatorio("relatorio.txt", &dados)) {
        printf("Erro ao criar relatorio.txt.\n");
        return 1;
    }

    printf("Diferenca (maior-menor): %d\n", diferenca_maior_menor(&dados));

    media = media_numeros(&dados);
    printf("Media: %.2f\n", media);

    if (!criar_ficheiro_acima_media("acima_media.txt", &dados, media)) {
        printf("Erro ao criar acima_media.txt.\n");
        return 1;
    }

    printf("Relatorios criados com sucesso.\n");
    return 0;
}
