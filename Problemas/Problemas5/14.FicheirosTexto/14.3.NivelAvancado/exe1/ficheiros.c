#include "ficheiros.h"

#include <stdio.h>
#include <string.h>

static int indice_tipo(const Veiculo *veiculos, int total, char tipo)
{
    for (int i = 0; i < total; i++) {
        if (veiculos[i].tipo == tipo) {
            return i;
        }
    }
    return -1;
}

int ler_veiculos(const char *nome_ficheiro, Veiculo *veiculos, int max, int *total)
{
    FILE *f = fopen(nome_ficheiro, "r");
    int n = 0;

    if (f == NULL || veiculos == NULL || total == NULL) {
        return 0;
    }

    while (n < max && fscanf(f, " %c %d %lf", &veiculos[n].tipo, &veiculos[n].disponiveis, &veiculos[n].preco_diario) == 3) {
        veiculos[n].procuras = 0;
        n++;
    }

    fclose(f);
    *total = n;
    return n > 0;
}

int realizar_reservas(Veiculo *veiculos, int total_veiculos, Reserva *reservas, int max_reservas, int *total_reservas)
{
    char continuar = 's';
    int total = 0;

    if (veiculos == NULL || reservas == NULL || total_reservas == NULL) {
        return 0;
    }

    while ((continuar == 's' || continuar == 'S') && total < max_reservas) {
        Reserva r;
        int idx;

        printf("Tipo do veiculo (A/B/C...): ");
        scanf(" %c", &r.tipo);
        idx = indice_tipo(veiculos, total_veiculos, r.tipo);
        if (idx < 0) {
            printf("Tipo inexistente.\n");
            continue;
        }

        printf("Dias de aluguer: ");
        scanf("%d", &r.dias);
        getchar();

        if (r.dias <= 0 || veiculos[idx].disponiveis <= 0) {
            printf("Reserva invalida ou sem disponibilidade.\n");
            continue;
        }

        printf("Estacao de levantamento: ");
        fgets(r.estacao_levantamento, sizeof(r.estacao_levantamento), stdin);
        r.estacao_levantamento[strcspn(r.estacao_levantamento, "\n")] = '\0';

        printf("Estacao de devolucao: ");
        fgets(r.estacao_devolucao, sizeof(r.estacao_devolucao), stdin);
        r.estacao_devolucao[strcspn(r.estacao_devolucao, "\n")] = '\0';

        printf("Nome do cliente: ");
        fgets(r.nome, sizeof(r.nome), stdin);
        r.nome[strcspn(r.nome, "\n")] = '\0';

        printf("Morada do cliente: ");
        fgets(r.morada, sizeof(r.morada), stdin);
        r.morada[strcspn(r.morada, "\n")] = '\0';

        r.total_pagar = (double)r.dias * veiculos[idx].preco_diario;

        veiculos[idx].disponiveis--;
        veiculos[idx].procuras++;

        reservas[total++] = r;
        printf("Total a pagar: %.2f\n", r.total_pagar);

        printf("Pretende inserir outra reserva? (s/n): ");
        scanf(" %c", &continuar);
        getchar();
    }

    *total_reservas = total;
    return 1;
}

int guardar_reservas_binario(const char *nome_ficheiro, const Reserva *reservas, int total_reservas)
{
    FILE *f = fopen(nome_ficheiro, "wb");

    if (f == NULL || reservas == NULL || total_reservas < 0) {
        return 0;
    }

    fwrite(&total_reservas, sizeof(int), 1, f);
    if (total_reservas > 0) {
        fwrite(reservas, sizeof(Reserva), (size_t)total_reservas, f);
    }

    fclose(f);
    return 1;
}

int atualizar_ficheiro_veiculos(const char *nome_ficheiro, const Veiculo *veiculos, int total_veiculos)
{
    FILE *f = fopen(nome_ficheiro, "w");

    if (f == NULL || veiculos == NULL || total_veiculos <= 0) {
        return 0;
    }

    for (int i = 0; i < total_veiculos; i++) {
        fprintf(f, "%c %d %.2f\n", veiculos[i].tipo, veiculos[i].disponiveis, veiculos[i].preco_diario);
    }

    fclose(f);
    return 1;
}

char tipo_mais_procurado(const Veiculo *veiculos, int total_veiculos)
{
    int idx = -1;
    int maior = -1;

    for (int i = 0; i < total_veiculos; i++) {
        if (veiculos[i].procuras > maior) {
            maior = veiculos[i].procuras;
            idx = i;
        }
    }

    return idx >= 0 ? veiculos[idx].tipo : '?';
}
