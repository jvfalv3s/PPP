#include<stdio.h>
#include "11_1_1_fila.h"

void cria (tipoFila *fila);
void destroi(tipoFila *fila);
void insere(tipoFila *fila, double x);
int retira(tipoFila *fila, double *px);
void mostra(tipoFila *fila);

int main(){
    int i, n;
    double z;
    tipoFila fila;

    cria(&fila);
    printf("N = ");
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        printf("z[%d] = ", i);
        scanf("%lf", &z);
        insere(&fila, z);
    }
    printf("Conteudo da fila\n");
    mostra(&fila);
    printf("esvaziando a fila\n");
    while (retira(&fila, &z) == 1)
        printf("Retirado: %f\n", z);
    printf("Conteudo da fila\n");
    mostra(&fila);
    destroi(&fila);
    return 0;
}
