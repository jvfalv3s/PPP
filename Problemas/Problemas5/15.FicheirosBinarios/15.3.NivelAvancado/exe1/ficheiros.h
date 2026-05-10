#ifndef FICHEIROS_H
#define FICHEIROS_H

#define MAX_DESC 80
#define MAX_ITENS 5000

typedef struct {
    int referencia;
    char descricao[MAX_DESC];
    int quantidade;
} Item;

int validar_inventario(const char *ficheiro_binario, int *tem_duplicados);
int gerar_lista_reposicao(const char *ficheiro_binario, const char *ficheiro_texto);

#endif // FICHEIROS_H
