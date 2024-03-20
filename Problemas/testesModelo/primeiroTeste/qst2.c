//Desenvolva uma funcao que, recebendo uma cadeia de caracteres, devolva a soma dos numeros inteiros que nela se encontrem. Considere todos os numeros nao negativos.

//exemplo: input: "teste 2 de 30 programacao 40", output: 72

#include <stdio.h>

int main(){
    printf("Digite uma frase: ");
    char frase[100];
    fgets(frase, 100, stdin);
    int i = 0;
    int soma = 0;
    while(frase[i] != '\0'){
        if(frase[i] >= '0' && frase[i] <= '9'){
            int num = 0;
            while(frase[i] >= '0' && frase[i] <= '9'){
                num = num*10 + (frase[i] - '0');
                i++;
            }
            soma += num;
        }else{
            i++;
        }
    }

    printf("Soma dos numeros: %d\n", soma);

    
    return 0;
}