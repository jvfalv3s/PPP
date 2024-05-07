/*escreva um programa que leia um ficheiro e determine a linha mais longa*/

#include<stdio.h>
#include<string.h>
#define TAM 81

int main(){
    char s[TAM];
    int i, i_maior, tam , tam_maior, tmp;
    FILE *f;

    //f = fopen("ficheiro.txt", "r");

    f = stdin;

    if(f == NULL){
        printf("erro ao abrir ficheiro. \n");
        return -1;
    }

    tmp = tam = 0; tam_maior = -1;
    i = i_maior = 0;

    while(fgets(s, TAM, f) != NULL){
        tmp = strlen(s);
        if(s[tmp-1]=='\n'){
            i++;
            tam += tmp - 1;
            if(tam > tam_maior){
                i_maior = i;
                tam_maior = tam;
            }
            tam = 0;
        }else{
            tam += tmp;
        }
        if( tmp > 0 && s[tmp -1] != '\n'){
            i++;
            if (tam > tam_maior){
                i_maior = i;
                tam_maior = tam;
            }
        }
        if(i != 0){
            printf("Numero de linhas: %d\n", i);
            printf("Linha mais longa: %d com %d caracteres.\n", i_maior, tam_maior);
        }else
            printf("Ficheiro vazio.\n");
        fclose(f);
        return 0;
    }

}