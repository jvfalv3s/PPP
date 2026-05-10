#ifndef FICHEIROS_H
#define FICHEIROS_H

#define MAX_NUMEROS 5000

typedef struct {
    int numeros[MAX_NUMEROS];
    int total;
    int maior;
    int menor;
} Estatisticas;

int ler_numeros_ficheiro(const char *nome, Estatisticas *dados);
int criar_relatorio(const char *nome, const Estatisticas *dados);
int diferenca_maior_menor(const Estatisticas *dados);
double media_numeros(const Estatisticas *dados);
int criar_ficheiro_acima_media(const char *nome, const Estatisticas *dados, double media);

#endif // FICHEIROS_H
