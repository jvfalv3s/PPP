#include "ficheiros.h"

#include <stdio.h>
#include <string.h>

static void remover_nova_linha(char *texto)
{
	size_t tamanho = strlen(texto);
	if (tamanho > 0 && texto[tamanho - 1] == '\n') {
		texto[tamanho - 1] = '\0';
	}
}

static void imprimir_linha_quebrada(const char *linha)
{
	char copia[MAX_LINHA];
	char *palavra;
	int comprimento_atual = 0;

	strncpy(copia, linha, sizeof(copia) - 1);
	copia[sizeof(copia) - 1] = '\0';

	palavra = strtok(copia, " \t");
	while (palavra != NULL) {
		int tam_palavra = (int)strlen(palavra);

		if (comprimento_atual == 0) {
			printf("%s", palavra);
			comprimento_atual = tam_palavra;
		} else if (comprimento_atual + 1 + tam_palavra <= LIMITE_LINHA) {
			printf(" %s", palavra);
			comprimento_atual += 1 + tam_palavra;
		} else {
			printf("\n%s", palavra);
			comprimento_atual = tam_palavra;
		}

		palavra = strtok(NULL, " \t");
	}

	printf("\n");
}

int mostrar_ficheiro_formatado(const char *nome_ficheiro)
{
	FILE *ficheiro = fopen(nome_ficheiro, "r");
	char linha[MAX_LINHA];

	if (ficheiro == NULL) {
		return 0;
	}

	while (fgets(linha, sizeof(linha), ficheiro) != NULL) {
		remover_nova_linha(linha);

		if (linha[0] == '\0') {
			printf("\n");
		} else {
			imprimir_linha_quebrada(linha);
		}
	}

	fclose(ficheiro);
	return 1;
}
