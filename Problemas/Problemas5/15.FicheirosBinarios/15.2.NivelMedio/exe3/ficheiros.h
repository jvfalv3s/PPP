#ifndef FICHEIROS_H
#define FICHEIROS_H

#define TAM_NOME 50

typedef struct {
    char nome[TAM_NOME];
    int ano;
} Pessoa;

typedef struct {
    long offsets[26];
} Indice;

int criar_ficheiro_com_indice(const char *origem, const char *destino);

#endif // FICHEIROS_H
