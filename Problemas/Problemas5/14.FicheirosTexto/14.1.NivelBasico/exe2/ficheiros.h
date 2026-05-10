#ifndef FICHEIROS_H
#define FICHEIROS_H

#define MAX_NOME 100
#define MAX_CONTACTOS 200

typedef struct {
    char nome[MAX_NOME];
    char telefone[MAX_NOME];
} Contacto;

int ler_contactos(Contacto *lista, int max);
void ordenar_contactos_por_nome(Contacto *lista, int total);
int guardar_contactos(const char *nome_ficheiro, const Contacto *lista, int total);

#endif // FICHEIROS_H
