#ifndef FICHEIROS_H
#define FICHEIROS_H

#define MAX_PALAVRAS 1000
#define MAX_PALAVRA 128

int ordenar_ficheiro_palavras(const char *nome_ficheiro);
int inserir_palavra_linha(const char *nome_ficheiro, const char *palavra, int linha);

#endif // FICHEIROS_H
