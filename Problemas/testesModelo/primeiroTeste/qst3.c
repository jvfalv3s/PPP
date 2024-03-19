/*escreva o codigo de uma funcao com o seguinte prototipo void stirling2(int m, int S[m+1][m+1]); que dada uma matriz quadrada de dimensao apropriada, a preencha com os
os numeros de sterling de segunda especie  para todos os valores de n e k ate um dado valor de m, inclusive.

S(n,0) = 0, para todo n> 0
S(n, k) = k, para */

#include<stdio.h>
#define M 5

void stirling2(int m, int S[m+1][m+1]);

int main(){
    int S[M + 1][M + 1];
    int n, k;
    stirling2(M, S);
    for(n = 0; n <= M; n++){
        for(k = 0; k <= M; k++)
            printf("%6d ", S[n][k]);
        printf("\n");
    }
    return 0;
}

void stirling2(int m, int S[m+1][m+1]){
    int n, k;
    for (n = 0; n <= m; n++)
        for(k = 0; k <= n; k++)
            if (k == n)
                S[n][k] = 1;
            else if (k == 0)
                S[n][k] = 0;
            else
                S[n][k] = k * S[n - 1][k] + S[n - 1][k - 1];
}

//corrigido pelo professor.