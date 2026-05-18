#ifndef FICHEIROS_H
#define FICHEIROS_H

#define TAM_NOME 50

typedef struct {
    char nome[TAM_NOME];
    int ano;
} Pessoa;

typedef struct {
    long alfabeto[26];
} Indice;

int mostrar_nomes_por_letra(const char *ficheiro, char letra);

#endif // FICHEIROS_H
