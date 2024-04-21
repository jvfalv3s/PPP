/*Faca um programa que construa uma matriz de NxN (N e fixado pelo porgramador) valores inteiros.
Desenvolva , ainda, as seguintes funcoes:
-Uma funcao que peca ao utilizador os valores necessarios para preencher a matriz;
-Uma funcao que construa a matriz resultante da inicial multiplicada por uma valor pedido ao utilizador*/

#include<stdio.h>
#include<stdlib.h>

void preencher_matriz(int n, int m[n][n]);
void multiplicar_matriz(int n, int m[n][n], int k);

void preencher_matriz(int n, int m[n][n]){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("m[%d][%d] = ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

void multiplicar_matriz(int n, int m[n][n], int k){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            m[i][j] *= k;
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int n = 3, m[n][n], k;
    preencher_matriz(n, m);
    printf("k = ");
    scanf("%d", &k);
    multiplicar_matriz(n, m, k);
    return 0;
}