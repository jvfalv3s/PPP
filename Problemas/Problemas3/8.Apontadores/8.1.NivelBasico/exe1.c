#include<stdio.h>

int main(){
    //variaveis normais
    float fahr, celsius;
    int lower, upper, step;

    //declaracao dos ponteiros
    float *pfahr, *pcelsius;
    int *pupper, *pstep;

    //inicilizacao das variaveis
    lower = 0;
    upper = 300;
    step = 20;
    fahr = lower;

    //Atribuição dos endereços aos ponteiros
    pfahr =  &fahr;
    pcelsius = &celsius;
    pupper = &upper;
    pstep = &step;

    while(1){
        *pcelsius = (5.0/9.0) * (*pfahr-32);
        printf("%3.0f %6.1f\n", *pfahr, *pcelsius);
        *pfahr += *pstep;
        if(*pfahr > *pupper) {
        break;
        }
    

    }
    return 0;
}