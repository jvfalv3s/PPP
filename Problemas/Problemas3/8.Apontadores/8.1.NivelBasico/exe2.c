#include<stdio.h>
#include<stdlib.h>
//percorrer um vetor de 12 inteiros (pre-definidos) e determine a media desses valores 
//usando apontadores para percorrer o vetor

float media(int *ptr, int tamanho){

    int soma = 0;
    int *fim = ptr + tamanho; //Ponteiro que marca o limite do vetor

    //while pra percorrer o vetor usando ponteiros
    while (ptr < fim){
        soma += *ptr;
        ptr++;
    }

    return (float)soma/tamanho; // retorna a media fazendo casting de soma para float

}



int main (){

    int vetor[12] = {2,3,6,4,8,10,2,3,4,4,9,1};
    int n = 12;

    float media1 = media(vetor, n);

    printf(" A media dos valores e: %.2f\n", media1);

    return 0;
}