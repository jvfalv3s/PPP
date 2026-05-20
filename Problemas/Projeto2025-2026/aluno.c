#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "aluno.h"

//funcoes utilitarias de leitura (resolucao do skip ao pressionar uma opcao do menu)

//funcao para limpar o buffer do stdin
void limpar_buffer_stdin(void){
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { 
        /* limpa caracteres restantes da linha */
    }
}

//funcao que garante a leitura correta apenas de ints
int ler_inteiro(const char *mensagem, int *valor){
    while (1) {
        printf("%s", mensagem);
        if (scanf(" %d", valor) == 1) {
            limpar_buffer_stdin();
            return 1;
        }

        printf("Entrada invalida. Insira um numero inteiro.\n");
        limpar_buffer_stdin();
    }
}

//funcao que garante a leitura correta apenas de floats
int ler_float(const char *mensagem, float *valor){
    while (1) {
        printf("%s", mensagem);
        if (scanf(" %f", valor) == 1) {
            limpar_buffer_stdin();
            return 1;
        }

        printf("Entrada invalida. Insira um numero valido.\n");
        limpar_buffer_stdin();
    }
}

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

static struct lista_alunos *find_aluno_by_id(struct lista_alunos *list, int id_aluno){
    struct lista_alunos *current = list->next;
    while(current != NULL){
        if(current->al.numero == id_aluno){
            return current;
        }
        current = current->next;
    }
    return NULL;
}

static void insert_despesa_lista(struct lista_despesas *list, struct despesas d1, int id_aluno){
    struct lista_despesas *node, *previous, *useless;
    node = (struct lista_despesas *)malloc(sizeof(struct lista_despesas));
    if (node != NULL) {
        node->desp = d1;
        node->desp.id_aluno = id_aluno;
        search_despesas(list, d1.descricao, &previous, &useless);
        node->next = previous->next;
        previous->next = node;
    }
}
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
void insert_despesa(struct lista_alunos *lista_alunos, struct lista_despesas *list, struct despesas d1, int id_aluno){//atentar para qual aluno a despesa esta associada, usar o id_aluno para comparar com o numero do aluno na struct aluno e assim associar a despesa ao aluno correto
    struct lista_alunos *aluno = find_aluno_by_id(lista_alunos, id_aluno);

    if (aluno == NULL) {
        printf("Aluno com numero %d nao encontrado. Despesa nao registrada.\n", id_aluno);
        return;
    }

    insert_despesa_lista(list, d1, id_aluno);
    aluno->al.saldo -= d1.valor;
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
    if(empty_alunos(list)){
        printf("Nao ha alunos cadastrados.\n");
    }
}
//print_despesa_aluno (printar os dados do aluno e todas as suas despesas)
void print_despesa_aluno(struct lista_alunos *list_alunos, struct lista_despesas *list_despesas, int id_aluno){
    struct lista_alunos *aluno = find_aluno_by_id(list_alunos, id_aluno);
    struct lista_despesas *current;
    float total_despesas = 0.0;
    int encontrou_despesa = 0;

    if (aluno == NULL) {
        printf("Aluno com numero %d nao encontrado.\n", id_aluno);
        return;
    }

    print_aluno(aluno->al);
    printf("Despesas do aluno %s:\n", aluno->al.nome);

    current = list_despesas->next; //pular o header
    while(current != NULL){
        if (current->desp.id_aluno == id_aluno) {
            printf("Valor: %.2f\n", current->desp.valor);
            printf("Descricao: %s\n", current->desp.descricao);
            printf("Data: %s\n", current->desp.data);
            total_despesas += current->desp.valor;
            encontrou_despesa = 1;
        }
        current = current->next;
    }

    if (!encontrou_despesa) {
        printf("Nao ha despesas registradas para este aluno.\n");
    }

    printf("Total de despesas: %.2f\n", total_despesas);
    printf("Saldo atual do aluno: %.2f\n", aluno->al.saldo);
}
//print_lista_despesas_aluno
void print_lista_despesas_aluno(struct lista_despesas *list, int id_aluno){
    struct lista_despesas *current = list->next; //pular o header
    printf("Despesas do aluno com ID %d:\n", id_aluno);
    while(current != NULL){
        if(current->desp.id_aluno == id_aluno){
            printf("Valor: %.2f\n", current->desp.valor);
            printf("Descricao: %s\n", current->desp.descricao);
            printf("Data: %s\n", current->desp.data);
        }
        current = current->next;
    }
}
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

//----funcoes de ficheiros----//

