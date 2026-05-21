#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include <ctype.h>

//main do codigo

int main(){

    //inicializar a lista de alunos, carregar os dados do ficheiro para a memoria
    struct lista_alunos *list = create_lista_alunos();
    struct lista_despesas *lista_despesas = create_lista_despesas();
    
     while(1){
        printf("Menu:\n");

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
        //abrir ficheiro e carregar os dados para a memoria
        printf("8. Abrir ficheiro\n");
        //mostrar aluno especifico e suas despesas
        printf("9. Mostrar aluno e despesas\n");
        //procurar alunos com despesas acima de um valor especifico
        printf("10. Procurar alunos com despesas acima de um valor especifico\n");
    
        //ler a opcao do menu, validar a opcao e chamar a funcao correspondente
        int opcao;
        ler_inteiro("Insira a opcao: ", &opcao);
        
        switch (opcao) {
            case 1:
                //chamar funcao para adicionar aluno
                //primeiro chamar o utilizador para inserir os dados do aluno via scanf
                //enviar os dados para a struct aluno que envia para a funcao insert_aluno
                struct aluno a1;
                ler_nome("Insira o nome do aluno: ", a1.nome, MAX);
                ler_nome("Insira o curso do aluno: ", a1.curso, MAX);
                ler_data("Insira a data de nascimento do aluno (dd/mm/aaaa): ", a1.data_nascimento, MAX);
                ler_inteiro("Insira o ano do aluno: ", &a1.ano);
                ler_inteiro("Insira o numero do aluno: ", &a1.numero);
                a1.saldo = 0.0; //saldo inicial do aluno e 0
                insert_aluno(list, a1);//chamar funcao para adicionar aluno, enviar a struct aluno para a funcao insert_aluno
                break;
            case 2:
                //chamar funcao para eliminar aluno
                int key;
                ler_inteiro("Insira o numero do aluno a eliminar: ", &key);
                delete_aluno(list, lista_despesas, key);
                break;
            case 3:
                //chamar funcao para listar alunos
                print_lista_alunos(list);
                printf("\n");
                break;
            case 4:
                //chamar funcao para registrar despesa
                struct despesas d1;
                int id_aluno;
                ler_inteiro("Insira o ID do aluno: ", &id_aluno);
                ler_float("Insira o valor da despesa: ", &d1.valor);
                // Validacao de seguranca: valor nao pode ser negativo ou zero
                if (d1.valor <= 0) {
                    printf("Erro: O valor da despesa deve ser positivo.\n");
                    break;
                } 
                ler_descricao("Insira a descricao da despesa: ", d1.descricao, MAX);
                ler_data("Insira a data da despesa (dd/mm/aaaa): ", d1.data, MAX);
                insert_despesa(list, lista_despesas, d1, id_aluno);
                break;
            case 5:
                //chamar funcao para carregar saldo
                int id_aluno_carregar;
                float valor_carregar;
                ler_inteiro("Insira o ID do aluno: ", &id_aluno_carregar);
                ler_float("Insira o valor a carregar: ", &valor_carregar);
                
                // Validacao de seguranca: valor nao pode ser negativo ou zero
                if (valor_carregar <= 0) {
                    printf("Erro: O valor a carregar deve ser positivo.\n");
                    break;
                }
                
                carregar_conta(list, id_aluno_carregar, valor_carregar);
                break;
            case 6:
                //chamar funcao para gravar dados para o ficheiro
                //"puxar" os dados da memoria para o ficheiro.
                gravar_dados(list, lista_despesas);
                //ao chamar a funcao, printar um mensagem de sucesso ou erro, dependendo do resultado da funcao gravar_dados
                break;
            case 7:
                //sair do programa
                exit(0);
            case 8:
                //chamar funcao para abrir ficheiro e carregar os dados para a memoria
                abrir_ficheiro(list, lista_despesas);
                break;
            case 9:
                //mostrar aluno especifico e todas as suas despesas
                int id_aluno_consulta;
                ler_inteiro("Insira o numero do aluno: ", &id_aluno_consulta);
                print_aluno_e_despesas(list, lista_despesas, id_aluno_consulta);
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
            case 10:
                //procurar alunos com despesas acima de um valor especifico
                float valor_plafond;
                ler_float("Insira o valor para procurar alunos com despesas acima desse valor: ", &valor_plafond);
                procurar_plafond(list, valor_plafond);
                break;
        }
    
    }

    return 0;
}