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

int maiorPalavra(FILE *f){
    char *s;
    int maior = 0;
    int tam = 0;

    s = (char *) malloc(TAM * sizeof(char));
    if(s == NULL){
        printf("Erro ao alocar memória\n");
        return 1;
    }

    while(fgets(s, TAM, f) != NULL){
        tam = strlen(s) - 1;
        if(tam > maior){
            maior = tam;
        }
    }

    free(s);
    return maior;
}

void palin(FILE *f, FILE *f2){
    char *s;
    int i, j, tam;
    int palin = 1;

    s = (char *) malloc(TAM * sizeof(char));
    if(s == NULL){
        printf("Erro ao alocar memória\n");
        return;
    }

    while(fgets(s, TAM, f) != NULL){
        tam = strlen(s) - 1;
        for(i = 0, j = tam - 1; i < tam / 2; i++, j--){
            if(s[i] != s[j]){
                palin = 0;
                break;
            }
        }
        if(palin){
            fprintf(f2, "%s", s);
        }
        palin = 1;
    }
    free(s);
}

int main(){
    char *s;
    FILE *f;
    //FILE *f2;

    f = fopen("palavras.txt", "w");
    if(f == NULL){
        printf("Erro ao abrir o ficheiro\n");
        return 1;
    }

    s = (char *) malloc(TAM * sizeof(char));
    if(s == NULL){
        printf("Erro ao alocar memória\n");
        return 1;
    }

    printf("Introduza palavras para guardar no ficheiro (termina com linha vazia):\n");
    do{
        fgets(s, TAM, stdin);
        if(s[0] != '\n'){
            fprintf(f, "%s", s);
        }
    }while(s[0] != '\n');

    fclose(f);
    free(s);
    
    f = fopen("palavras.txt", "r");
    if(f == NULL){
        printf("Erro ao abrir o ficheiro\n");
        return 1;
    }

    printf("A maior palavra tem %d carateres\n", maiorPalavra(f));

    fclose(f);

    return 0;
}