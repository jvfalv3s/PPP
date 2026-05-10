#include <stdio.h>
#include <string.h>

#include "ficheiros.h"

int main(void)
{
    char nome_ficheiro[256];
    char linha[MAX_LINHA];
    int tamanho = 0;

    printf("Nome do ficheiro de texto: ");
    if (fgets(nome_ficheiro, sizeof(nome_ficheiro), stdin) == NULL) {
        printf("Erro a ler nome do ficheiro.\n");
        return 1;
    }
    nome_ficheiro[strcspn(nome_ficheiro, "\n")] = '\0';

    if (!linha_mais_longa(nome_ficheiro, linha, MAX_LINHA, &tamanho)) {
        printf("Nao foi possivel obter a linha mais longa.\n");
        return 1;
    }

    printf("Linha mais longa (%d caracteres): %s\n", tamanho, linha);
    return 0;
}

    //criar o ficheiro e escrever algumas linhas
    f = fopen("ficheiro.txt", "w");
    if(f == NULL){
        printf("Erro ao criar o ficheiro.\n");
        return 1;
    }
    fprintf(f, "Esta é a primeira linha.\n");
    fprintf(f, "Esta é a segunda linha, que é um pouco mais longa.\n");
    fprintf(f, "Esta é a terceira linha.\n");
    fclose(f);
    

    f = fopen("ficheiro.txt", "r");
    if(f == NULL){
        printf("Erro ao abrir o ficheiro.\n");
        return 1;
    }

    while(fgets(linha, sizeof(linha), f) != NULL){ // fgets lê uma linha do ficheiro e armazena em 'linha'
        int len = strlen(linha);
        if(len > max){
            max = len;
        }
    }

    printf("A linha mais longa tem %d caracteres.\n", max - 1); // Subtrai 1 para não contar o '\n'

    fclose(f);
    return 0;

}