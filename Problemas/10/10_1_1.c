/*escreva um programa basico que leia uma linha de cacarteres da consola, os armazene num bloco de dimensao adequada, e determine o maior valor dos ultimos
k elementos. Devera modularizar o seu programa construindo as seguintes funcoes:
-Uma funcao que leia n inteiros e os carregue num vetor dado;
-uma funcao que calcule o valor maximo de um vetor inteiro de dados
*/

#include<stdio.h>
#include<stdlib.h>

void ler_inteiros(int n, int *p);
int maximo(int n, int *p);

void ler_inteiros(int n, int *p){
    int i;
    for(i = 0; i < n; i++){
        printf("p[%d] = ", i);
        scanf("%d", p + i);
    }
}

int maximo(int n, int *p){
    //supondo que n > 0
    int i,max;
    max = p[0];
    for(i = 1; i < n; i++){
        if(p[i] > max){
            max = p[i];
        }
    }
    return max;
}

int main(){
    int n = 0, k= 0, *p;
    printf("n = ");
    scanf("%d", &n);
    printf("k = ");
    scanf("%d", &k);
    if(k > 0 && n >= k){
        p = malloc(n * sizeof(int));
        if(p == NULL){
            printf("Erro: memmoria nao disponivel\n");
            return 1;
        }
        ler_inteiros(n, p);
        printf("Maximo dos ultimos %d elementos\n", k);

        free(p);
    }
    return 0;
}