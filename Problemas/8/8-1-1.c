//altere o programa apresentado para que, dentro do ciclo while , apenas se usem variaveis do tipo apontador. mantendo o comportamento do programa.

//farenheit to celsius, if version.

#include<stdio.h>

int main(){
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while(1){
        celsius = (5.0/9.0) * (fahr-32);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr += step;
        if(fahr > upper) break;
    }
    return 0;
}

int main(){
    float fahr, celsius;
    float *pfahr = &fahr;
    float *pcelsius = &celsius;
    int lower, upper, step;
    int *plower = &lower;
    int *pupper = &upper;
    int *pstep = &step;

    *plower = 0;
    *pupper = 300;
    *pstep = 20;

    *pfahr = *plower;

    while(1){
        *pcelsius = (5.0/9.0) * (*pfahr-32);
        printf("%3.0f %6.1f\n", *pfahr, *pcelsius);
        *pfahr += *pstep;
        if(*pfahr > *pupper) break;
    }
}