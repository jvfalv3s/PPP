#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include <ctype.h>

//main do codigo

int main(){

    //inicializar a lista de alunos, carregar os dados do ficheiro para a memoria
    struct lista_alunos *list = create_lista_alunos();
    struct lista_despesas *list_despesas = create_lista_despesas();
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
    
        int opcao = getchar();
        while (getchar() != '\n');  // Limpar o buffer do input
        
        switch (opcao) {
            case '1':
                //chamar funcao para adicionar aluno
                //primeiro chamar o utilizador para inserir os dados do aluno via scanf
                //enviar os dados para a struct aluno que envia para a funcao insert_aluno
                struct aluno a1;
                printf("Insira o nome do aluno: ");
                scanf(" %99s", a1.nome);
                printf("Insira o curso do aluno: ");
                scanf(" %99s", a1.curso);
                printf("Insira a data de nascimento do aluno (dd/mm/aaaa): ");
                scanf(" %99s", a1.data_nascimento);
                printf("Insira o ano do aluno: ");
                scanf(" %d", &a1.ano);
                printf("Insira o numero do aluno: ");
                scanf(" %d", &a1.numero);
                a1.saldo = 0.0; //saldo inicial do aluno é 0
                insert_aluno(list, a1);//chamar funcao para adicionar aluno, enviar a struct aluno para a funcao insert_aluno
                break;
            case '2':
                //chamar funcao para eliminar aluno
                int key;
                printf("Insira o numero do aluno a eliminar: ");
                scanf(" %d", &key);
                delete_aluno(list, key);
                break;
            case '3':
                //chamar funcao para listar alunos
                print_lista_alunos(list);
                printf("\n");
                break;
            case '4':
                //chamar funcao para registrar despesa
                struct despesas d1;
                int id_aluno;
                printf("Insira o ID do aluno: ");
                scanf(" %d", &id_aluno);
                printf("Insira o valor da despesa: ");
                scanf(" %f", &d1.valor);
                
                // Validacao de seguranca: valor nao pode ser negativo ou zero
                if (d1.valor <= 0) {
                    printf("Erro: O valor da despesa deve ser positivo.\n");
                    break;
                }
                
                printf("Insira a descricao da despesa: ");
                scanf(" %99s", d1.descricao);
                insert_despesa(list_despesas, d1, id_aluno);
                break;
            case '5':
                //chamar funcao para carregar saldo
                int id_aluno_carregar;
                float valor_carregar;
                printf("Insira o ID do aluno: ");
                scanf(" %d", &id_aluno_carregar);
                printf("Insira o valor a carregar: ");
                scanf(" %f", &valor_carregar);
                
                // Validacao de seguranca: valor nao pode ser negativo ou zero
                if (valor_carregar <= 0) {
                    printf("Erro: O valor a carregar deve ser positivo.\n");
                    break;
                }
                
                carregar_conta(list, id_aluno_carregar, valor_carregar);
                break;
            case '6':
                //chamar funcao para gravar dados para o ficheiro
                //"puxar" os dados da memoria para o ficheiro.
                //void gravar_dados(struct lista_alunos *list, struct lista_despesas *list_despesas);
                break;
            case '7':
                //sair do programa
                exit(0);
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    
    }
    

    //a principio pensei em ficheiro de texto, mas como vou colocar listas, faz mais sentido usar ficheiros binarios, para guardar as estruturas.

    return 0;
}