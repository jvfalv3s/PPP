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

static int e_palindromo(const char *palavra)
{
	size_t inicio = 0;
	size_t fim = strlen(palavra);

	if (fim == 0) {
		return 0;
	}

	fim--;
	while (inicio < fim) {
		if (palavra[inicio] != palavra[fim]) {
			return 0;
		}
		inicio++;
		fim--;
	}

	return 1;
}

int guardar_palavras_em_ficheiro(const char *nome_ficheiro)
{
	FILE *ficheiro = fopen(nome_ficheiro, "w");
	char buffer[MAX_PALAVRA];

	if (ficheiro == NULL) {
		return 0;
	}

	printf("Introduza palavras (linha vazia termina):\n");
	while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
		remover_nova_linha(buffer);

		if (buffer[0] == '\0') {
			break;
		}

		fprintf(ficheiro, "%s\n", buffer);
	}

	fclose(ficheiro);
	return 1;
}

int palavra_maior_do_ficheiro(const char *nome_ficheiro, char *maior_palavra, int capacidade)
{
	FILE *ficheiro = fopen(nome_ficheiro, "r");
	char buffer[MAX_PALAVRA];
	size_t maior_tamanho = 0;
	int encontrou = 0;

	if (ficheiro == NULL || capacidade <= 0) {
		return 0;
	}

	maior_palavra[0] = '\0';

	while (fgets(buffer, sizeof(buffer), ficheiro) != NULL) {
		size_t tamanho;

		remover_nova_linha(buffer);
		tamanho = strlen(buffer);

		if (tamanho > maior_tamanho) {
			strncpy(maior_palavra, buffer, (size_t)capacidade - 1);
			maior_palavra[capacidade - 1] = '\0';
			maior_tamanho = tamanho;
			encontrou = 1;
		}
	}

	fclose(ficheiro);
	return encontrou;
}

int criar_ficheiro_palindromos(const char *origem, const char *destino)
{
	FILE *ficheiro_origem = fopen(origem, "r");
	FILE *ficheiro_destino;
	char buffer[MAX_PALAVRA];

	if (ficheiro_origem == NULL) {
		return 0;
	}

	ficheiro_destino = fopen(destino, "w");
	if (ficheiro_destino == NULL) {
		fclose(ficheiro_origem);
		return 0;
	}

	while (fgets(buffer, sizeof(buffer), ficheiro_origem) != NULL) {
		remover_nova_linha(buffer);
		if (e_palindromo(buffer)) {
			fprintf(ficheiro_destino, "%s\n", buffer);
		}
	}

	fclose(ficheiro_origem);
	fclose(ficheiro_destino);
	return 1;
}
