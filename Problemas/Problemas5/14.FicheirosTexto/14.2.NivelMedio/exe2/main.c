#include <stdio.h>
#include <string.h>

#include "ficheiros.h"

static void remover_nova_linha(char *texto)
{
	size_t tamanho = strlen(texto);
	if (tamanho > 0 && texto[tamanho - 1] == '\n') {
		texto[tamanho - 1] = '\0';
	}
}

int main(void)
{
	char nome_ficheiro[MAX_NOME_FICHEIRO];

	printf("Introduza o nome do ficheiro de texto: ");
	if (fgets(nome_ficheiro, sizeof(nome_ficheiro), stdin) == NULL) {
		printf("Erro ao ler o nome do ficheiro.\n");
		return 1;
	}

	remover_nova_linha(nome_ficheiro);
	if (nome_ficheiro[0] == '\0') {
		printf("Nome de ficheiro invalido.\n");
		return 1;
	}

	if (!mostrar_ficheiro_formatado(nome_ficheiro)) {
		printf("Erro: nao foi possivel abrir o ficheiro '%s'.\n", nome_ficheiro);
		return 1;
	}

	return 0;
}
