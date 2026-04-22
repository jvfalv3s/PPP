#include<stdio.h>
#include<math.h>

double calcularComprimento(double *ptr, int numPontos){
    double comprimentoTotal = 0.0;

    for(int i = 0; i < numPontos-1; i++){
        double x1 = *ptr;
        double y1 = *(ptr + 1);

        double x2 = *(ptr + 2);
        double y2 = *(ptr + 3);

        double distancia = sqrt(pow(x2 - x1, 2) * pow(y2 - y1, 2));
        comprimentoTotal += distancia;

        ptr +=2;
    }
    return comprimentoTotal;
}

int main(){

    double pontos[10][2] = {{0,0}, {1,1}, {2, 0}, {3, 1}, {4, 0},
        {5, 1}, {6, 0}, {7, 1}, {8, 0}, {9, 1}};

        
    double comprimento = calcularComprimento(&pontos[0][0], 10);

    printf("O comprimento total da linha formada pelos pontos e: %.4f\n", comprimento);

    return 0;
}