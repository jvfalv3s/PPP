#include <stdio.h>

#include "ficheiros.h"

int main(void)
{
    Veiculo veiculos[MAX_TIPOS];
    Reserva reservas[MAX_RESERVAS];
    int total_veiculos = 0;
    int total_reservas = 0;
    char tipo;

    if (!ler_veiculos("veiculos.txt", veiculos, MAX_TIPOS, &total_veiculos)) {
        printf("Erro ao ler veiculos.txt.\n");
        return 1;
    }

    if (!realizar_reservas(veiculos, total_veiculos, reservas, MAX_RESERVAS, &total_reservas)) {
        printf("Erro no processamento de reservas.\n");
        return 1;
    }

    if (!guardar_reservas_binario("rent_a_car.dat", reservas, total_reservas)) {
        printf("Erro ao criar rent_a_car.dat.\n");
        return 1;
    }

    if (!atualizar_ficheiro_veiculos("veiculos.txt", veiculos, total_veiculos)) {
        printf("Erro ao atualizar veiculos.txt.\n");
        return 1;
    }

    tipo = tipo_mais_procurado(veiculos, total_veiculos);
    printf("Tipo mais procurado no dia: %c\n", tipo);

    return 0;
}
