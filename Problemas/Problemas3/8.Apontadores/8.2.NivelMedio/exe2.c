#include<stdio.h>
#include<stdlib.h>

typedef struct{

    int dia, mes, ano;

}Data;


Data encontrarMenorData(Data *vetor, int tamanho){

    Data *menor = vetor;

    Data *p = vetor + 1;
    Data *fim = vetor + tamanho;

    while(p < fim){

        if (p->ano < menor->ano){
            menor = p;
        }
        else if(p ->ano == menor-> ano){
            if(p->mes < menor->mes){
                menor = p;
            }
            else if(p->mes == menor-> mes){
                if(p->dia < menor->dia){
                    menor = p;
                }
            }
        }
        p++;
    }
    return *menor;
}


int main(){
    // Inicialização de um vetor com 10 datas
    Data datas[10] = {
        {15, 5, 2023}, {20, 1, 2024}, {1, 1, 2022}, {10, 12, 2021},
        {5, 3, 2022}, {25, 12, 2021}, {30, 6, 2023}, {14, 2, 2021},
        {1, 1, 2021}, {31, 12, 2020}
    };

    Data menor = encontrarMenorData(datas, 10);

    printf("A menor data e: %02d/%02d/%04d\n", menor.dia, menor.mes, menor.ano);

    return 0;
}