//gravar_dados (gravar os dados da lista de alunos e despesas para um ficheiro binario) para proxima semana// to fraco de ficheiros
void gravar_dados(struct lista_alunos *list, struct lista_despesas *lista_despesas){
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
    //printar mensagem de sucesso
    printf("Dados de alunos gravados com sucesso.\n");
    fclose(file);
    //Gravar a lista de despesas
    file = fopen("despesas.bin", "wb");
    if (file == NULL) {
        printf("Erro ao abrir o ficheiro para escrita.\n");
        return;
    }
    struct lista_despesas *current_despesa = lista_despesas->next; //pular o header
    while(current_despesa != NULL){
        fwrite(&(current_despesa->desp), sizeof(struct despesas), 1, file);
        current_despesa = current_despesa->next;
    }
    //printar mensagem de sucesso
    printf("Dados de despesas gravados com sucesso.\n");
    fclose(file);
}
//abrir ficheiro(com as infos de ambas as listas?) -> ler os dados do ficheiro e carregar para a memoria, vai ser chamada bastante nas funcoes de comparacao
void abrir_ficheiro(struct lista_alunos *list, struct lista_despesas *lista_despesas){
    // Ler a lista de alunos
    FILE *file = fopen("dados.bin", "rb");
    if (file == NULL) {
        printf("Erro ao abrir o ficheiro para leitura.\n");
        return;
    }
    else {
        printf("Ficheiro aberto com sucesso.\n");
    }
    struct aluno a1;
    while(fread(&a1, sizeof(struct aluno), 1, file) == 1){
        insert_aluno(list, a1);
    }
    fclose(file);
    // Ler a lista de despesas
    file = fopen("despesas.bin", "rb");
    if (file == NULL) {
        printf("Erro ao abrir o ficheiro para leitura.\n");
        return;
    }
    else {
        printf("Ficheiro de despesas aberto com sucesso.\n");
    }
    struct despesas d1;
    while(fread(&d1, sizeof(struct despesas), 1, file) == 1){
        insert_despesa_lista(lista_despesas, d1, d1.id_aluno);
    }
    fclose(file);
}
//----------------------------//

//----funcoes de integridade de dados----//
//verificar se o aluno tem saldo suficiente antes de efetuar a despesa, aplicar mensagens de erro e nao deixar o programa sair em caso de erro, por exemplo, se o aluno nao existe, imprimir uma mensagem de erro e retornar ao menu
void verificar_saldo_suficiente(struct lista_alunos *list, int id_aluno, float valor_despesa){
    struct lista_alunos *aluno = find_aluno_by_id(list, id_aluno);

    if (aluno == NULL) {
        printf("Aluno com numero %d nao encontrado. Despesa nao registrada.\n", id_aluno);
        return;
    }

    if (aluno->al.saldo < valor_despesa) {
        printf("Saldo insuficiente para registrar a despesa. Saldo atual: %.2f\n", aluno->al.saldo);
        return;
    }
}
//procurar  alunos com despesas acima de um valor especifico, imprimir os alunos e o valor total das despesas (terei que percorrer a lista de alunos e a lista de despesas de cada aluno, comparar o valor da despesa com o valor especifico e imprimir os alunos que tiverem despesas acima desse valor)
void procurar_plafond(struct lista_alunos *list, float valor){
    struct lista_alunos *current_aluno = list->next; //pular o header
    int found = 0;
    while(current_aluno != NULL){
        float total_despesas = 0.0;
        struct lista_despesas *current_despesa = current_aluno->al.despesas; //pular o header
        while(current_despesa != NULL){
            total_despesas += current_despesa->desp.valor;
            current_despesa = current_despesa->next;
        }
        if(total_despesas > valor){
            printf("Aluno: %s, Total de despesas: %.2f\n", current_aluno->al.nome, total_despesas);
            found = 1;
        }
        current_aluno = current_aluno->next;
    }
    if(!found){
        printf("Nenhum aluno encontrado com despesas acima de %.2f.\n", valor);
    }
} //tem que percorrer a lista de alunos e a lista de despesas de cada aluno, comparar o valor da despesa com o valor especifico e imprimir os alunos que tiverem despesas acima desse valor

// funcao para printar um aluno especifico a prtir do seu numero e todas as suas despesas, para facilitar a verificacao de dados e a associacao entre alunos e despesas
void print_aluno_e_despesas(struct lista_alunos *list, struct lista_despesas *lista_despesas, int id_aluno){
    print_despesa_aluno(list, lista_despesas, id_aluno);
}

//---------------------------------------//

//1. despesas nao atualizam o saldo do aluno
//2. eliminar o aluno nao elimina a lista de despesas
//3. listar as depesas de um aluno especifico ou listar todos os alunos com seus saldos e depesas.
//4. as depesas precisam de uma data, adicionar ao struct despesas e ao print_despesa_aluno
//5. verificar datas, nomes e valores.
//6. como verificar se as depesas precisam de um id.