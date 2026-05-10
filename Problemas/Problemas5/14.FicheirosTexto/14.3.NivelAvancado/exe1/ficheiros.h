#ifndef FICHEIROS_H
#define FICHEIROS_H

#define MAX_TIPOS 50
#define MAX_RESERVAS 500
#define MAX_NOME 120

typedef struct {
    char tipo;
    int disponiveis;
    double preco_diario;
    int procuras;
} Veiculo;

typedef struct {
    char tipo;
    int dias;
    char estacao_levantamento[50];
    char estacao_devolucao[50];
    char nome[MAX_NOME];
    char morada[MAX_NOME];
    double total_pagar;
} Reserva;

int ler_veiculos(const char *nome_ficheiro, Veiculo *veiculos, int max, int *total);
int realizar_reservas(Veiculo *veiculos, int total_veiculos, Reserva *reservas, int max_reservas, int *total_reservas);
int guardar_reservas_binario(const char *nome_ficheiro, const Reserva *reservas, int total_reservas);
int atualizar_ficheiro_veiculos(const char *nome_ficheiro, const Veiculo *veiculos, int total_veiculos);
char tipo_mais_procurado(const Veiculo *veiculos, int total_veiculos);

#endif // FICHEIROS_H
