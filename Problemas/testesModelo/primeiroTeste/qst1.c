//Assuma que  a seguinte funcao e invocada com limite = 6 e que todas as  posicoes validas  e necessarias de array, foram inicializadas com 0.

#include <stdio.h>

int something(int array[], int limit){
    int count = 0, i;
    for (i = 2; i <= limit; i++){
        if (array[i] == 0){
            count++;
            for(int j = i * i; j <= limit; j += i){
                array[j] = 1;
            }
        }
    }
    return count;
}

int main(){
    int array[6] = {0, 0, 0, 0, 0, 0};
    printf("%d\n", something(array, 6));
    return 0;
}