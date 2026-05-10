#ifndef FICHEIROS_H
#define FICHEIROS_H

#define TAM_NOME 50

typedef struct {
    char nome[TAM_NOME];
    int ano;
} Pessoa;

int mostrar_inverso(const char *nome_ficheiro);

#endif // FICHEIROS_H
