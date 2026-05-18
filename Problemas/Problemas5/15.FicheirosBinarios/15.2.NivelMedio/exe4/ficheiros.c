#include "ficheiros.h"

#include <ctype.h>
#include <stdio.h>

int mostrar_nomes_por_letra(const char *ficheiro, char letra)
{
    FILE *f = fopen(ficheiro, "rb");
    //ler o ficheiro binario e mostrar ao utilizador quala a letra do alfabeto cujos nomes quer ver;
    //criar um indice para o ficheiro, onde cada letra conta o offset da primeira letra do nome (como na struct indice valur alfabeto)


    //verificar a tipagem do ficheiro binario, nesse exemplo comparar o vetor com o alfabeto do struct no header.

    fclose(f);
    return 1;
}

int criar_nomes_binario(const char *ficheiro)
{
    FILE *f = fopen(ficheiro, "wb");
    if (!f) {
        return 0;
    }

    Pessoa pessoas[] = {
        {"Alice", 1990},
        {"Bob", 1985},
        {"Charlie", 1992},
        {"David", 1988},
        {"Eve", 1991}
    };

    for (size_t i = 0; i < sizeof(pessoas) / sizeof(pessoas[0]); i++) {
        fwrite(&pessoas[i], sizeof(Pessoa), 1, f);
    }

    fclose(f);
    return 1;
}
