//estruturas de dados para o aluno e para a lista de alunos

// vou ter uma lista de alunos e uma lista de despesas gerais ou uma lista de alunos associado a uma lista de despesas?
//posso usar o mesmo exemplo da questao 13.3.3, uma lista com cada no com varios ponteiros, um para o aluno, outro para a despesa e assim por diante.
#ifndef ALUNO_H
#define ALUNO_H

#define MAX 100

//struct do aluno com alunos  (nome,  data  de nascimento,  curso,  ano,  número,  saldo).
struct aluno{
    char nome[MAX];
    char curso[MAX];
    char data_nascimento[MAX]; //lembrar de especificar o formato de leitura de data
    
    //dados com duvida em tipo.
    int ano;
    int numero;
    float saldo;
    
    //ponteiro para a lista de despesas do aluno
    struct lista_despesas *despesas;
};

//struct da lista de alunos, com um ponteiro para o proximo aluno e um ponteiro para a lista de despesas do aluno
struct lista_alunos{
    struct aluno al;
    struct lista_alunos *next;
};

//struct da despesa (descricao, valor, data, aluno associado) ainda decidindo se vou ter uma lista de despesas ou se vou associar as despesas por aluno usando ponteiros, aka cad aluno tem uma lista de despesas associada.

struct despesas{
    float valor;
    char descricao[MAX];
    char data[MAX];
    //ponteiro para o aluno especifico associado a esta despesa, para facilitar a associacao da despesa ao aluno correto, vou usar o numero do aluno como chave de associacao
    int id_aluno;
    
};

//struct da lista de despesas, com um ponteiro para o proximo despesa e um id do aluno associado
struct lista_despesas{
    struct despesas desp;
    struct lista_despesas *next;
};

//funcoes utilitarias de leitura
void limpar_buffer_stdin(void);
int ler_inteiro(const char *mensagem, int *valor);
int ler_float(const char *mensagem, float *valor);
int ler_texto(const char *mensagem, char *buffer, int tamanho_max);
int ler_nome(const char *mensagem, char *buffer, int tamanho_max);
int ler_data(const char *mensagem, char *buffer, int tamanho_max);
int ler_descricao(const char *mensagem, char *buffer, int tamanho_max);

//prototipos das funcoes:
//create_lista_alunos
struct lista_alunos *create_lista_alunos(void);
//create_lista_despesas
struct lista_despesas *create_lista_despesas(void);
//empty
int empty_alunos(struct lista_alunos *list);
int empty_despesas(struct lista_despesas *list);
//clean
struct lista_alunos *clean_lista_alunos(struct lista_alunos *list);
struct lista_despesas *clean_lista_despesas(struct lista_despesas *list);
//search
void search_alunos(struct lista_alunos *list, char *key, struct lista_alunos **previous,struct lista_alunos **current);
void search_despesas(struct lista_despesas *list, char *key, struct lista_despesas **previous,struct lista_despesas **current);
//delete
void delete_aluno(struct lista_alunos *list, struct lista_despesas *lista_despesas, int key);
void delete_despesa(struct lista_despesas *list, char *key);
//insert
void insert_aluno(struct lista_alunos *list, struct aluno a1);
void insert_despesa(struct lista_alunos *lista_alunos, struct lista_despesas *list, struct despesas d1, int id_aluno);//atentar para qual aluno a despesa esta associada, usar o id_aluno para comparar com o numero do aluno na struct aluno e assim associar a despesa ao aluno correto
//print_aluno
void print_aluno(struct aluno a);
//print_lista_alunos em ordem alfabetica
void print_lista_alunos(struct lista_alunos *list);
//print_despesa_aluno (printar os dados do aluno e todas as suas despesas)
void print_despesa_aluno(struct lista_alunos *list_alunos, struct lista_despesas *list_despesas, int id_aluno);
//print_aluno_e_despesas (mostrar um aluno especifico e suas despesas)
void print_aluno_e_despesas(struct lista_alunos *list, struct lista_despesas *lista_despesas, int id_aluno);
//print_lista_despesas_aluno
void print_lista_despesas_aluno(struct lista_despesas *list, int id_aluno);
//carregar_conta (adicionar saldo a um aluno)
void carregar_conta(struct lista_alunos *list, int id_aluno, float valor);
//procurar  alunos com despesas acima de um valor especifico, imprimir os alunos e o valor total das despesas (terei que percorrer a lista de alunos e a lista de despesas de cada aluno, comparar o valor da despesa com o valor especifico e imprimir os alunos que tiverem despesas acima desse valor)
void procurar_plafond(struct lista_alunos *list, float valor); //tem que percorrer a lista de alunos e a lista de despesas de cada aluno, comparar o valor da despesa com o valor especifico e imprimir os alunos que tiverem despesas acima desse valor


//----funcoes de ficheiros----//
//gravar_dados (gravar os dados da lista de alunos e despesas para um ficheiro binario) para proxima semana// to fraco de ficheiros
void gravar_dados(struct lista_alunos *list, struct lista_despesas *list_despesas);
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

#endif