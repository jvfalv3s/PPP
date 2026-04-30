#include<stdio.h>

int vetorInt[] = {1,2,3,4,5,7};

void dobroImpar(){

    for(int i = 0; i < 7; i++){
        if(vetorInt[i] % 2 != 0){
            vetorInt[i] = vetorInt[i] * 2;
        }
    }
    for(int i = 0; i < 7; i++){
        printf("%d ", vetorInt[i]);
    }
}

int main(){
    dobroImpar();
    return 0;
}