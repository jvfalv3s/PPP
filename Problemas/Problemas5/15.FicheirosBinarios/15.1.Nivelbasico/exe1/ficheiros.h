#ifndef FICHEIROS_H
#define FICHEIROS_H

#define MAX_PESSOAS 500
#define TAM_NOME 50

typedef struct {
    char nome[TAM_NOME];
    int ano;
} Pessoa;

int ler_pessoas(Pessoa *pessoas, int max);
void ordenar_pessoas(Pessoa *pessoas, int total);
int guardar_pessoas_binario(const char *nome_ficheiro, const Pessoa *pessoas, int total);

#endif // FICHEIROS_H
