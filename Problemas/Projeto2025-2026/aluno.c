#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "aluno.h"

//prototipos das funcoes:
//create_lista_alunos
struct lista_alunos *create_lista_alunos(void){
    struct lista_alunos *aux;
    // Create header node
    struct aluno a1 = {"", "", "", 0, 0, 0.0, NULL};
    aux = (struct lista_alunos *)malloc(sizeof(struct lista_alunos));
    if (aux != NULL) {
        aux->al = a1;
        aux->next = NULL;
    }
    return aux;
}
//create_lista_despesas
struct lista_despesas *create_lista_despesas(void){
    struct lista_despesas *aux;
    // Create header node
    struct despesas d1 = {0.0, "", "", 0};
    aux = (struct lista_despesas *)malloc(sizeof(struct lista_despesas));
    if (aux != NULL) {
        aux->desp = d1;
        aux->next = NULL;
    }
    return aux;
}
//empty
int empty_alunos(struct lista_alunos *list){
    return list->next == NULL;
}
int empty_despesas(struct lista_despesas *list){
    return list->next == NULL;
}
//clean
struct lista_alunos *clean_lista_alunos(struct lista_alunos *list){
    while(list != NULL){
        struct lista_alunos *temp_ptr = list;
        list = list->next;
        free(temp_ptr);
    }
    return NULL;
}
struct lista_despesas *clean_lista_despesas(struct lista_despesas *list){
    while(list != NULL){
        struct lista_despesas *temp_ptr = list;
        list = list->next;
        free(temp_ptr);
    }
    return NULL;
}
//search
void search_alunos(struct lista_alunos *list, char *key, struct lista_alunos **previous,struct lista_alunos **current){
    *previous = list;
    *current = list->next;
    while((*current) != NULL && strcmp((*current)->al.nome, key) < 0){
        *previous = *current;
        *current = (*current)->next;
    }
}
void search_despesas(struct lista_despesas *list, char *key, struct lista_despesas **previous,struct lista_despesas **current){
    *previous = list;
    *current = list->next;
    while((*current) != NULL && strcmp((*current)->desp.descricao, key) < 0){
        *previous = *current;
        *current = (*current)->next;
    }
}
//delete
void delete_aluno(struct lista_alunos *list, int key){
    struct lista_alunos *previous = list;
    struct lista_alunos *current;

    if (list == NULL) {
        return;
    }

    current = list->next;
    while (current != NULL && current->al.numero != key) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Aluno com numero %d nao encontrado.\n", key);
        return;
    }

    previous->next = current->next;
    free(current);
    printf("Aluno com numero %d eliminado com sucesso.\n", key);
}
void delete_despesa(struct lista_despesas *list, char *key);
//insert
void insert_aluno(struct lista_alunos *list, struct aluno a1){
    struct lista_alunos *node, *previous, *useless;
    node = (struct lista_alunos *)malloc(sizeof(struct lista_alunos));
    if (node != NULL) {
        node->al = a1;
        search_alunos(list, a1.nome, &previous, &useless);
        node->next = previous->next;
        previous->next = node;
    }
}
void insert_despesa(struct lista_despesas *list, struct despesas d1, int id_aluno){//atentar para qual aluno a despesa esta associada, usar o id_aluno para comparar com o numero do aluno na struct aluno e assim associar a despesa ao aluno correto
    struct lista_despesas *node, *previous, *useless;
    node = (struct lista_despesas *)malloc(sizeof(struct lista_despesas));
    if (node != NULL) {
        node->desp = d1;
        node->desp.id_aluno = id_aluno; //associar a despesa ao aluno correto usando o id_aluno, id_aluno é o numero do aluno, que é unico para cada aluno, entao posso usar isso como chave de associacao
        search_despesas(list, d1.descricao, &previous, &useless);
        node->next = previous->next;
        previous->next = node;
    }
}
//print_aluno
void print_aluno(struct aluno a){
    printf("Nome: %s\n", a.nome);
    printf("Curso: %s\n", a.curso);
    printf("Data de nascimento: %s\n", a.data_nascimento);
    printf("Ano: %d\n", a.ano);
    printf("Numero: %d\n", a.numero);
    printf("Saldo: %.2f\n", a.saldo);
}
//print_lista_alunos em ordem alfabetica
void print_lista_alunos(struct lista_alunos *list){
    struct lista_alunos *current = list->next; //pular o header
    while(current != NULL){
        print_aluno(current->al);
        current = current->next;
    }
}
//print_despesa_aluno (printar a despesa total de um aluno, total de saldo (saldo inicial - total de despesas))
void print_despesa_aluno(struct aluno a);
//print_lista_despesas_aluno
void print_lista_despesas_aluno(struct lista_despesas *list, int id_aluno);
//carregar_conta (adicionar saldo a um aluno)
void carregar_conta(struct lista_alunos *list, int id_aluno, float valor){
    struct lista_alunos *current = list->next; //pular o header
    while(current != NULL){
        if(current->al.numero == id_aluno){
            current->al.saldo += valor;
            printf("Saldo carregado com sucesso. Novo saldo: %.2f\n", current->al.saldo);
            return;
        }
        current = current->next;
    }
    printf("Aluno com numero %d nao encontrado.\n", id_aluno);
}
//procurar  alunos com despesas acima de um valor especifico, imprimir os alunos e o valor total das despesas (terei que percorrer a lista de alunos e a lista de despesas de cada aluno, comparar o valor da despesa com o valor especifico e imprimir os alunos que tiverem despesas acima desse valor)
void procurar_plafond(struct lista_alunos *list, float valor); //tem que percorrer a lista de alunos e a lista de despesas de cada aluno, comparar o valor da despesa com o valor especifico e imprimir os alunos que tiverem despesas acima desse valor


//----funcoes de ficheiros----//
//gravar_dados (gravar os dados da lista de alunos e despesas para um ficheiro binario) para proxima semana// to fraco de ficheiros
void gravar_dados(struct lista_alunos *list, struct lista_despesas *list_despesas){
    FILE *file = fopen("dados.bin", "wb");
    if (file == NULL) {
        printf("Erro ao abrir o ficheiro para escrita.\n");
        return;
    }
    // Gravar a lista de alunos
    struct lista_alunos *current_aluno = list->next; //pular o header
    while(current_aluno != NULL){
        fwrite(&(current_aluno->al), sizeof(struct aluno), 1, file);
        current_aluno = current_aluno->next;

    }
    fclose(file);
}
//abrir ficheiro(com as infos de ambas as listas?) -> ler os dados do ficheiro e carregar para a memoria, vai ser chamada bastante nas funcoes de comparacao
void abrir_ficheiro(struct lista_alunos *list, struct lista_despesas *list_despesas);
//----------------------------//


//----funcoes de integridade de dados----//
//verificar se o aluno existe antes de eliminar, listar ou carregar conta
void verificar_aluno_existe(struct lista_alunos *list, int key);
//verificar se a despesa existe antes de eliminar
void verificar_despesa_existe(struct lista_despesas *list, char *key);
//verificar se o valor da despesa e do carregamento de conta estao corretos antes de efetuar a operacao
void verificar_valor(float valor);
//verificar se o aluno tem saldo suficiente antes de efetuar a despesa, aplicar mensagens de erro e nao deixar o programa sair em caso de erro, por exemplo, se o aluno nao existe, imprimir uma mensagem de erro e retornar ao menu
void verificar_saldo_suficiente(struct lista_alunos *list, int id_aluno, float valor_despesa);
//---------------------------------------//
