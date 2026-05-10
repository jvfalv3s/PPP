#include <stdio.h>

#include "ficheiros.h"

int main(void)
{
	char maior_palavra[MAX_PALAVRA];

	if (!guardar_palavras_em_ficheiro("palavras.txt")) {
		printf("Erro: nao foi possivel criar o ficheiro palavras.txt.\n");
		return 1;
	}

	if (palavra_maior_do_ficheiro("palavras.txt", maior_palavra, MAX_PALAVRA)) {
		printf("Palavra com mais caracteres: %s\n", maior_palavra);
	} else {
		printf("Nao existem palavras validas no ficheiro palavras.txt.\n");
	}

	if (!criar_ficheiro_palindromos("palavras.txt", "palin.txt")) {
		printf("Erro: nao foi possivel criar o ficheiro palin.txt.\n");
		return 1;
	}

	printf("Ficheiro palin.txt criado com sucesso.\n");
	return 0;
}
