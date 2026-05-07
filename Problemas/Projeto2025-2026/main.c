#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

//main do codigo

int main(){

    //inicializar a lista de alunos, carregar os dados do ficheiro para a memoria

    //aqui vai ter o menu e as chamadas das funcoes
    
     while(1){
        printf("Menu:\n");
        //funcoes do menu (prototipos das funcoes no header)

        //aluno novo
        printf("1. Adicionar aluno\n");
        //eliminar aluno
        printf("2. Eliminar aluno\n");
        //listar alunos
        printf("3. Listar alunos\n");
        //registrar despesa
        printf("4. Registrar despesa\n");
        //carregar saldo
        printf("5. Carregar saldo\n"); //aqui eu tenho que procurar um aluno especifico
        //gravar dados para o ficheiro
        printf("6. Gravar dados\n");
        //sair do programa
        printf("7. Sair\n");
    /*
        switch (expression)
        {
        case constant expression:
           (codigo aqui)
            break;
        
        default:
            break;
        }
    */
    }
    

    //a principio pensei em ficheiro de texto, mas como vou colocar listas, faz mais sentido usar ficheiros binarios, para guardar as estruturas.

    return 0;
}