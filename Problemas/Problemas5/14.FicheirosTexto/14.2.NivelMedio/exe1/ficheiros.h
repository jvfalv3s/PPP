#ifndef FICHEIROS_H
#define FICHEIROS_H

#define MAX_PALAVRA 256

int guardar_palavras_em_ficheiro(const char *nome_ficheiro);
int palavra_maior_do_ficheiro(const char *nome_ficheiro, char *maior_palavra, int capacidade);
int criar_ficheiro_palindromos(const char *origem, const char *destino);



#endif // FICHEIROS_H