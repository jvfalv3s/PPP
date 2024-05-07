/*Desenvolva uma aplicação capaz de receber do utilizador um dado número de palavras
(a introdução de palavras termina com uma linha vazia), armazenando-as num ficheiro
de texto (uma em cada linha), de nome “palavras.txt”. Para além disso desenvolva
funções para:
• indicar qual a palavra com mais carateres existente no ficheiro;
• criar um novo ficheiro (de nome “palin.txt”) que contenha todas as palavras existentes
no ficheiro e que sejam palíndromas (cuja leitura é igual começando do inicio para o fim
ou em sentido inverso).*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAM 10

int main(){
    char *s;
    FILE *f;

    f = fopen("palavras.txt", "w");
    if(f == NULL){
        printf("Erro ao abrir ficheiro.\n");
        return -1;
    }
    while(scanf("%ms", &s) > 0){
        printf("String \"%s\"\n", s);
        free(s);
    }
    fclose(f);
    return 0;
}