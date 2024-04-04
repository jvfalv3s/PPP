/*escreva um programa que leia uma linha de caracteres da consola os armazene num bloco de memoria e identifique
a posicao em que ocorre o inicio da palavra "Wally", caso ela exista. Se a palavra nao existir o programa deve dizer-lo.
Devera modularizar o seu programa construindo e utilizando as seguintes funcoes:
-Uma funcao que leia os caracteres de uma linha e os carregue num vetor dado;
-Uma funcao que localize, numa dada cadeia de caracteres s, a posicao em que ocorre uma subcadeia w; se nao ocorrer em s
a funcao devera devolver o valor 1.*/

#include<stdio.h>
#include<stdlib.h>

void ler_linha(int n, char s[n]);
int procura_wally(char *s);

void ler_linha(int n, char s[n]){
    printf("linha = ");
    fgets(s, n, stdin);
}

int procura_wally(char *s){
    int j;
    char b[]= "Wally";
    char *p;
    for (p = s; *p != '\0'; p++){
        for(j = 0; b[j] != '\0' && b[j] == p[j]; j++);
        if(b[j] == '\0')
            return p - s;
    }
    return -1;
}

int main(){
    int n = 100, k;
    char *s;
    s = malloc(n * sizeof(char));
    if (s == NULL)
        return 1; /*erro*/
    ler_linha(n, s);
    k = procura_wally(s);
    if(k == -1)
        printf("Wally nao encontrado\n");
    else
        printf("Wally encontrado na posicao %d\n", k);

    free(s);
    return 0;
}