//considere um vetor de 12 inteiros pre definidos. Crie uma funcao que determine a media desses valores, usando apontadores para correr o vetor.
#include<stdio.h>
#define TAM 12

double media(int n, int v[n]);

int main(){
    int v[TAM] = {1,2,3,4,5,6,7,8,9,10,11,12};
    printf("media = %f\n", media(TAM, v));


    return 0;
}

double media(int n, int v[n]){
    int soma = 0;
    int *p = v + n;
    for(; v < p; v++) //o for pode ter a primeira posicao vazia.
        soma += *v;
    return (double)soma /TAM;
}