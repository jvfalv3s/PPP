/* dada uma matriz com as coordenadas de 10 pontos do plano, usando 
apontadores, determine o comprimento da linha por eles formada*/

#include<stdio.h>
#include<math.h>

//estrutura para representar um ponto no plano
typedef struct{
    float y;
    float x;
} ponto;

//funcao que calcula a distancia entre dois pontos

int distanciaPontos(){
    ponto p1, p2;
    ponto *pp1 = &p1;
    ponto *pp2 = &p2;
    float distancia;
    float *pdistancia = &distancia;
}

int main(){
    ponto pontos[10];
    ponto *ppontos = pontos;
    int i;
    float comprimento = 0;
    float *pcomprimento = &comprimento;

    for(i = 0; i < 10; i++){
        printf("Introduza as coordenadas do ponto %d: ", i+1);
        scanf("%f %f", &ppontos[i].x, &ppontos[i].y);
    }

    for(i = 0; i < 9; i++){
        *pcomprimento += sqrt(pow(ppontos[i].x - ppontos[i+1].x, 2) + pow(ppontos[i].y - ppontos[i+1].y, 2));
    }

    printf("O comprimento da linha formada pelos pontos e: %f\n", *pcomprimento);

    return 0;
}

